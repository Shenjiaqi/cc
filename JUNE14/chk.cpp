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
const int N = 100007;
const int MOD = 1e9 + 7;
int p[N];
int ans;
int main()
{
  int n;
  scanf("%d", &n);
  for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", p + i );
    }
  for( int i = 0 ; i < n ; ++i )
    for( int j = i + 1; j < n ; ++j )
      if( p[i] == p[j] )
	for( int a = 0 ; a < i ; ++a )
	  if( p[a] != p[i] )
	    for( int b = i + 1 ; b < j ; ++b )
	      if( p[a] == p[b] )
		{
		  cout << i << ' ' << j << ' ' << a << ' ' << b << endl;
		  ++ans;
		  if( ans >= MOD )
		    ans -= MOD;
		}
  printf("%d", ans);
  return 0;
}
