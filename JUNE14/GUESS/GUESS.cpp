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
ll gcd( ll a, ll b )
{
  return b == 0 ? a : gcd( b, a % b );
}
int main()
{
  ios::sync_with_stdio( false );
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int n, m;
      scanf("%d%d", &n, &m);
      ll a = (ll)( ( 1 + n ) / 2 ) * ( m / 2 ) + 
	(ll)( n / 2 ) * ( ( 1 + m ) / 2 );
      ll b = (ll)n * m;
      ll d = gcd( a, b );
      a /= d, b /= d;
      cout << a << '/' << b << endl;
    }
  return 0;
}
