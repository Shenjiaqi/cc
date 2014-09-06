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
int dis[N];
bool in[N];
vector<int> p[N], q[N];
void add( vector<int> (&a)[N], int f, int t )
{
  a[f].push_back(t);
}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for( int i = 0 ; i < m ; ++i )
    {
      int f, t;
      scanf("%d%d", &f, &t);
      add( p, f, t);
      add( q, t, f);
    }
  for( int i = 1 ; i <= n ; ++i )
    dis[i] = n + 1;
  queue<int> que;
  dis[1] = 0;
  que.push(1);
  in[1] = true;
  for( ; !que.empty(); )
    {
      int v = que.front();
      in[v] = false;
      que.pop();
      for( auto i : p[v] )
	{
	  if( dis[v] < dis[i] )
	    {
	      dis[i] = dis[v];
	      if( !in[i] )
		{
		  in[i] = true;
		  que.push(i);
		}
	    }
	}
      for( auto i : q[v] )
	{
	  if( dis[v] + 1 < dis[i] )
	    {
	      dis[i] = dis[v] + 1;
	      if( !in[i] )
		{
		  in[i] = true;
		  que.push(i);
		}
	    }
	}
    }
  if( dis[n] == n + 1 )
    printf("-1");
  else printf("%d", dis[n] );
  return 0;
}
