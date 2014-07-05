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
ll poV[NN][NNN];
int subM( ll a, ll b )
{
  // if( a >= MOD )
  //   a %= MOD;
  // if( b >= MOD )
  //   b %= MOD;
  a -= b;
  return a < 0 ? a + MOD : a;
}
int addM( ll a, ll b)
{
  // if( a >= MOD )
  //   a %= MOD;
  // if( b >= MOD )
  //   b %= MOD;
  a += b;
  return a >= MOD ? a - MOD : a;
}
int mulM( ll a, ll b )
{
  // if( a >= MOD )
  //   a %= MOD;
  // if( b >= MOD )
    // b %= MOD;
  return ( (ll) a * b ) % MOD;
}
// ll po( ll b, int v )
// {
//   ll r(1);
//   for( ; v; v >>= 1, b *= b )
//     if( v & 1 )
//       {
// 	r *= b;
//       }
//   return r;
// }
bool poLE( ll v, int t, ll m )
{
  if( v < NN && t < NNN )
    return poV[v][t] <= m;
  ll vvv = v;
  ll ttt = t;
  ld tv = v;
  ll c = 1;
  ld tc = 1;
  for( ; t && c <= m; t >>= 1 )
    {
      if( 1 & t )
	{
	  c *= v;
	  tc *= tv;
	  if( tc > (ll)1e18 + 7 )
	    return false;
	}
      v *= v;
      tv *= tv;
    }
  // if( vvv < NN && ttt < NNN )
  //   if( ( poV[vvv][ttt] <= m ) != ( c <= m ) )
  //     assert(0);
  return c <= m;
}
int main()
{
  for( int i = 1; i < NN; ++i )
    {
      poV[i][0] = 1;
      for( int j = 1; j < NNN; ++j )
	{
	  poV[i][j] = poV[i][j - 1] * i;
	  if( poV[i][j] < poV[i][j - 1 ] || poV[i][j - 1] >= (ll)1e18 + 7 )
	    poV[i][j] = (ll)1e18 + 7;
	}
    }
  // ios::sync_with_stdio(false);
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
	{
	  sum[i] = addM( sum[ i + 1 ], p[i] );
	}
      for( int i = 0; i < q; ++i )
	{
	  ll x;
	  scanf("%lld", &x);
	  int j = 0;
	  int ans(0);
	  ll xx = x;
	  for( int j = 0; j < n; ++j )
	    {
	      if( j > 0 )
		{
		  // ll f = max( 1LL, (ll)powl( xx, (ld)1.0 / ( j + 2 ) ) );
		  ll f = 1;
		  ll t = x;//min( x, (ll)powl( xx, (ld)1.0 / ( j ) ) );
		  // ll t = min( x, f + 1000);
		  for( ; f <= t; )
		    {
		      ll m = ( f + t ) / 2;
		      // cout << m << ' ' << j + 1 << endl;
		      if( poLE( m, j + 1, xx ) )
			f = m + 1, x = m;
		      else
			{
			  t = m - 1;
			}
		    }
		}
	      // cout << x << endl;
	      if( x == 1 )
	      	{
	      	  ans = addM( ans, sum[j] );
	      	  break;
	      	}
	      else
	      	if( x < 31 )
	      	{
	      	  // assert( j < NNN );
	      	  for( ; j < n && x > 1; --x )
	      	    {
	      	      int jj = j;
	      	      for( ; jj < n && poV[x][jj + 1] <= xx; ++jj )
	      		;
	      	      // cout << j << ' ' << jj << ' ' << x << ' ' << xx << ' ' << poV[x][j] << endl;
	      	      ans = addM( ans, mulM( x, subM(sum[j], sum[jj]) ) );
	      	      j = jj;
	      	    }
	      	  if( j < n )
	      	    ans = addM( ans, sum[j] );
	      	  break;
	      	}
	      else
		ans = addM( ans, mulM( p[j], x % MOD) );
	      // cout << x << endl;
	    }
	  printf("%d ", ans);
	}
      printf("\n");
    }
  return 0;
}
