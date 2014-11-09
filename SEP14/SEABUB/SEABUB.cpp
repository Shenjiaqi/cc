#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int N = 107;
const int M = ( N - 1 ) * N / 2;
ld p[N][M];
ld q[N][M];
int v[N];
int cnt[N];
void add( int pos, int v)
{
  for( ; pos < N ; pos += ( pos & ( -pos ) ) )
    cnt[pos] += v;
}
int que( int pos )
{
  int r(0);
  for( ; pos; pos ^= ( pos & ( -pos ) ) )
    r += cnt[pos];
  return r;
}
int main()
{
  for( int i = 1; i < N ; ++i )
    {
      p[i][0] = 1.0;
      for( int j = 1; j <= ( i - 1 ) * i / 2 ; ++j )
	{
	  p[i][j] = p[i][j - 1] + p[ i - 1 ][j];
	  if( j >= i )
	    p[i][j] -= p[ i - 1 ][ j - i ];
	}
    }
  for( int i = 1 ; i < N ; ++i )
    {
      ld sum(0.0);
      int c = ( i - 1 ) * i / 2;
      for( int j = 0 ; j <= c ; ++j )
	{
	  sum += p[i][j];
	}
      for( int j = 0 ; j <= c ; ++j )
	{
	  ld tmp = p[i][j] / sum;
	  q[i][j] = ( j > 0 ? q[i][j - 1] : 0 ) + tmp * (ld)j;
	  p[i][j] = ( j > 0 ? p[i][j - 1] : 0 ) + tmp;
	}
    }
  // ios::sync_with_stdio(false);
  int T;
  // cin >> T;
  scanf("%d", &T);
  // cout.precision(13);
  for( ; T; --T )
    {
      int n;
      ll k;
      // cin >> n >> k;
      scanf("%d%lld", &n, &k);
      int rev(0);
      memset( cnt, 0, sizeof(cnt) );
      for( int i = 0 ; i < n ; ++i )
	{
	  scanf("%d", v + i );
	  rev += i - que(v[i]);
	  add( v[i], 1);
	}
      ld ans;
      if( k < rev )
	{
	  if( k > 0 )
	    {
	      int c = n * ( n - 1 ) / 2;
	      ld avg = q[n][c];
	      for( int j = 1; j < k ; ++j )
		{
		  int l = min( (int)( avg ) + j, c);
		  avg = avg * max( (ld)1.0 - p[n][l], (ld)0.0);
		  if( l > j )
		    avg += ( q[n][l] - q[n][j] - ( p[n][l] - p[n][j] ) * (ld)j );
		}
	      ans = min( (ld)rev - k, avg);
	    }
	  else ans = rev;
	}
      else ans = 0;
      printf("%.7lf\n", (double)ans);
      // cout << ans << endl;
    }
  return 0;
}
