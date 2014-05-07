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
const int N = 255007;
int pre[N * 2];
int len[N * 2];
int p[N * 2]['z' - 'a' + 7], poi, lst;
char s[N];
void add(int v)
{
  if( poi >= sizeof( pre ) / sizeof( pre[0] ) )
    return;
  ++poi;
  memset( p[poi], -1, sizeof( p[poi] ) );
  len[poi] = 1 + len[lst];
  int i = lst;
  lst = poi;
  for( ; i >= 0 && p[i][v] < 0; i = pre[i] )
    p[i][v] = lst;
  if( i >= 0 )
    {
      int tmp = p[i][v];
      if( len[i] != len[tmp] - 1 )
	{
	  ++poi;
	  memcpy( p[poi], p[tmp], sizeof( p[poi] ) );
	  len[poi] = len[i] + 1;
	  pre[poi] = pre[tmp];
	  pre[lst] = pre[tmp] = poi;
	  for(; i >= 0 && tmp == p[i][v]; i = pre[i] )
	    p[i][v] = poi;
	}
      else pre[lst] = tmp;
    }
  else
    pre[lst] = 0;
}
int main()
{
  scanf("%s", s);
  pre[0] = -1;
  memset( p[0], -1, sizeof(p[0] ) );
  for( int i = 0 ; s[i]; ++i )
    add(s[i] - 'a');
  scanf("%s", s);
  int maxLen = 0, ansS = 0;
  for( int i = 0, j = 0, k = 0; s[i]; ++i)
    {
      int tmp = p[k][ s[i] - 'a' ];
      if( tmp >= 0 )
	{
	  // cout << i << ' ' << k << ' ' << len[k] << endl;
	  k = tmp;
	  // j = min( 1 + j, len[k]);
	  ++j;
	}
      else
	{
	  for(; k >= 0 && p[k][ s[i] - 'a' ] < 0; k = pre[k] )
	    ;
	  if( k < 0 )
	    j = 0, k = 0;
	  else
	    j = len[k] + 1, k = p[k][ s[i] - 'a' ];
	}
      if( j > maxLen )
	maxLen = j, ansS = i - maxLen + 1;
    }
  if( maxLen )
    {
      s[ansS + maxLen] = '\0';
      printf("%s\n%d\n", s + ansS, maxLen);
    }
  else printf("0\n");
  return 0;
}
