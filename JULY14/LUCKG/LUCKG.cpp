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
const int N = 1007;
const int M = 1007;
int p[N];
int q[N][M];
int tmp[N][M];
int vis[N];
int idx[N];
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      if( t )
	printf("\n");
      int n, m;
      scanf("%d%d", &n, &m);
      for( int i = 0 ; i < n ; ++i )
	{
	  scanf("%d", p + i );
	}
      bool ok = true;
      int num = n * m;
      for( int i = 0 ; ok && i < n ; ++i )
	{
	  if( vis[i] != t + 1 )
	    {
	      vector<int> v;
	      for( int j = i; vis[j] != t + 1; j = p[j] )
		{
		  vis[j] = t + 1;
		  v.push_back(j);
		}
	      if( v.size() > 2 )
		{
		  for( int j = m - 1, k = 0, preSum = 0; j >= 0;  )
		    if( 2 * ( m * j + k + preSum ) > m * m )
		      {
			if( k == 0 || ( m - k <= j ) )
			  {
			    tmp[0][j] = k;
			    --j;
			    preSum += k;
			  }
			else
			  {
			    ++k;
			  }
		      }
		    else
		      {
			++k;
		      }
		  for( int j = 1; j < v.size() - 1; ++j )
		    {
		      int c = m - 1;
		      for( ; c >= 0 && tmp[j - 1][c] == 0; --c )
			;
		      for( int k = m - 1, preSum = 0; k >= 0; )
			{
			  if( c + 1 < m )
			    {
			      if( 2 * ( m - c - 1  + preSum + m * k ) > m * m )
				{
				  if( tmp[ j - 1 ][ c + 1 ] == 0 || c + 1 <= k )
				    {
				      tmp[j][k] = tmp[j - 1][c + 1];
				      preSum += m - c - 1;
				      --k;
				    }
				  else --c;
				}
			      else --c;
			    }
			  else if( 2 * ( preSum + m * k ) > m * m )
			    {
			      tmp[j][k] = 0;
			      --k;
			    }
			  else --c;
			}
		    }
		  int sum(0);
		  for( int j = 0; j < m ; ++j )
		    sum += ( m - tmp[v.size() - 2][j] );
		  if( 2 * sum <= m * m )
		    {
		      assert( v.size() > m );
		      ok = false;
		    }
		  else
		    {
		      for( int j = 0 ; j < v.size() - 1; ++j )
			idx[j] =  m - 1;
		      for( int j = 0; j <= m; ++j )
			{
			  for( int k = 0 ; k < v.size() - 1; ++k )
			    {
			      for( ;idx[k] >= 0 && tmp[k][ idx[k] ] == j; )
				{
				  q[ v[k + 1] ][ idx[k] ] = num;
				  --num;
				  --idx[k];
				}
			    }
			  if( j < m )
			    {
			      q[ v[0] ][ m - j - 1 ] = num;
			      --num;
			    }
			}
		      // for( int i = 0; i < v.size(); ++i )
		      // 	{
		      // 	  int a = v[i];
		      // 	  int b = v[ ( i + 1 ) % v.size() ];
		      // 	  int cnt(0);
		      // 	  for( int j = 0, k = 0; j < m; ++j )
		      // 	    {
		      // 	      cnt += k;
		      // 	      for( ; k < m && q[a][j] > q[b][k]; ++k )
		      // 		++cnt;
		      // 	    }
		      // 	  assert( cnt * 2 > m * m );
		      // 	}
		    }
		}
	      else
		ok = false;
	    }
	}
      if( ok )
	{
	  // assert( num == 0 );
	  for( int i = 0 ; i < n ; ++i )
	    {
	      if( i )
		printf("\n");
	      for( int j = 0 ; j < m ; ++j )
		{
		  printf("%d", q[i][j]);
		  if( j < m - 1 )
		    printf(" ");
		}
	    }
	}
      else printf("No Solution");
    }
  return 0;
}
