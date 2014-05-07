#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int M = 107;
const int N = 100007;
int v[N];
int dp[2][M];
const int mod = 1000000009;
int main()
{
  int T;
  scanf("%d", &T);
  for( int i = 0; i < T; ++i )
    {
      int n, q;
      scanf("%d%d", &n, &q);
      for( int j = 0; j < n; ++j )
	scanf("%d", v + j );
      for( int j = 0; j < q; ++j )
	{
	  int m;
	  scanf("%d", &m);
	  int f, t;
	  f = 0, t = 1;
	  memset( dp[f], 0, sizeof(dp[f]) );
	  dp[f][0] = 1;
	  for( int k = 0; k < n; ++k )
	    {
	      memcpy( dp[t], dp[f], sizeof(dp[t]) );
	      for( int l = 0; l < m; ++l )
		{
		  int c = ( l + ( v[k] % m ) + m ) % m;
		  dp[t][c] += dp[f][l];
		  dp[t][c] %= mod;
		}
	      swap( f, t );
	    }
	  printf("%d\n", dp[f][0] );
	}
    }
  return 0;
}
