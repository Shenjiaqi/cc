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
const int M = 21;
const int N = 20007;
bool canSel[1 << M];
bool collide[M][M];
vector<int> offer[M];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m );
  for( int i = 0 ; i < m ; ++i )
    {
      int k;
      scanf("%d", &k);
      for( int j = 0 ; j < k; ++j )
	{
	  int ai;
	  scanf("%d", &ai);
	  offer[i].push_back(ai);
	}
    }
  for( int i = 0 ; i < m ; ++i )
    for( int j = i + 1; j < m; ++j )
      for( int a1 = 0, a2 = 0; a1 < offer[i].size() && a2 < offer[j].size();
	   )
	if( offer[i][a1] == offer[j][a2] )
	  {
	    collide[i][j] = collide[j][i] = true;
	    break;
	  }
	else if( offer[i][a1] < offer[j][a2] )
	  ++a1;
	else ++a2;
  canSel[0] = true;
  int ans = 0;
  for( int i = 1 ; i < 1 << m; ++i )
    {
      int newOne = __builtin_ctz(i);
      int rest = i ^ ( 1 << newOne );
      if( canSel[rest] )
	{
	  if( rest == 0 )
	    canSel[i] = true;
	  else
	    {
	      int lastOne = __builtin_ctz(rest);
	      int rRest = rest ^ ( 1 << lastOne );
	      if( canSel[rRest | ( 1 << newOne )] && 
		  !collide[newOne][lastOne] )
		canSel[i] = true;
	    }
	}
      if( canSel[i] )
	ans = max( ans, __builtin_popcount(i) );
    }
  cout << ans;
  return 0;
}
