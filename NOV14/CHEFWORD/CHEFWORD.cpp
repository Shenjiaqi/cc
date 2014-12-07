#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

typedef long double ld;
const int L = 7;
const int W = 'z' - 'a' + 1;

char s[L], si[L];
double tra[W][W];

inline void mul(double to[W][W], const double a[W][W], const double b[W][W])
{
  for (int i = 0; i < W; ++i)
    {
      for (int j = 0; j < W; ++j)
	{
	  double tmp(0);
	  for (int k = 0; k < W; ++k)
	    {
	      tmp += (double)a[i][k] * b[k][j];
	    }
	  to[i][j] = tmp;
	}
    }
}

int main()
{
  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      int n, k;
      scanf("%d%d%s", &n, &k, s);

      for (int i = 0; i < W; ++i)
	{
	  for (int j = 0; j < W; ++j)
	    {
	      scanf("%lf", &tra[i][j]);
	    }
	}

      double transform[2][W][W];
      int f = 0, t = 1;

      for (int i = 0; i < W; ++i)
	{
	  for (int j = 0; j < W; ++j)
	    {
	      if (i == j)
		{
		  transform[f][i][j] = 1.0;
		}
	      else
		{
		  transform[f][i][j] = 0;
		}
	    }
	}

      double tmp[W][W];
      for (int tK(k); tK; tK >>= 1)
	{
	  if (tK & 1)
	    {
	      mul(transform[t], transform[f], tra);
	      swap(f, t);
	    }

	  mul(tmp, tra, tra);
	  memcpy(tra, tmp, sizeof(tra));
	}

      int ls = strlen(s);
      double ans(0);

      unordered_set<int> appeared;
      for (int i = 0; i < n; ++i)
	{
	  scanf("%s", si);

	  int lsi = strlen(si);
	  if (lsi == ls)
	    {
	      int val(0);
	      for (int i = 0; i < ls; ++i)
		{
		  val = val * W + si[i];
		}
	      if (appeared.count(val) > 0)
		{
		  continue;
		}
	      appeared.insert(val);

	      double tmpAns(1.0);
	      for (int j = 0; s[j]; ++j)
		{
		  int from = s[j] - 'a';
		  int to = si[j] - 'a';
		  tmpAns *= transform[f][from][to];
		}
	      ans += tmpAns;
	    }
	}

      printf("%.6lf\n", (double)ans);
    }

  return 0;
}
