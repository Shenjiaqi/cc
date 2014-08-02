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
ll cal( ll a, ll b )
{
  assert( a >= b );
  ll r(0);
  r += b * 2LL;
  a -= b;
  r += ( a / 2 ) * 4;
  return ( a & 1 ) ? r + 3: r;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int x, y;
      scanf("%d%d", &x, &y );
      x = abs(x);
      y = abs(y);
      ll ans;
      if( x == y )
	ans = x * 2LL;
      else if( x > y )
	{
	  ans = cal( x, y );
	}
      else
	{
	  ans = 1 + cal( y - 1, x );
	}
      printf("%lld\n", ans);
    }
  return 0;
}
