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
bool pri[10000];
int main()
{
  set<int> sett;
  for( int i = 2; i < 10000; ++i )
    if( !pri[i] )
      {
	sett.insert(i);
	if( i > 2007 )
	  break;
	for( int j = i + i; j < 10000; j += i )
	  pri[j] = true;
      }
  int T;
  scanf("%d", &T);
  for( int i = 0; i < T; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y );
      int z = *sett.upper_bound( x + y ) - x - y;
      printf("%d\n", z);
    }
  return 0;
}
