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
int cnt[M];
int val[M];
int rev[N];
const int mod = 1000000009;
int main()
{
  for( int i = 1; i < N; ++i )
    {
      int k = 1;
      for( int j = mod - 2, l = i; j; j >>= 1, l = ( (ll)l * (ll)l ) % mod )
	if( j & 1 )
	  k = ( (ll)k * (ll) l ) % mod;
      rev[i] = k;
    }
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
	  memset( cnt, 0, sizeof( cnt ) );
	  for( int k = 0; k < n; ++k )
	    ++cnt[ ( ( v[k] % m ) + m ) % m ];
	  int f, t;
	  f = 0, t = 1;
	  memset( dp[f], 0, sizeof( dp[f] ) );
	  dp[f][0] = 1;
	  for( int k = 0; k < m; ++k )
	    {
	      memset( val, 0, sizeof( val ) );
	      for( int l = 0, c = 1; l <= cnt[k]; ++l )
		{
		  int tmp = ( ( l % m ) * k ) % m;
		  val[tmp] = ( (ll)val[tmp] + c ) % mod;
		  c = ( (ll)c * ( ( ( ll) ( cnt[k] - l ) * (ll)rev[l + 1] ) % mod ) ) % mod;
		}
	      memset( dp[t], 0, sizeof( dp[t] ) );
	      for( int l = 0; l < m; ++l )
		if( val[l] )
		  for( int u = 0; u < m; ++u )
		    {
		      int tmp = ( u + l ) % m;
		      dp[t][tmp] = ( (ll)dp[t][tmp] + 
				     (ll)val[l] * (ll)dp[f][u] ) % mod;
		    }
	      swap( f, t );
	    }
	  printf("%d\n", dp[f][0] );
	}
    }
  return 0;
}
