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
const int N = 47;
const int C = 41;
struct e
{
  ll count;
  ll cost;
};
int main()
{
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t )
    {
      int n, m;
      scanf("%d%d", &n, &m);
      vector<pair<int,int> > p;
      p.resize(n);
      for( int i = 0; i < n; ++i )
	scanf("%d%d", &p[i].first, &p[i].second);
      sort( p.begin(), p.end() );
      e dp[N][N];
      e tmp[N][N];
      e tmp2[N][N];
      memset( dp, 0, sizeof(dp) );
      dp[0][0].count = 1, dp[0][0].cost = 0;
      for( int i = 0; i < n; )
	{
	  memset( tmp, 0, sizeof(tmp) );
	  for(int color = p[i].first; i < n && p[i].first == color; ++i )
	    {
	      memset( tmp2, 0, sizeof(tmp2) );
	      for( int num = 0; num <= i; ++num )
		for( int col = 0; col <= num; ++ col )
		  {
		    tmp2[num][col].cost += tmp[num][col].cost;
		    tmp2[num][col].count += tmp[num][col].count;
		    tmp2[num + 1][col].count += tmp[num][col].count;
		    tmp2[num + 1][col].cost += tmp[num][col].cost + 
		      tmp[num][col].count * p[i].second;

		    // tmp2[num][col].count += dp[num][col].count;
		    // tmp2[num][col].cost += dp[num][col].cost;
		    tmp2[num + 1][col + 1].count += dp[num][col].count;
		    tmp2[num + 1][col + 1].cost += dp[num][col].cost +
		      dp[num][col].count * p[i].second;
		    if( tmp2[num][col].count < 0 || tmp2[num + 1][col].count < 0 ||
			tmp2[num + 1][col + 1].count < 0 )
		      assert(0);
		  }
	      memcpy( tmp, tmp2, sizeof(tmp) );
	    }
	  // memcpy( dp, tmp, sizeof(dp) );
	  for( int num = 0; num <= i + 1; ++ num )
	    for( int col = 0; col <= num; ++col )
	      dp[num][col].cost += tmp[num][col].cost,
		dp[num][col].count += tmp[num][col].count;
	}
      ld countSum(0);
      for( int i = m; i <= n; ++i )
	for( int j = m; j <= i; ++j )
	  countSum += dp[i][j].count;
      ld costExp(0);
      for( int i = m; i <= n; ++i )
	for( int j = m ;j <= i; ++j )
	  costExp += ( (ld)dp[i][j].cost ) / countSum;
      printf("%.9lf\n", (double)costExp);
    }
  return 0;
}
