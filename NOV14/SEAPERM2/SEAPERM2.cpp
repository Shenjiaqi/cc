#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 307;

int p[N][N];
int ans[N];

map<int, int> mapp;
vector<int> row1;

inline void solve1(int n);
inline void solve2(int n);
inline void solve3(int n);
inline void solveB(int n);

int main()
{
  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      int n;
      scanf("%d", &n);

      mapp.clear();
      row1.clear();

      for (int i = 0; i < n; ++i)
	{
	  for (int j = 0; j < n - 1; ++j)
	    {
	      scanf("%d", &p[i][j]);

	      if (p[i][j] == 1)
		{
		  ++mapp[j];

		  if (mapp[j] == 1)
		    {
		      row1.push_back(i);
		    }
		}
	    }
	}

      if (n < 5)
	{
	  solveB(n);
	}
      else if (mapp.size() == 3)
	{
	  solve3(n);
	}
      else if(mapp.size() == 2)
	{
	  solve2(n);
	}
      else if(mapp.size() == 1)
	{
	  solve1(n);
	}

      for (int i = 0; i< n; ++i)
	{
	  printf("%d ", ans[i]);
	}
      printf("\n");
    }

  return 0;
}

void getAns(int n, int r, int c)
{
  int i = 0;
  for (; i < c; ++i)
    {
      ans[i] = p[r][i] + 1;
    }

  ans[i] = 1;
  ++i;

  for (; i < n; ++i)
    {
      ans[i] = p[r][i - 1] + 1;
    }
}

void getPAns(int n, int c)
{
  const int rc(c);

  vector<int> q;
  for (int i = 0; i < n; ++i)
    {
      if (p[i][c] == 1)
	{
	  q.push_back(i);
	}
    }

  ++c;
  for (int i = 2; c < n - 1; ++c, ++i)
    {
      vector<int> tmpQ;

      for (auto j: q)
	{
	  if (p[j][c] != i)
	    {
	      tmpQ.push_back(j);
	    }
	}

      if (!tmpQ.empty())
	{
	  if (q.size() > tmpQ.size())
	    {
	      q = tmpQ;
	      break;
	    }
	}
    }

  getAns(n, q[0], rc);
}

void solve3(int n)
{
  int s[3][2], si(0);
  for (auto i: mapp)
    {
      s[si][0] = i.first;
      s[si][1] = i.second;
      ++si;
    }

  int r(0), c(0);
  if (s[0][1] == 1 && s[1][0] == s[2][0] - 1 &&
      s[1][1] == s[2][0] && s[2][1] == n - 1 - s[2][0])
    {
      for (auto i: row1)
	{
	  if (p[i][s[0][0]] == 1)
	    {
	      r = i;
	      break;
	    }
	}
      // c = s[0][0];
      c = s[2][0];
    }
  else
    {
      for (auto i: row1)
	{
	  if (p[i][s[2][0]] == 1)
	    {
	      r = i;
	      break;
	    }
	}
      // c = s[2][0];
      c = s[1][0];
    }

  getAns(n, r, c);
}

void solve2(int n)
{
  int s[2][2], si(0);
  for (auto i: mapp)
    {
      s[si][0] = i.first;
      s[si][1] = i.second;
      ++si;
    }

  if ((s[1][0] == n - 2 && s[0][1] == 1) ||
      (s[0][0] == 0 && s[1][1] == 1))
    {
      int c =  s[0][1] == 1 ? s[0][0] : s[1][0];
      int r(0);
      for (auto i: row1)
	{
	  if (p[i][c] == 1)
	    {
	      r = i;
	      break;
	    }
	}

      getAns(n, r, s[0][1] == 1 ? s[1][0] : s[0][0]);
    }
  else
    {
      bool needSwap = false;
      if (s[1][1] == n - 1 - s[1][0] && s[0][1] == s[1][0] + 1)
	{
	  //       s[1][0]
	  // ... 2 1 ...
	  needSwap = true;
	}

      if (needSwap)
	{
	  s[0][0] = n - 2 - s[0][0];
	  s[1][0] = n - 2 - s[1][0];

	  for (int i = 0; i < n; ++i)
	    {
	      for (int a = 0, b = n - 2; a < b; ++a, --b)
		{
		  swap(p[i][a], p[i][b]);
		}
	    }
	}

      getPAns(n, max(s[0][0], s[1][0]));

      if (needSwap)
	{
	  for (int a = 0, b = n - 1; a < b; ++a, --b)
	    {
	      swap(ans[a], ans[b]);
	    }
	}
    }
}

void solve1(int n)
{
  int c = mapp.begin()->first;

  if (c == n - 2)
    {
      for (int i = 0; i < n; ++i)
	{
	  for (int a = 0, b = n - 2; a < b; ++a, --b)
	    {
	      swap(p[i][a], p[i][b]);
	    }
	}
    }

  getPAns(n, c == n - 2 ? 0 : c);

  if (c == n - 2)
    {
      for (int a = 0, b = n - 1; a < b; ++a, --b)
	{
	  swap(ans[a], ans[b]);
	}
    }
}

void solveB(int n)
{
  for (int i = 0; i < n; ++i)
    {
      ans[i] = i + 1;
    }

  unordered_map<ll, int> vis;
  for (int i = 0; i < n; ++i)
    {
      ll tmp(0);
      for (int j = 0; j < n - 1; ++j)
	{
	  tmp = tmp * N + p[i][j];
	}

      ++vis[tmp];
    }

  for (;;)
    {
      unordered_map<ll, int> rVis(vis);

      bool ok = true;
      for (int i = 0; ok && i < n; ++i)
	{
	  ll tmp(0);
	  for (int j = 0; j < n; ++j)
	    {
	      if (i != j)
		{
		  if (ans[j] > ans[i])
		    {
		      tmp = tmp * N + ans[j] - 1;
		    }
		  else
		    {
		      tmp = tmp * N + ans[j];
		    }
		}
	    }

	  if (vis.count(tmp) == 0 || --vis[tmp] < 0)
	    {
	      ok = false;
	    }
	}
      
      if (ok)
	{
	  break;
	}

      vis = rVis;
      next_permutation(ans, ans + n);
    }
}
