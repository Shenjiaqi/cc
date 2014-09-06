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
#include <unordered_map>
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
const int zero = 1e9;
const int MOD = 1e9 + 9;
int addM( int a, int b)
{
  a += b;
  return a >= MOD ? a - MOD : a;
}
int subM( int a, int b)
{
  a -= b;
  return a < 0 ? a + MOD : a;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( ; T; --T )
    {
      int n;
      scanf("%d", &n);
      int sum = 1;
      unordered_map<int, int> mapp;
      for( int i = 0, pre = 0 ; i < n ; ++i )
	{
	  int v;
	  scanf("%d", &v);
	  if( i > 0 )
	    {
	      int d = v - pre;
	      int ad = subM(sum, mapp[d]);
	      mapp[d] = addM(mapp[d], ad);
	      sum = addM( sum, ad);
	    }
	  pre = v;
	}
      printf("%d\n", subM( sum, 1) );
    }
  return 0;
}
