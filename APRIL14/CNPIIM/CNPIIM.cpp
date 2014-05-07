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
const int N = 2507;
const int M = ( N / 2 ) * ( N / 2 ) + 7;
int num[M];
int main()
{
  for( int i = 1; i < M; ++i )
    for( int j = i; j < M; j += i )
      ++num[j];
  // cout << num[2] << endl;
  num[1] = 1;
  for( int i = 2; i < M; ++i )
    num[i] += num[ i - 1 ];
  
  ios::sync_with_stdio(0);
  int T;
  scanf("%d", &T);
  for( int i = 0; i < T; ++i )
    {
      int n;
      scanf("%d", &n );
      ll ans(0);
      for( int i = 1; i <= n / 2; ++i )
	{
	  int j = n - i;
	  ll tmp = num[ i * j - 1 ];
	  ans += tmp;
	  if( i != j )
	    ans += tmp;
	}
      cout << ans << endl;
    }
  return 0;
}
