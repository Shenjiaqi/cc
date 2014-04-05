#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <tuple>
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
int gcd( int a, int b)
{
  return b == 0 ? a : gcd( b, a % b ) ;
}
int a[N];
int main()
{
  int n, m;
  cin >> n >> m;
  for( int i = 1;  i <= n ; ++i )
    cin >> a[i];
  for( int i = 0 ; i < m ; ++i )
    {
      int g, x, y;
      cin >> g >> x >> y;
      int ansV = -1, ansNum = -1;
      for( int j = x; j <= y ; ++j )
	if( gcd( g, a[j] ) > 1 )
	  {
	    if( a[j] > ansV )
	      ansV = a[j], ansNum = 1;
	    else if( a[j] == ansV )
	      ++ansNum;
	  }
      cout << ansV << ' ' << ansNum ;
      // if( i == 69 )
      // 	cout << ' ' << gcd( g, ansV ) ;
      // else
	cout << endl;
    }
  return 0;
}
