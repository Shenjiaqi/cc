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
int p[N];
int main()
{
  ios::sync_with_stdio(false);
  int n, k;
  scanf("%d%d", &n, &k);
  int maxV = -2e9 - 7, minV = 2e9 + 7;
  for( int i = 0; i < n; ++i )
    {
      scanf("%d", p + i);
      maxV = max( maxV, p[i]);
      minV = min( minV, p[i]);
    }
  for( int i = 0; i < n; ++i )
    {
      ll tmp = p[i];
      if( k & 1 )
  	tmp = (ll)maxV - tmp;
      else if( k > 0 )
	tmp -= (ll)minV;
      cout << tmp << ' ';
    }
  return 0;
}
