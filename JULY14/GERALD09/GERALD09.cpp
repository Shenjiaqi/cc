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
const int N = 17;
const int M = 17;
char res[N][M];
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      if( t )
	printf("\n");
      int n, m, k;
      scanf("%d%d%d", &n, &m, &k);
      int sum(0), same(0);
      for( int i = 0 ; i < n ; ++i)
	for( int j = 0 ; j < m ; ++j )
	  {
	    int tmp = ( n - i ) * ( m - j );
	    sum += tmp;
	    same += ( tmp * ( tmp - 1 ) ) / 2;
	  }
      sum = ( sum * ( sum - 1 ) ) / 2;
      int diff = sum - same;
      memset( res, 0, sizeof(res));
      if( diff < k )
	{
	  
	}
    }
  return 0;
}
