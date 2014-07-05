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
const int N = 20;
int p[N][2];
int q[ 1 << N ];
ld po[N + 7];
int main()
{
  po[0] = 1;
  for( int i = 1; i < N + 7; ++i )
    po[i] = po[ i - 1 ] * (ll)i;
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int n, k;
      scanf("%d%d", &n, &k);
      for( int i = 0 ; i < n ; ++i )
	{
	  scanf("%d%d", &p[i][0], &p[i][1] );
	}
      q[0] = 0;
      for( int i = 1 ; i < ( 1 << n ) ; ++i )
	{
	  int t = __builtin_ctz(i);
	  q[i] = q[ i ^ ( 1 << t ) ] + p[t][0];
	}
      ld ans(0);
      for( int i = 0 ; i < n ; ++i )
	{
	  for( int j = i + 1 ; j < n ; ++j )
	    {
	      if( p[i][1] == p[j][1] )
		{
		  int msk = ( ( 1 << ( n ) ) - 1 ) ^ ( 1 << i ) ^ ( 1 << j );
		  for( int l = ( ( 1 << ( n ) ) - 1 ) & msk; ; )
		    {
		      int len = q[l];
		      // cout << l << ' ' << len << "!" << endl;
		      if( len < k && p[i][0] + p[j][0] + len > k )
			{
			  ld tmp = min( p[i][0] + p[j][0] + len - k, p[i][0]) - 
			    max( p[i][0] + len + 1 - k, 1) + 1;
			  // cout << tmp << ' ' << len << endl;
			  // for( int i = 0 ; i < n ; ++i )
			  // 	if( ( 1 << i ) & l )
			  // 	  cout << i + 1 << ' ';cout << endl;
			  int t = __builtin_popcount(l);
			  tmp *= po[ n - 2 - t ] * (ld)( n - 2 - t + 1 );
			  tmp *= po[t];
			  // cout << tmp << ' ' << ( po[ n - 2 - t ] * ( n - 2 - t + 1 ) ) <<
			  // 	' ' << po[t] << ' ' << t << endl;
			  ans += tmp;
			}
		      if( l == 0 )
			break;
		      l = ( l - 1 ) & msk;
		    }
		}
	    }
	}
      ans *= (ld)2.0 / po[n];
      for( int i = 0 ; i < n ; ++i )
	ans += max( 0, p[i][0] - k );
      printf("%.7Lf\n", ans);
    }
  return 0;
}
