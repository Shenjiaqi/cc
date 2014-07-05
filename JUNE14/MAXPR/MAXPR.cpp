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
const int L = 101;
const int MOD = 1e9 + 7;
int num[L];
int p[L][L * 2];
int addM( int a, int b )
{
  ll c = a;
  c += b;
  return c >= MOD ? c - MOD : c;
}
int subM( int a, int b )
{
  a -= b;
  if( a < 0 )
    a += MOD;
  return a;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      memset( num, 0, sizeof(num) );
      memset( p, 0, sizeof(p) );
      int n;
      scanf("%d", &n);
      int ans(0);
      int all(1);
      for( int i = 0 ; i < n; ++ i)
	{
	  all = addM( all, all);
	  int a;
	  scanf("%d", &a);
	  // ++ans;
	  // for( int j = 1; j < L; ++j )
	  //   ans = addM( ans, num[j] );
	  // for( int j = 0; j < 2 * L; ++j )
	  //   ans = addM( ans, p[a][j]);
	  // for( int j = 0; j < L * 2; ++j )
	  //   {
	  //     int nxt = j - L + a;
	  //     if( nxt >= 0 && nxt < L )
	  // 	p[nxt][j] = addM( p[nxt][j], p[a][j] );
	  //   }
	  // for( int j = 0; j < L; ++j )
	  //   {
	  //     int nxt = 2 * a - j;
	  //     if( nxt > 0 && nxt < L )
	  // 	p[nxt][ a - j + L ] = addM( p[nxt][ a - j + L], num[j] );
	  //   }
	  // num[a] = addM( num[a], 1 );
	  for( int j = 0; j < 2 * L; ++j )
	    {
	      if( p[a][j] )
	  	{
	  	  ans = addM( ans, p[a][j]);
	  	  int nxt = a + j - L;
	  	  if( nxt > 0 && nxt < L )
	  	    {
	  	      p[nxt][j] = addM( p[nxt][j], p[a][j]);
	  	    }
	  	}
	    }
	  for( int j = 1; j < L; ++j )
	      if( j < L && num[j] )
	  	{
	  	  ans = addM( ans, num[j] );
	  	  int nxt = 2 * a - j;
	  	  if( nxt > 0 && nxt < L )
	  	    p[nxt][ a - j + L ] = addM( p[nxt][ a - j + L ], num[j]);
	  	}
	  //}
	  num[a] = addM( 1, num[a]);
	  ans = addM( ans, 1);
	}
      ans = subM( all, addM( ans, 1 ) );
      printf("%d\n", ans);
    }
  return 0;
}
