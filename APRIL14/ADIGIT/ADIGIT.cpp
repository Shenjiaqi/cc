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
char s[N];
int p[N][10];
int main()
{
  int n, m;
  scanf("%d%d%s", &n, &m, s);
  for( int i = 1; i <= n; ++i )
    {
      for( int j = 0; j < 10; ++j )
	p[i][j] = p[i - 1][j];
      ++p[i][ s[i - 1] - '0' ];
    }
  for( int i = 0; i < m; ++i )
    {
      int x;
      scanf("%d", &x);
      int ans(0);
      for( int j = 0; j < 10; ++j )
	ans += abs( s[x - 1] - '0' - j ) * p[ x - 1 ][j];
      printf("%d\n", ans);
    }
  return 0;
}
