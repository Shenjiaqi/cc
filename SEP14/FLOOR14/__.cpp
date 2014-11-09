#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int nm( int a, int b)
{
  return a >= b ? a - b : a;
}
int cal( ll v, int m )
{
  int m30 = m * 30;
  v %= m30;
  int r = ( 6LL * v + 15 ) % m30;
  r = ( (ll)r * v + 10 ) % m30;
  r = ( ( ( (ll)r * v ) % m30 ) * v - 1) % m30;
  if( r < 0 )
    r += m30;
  return ( ( ( r * v ) % m30 ) / 30 );
}
int main()
{
  int T;
  scanf("%d", &T);
  char sn[17];
  int m;
  for( ; T; --T)
    {
      scanf("%s%d", sn, &m);
      // int rn(0);
      ll n(0);
      for(int i = 0 ; sn[i] ; ++i )
	{
	  // rn = ( rn * 10 + ( sn[i] - '0' ) ) % rm;
	  n = n * 10 + sn[i] - '0';
	}
      int ans(0);
      for( int i = 1 ; ; ++i )
	{
	  ll tmp = (ll)i * i;
	  if( tmp <= n )
	    {
	      tmp %= m;
	      tmp = ( ( tmp * tmp ) % m ) * ( ( n / i ) % m );
	      ans += ( tmp % m );
	      ans = nm( ans, m);
	    }
	  else
	    {
	      ll t = n;
	      for( int j = 1 ; j <= n / i; ++j )
		{
		  ll nxt = n / ( j + 1 );
		  int tmp = ( cal(t, m) - cal(nxt, m) ) % m;
		  if( tmp < 0 )
		    tmp += m;
		  ans += ( (ll)tmp * ( j % m ) ) % m;
		  ans = nm(ans, m);
		  t = nxt;
		}
	      break;
	    }
	}
      assert(ans>=0);
      printf("%d\n", ans);
    }
  return 0;
}
