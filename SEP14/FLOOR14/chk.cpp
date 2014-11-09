#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void modM( ll a, ll b, int mod )
{
  a = ( a >= mod ) ? ( a % mod ) : a;
  b = ( b >= mod ) ? ( b % mod ) : b;
}
int addM( ll a, ll b, int mod)
{
  modM(a, b, mod);
  a += b;
  return ( a >= mod ) ? ( a - mod ) : a;
}
int subM( ll a, ll b, int mod )
{
  modM( a, b, mod );
  a -= b;
  return ( a < 0 ) ? ( a + mod ) : a;
}
int mulM( ll a, ll b, int mod )
{
  modM( a, b, mod );
  a *= b;
  return ( a >= mod ) ? ( a % mod ) : a;
}
int divM( ll a, ll b, int mod )
{
  a /= b;
  return ( a >= mod ) ? ( a % mod ) : a;
}
int main()
{
  int T;
  scanf("%d", &T);
  for( ; T--; )
    {
      ll n, m;
      int ans(0);
      cin >> n >> m;
      for( int i = 1 ; i <= n ; ++i )
	{
	  ll v = mulM( i, i, m );
	  ans = addM( ans, mulM( mulM( v, v, m ), divM( n, i, m), m ), m);
	}
      cout << ans << endl;
    }
  return 0;
}
