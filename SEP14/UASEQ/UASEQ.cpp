#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const ll inf = (ll)(1e18) + 7LL;
int p[N];
ll q[N];
void calAD( int val, int pos, int det, pair<ll, ll> & ret)
{
  ret.first = (ll)val - (ll)pos * (ll)det;
  ret.second = det;
}
void calNewP( pair<ll, ll> arr, int num )
{
  q[0] = arr.first;
  for( int i = 1 ; i < num ; ++i )
    q[i] = q[i - 1] + arr.second;
}
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", p + i );
    }
  pair<ll, ll> ans;
  ans.first = ans.second = inf;
  if( n <= 100 )
    {
      for( int i = 0 ; i < n ; ++i )
	{
	  for( int j = i + 1 ; j < n ; ++j )
	    {
	      int d = p[j] - p[i];
	      if( ( d % ( j - i ) ) == 0 )
		{
		  pair<ll, ll> ret;
		  calAD( p[i], i, d / ( j - i ), ret);
		  if( ans > ret )
		    {
		      calNewP( ret, n);
		      int cntK(0);
		      for( int j = 0 ; cntK <= k && j < n ; ++j )
			if( q[j] != p[j] )
			  ++cntK;
		      if( cntK <= k )
			{
			  ans = ret;
			}
		    }
		}
	    }
	}
    }
  else
    {
      map< pair<ll, ll>, int> mapp;
      for( int i = 1 ; i < n ; ++i )
	{
	  pair<ll, ll> ret;
	  calAD( p[i - 1], i - 1, p[i] - p[i - 1], ret);
	  ++mapp[ ret ];
	}
      for( auto i : mapp )
	{
	  if( n - ( i.second + 1 ) <= k )
	    {
	      ans = i.first;
	      break;
	    }
	}
    }
  calNewP( ans, n);
  ios::sync_with_stdio(false);
  assert( ans.first < inf );
  for( int i = 0 ; i < n ; ++i )
    {
      cout << q[i] << ' ';
      if( q[i] != p[i] )
	--k;
    }
  return 0;
}
