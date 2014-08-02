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
int p[N];
bool vis[N];
int v[N];
int dfs( int v)
{
  if( !vis[v] )
    {
      vis[v] = true;;
      return 1 + dfs( p[v] );
    }
  return 0;
}
vector<ppi> fact[N];
const ll mod = 1e9 + 7;
int mul( int a, int b )
{
  return ((ll)a * b ) % mod;
}
int main()
{
  for( int i = 2; i < N; ++i )
    if( fact[i].empty() )
      {
	for( int j = i; j < N; j += i )
	  {
	    int k = 1;
	    for( int t = j; ( t % i ) == 0; k *= i )
	      t /= i;
	    fact[j].push_back( ppi( k, i) );
	  }
      }
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int n;
      scanf("%d", &n);
      for( int i = 1; i <= n ; ++i )
	{
	  scanf("%d", p + i );
	}
      vector<int> val;
      int ans = 1;
      memset( vis, 0, sizeof(vis) );
      for( int i = 1; i <= n; ++i )
	v[i] = 1;
      for( int i = 1; i <= n; ++i )
	{
	  if( !vis[i] )
	    {
	      int cnt = dfs( i );
	      for( auto j : fact[cnt] )
		{
		  int val = j.second;
		  if( v[val] < j.first )
		    {
		      ans = mul( ans, j.first / v[val] );
		      v[val] = j.first;
		    }
		}
	    }
	}
      printf("%d\n", ans);
    }
  return 0;
}
