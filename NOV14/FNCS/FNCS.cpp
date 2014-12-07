#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int SN = 330;
const int Q = 1e5 + 10;
const int SQ = 330;

struct query
{
  int type;
  int a;
  int b;
};

int ai[N];
int f[N][2];
int appearCount[SN][SQ];
ll rangeVal[SN];
ll prefixSum[N];
int p[SN][N];
int refIdx[N][2], refIdxI;

void updatePredixSum(int idx, int det)
{
  ++idx;
  for (; idx < N; idx += (idx & (-idx)))
    {
      // if (idx >= N)
      // 	return;
      prefixSum[idx] += det;
    }
}

ll calPrefixSum(int idx)
{
  ++idx;

  ll r(0);

  for (; idx; idx ^= (idx & (-idx)))
    {
      // if (idx >= N)
      // 	return 0;
      r += prefixSum[idx];
    }

  return r;
}

ll calFuncByAi(int idx)
{
  // if (idx >= N)
  //   return 0;

  ll r(calPrefixSum(f[idx][1]));

  return f[idx][0] > 0 ? r - calPrefixSum(f[idx][0] - 1) : r;
}

void add(int idx, int val, int col)
{
  ++idx;

  for (; idx < N; idx += (idx &(-idx)))
    {
      // if (idx >= N)
      // 	return ;
      p[col][idx] += val;
    }
}

int que(int idx, int col)
{
  ++idx;

  int r(0);

  for (; idx; idx ^= (idx & (-idx)))
    {
      // if (col >= SN || idx >= N)
      // 	  return 0;
      r += p[col][idx];
    }

  return r;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    {
      scanf("%d", &ai[i]);

      updatePredixSum(i, ai[i]);
    }

  for (int i = 0; i < n; ++i)
    {
      scanf("%d%d", &f[i][0], &f[i][1]);
      --f[i][0], --f[i][1];
    }

  int sN(sqrt(n) + 1);
  for (int i = 0, j = 0; i < n; ++j)
    {
      for (const int limI = min(i + sN, n); i < limI; ++i)
	{
	  // if (j >= SN)
	  //   return 0;
	  rangeVal[j] += calFuncByAi(i);
	}
    }

  int Q;
  scanf("%d", &Q);
  
  for (int i = 0, j = 0; i < n; ++j)
    {
      for (const int rI(min(n, i + sN)); i < rI; ++i)
	{
	  add(f[i][0], 1, j);
	  add(f[i][1] + 1, -1, j);
	}
    }

  const int sQ(sqrt(Q) + 1);
  for (int i = 0; i < Q;)
    {
      ++refIdxI;
      vector<int> refVec;

      queue<query> queryList;

      int idxCnt(0);
      for (int type1(0); i < Q && type1 < sQ; ++i)
	{
	  int type, a, b;
	  scanf("%d%d%d", &type, &a, &b);

	  if (type == 1)
	    {
	      ++type1;
	      --a;
	      if (refIdx[a][1] != refIdxI)
		{
		  refIdx[a][1] = refIdxI;
		  refIdx[a][0] = idxCnt++;
		  refVec.push_back(a);
		}
	    }
	  else
	    {
	      --a, --b;
	    }

	  queryList.push(query{type, a, b});
	}

      for (int j = 0; j < (n / sN + 1); ++j)
	{
	  for (auto& i:refVec)
	    {
	      const int& pos = i;
	      const int& idx = refIdx[i][0];
	      int count = que(pos, j);
	      appearCount[j][idx] = count;
	    }
	}

      for (;!queryList.empty(); queryList.pop())
	{
	  const query& cQuery = queryList.front();

	  const int& type = cQuery.type;
	  const int& a = cQuery.a;
	  const int& b = cQuery.b;

	  if (type == 1)
	    {
	      for (int i = 0; i < (n / sN + 1); ++i)
		{
		  rangeVal[i] += (ll)appearCount[i][refIdx[a][0]] * 
		    (ll)(b - ai[a]);
		}
	      updatePredixSum(a, b - ai[a]);
	      ai[a] = b;
	    }
	  else
	    {
	      int rA = (a + sN - 1) / sN;
	      int rB = b / sN;

	      ull ans(0);

	      for (int i = a, tI = min(rA * sN, b + 1); i < tI; ++i)
		{
		  ans += calFuncByAi(i);
		}

	      if (rA <= rB)
		{
		  for (int i = rB * sN; i <= b; ++i)
		    {
		      ans += calFuncByAi(i);
		    }

		  for (int i = rA; i < rB; ++i)
		    {
		      // if (i >= SN)
		      // 	return 0;
		      ans += rangeVal[i];
		    }
		}

	      printf("%llu\n", ans);
	    }
	}
    }

  return 0;
}
