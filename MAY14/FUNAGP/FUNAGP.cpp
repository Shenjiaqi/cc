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
const int Q = 1e5 + 7;
struct e
{
  int s, d;
  int s2, d2;
  int v;
  // int tag, tagi;
};
e p[N * 4];
int n, r, p1, p2;
int val[N];
int por[N][2];
int revr[2];
int rev2[2];
inline int addM( int a, int b, int m)
{
  return ( (ll)a + b) % m;
}
inline int subM( int a, int b, int m)
{
  a = ( (ll)a - b ) % m ;
  return a < 0 ? m + a : a;
}
inline int mulM( int a, int b, int m)
{
  return ( (ll)a * (ll)b ) % m;
}
inline int powM( int a, int b, int m)
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
inline int rev( int a, int m)
{
  // m is a prime number
  // assert(a > 0 && ( a % m ) );
  return powM( a, m - 2, m);
}
int dfsInit( int id, int from, int to)
{
  p[id].s = p[id].d = 0;
  p[id].s2 = p[id].s = 0;
  p[id].d2 = p[id].d = 0;
  if( from == to )
    {
      // p[id].v = addM( val[from], 0, p1);
      p[id].v = val[from];
    }
  else
    {
      int mid = ( (ll)from + to ) / 2;
      p[id].v = addM( dfsInit( id * 2, from, mid ),
  		      dfsInit( id * 2 + 1, mid + 1, to), p1 );
    }
  return p[id].v;
}
void init( int n )
{
  // ++tagi;
  dfsInit( 1, 1, n);
}
int cal( int s, int d, int num, int m )
{
  // assert( num >= 0 );
  if( num == 0 )
    return 0;

  if( ( r % m ) != 1 )
    {
      // cout << "!" << r - 1 << ' ' << m << ' ' << ( r - 1 ) % m << endl;
      // int rr = rev( r - 1, m );
      int rr = revr[ m == p1 ? 0 : 1];
      // assert( m == p1 || m == p2);
      int r_a_1 = m == p1 ? por[num - 1][0] : por[num - 1][1];
      // = powM( r, num - 1, m );
      int r_a = mulM( r_a_1, r, m);
      int tmp1 = mulM( s, subM( r_a, 1, m), m );
      int tmp2 = mulM( subM( num, 1, m), 
		      r_a, m);
      int tmp3 = mulM( mulM( r, subM( 1, r_a_1, m ), m ), rr, m);
      tmp2 = mulM( d, addM( tmp2, tmp3, m), m);
      tmp1 = mulM( addM( tmp1, tmp2, m), rr, m);
      return tmp1;
    }
  int tmp1 = mulM( s, num, m);
  int tmp2;
  if( m > 2 )
    {
      tmp2 = mulM( mulM( subM( num, 1, m ), d, m), num, m);
      tmp2 = mulM( tmp2, rev2[ m == p1 ? 0 : 1], m );
      // cout << endl << '$' << tmp1 << ' ' << tmp2 << '$' << endl;
    }
  else
    {
      ll ttt = num;
      ttt *= num - 1;
      ttt /= 2;
      tmp2 = mulM( ttt % 2, d, 2);
    }
  return addM( tmp1, tmp2, m);
}
int dfsAddAgp( int id, int from, int to, int s, int d, int s2, int d2,
		int x, int y)
{
  if( to < x || from > y )
    return 0;
  if( from <= x && y <= to )
    {
      int num = x - from;
      int ttmp, ttmp2; //powM( r, num, p1);
      ttmp = por[num][0], ttmp2 = por[num][1];
      int tmp = mulM( addM( s, mulM( num, d, p1), p1), 
		     ttmp, p1 );
      p[id].s = addM( tmp, p[id].s, p1 );
      int nd = mulM( d, ttmp, p1);
      p[id].d = addM( p[id].d, nd, p1);
      
      // ttmp = powM( r, num, p2);
      int tmp2 = mulM( addM( s2, mulM( num, d2, p2), p2),
      		  ttmp2, p2);
      p[id].s2 = addM( tmp2, p[id].s2, p2);
      p[id].d2 = addM( p[id].d2, mulM( d2, ttmp2, p2 ), p2);

      // tmp =  subM( cal( s, d, y - from + 1, p1),
      // 		   cal( s, d, x - 1 - from + 1, p1), p1);
      // return tmp;
      return cal( tmp, nd, y - x + 1, p1);
    }
  // x < y
  int mid = ( (ll)x + y ) / 2;
  int tmp = addM( dfsAddAgp( id * 2, from, to, s, d, s2, d2,
			     x, mid ),
		  dfsAddAgp( id * 2 + 1, from, to, s, d, s2, d2,
			     mid + 1, y), p1 );
  p[id].v = addM( tmp, p[id].v, p1);
  return tmp;
}
void addAgp( int s, int d, int from, int to )
{
  dfsAddAgp( 1, from, to, s % p1, d % p1, s % p2, d % p2,
	     1, n);
}

