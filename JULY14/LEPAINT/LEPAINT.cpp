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
const int C = 107;
const int K = 57;
const int N = 57;
ld p[C], tmp[C];
ld q[K];
ld z[K][K];
int main()
{
  z[0][0] = 1;
  for( int i = 1; i < K; ++i )
    for( int j = 0 ; j <= i; ++j )
      {
	z[i][j] = ( ( j > 0 ? z[i - 1][ j - 1] : 0 ) + z[i - 1][j] ) / 2.0;
      }
  int T;
  scanf("%d", &T);
  for(int t = 0 ; t < T ; ++t )
    {
      int n, c, k;
      scanf("%d%d%d", &n, &c, &k);
      memset( q, 0, sizeof(q) );
      memset( p, 0, sizeof(p) );
      p[1] = 1;
      for( int i = 0; i <= k; ++i )
	{
	  for( int j = 0 ; j < c ; ++j )
	    {
	      q[i] += p[j] * j;
	    }
	  memset( tmp, 0, sizeof(tmp) );
	  for( int j = 0 ; j < c ; ++j )
	    {
	      for( int k = 0 ; k < c; ++k )
		{
		  tmp[ ( j * k ) % c ] += p[j] / (ld)c;
		}
	    }
	  memcpy( p, tmp, sizeof(p) );
	}
      int cnt[N] = {0};
      for( int i = 0 ; i < k ; ++i )
	{
	  int l, r;
	  scanf("%d%d", &l, &r);
	  for( int j = l ; j <= r; ++j )
	    ++cnt[j];
	}
      ld ans(0);
      for( int i = 1 ; i <= n; ++i )
	{
	  for( int j = 0; j <= cnt[i]; ++j )
	    ans += z[ cnt[i] ][j] * q[j];
	}
      printf("%.6lf\n", (double)ans);
    }
  return 0;
}
