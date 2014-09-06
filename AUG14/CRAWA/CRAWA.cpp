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
int main()
{
  int T;
  scanf("%d", &T);
  for( int i = 0 ; i < T ; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y);
      bool ok = false;
      if( x == 0 )
	{
	  if( 0 == ( y & 1 ) )
	    ok = true;
	}
      else if( y == 0 )
	{
	  if( x > 0 )
	    {
	      if( x & 1 )
		ok = true;
	    }
	  else if( 0 == ( x & 1 ) )
	    ok = true;
	}
      else if ( x > 0 && y > 0 )
	{
	  if( x & 1 )
	    {
	      if( y <= x + 1 )
		ok = true;
	    }
	  if( 0 == ( y & 1 ) )
	    {
	      if( x < y )
		ok = true;
	    }
	}
      else if( x < 0 && y > 0 )
	{
	  if( 0 == ( x & 1 ) )
	    {
	      if( y <= abs(x) )
		ok = true;
	    }
	  if( 0 == ( y & 1 ) )
	    {
	      if( abs(x) <= y )
		ok = true;
	    }
	}
      else if( x < 0 && y < 0 )
	{
	  if( 0 == ( x & 1 ) )
	    {
	      if( abs(y) <= abs(x) )
		ok = true;
	    }
	  if( 0 == ( y & 1 ) )
	    {
	      if( abs(x) < abs(y) )
		ok = true;
	    }
	}
      else
	{
	  if( x & 1 )
	    {
	      if( abs(y) < x )
		ok = true;
	    }
	  if( 0 == ( y & 1 ) )
	    {
	      if( x <= 1 - y )
		ok = true;
	    }
	}
      printf("%s\n", ( ok ? "YES" : "NO" ) );
    }
  return 0;
}
