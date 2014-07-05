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
const int N = 1e5 + 7;
const int SN = 330;
const ll MOD = 1e9 + 7;
int p[N];
vector<int> q[SN];
int c[N][2], ci;
vector<int> lst[N];
int id[N];
int lastV[N];
void ad( int v )
{
  if( c[v][1] != ci )
    {
      c[v][1] = ci;
      c[v][0] = 1;
    }
  else
    ++c[v][0];
}
int que( int v )
{
  if( c[v][1] != ci )
    return 0;
  return c[v][0];
}
int addM( int a, int b )
{
  if( a >= MOD )
    a -= MOD;
  if( b >= MOD )
    b -= MOD;
  a += b;
  return a >= MOD ? a - MOD : a;
}
int main()
{
  int n;
  scanf("%d", &n);
  for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", p + i );
      lst[ p[i] ].push_back(i);
    }
  int cnt(0);
  for( int i = 0; i < n ; ++cnt )
    {
      ++ci;
      for( int j = i; j < n && j < i + SN; ++j )
	{
	  ad( p[j] );
	}
      int num(0);
      for( int j = 0 ; j < i ; ++j )
	{
	  int tmp = que( p[j] );
	  num = addM( num, tmp);
	  q[ci - 1].push_back( tmp ); 
	}
      i += SN;
    }
  int ans(0);
  ++ci;
  for( int i = 0 ; i < n ; ++i )
    {
      int v = p[i];
      ++id[v];
      if( id[v] < lst[v].size() )
	{
	  int t = lst[v][id[v]];
	  if( i > 0 )
	    {
	      int ff = ( SN - 1 + i ) / SN;
	      int tt = t / SN;
	      for( int j = ff ; j < tt ; ++j )
		{
		  lastV[v] = addM( lastV[v], q[j][ i - 1 ] );
		}
	      if( ff <= tt )
		for( int j = i + 1 ; j < t && j < ff * SN ; ++j )
		  {
		    lastV[v] = addM( lastV[v], que( p[j] ) );
		  }
	      for( int j = max( i + 1, tt * SN ); j < t ; ++j )
		lastV[v] = addM( lastV[v], que( p[j] ) );
	      ans = addM( ans, lastV[v] );
	      cout << i << ' ' << ans << endl;; 
	    }
	}
      ad( p[i] );
    }
  printf("%d", ans);
  return 0;
}
