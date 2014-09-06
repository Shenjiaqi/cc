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
#include <unordered_set>
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
int cnt[M];
int p[M];
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int n, m;
      scanf("%d%d", &n, &m);
      for( int i = 0 ; i < m ; ++i )
	{
	  scanf("%d", p + i );
	  ++cnt[ p[i] ];
	}
      int ans(0);
      unordered_set<int> st;
      for( int i = 0 ; i < m ; ++i )
	{
	  int v = p[i];
	  --cnt[v];
	  if( st.find(v) == st.end() )
	    {
	      ++ans;
	      if( cnt[v] > 0 )
		{
		  if( st.size() >= n )
		    st.erase(st.begin());
		  st.insert(v);
		}
	      else if( st.size() >= n )
		{
		  st.erase( st.begin() );
		}
	    }
	  else if( cnt[v] == 0 )
	    {
	      st.erase(v);
	    }
	  for( auto j : st )
	    cout << j << ' ' ;
	  cout << "   " << ans << ' ' << v << endl;
	}
      printf("%d\n", ans);
    }
  return 0;
}
