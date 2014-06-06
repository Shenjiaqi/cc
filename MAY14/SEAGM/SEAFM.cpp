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
const int N = 107;
int p[N][3];
bool dp[N][N];
bool vis[N][N];
ld ex[N][N];
bool vi[N][N];
int gcd( int a, int b)
{
  if( a < b )
    swap( a, b);
  return b == 0 ? a : gcd( b, a % b );
}
bool opt( int left, int gcdV, int s)
{
  if( left == 0 )
    return false;
  if( !vis[left][gcdV] )
    {
      vis[left][gcdV] = true;
      dp[left][gcdV] = false;
      for( int i = s; !dp[left][gcdV];)
	{
	  int tmp = gcd( gcdV, p[i][0] );
	  if( tmp > 1 )
	    {
	      p[ p[i][1] ][2] = p[i][2];
	      p[ p[i][2] ][1] = p[i][1];
	      if( !opt( left - 1, tmp, p[i][2] ) )
		dp[left][gcdV] = true;
	      p[ p[i][1] ][2] = i;
	      p[ p[i][2] ][1] = i;
	    }
	  i = p[i][2];
	  if( i == s )
	    break;
	}
    }
  return dp[left][gcdV];
}
ld ran( int left, int gcdV, int s )
{
  if( left == 0 )
    return 0;
  if( !vi[left][gcdV] )
    {
      vi[left][gcdV] = true;
      ex[left][gcdV] = 0;
      for( int i = s; ; )
	{
	  int tmp = gcd( gcdV, p[i][0]);
	  if( tmp > 1 )
	    {
	      p[ p[i][2] ][1] = p[i][1];
	      p[ p[i][1] ][2] = p[i][2];
	      ex[left][gcdV] += 1.0 - ran( left - 1, tmp, p[i][2]);
	      p[ p[i][2] ][1] = i;
	      p[ p[i][1] ][2] = i;
	    }
	  i = p[i][2];
	  if( i == s )
	    break;
	}
      ex[left][gcdV] /= (ld)left;
    }
  return ex[left][gcdV];
}
int main()
{
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t)
    {
      int n;
      scanf("%d", &n);
      for( int i = 0; i < n; ++i )
	{
	  int a;
	  scanf("%d", &a);
	  p[i][0] = a;
	  p[i][1] = i - 1;
	  p[i][2] = i + 1;
	}
      p[0][1] = n - 1;
      p[n - 1][2] = 0;
      memset( vis, 0, sizeof(vis) );
      printf("%c ", opt( n, 0, 0) ? '1' : '0');
      memset( vi, 0, sizeof(vi) );
      printf("%.4lf\n", (double)ran( n, 0, 0 ) );
    }
  return 0;
}
