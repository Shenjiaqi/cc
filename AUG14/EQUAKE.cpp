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
const int N = 8e5 + 7;
const int L = 12;
const int MM = 4;
struct
{
  int q[L];
  int idx;
}p[N * 4];
int v[N][2];
int po[17];
void init( int l, int r, int idx )
{
  if( l == r )
    {
      int tmp[MM];
      tmp[0] = v[l][0];
      for( int i = v[l][1] - 1, j = 0; i > 0; --i )
	{
	  tmp[i] = ( tmp[j] / 10 ) + ( tmp[j] % 10 ) * po[ v[l][1] - 1 ];
	  --j;
	  if( j < 0 )
	    j = v[l][1] - 1;
	}
      for( int i = 0, j = 0; i < L; ++i )
	{
	  p[idx].q[i] = tmp[j];
	  ++j;
	  if( j >= v[l][1] )
	    j = 0;
	}
    }
  else
    {
      int mid = ( l + r ) >> 1;
      int a = idx << 1;
      int b = a + 1;
      init( l, mid, a);
      init( mid + 1, r, b);
      int *q1 = p[a].q, *q2 = p[b].q;
      for( int i = 0 ; i < L ; ++i )
	{
	  p[idx].q[i] = max( q1[i], q2[i] );
	}
    }
}
int que( const int& f,const int& l,int rc,
	 int idx, int from, int to, int rot = 0)
{
  p[idx].idx += rot;
  if( p[idx].idx >= L )
    p[idx].idx -= L;
  if( l < from || f > to )
    {
      return 0;
    }
  if( f <= from && to <= l )
    {
      p[idx].idx += rc;
      if( p[idx].idx >= L )
	p[idx].idx -= L;
      // if( f == 1 && l == 3 && idx == 1 )
      // 	cout << rc << ' ' << p[idx].q[ p[idx].idx ] << endl;
      return p[idx].q[ p[idx].idx ];
    }
  else
    {
      int mid = ( from + to ) >> 1;
      int a = idx << 1;
      int b = a + 1;
      int aa, bb;
      int r = max( aa = que( f, l, rc, a, from, mid, p[idx].idx),
		   bb = que( f, l, rc, b, mid + 1, to, p[idx].idx) );
      int *q1 = p[a].q, *q2 = p[b].q;
      for( int i = 0, j = p[a].idx, k = p[b].idx ;
	   i < L ; ++i )
	{
	  p[idx].q[i] = max( q1[j], q2[k] );
	  ++j, ++k;
	  if( j == L )
	    j = 0;
	  if( k == L )
	    k = 0;
	}
      p[idx].idx = 0;
      return r;
    }
  return 0;
}
int main()
{
  int n;
  scanf("%d", &n);
  for( int i = 1 ; i <= n ; ++i )
    {
      scanf("%d", &v[i][0]);
      for( int j = v[i][0] ; j; j /= 10 )
	++v[i][1];
    }
  po[0] = 1;
  for( int i = 1 ; i < 10 ; ++i )
    po[i] = po[i - 1] * 10;
  init( 1, n, 1);
  int m;
  scanf("%d", &m);
  for( int i = 0 ; i < m ; ++i )
    {
      int t, l, r, f;
      scanf("%d%d%d", &t, &l, &r);
      ++l, ++r;
      if( t == 0 )
	{
	  scanf("%d", &f);
	  f %= L;
	  que( l, r, f, 1, 1, n);
	}
      else
	printf("%d\n", que( l, r, 0, 1, 1, n) );
    }
  return 0;
}
