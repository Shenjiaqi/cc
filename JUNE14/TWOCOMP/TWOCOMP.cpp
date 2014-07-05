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
const int N = 1e5 + 7;
const int L = 20;
const int M = 707;
const int inf = 2e9 + 7;
vector<int> p[N];
int pre[N][L];
int rd[2][M][4];
int lev[N];
int S, T;
bool in[N];
int seq[N];
int q[ M * M * 2 ][3], qoi;
int s[ M + M ];
int c[ M + M ];
void addP( int from, int to, int flow )
{
  ++qoi;
  q[qoi][0] = to, q[qoi][1] = flow, q[qoi][2] = s[from], s[from] = qoi;
  ++qoi;
  q[qoi][0] = from, q[qoi][1] = 0, q[qoi][2] = s[to], s[to] = qoi;
}
void dfs( int v, int from )
{
  lev[v] = lev[from] + 1;
  for( int i = 0, j = from ; i < L; ++i )
    {
      pre[v][i] = j;
      j = pre[j][i];
    }
  for( auto i : p[v] )
    {
      if( i != from )
	dfs( i, v );
    }
}
int up( int v, int l )
{
  for( int i = L - 1 ; i >= 0; --i )
    {
      if( lev[ pre[v][i] ] >= l )
	v = pre[v][i];
    }
  return v;
}
int getCom( int a, int b )
{
  if( lev[a] < lev[b] )
    swap( a, b );
  // cout << a << ' ' << b << endl;
  a = up( a, lev[b] );
  for( int i = L - 1 ; i >= 0 ; --i )
    {
      if( pre[a][i] != pre[b][i] )
	a = pre[a][i], b = pre[b][i];
    }
  // cout << "!" << a << ' ' << b << endl << endl;;
  return a == b ? a : pre[a][0];
}
bool bfsf()
{
  queue<int> que;
  memset( in, 0, sizeof(in) );
  memcpy( c, s, sizeof(c) );
  in[S] = true;
  que.push(S);
  for( ; !que.empty(); que.pop() )
    {
      int v = que.front();
      for( int i = c[v]; i; i = q[i][2] )
	{
	  int t = q[i][0];
	  if( !in[t] && q[i][1] > 0 )
	    {
	      seq[t] = seq[v] + 1;
	      in[t] = true;
	      que.push(t);
	    }
	}
    }
  return in[T];
}
int dfsf( int v, int f )
{
  if( v == T )
    return f;
  int rf = f;
  int i = c[v];
  for( ; i ; i = q[i][2] )
    {
      int t = q[i][0];
      if( seq[t] == seq[v] + 1 && q[i][1] > 0 )
	{
	  int val = dfsf( t, min( f, q[i][1] ) );
	  f -= val;
	  q[i][1] -= val;
	  q[ i + ( ( i & 1 ) ? 1 : -1 ) ][1] += val;
	  if( f == 0 )
	    break;
	}
    }
  c[v] = i;
  return rf - f;
}
int mf()
{
  int r(0);
  for( ; bfsf(); )
    for( ; ; )
      {
	int tmp = dfsf( S, inf );
	if( tmp == 0 )
	  break;
	r += tmp;
      }
  return r;
}
int main()
{
  int n, m[2];
  scanf("%d%d%dd", &n, &m[0], &m[1]);
  for( int i = 0 ; i < n - 1 ; ++i )
    {
      int x, y;
      scanf("%d%d", &x, &y);
      p[x].push_back(y);
      p[y].push_back(x);
    }
  dfs(1, 0);
  for( int i = 0; i < 2; ++i )
    {
      for( int j = 0 ; j < m[i]; ++j )
	{
	  int x, y, joy;
	  scanf("%d%d%d", &x, &y, &joy);
	  rd[i][j][0] = x, rd[i][j][1] = y, rd[i][j][2] = joy;
	  int v = getCom( x, y );
	  rd[i][j][3] = v;
	}
    }
  for( int i = 0 ; i < m[0] ; ++i )
    {
      int a[2][2];
      a[0][0] = rd[0][i][0], a[0][1] = rd[0][i][3];
      a[1][0] = rd[0][i][1], a[1][1] = rd[0][i][3];
      for( int j = 0 ; j < m[1] ; ++j )
	{
	  int b[2][2];
	  b[0][0] = rd[1][j][0], b[0][1] = rd[1][j][3];
	  b[1][0] = rd[1][j][1], b[1][1] = rd[1][j][3];
	  bool conf = false;
	  for( int c = 0; !conf && c < 2; ++c )
	    for( int d = 0; !conf && d < 2; ++d )
	      {
		int v = getCom( a[c][0], b[d][0] );
		if( a[c][1] == getCom( v, a[c][1] ) &&
		    b[d][1] == getCom( v, b[d][1] ) )
		  {
		    // if( i == 0 && j == 0 )
		    //   cout << a[c][0] << ' ' << a[c][1] << ' ' <<
		    // 	b[d][0] << ' ' << b[d][1] <<  ' ' << v <<  
		    // 	'  '<< getCom( v, a[c][1] ) << ' ' <<
		    // 	getCom( v, b[d][1] ) << endl;
		    conf = true;
		  }
	      }
	  if( conf )
	    {
	      addP( 1 + i, 1 + m[0] + j, inf );
	    }
	}
    }
  S = m[0] + m[1] + 1, T = S + 1;
  int sumJoy(0);
  for( int i = 0 ; i < m[0] ; ++i )
    {
      addP( S, i + 1, rd[0][i][2] );
      sumJoy += rd[0][i][2];
    }
  for( int i = 0 ; i < m[1] ; ++i )
    {
      addP( i + m[0] + 1, T, rd[1][i][2] );
      sumJoy += rd[1][i][2];
    }
  int maxFlow = mf();
  printf("%d", sumJoy - maxFlow );
  return 0;
}
