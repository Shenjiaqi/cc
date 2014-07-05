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
//#include <unordered_set>
//#include <unordered_map>
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
const int N = 10007;
const int MOD = 1e9 + 7;
const int NN = 1007;
const int NNN = 70;
int p[N];
int sum[N];
ll poV[1007][107];
int subM( int a, int b )
{
  a %= MOD, b %= MOD;
  a -= b;
  return a < 0 ? a + MOD : a;
}
int addM( int a, int b)
{
  a %= MOD;
  b %= MOD;
  a += b;
  return a >= MOD ? a - MOD : a;
}
int mulM( int a, int b )
{
  a %= MOD, b %= MOD;
  return ( (ll) a * b ) % MOD;
}
ll po( ll b, int v )
{
  ll r(1);
  for( ; v; v >>= 1, b *= b )
    if( v & 1 )
      {
	r *= b;
      }
  return r;
}
bool poLE( ll v, int t, ll m )
{
  ld tv = v;
  ll c = 1;
  ld tc = 1;
  for( ; t && c <= m; t >>= 1 )
    {
      if( 1 & t )
	{
	  c *= v;
	  tc *= tv;
	  if( tc > 1e18 + 7 )
	    return false;
	}
      v *= v;
      tv *= tv;
    }
  return c <= m;
}
ll rot( ll v, int tim )
{
  ll r(1);
  for( ll f = 1, t = v; f <= t; )
    {
      ll m = ( f + t ) / 2LL;
      if( poLE( m, tim, v ) )
	r = m, f = m + 1;
      else t = m - 1;
    }
  return r;
}
int main()
{
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t )
    {
      int n, q;
      scanf("%d%d", &n, &q);
      for( int i = 0; i < n; ++i )
	{
	  scanf("%d", p + i);
	  if( p[i] < 0 )
	    p[i] += MOD;
	}
      sum[n] = 0;
      for( int i = n - 1; i >= 0; --i )
	sum[i] = addM( sum[i], sum[ i + 1 ] );
      for( int i = 0 ; i < q ; ++i )
	{
	  ll x;
	  scanf("%lld", &x);
	  int ans(0);
	  for( int j = 0; j < n; ++j )
	    {
	      ll v = rot( x, j + 1 );
	      // // if( v > 25 )
	      // 	cout << v << ' ' << j << ' ' << x << endl;
	      ans = addM( ans, mulM( p[j], v ) );
	    }
	  printf("%d ", ans);
	}
      printf("\n");
    }
  return 0;
}
