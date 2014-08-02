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
const int N = 1e4 + 7;
int fa[N][2];
int que(int v)
{
  return fa[v][0] == v ? v : fa[v][0] = que( fa[v][0] );
}
void join( int x, int y )
{
  x = que(x);
  y = que(y);
  if( x != y )
    {
      if( fa[x][1] > fa[y][1] )
	{
	  fa[y][0] = fa[x][0];
	}
      else if( fa[x][1] < fa[y][1] )
	{
	  fa[x][0] = fa[y][0];
	}
    }
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int n;
      scanf("%d", &n);
      for( int i = 1 ; i <= n ; ++i )
	{
	  int p;
	  scanf("%d", &p);
	  fa[i][0] = i;
	  fa[i][1] = p;
	}
      int q;
      scanf("%d", &q);
      for( int j = 0 ; j < q ; ++j )
	{
	  int type;
	  scanf("%d", &type );
	  if( type )
	    {
	      int x;
	      scanf("%d", &x);
	      printf("%d\n", que( x ) );
	    }
	  else
	    {
	      int x, y;
	      scanf("%d%d", &x, &y);
	      x = que(x);
	      y = que(y);
	      if( x == y )
		{
		  printf("Invalid query!\n");
		}
	      else
		{
		  join( x, y);
		}
	    }
	}
    }
  return 0;
}
