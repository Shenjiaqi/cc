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
const int N = 1e5 + 7;
vector<int> p[N];
int main()
{
  ios::sync_with_stdio(false);
  int n, m, np;
  scanf("%d%d%d", &n, &m, &np);
  for( int i = 0; i < np; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y);
      p[x].push_back(y);
    }
  for( int i = 1; i <= n; ++i )
    {
      sort( p[i].begin(), p[i].end() );
      int preAdd = 0, preIdx = 0;
      int begVal = 1;
      for( int j = 0; j < p[i].size(); )
	{
	  int idx = p[i][j];
	  int cnt(0);
	  for( ; j < p[i].size() && p[i][j] == idx; ++j )
	    ++cnt;
	  if( idx == 1 )
	    begVal += cnt;
	  if( ( preIdx < idx - 1 && preAdd > 1 ) ||
	      ( preIdx == idx - 1 && preAdd > cnt + 1 ) )
	    break;
	  else
	    preAdd = cnt, preIdx = idx;
	}
      int ans(-1);
      if( preAdd <= 1 || preIdx == m )
	{
	  ans = m - begVal;
	  if( preIdx == m )
	    ans += preAdd;
	}
      printf("%d\n", ans);
    }
  return 0;
}
