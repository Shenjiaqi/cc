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
const int N = 1e5 + 7;
int val[N];
int val2[N];
int n, r, p1, p2;
int addM( int a, int b, int m)
{
  return ( (ll)a + b) % m;
}
int subM( int a, int b, int m)
{
  a = ( (ll)a - b ) % m ;
  return a < 0 ? m + a : a;
}
int mulM( int a, int b, int m)
{
  return ( (ll)a * (ll)b ) % m;
}
int powM( int a, int b, int m)
{
  int r = 1;
  for( ; b; b >>= 1 )
    {
      if( b & 1 )
	r = mulM( r, a, m);
      a = mulM( a, a, m);
    }
  return r;
}
int rev( int a, int m)
{
  // m is a prime number
  return powM( a, m - 2, m);
}
void addAgp( int s, int d, int x, int y )
{
  int rr = 1, rr2 = 1;
  int s2 = s;
  for( int i = x; i <= y; ++i )
    {
      val[i] = addM( val[i], mulM( s, rr, p1), p1 );
      val2[i] = addM( val2[i], mulM( s2, rr2, p2), p2);
      s = addM( s, d, p1);
      rr = mulM( rr, r, p1);
      s2 = addM( s2, d, p2);
      rr2 = mulM( rr2, r, p2);
    }
}
void setVal( int x, int g)
{
  // if( x==12)
  // cout << "!" << (val[x] % p1) << ' ' << ( val2[x] % p2 ) << endl;
  val2[x] = powM( val2[x], g, p2);
  val[x] = val2[x] % p1;
  // if( x==12)
  // cout << "!" << (val[x] % p1) << ' ' << ( val2[x] % p2 ) << endl;
}
int getSum( int x, int y)
{
  int r = 0;
  for( int i = x; i <= y; ++i )
    r = addM( r, val[i], p1);
  return r;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t)
    {
      int q;
      scanf("%d%d%d%d%d", &n, &q, &r, &p1, &p2);
      for( int i = 1; i <= n; ++i )
	{
	  scanf("%d", val + i);
	  val2[i] = val[i];
	}
      for( int i = 0; i < q; ++i )
	{
	  int type;
	  scanf("%d", &type);
	  if( type == 0 )
	    {
	      int s, d, x, y;
	      scanf("%d%d%d%d", &s, &d, &x, &y);
	      addAgp( s, d, x, y);
	    }
	  else if( type == 1 )
	    {
	      int x, g;
	      scanf("%d%d", &x, &g);
	      setVal( x, g);
	    }
	  else if( type == 2 )
	    {
	      int x, y;
	      scanf("%d%d", &x, &y);
	      printf("%d\n", getSum( x, y) );
	    }
	}
    }
  return 0;
}
