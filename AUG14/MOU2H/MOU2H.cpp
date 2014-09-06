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
#include <unordered_map>
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
const int N = 1e6 + 7;
const int H = 1e6 * 4 + 7;
const int MOD = 1e9 + 7;
int c[N], d[N], e[N], s[N][2], si;
int addM( int a, int b)
{
  a += b;
  return a >= MOD ? a - MOD : a;
}
int subM( int a, int b)
{
  a -= b;
  return a < 0 ? a + MOD : a;
}
void add( int val, int pos)
{
  for( ; pos < N ; pos += ( pos & ( -pos) ) )
    {
      if( s[pos][1] != si )
	{
	  s[pos][1] = si;
	  s[pos][0] = 0;
	}
      s[pos][0] = addM( s[pos][0], val);
    }
}
int que(int pos)
{
  int r(0);
  for( ; pos; pos ^= ( pos & ( -pos ) ) )
    {
      if( s[pos][1] != si )
	{
	  s[pos][1] = si;
	  s[pos][0] = 0;
	}
      r = addM( r, s[pos][0] );
    }
  return r;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 1 ; t <= T ; ++t )
    {
      int n;
      scanf("%d", &n);
      vector<int> de;
      map<int,int> mapp;
      for( int i = 0, pre = 0 ; i < n ; ++i )
	{
	  int v;
	  scanf("%d", &v);
	  if( i > 0 )
	    {
	      int val = v - pre;
	      mapp[val] = 0;
	      de.push_back(val);
	    }
	  pre = v;
	}
      int cnt(0);
      for( auto & i : mapp )
	i.second = ++cnt;
      // for( auto & i : de )
      // 	i = mapp[i];
      unordered_map<int,int> p, q;
      int ans0(0), ans1(0);
      si = t;
      for( int i = 1 ; i <= de.size() ; ++i )
	{
	  int v = mapp[ de[i - 1] ];
	  int ci, di, ei;
	  if( p.find(v) == p.end() )
	    {
	      ci = addM( ans0, 1);
	      di = 0;
	      ei = ans1;
	      add( ci, i );
	      q[v] = ci;
	    }
	  else
	    {
	      if( q.find(v) != q.end() )
		{
		  add( -q[v], p[v] );
		  q.erase(v);
		}
	      // ci = subM( c[i - 1], c[ p[v] - 1 ] );
	      ci = subM( c[i - 1], d[i - 1]);
	      // ci = subM( ci, s[ p[v] - 1 ] );
	      ci = subM( ci, que( p[v] ) );
	      // cout << i << ' ' << ci << ' ' << que( p[v] ) << endl;
	      di = subM( c[ p[v] ], c[ p[v] - 1 ] );
	      cout << di << endl;
	      ei = subM( d[i - 1], d[ p[v] ] );
	      // ei = addM( ei, subM( f[ i - 1 ], f[ p[v] ] ) );
	      ei = addM( ei, subM( e[i - 1], e[ p[v] ] ) );
			 // subM( e[i - 1], e[ p[v] ] ) );
	    }
	  // cout << ci << ' ' << di << ' ' << ei << endl;
	  p[v] = i;
	  c[i] = addM( ci, c[i - 1]);
	  d[i] = addM( di, d[i - 1]);
	  e[i] = addM( ei, e[i - 1]);
	  ans0 = addM( ans0, subM( ci, di) );
	  // ans1 = e[i] = addM( ans1, addM( di, ei ) );
	  ans1 = addM( ans1, addM( di, ei) );
	  cout << ans0 << ' ' << ans1 << ' ' << ei << endl;
	}
      printf("%d\n", addM( ans0, ans1) );
    }
  return 0;
}
