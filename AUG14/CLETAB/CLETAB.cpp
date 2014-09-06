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
bool in[M];
int q[M];
int main()
 {
  int T;
  scanf("%d", &T);
  for( ; T--; )
    {
      int n, m;
      scanf("%d%d", &n, &m);
      queue<int> p[M];
      for( int i = 0; i < m ; ++i)
	{
	  int v;
	  scanf("%d", &v);
	  in[v] = false;
	  q[i] = v;
	  p[v].push(i);
	}
      map<int, int, greater<int> > mapp;
      int ans(0);
      for( int i = 0 ; i < m ; ++i )
	{
	  int v = q[i];
	  p[v].pop();
	  if( !in[v] )
	    {
	      ++ans;
	      if( mapp.size() < n )
		{
		  if( !p[v].empty() )
		    {
		      mapp[ p[v].front() ] = v;
		      in[v] = true;
		    }
		}
	      else
		{
		  in[ mapp.begin()->second ] = false;
		  mapp.erase( mapp.begin() );
		  if( !p[v].empty() )
		    {
		      mapp[ p[v].front() ] = v;
		      in[v] = true;
		    }
		}
	    }
	  else
	    {
	      mapp.erase(i);
	      if( !p[v].empty() )
		{
		  mapp[ p[v].front() ] = v;
		}
	    }
	}
      printf("%d\n", ans);
    }
  return 0;
}
