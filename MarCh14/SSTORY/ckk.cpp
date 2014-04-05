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
const int N = 250000;
char s1[N], s2[N];
int main()
{
  scanf("%s%s", s1, s2);
  int l1 = strlen( s1 );
  int l2 = strlen( s2 );
  int pos, ans = 0;
  for( int f = 1, t = l2; f <= t; )
    {
      int mid = ( f + t ) >> 1;
      bool ok = false;
      for( int i = 0 ; !ok && i + mid <= l2; ++i )
	for( int j = 0; !ok && j + mid <= l1; ++j )
	  {
	    ok = true;
	    for( int k = 0 ; k < mid; ++k )
	      if( s2[i + k] != s1[ j + k ] )
		{
		  ok = false;
		  break;
		}
	    if( ok )
	      pos = i;
	  }
      if( ok )
	ans = mid, f = mid + 1;
      else t = mid - 1;
    }
  s2[ pos + ans ] = '\0';
  printf("%s\n%d\n", s2 + pos, ans );
  return 0;
}
