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
const int M = 1e6;
int s[M];
int tag[M];
int main()
{
  int T;
  scanf("%d", &T);
  for( ; T; --T)
    {
      int n, a, b, c, d;
      scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
      for( int i = 0 ; i < n; ++i )
	{
	  if( tag[d] == T )
	    ++s[d];
	  else
	    tag[d] = T, s[d] = 1;
	  d = (ll)a * ( ( (ll)d * (ll)d ) % M )  + (ll)b * (ll)d + c;
	  d %= M;
	}
      ll ans(0);
      int ansi(0);
      for( int i = M - 1; i > 0; --i )
	if( tag[i] == T && s[i] > 0 && ( s[i] & 1 ) )
	  {
	    if( ansi )
	      ans -= i;
	    else ans += i;
	    ansi ^= 1;
	  }
      cout << llabs(ans) << endl;
    }
  return 0;
}
