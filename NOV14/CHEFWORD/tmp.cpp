#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

typedef long double ld;

const int W = 'z' - 'a' + 1;

ld trans[W][W];

char s[2][7];

inline void mul(ld res[W][W], const ld a[W][W], const ld b[W][W])
{
  for (int i = 0; i < W; ++i)
    {
      for (int j = 0; j < W; ++j)
	{
	  res[i][j] = 0;
	  for (int k = 0; k < W; ++k)
	    {
	      res[i][j] += a[i][k] * b[k][j];
	    }
	}
    }
}

int main()
{
  ios::sync_with_stdio(false);

  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      int n, k;

      scanf("%d%d%s", &n, &k, s[0]);

      for (int i = 0; i < W; ++i)
	{
	  for (int j = 0; j < W; ++j)
	    {
	      cin >> trans[i][j];
	    }
	}

      ld transK[2][W][W];
      int f(0), t(1);

      for (int i = 0; i < W; ++i)
      	{
      	  for (int j = 0; j < W; ++j)
      	    {
      	      if (i == j)
      		{
      		  transK[f][i][j] = 1.0;
      		}
      	      else
      		{
      		  transK[f][i][j] = 0.0;
      		}
      	    }
      	}

      for (int tK(k); tK; tK >>= 1)
      	{
      	  if (tK & 1)
      	    {
      	      mul(transK[t], transK[f], trans);
      	      swap(t, f);
      	    }

      	  ld tmp[W][W];
      	  mul(tmp, trans, trans);
      	  memcpy(trans, tmp, sizeof(trans));
      	}

      ld ans(0);
      int l0 = strlen(s[0]);
      for (int i = 0; i < n; ++i)
	{
	  scanf("%s", s[1]);

	  int l1 = strlen(s[1]);

	  if (l0 == l1)
	    {
	      ld tmpAns(1);
	      for (int j = 0; j < l0; ++j)
	  	{
	  	  int a = s[0][j] - 'a';
	  	  int b = s[1][j] - 'a';
	  	  tmpAns *= transK[f][a][b];
	  	}

	      ans += tmpAns;
	    }
	}

      printf("%.6lf\n", (double)ans);
    }

  return 0;
}
