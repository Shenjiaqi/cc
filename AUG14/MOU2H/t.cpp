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
const int N = 1e6 + 7;
const int H = 1e6 * 4 + 7;
const int MOD = 1e9 + 7;
int sum0[N];
int sum1[N];
int dsum0[N];
int dsum1[N];
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
  for( int t = 1 ; t <= T ; ++t )
    {
      int n;
      scanf("%d", &n);
      unordered_map<int,int> q[2], dq[2],
	p;
      for( int i = 0, pre = 0 ; i < n ; ++i )
	{
	  int v;
	  scanf("%d", &v);
	  if( i != 0 )
	    {
	      int d = v - pre;
	      int tqd0 = q[0][d], tqd1 = q[1][d];
	      // int tdqd0 = dq[d][0], tdqs1 = dq[d][1];
	      if( p.find(d) == p.end() )
		{
		  q[0][d] = addM( sum0[i - 1], 1);
		  q[1][d] = sum1[i - 1];
		}
	      else
		{
		  // q[d][0] = addM( subM( sum0[i - 1], tqd0), tqd0);
		  q[0][d] = subM( sum0[i - 1], sum0[ p[d] - 1] );
		  // q[d][1] = addM( subM( sum1[i - 1], sum1[ p[d] - 1 ] ),
		  // 		  tdqd1);
		  q[1][d] = addM( subM( sum1[i - 1], sum1[ p[d] - 1 ] ),
				  dq[0][d] );
		}
	      dq[0][d] = subM( q[0][d], tqd0);
	      // dqsubM( q[d][1], tqd1);
	      sum0[i] = addM( sum0[i - 1], subM( q[0][d], tqd0) );
	      sum1[i] = addM( sum1[i - 1], subM( q[1][d], tqd1) );
	      // dsum0[i] = addM( dsum0[i - 1], subM( dq[d][0], tdqd0) );
	      // dsum1[i] = addM( dsum1[i - 1], subM( dq[d][1], tdqd1) );
	      p[d] = i;
	    }
	  pre = v;
	}
    }
  return 0;
}
