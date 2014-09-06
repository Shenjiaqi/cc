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
const int M = 407;
int p[M];
bool in[M];
queue<int> q[M];
int main()
{
  int T;
  scanf("%d", &T);
  for( ; T-- ; )
    {
      int n, m;
      scanf("%d%d", &n, &m);
      for( int i = 0 ; i < m ; ++i )
	{
	  scanf("%d", p + i );
	  q[ p[i] ].push(i);
	}
      map<int, int, greater<int> > mapp;
      memset( in, 0, sizeof(in) );
      int ans(0), cnt(0);
      for( int i = 0 ; i < m ; ++i )
	{
	  int v = p[i];
	  q[v].pop();
	  if( !in[v] )
	    {
	      ++ans;
	      if( cnt < n )
		{
		  if( !q[v].empty() )
		    {
		      in[v] = true;
		      ++cnt;
		    }
		}
	      else
		{
		  int rpV = -1, rpI = 0;
		  for( int j = 1 ; j < M ; ++j )
		    if( in[j] && ( q[j].empty() || q[j].front() > rpV ) )
		      {
			rpV = q[j].empty() ? m + 1 : q[j].front();
			rpI = j;
		      }
		  in[rpI] = false;
		  --cnt;
		  if( !q[v].empty() )
		    {
		      ++cnt;
		      in[v] = true;
		    }
		}
	    }
	  else if( q[v].empty() )
	    {
	      in[v] = false;
	    }
	}
      printf("%d\n", ans);
    }
  return 0;
}
