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
const ll mod = 1e9 + 7;
const int N = 507;
const int E = 1e6 + 7;
int rev[N][ ( ( N - 1 ) * N ) / 2 + 1 ];
int cc[N][N];
int po[N];
// int ans[N][ ( ( N - 1 ) * N ) / 2 + 1 ];
int addM( ll a, ll b )
{
  // assert( a < mod && b < mod );
  a += b;
  return a >= mod ? a - mod : a;
}
int mulM( ll a, ll b )
{
  // assert( a < mod && b < mod );
  a *= b;
  return a >= mod ? a % mod : a;
}
int subM( ll a, ll b )
{
  a -= b;
  return a < 0 ? a + mod : a ;
}
int maxRev( int v )
{
  return ( ( v - 1 ) * v ) / 2;
}
int main()
{
  for( int i = 0 ; i < N; ++i )
    {
      rev[i][0] = 1;
      for( int j = 1 ; j <= maxRev(i) ; ++j )
	{
	  rev[i][j] = addM( rev[i][ j - 1 ], rev[ i - 1 ][j] );
	  if( i <= j )
	    rev[i][j] = subM( rev[i][j], rev[ i - 1 ][ j - i ] );
	}
    }
  for( int i = 0 ; i < N; ++i )
    for( int j = 1; j <= maxRev(i) ; ++j )
      rev[i][j] = addM( rev[i][j], rev[i][ j - 1 ] );
  for( int i = 0 ; i < N; ++i )
    {
      cc[i][0] = 1;
      for( int j = 1 ; j <= i; ++j )
	cc[i][j] = addM( cc[i - 1][ j - 1 ], cc[ i - 1 ][j] );
    }
  po[0] = 1;
  for( int i = 1; i < N; ++i )
    po[i] = mulM( po[ i - 1 ], i );
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      if( t )
	printf("\n");
      int n, e;
      scanf("%d%d", &n, &e);
      int ans(0);
      for( int i = 1; i <= n ; ++i )
	{
	  int tmp1 = cc[n][i];
	  tmp1 = mulM( tmp1, tmp1);
	  int tmp2 = mulM( po[ n - i + 1 ], po[ n - i ] );
	  ans = addM( ans, mulM(
				mulM( rev[i][ min( maxRev(i), e) ],
				      tmp1),
				tmp2) );
	}
      printf("%d", ans);
    }
  return 0;
}
