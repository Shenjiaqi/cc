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
const int MM = 1e6 + 7;
const int TRA = 70;
const int MX = 19;
ll n[MM];
int m[MM];
int idx[MM];
int ans[MM];
bool cmp( int a, int b)
{
  if( m[a] == m[b] )
    {
      if( n[a] == n[b] )
	return a < b;
      return n[a] < n[b];
    }
  return m[a] < m[b];
}
void cp( int to[MX][MX], int from[MX][MX] )
{
  memcpy( to, from, sizeof(int) * MX *MX );
}
void mul( int to[MX][MX], int a[MX][MX], int mod )
{
  static tmp[MX][MX];
  memset( tmp, 0, sizeof(tmp) );
  for( int i = 0 ; i < MX ; ++i )
    for( int j = 0 ; j < MX ; ++j )
      for( int k = 0 ; k < MX ; ++k )
	tmp[i][j] = addM( tmp[i][j], mulM( to[i][k], a[k][j], mod), mod);
  cp( to, tmp);
}

int tra[TRA][MX][MX};
void get( int mx[MX][MX], int num, int mod )
{
  cp( mx, tra[0]);
  for( int i = 1 ; num; num >>= 1, ++i )
    if( num & 1 )
      mul( mx, tra[num]);
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int i = 0 ; i < T ; ++i )
    {
      scanf("%I64d%d", n + i, m + i);
      idx[i] = i;
    }
  sort( idx, idx + T, cmp );
  for( int i = 0 ; i < T ; ++i )
    {
      int j = i;
      vector<int> ln;
      int rMx[MX][MX];
      int mod = m[ idx[i] ];
      for( ; j < T && mod == m[ idx[j] ] ; ++j )
	{
	  int mx[MX][MX];
	  int ti = i == j ? n[ idx[j] ] : n[ idx[j] ] - n[ idx[j - 1] ];
	  get( mx, ti, mod );
	  int res;
	  if( i == j )
	    cp( rMx, mx);
	  else
	    mul( rMx, mx, mod);
	  res = cal( rMx, mod);
	  if( res == 0 )
	    {
	      for( ; j < T && mod == m[ idx[j] ] ; ++j )
		ans[ idx[j] ] = res;
	    }
	  else
	    ans[ idx[j] ] = res;
	}
    }
  for( int i = 0 ; i < T ; ++i )
    printf("%d\n", ans[i] );
  return 0;
}