int dfsGetSum( int id, int from, int to, int x, int y)
{
  if( y < from || to < x )
    return 0;
  if( p[id].s || p[id].d || p[id].s2 || p[id].d2 )
    {
      if( x < y )
	{
	  int mid = ( x + y ) / 2;
	  int tmp = addM( dfsAddAgp( id * 2, x, y, p[id].s, p[id].d, 
				     p[id].s2, p[id].d2,
				     x, mid),
			  dfsAddAgp( id * 2 + 1, x, y, p[id].s, p[id].d, 
				     p[id].s2, p[id].d2,
				     mid + 1, y), p1);
	  // assert( tmp == cal( p[id].s, p[id].d, y - x + 1, p1) );
	  p[id].v = addM( p[id].v, tmp, p1);
	}
      else // x == y
	{
	  p[id].v = addM( p[id].v, cal( p[id].s, p[id].d, y - x + 1, p1), p1 );
	  val[x] = addM( val[x], cal( p[id].s2, p[id].d2, y - x + 1, p2), p2 );
	}
      p[id].s = p[id].d = 0;
      p[id].s2 = p[id].d2 = 0;
    }
  if( from <= x && y <= to )
    {
      return p[id].v;
    }
  int mid = ( x + y ) / 2;
  return addM( dfsGetSum( id * 2, from, to, x, mid ),
	       dfsGetSum( id * 2 + 1, from, to, mid + 1, y), p1 );
}
int getSum( int from, int to)
{
  return dfsGetSum( 1, from, to, 1, n);
}
int dfsSetVal( int id, int pos, int g, int x, int y)
{
  if( p[id].s || p[id].d || p[id].s2 || p[id].d2 )
    {
      if( x < y )
	{
	  int mid = ( x + y ) / 2;
	  int tmp = addM( dfsAddAgp( id * 2, x, y, p[id].s, p[id].d, 
				     p[id].s2, p[id].d2,
					   x, mid),
			  dfsAddAgp( id * 2 + 1, x, y, p[id].s, p[id].d, 
					   p[id].s2, p[id].d2,
					   mid + 1, y ), p1);
	  p[id].v = addM( p[id].v, tmp, p1);
	}
      else // x == y == pos 
	{
	  p[id].v = addM( p[id].v, cal( p[id].s, p[id].d, y - x + 1, p1 ), p1 );
	  val[x] = addM( val[x], cal( p[id].s2, p[id].d2, y - x + 1, p2), p2 );
	}
      p[id].s = p[id].d = 0;
      p[id].s2 = p[id].d2 = 0;
    }
  int det = 0;
  if( x < y )
    {
      int mid = ( x + y ) / 2;
      if( pos <= mid )
	det = dfsSetVal( id * 2, pos, g, x, mid );
      else
	det = dfsSetVal( id * 2 + 1, pos, g, mid + 1, y );
    }
  else // x == y == pos
    {
      val[x] =  powM( val[x], g, p2);
      det = subM( val[x], p[id].v, p1);
    }
  p[id].v = addM( p[id].v, det, p1);
  return det;
}
void setVal( int x, int g)
{
  dfsSetVal( 1, x, g, 1, n);
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
	scanf("%d", val + i);
      init(n);
      por[0][0] = por[0][1] = 1;
      for( int i = 1; i <= n; ++i )
	{
	  por[i][0] = mulM( por[i - 1][0], r, p1);
	  por[i][1] = mulM( por[i - 1][1], r, p2);
	}
      revr[0] = rev( r - 1, p1 );
      revr[1] = rev( r - 1, p2 );
      rev2[0] = rev( 2, p1 );
      rev2[1] = rev( 2, p2 );
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
  // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
