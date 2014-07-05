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
const int N = 100007;
char s[N];
int d[N];
int dis[200];
vector<int> pos[200];
bool in[N];
int main()
{
  memset(dis, 1 << 6, sizeof(dis) );
  memset( d, 1 << 6, sizeof(d) );
  scanf("%s", s);
  int n = strlen(s);
  for( int i = 0 ; s[i]; ++i )
    pos[s[i]].push_back(i);
  queue<int> q;
  q.push( 0 );
  d[0] = 0;
  in[0] = true;
  for( ; !q.empty(); )
    {
      int v = q.front();
      q.pop();
      in[v] = false;
      int dd = d[v];
      if( v > 0 && d[v - 1] > dd + 1 )
	{
	  d[v - 1] = dd + 1;
	  if( !in[v - 1] )
	    {
	      q.push(v - 1 );
	      in[ v - 1 ] = true;
	    }
	}
      if( v < n - 1 && d[v + 1] > dd + 1 )
	{
	  d[v + 1] = dd + 1;
	  if( !in[v + 1] )
	    {
	      q.push( v + 1 );
	      in[ v + 1 ] = true;
	    }
	}
      if( dis[ s[v] ] > dd + 1 )
	{
	  dis[ s[v] ] = dd + 1;
	  for( auto j : pos[ s[v] ] )
	    {
	      if( d[j] > dd + 1 )
		{
		  d[j] = dd + 1;
		  if( !in[j] )
		    {
		      in[j] = true;
		      q.push(j);
		    }
		}
	    }
	}
    }
  printf("%d", d[n - 1] );
  return 0;
}
