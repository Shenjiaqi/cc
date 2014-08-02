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
vector<ppi> p;
int fa[N];
int que(int v)
{
  return v == fa[v] ? v : ( fa[v] = que( fa[v] ) );
}
void join( int a, int b )
{
  a = que(a);
  b = que(b);
  if( a != b )
    fa[a] = b;
}
int main()
{
  int n, k, q;
  scanf("%d%d%d", &n, &k, &q);
  for( int i = 0 ; i < n ; ++i )
    {
      int pos;
      scanf("%d", &pos);
      p.push_back( ppi( pos, i) );
      fa[i] = i;
    }
  sort( p.begin(), p.end() );
  for( int i = 1 ; i < n ; ++i )
    {
      if( p[i].first - p[i - 1].first <= k )
	join( p[i].second, p[i - 1].second );
    }
  for( int i = 0 ; i < q; ++i )
    {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%s\n", ( que( a - 1 ) == que( b - 1 ) ) ? "Yes" : "No");
    }
  return 0;
}
