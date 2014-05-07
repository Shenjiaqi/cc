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
int main()
{
  int T;
  scanf("%d", &T);
  for( int i = 0; i < T; ++i )
    {
      int n;
      int d[2];
      scanf("%d%d%d", &n, &d[0], &d[1]);
      vector<ppi> e[2];
      for( int j = 0; j < 2; ++j )
	for( int k = 0; k < d[j]; ++k )
	  {
	    int f, t;
	    scanf("%d%d", &f, &t);
	    e[j].push_back( ppi( f, t) );
	  }
      int j = 0;
      for( ; j < d[0]; ++j )
	{
	  int l = e[0][j].first, r = e[0][j].second;
	  int k = 0;
	  for( ; k < d[1]; ++k )
	    {
	      int a = e[1][k].first, b = e[1][k].second;
	      if( b < a )
		{
		  if( r < l )
		    {
		      if( l >= a && r <= b )
			break;
		    }
		  else if( max( l, r ) <= b ||
			   min( l, r ) >= a )
		    break;
		}
	      else if( r >= l )
		{
		  if( l >= a && r <= b )
		    break;
		}
	    }
	  if( k >= d[1] )
	    break;
	}
      printf("%s\n", j >= d[0] ? "Yes" : "No");
    }
  return 0;
}
