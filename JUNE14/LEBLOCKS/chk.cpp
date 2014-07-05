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
const int N = 20;
const int L = 11;
int p[N][2];
int q[N * L];
ld ans;
int k;
bool choosed[N];
void dfs( int l, int n, int len )
{
  if( l == n )
    {
      int cnt(0);
      for( int i = 0 ; i + k < len ; ++i )
	if( q[i] == q[ i + k ] )
	  ++ans, ++cnt;
      for( int i = 0 ; i < len ; ++i )
	cout << q[i] ;
      cout << "  " << cnt;
      cout << endl;
    }
  else
    {
      for( int i = 0 ; i < n ; ++i )
	if( !choosed[i] )
	  {
	    choosed[i] = true;
	    for( int j = 0 ;  j < p[i][0] ; ++j, ++len )
	      q[len] = p[i][1];
	    dfs( l + 1, n, len );
	    len -= p[i][0];
	    choosed[i] = false;
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
      scanf("%d%d", &n, &k);
      for( int i = 0 ; i < n ; ++i )
	{
	  scanf("%d%d", &p[i][0], &p[i][1] );
	}
      ans = 0;
      dfs(0, n, 0);
      for( int i = 2; i <= n; ++i )
	ans /= i;
      printf("%.7Lf\n", ans);
    }
  return 0;
}
