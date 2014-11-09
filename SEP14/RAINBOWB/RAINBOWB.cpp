#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int addM( int a, int b)
{
  a += b;
  return ( a >= MOD ) ? ( a - MOD ) : a;
}
int mulM( ll a, int b)
{
  a *= b;
  return ( a >= MOD ) ? ( a % MOD ) : a;
}
int powM( int a, int b)
{
  int r = 1;
  for( int i = 1; i <= b; i <<= 1 )
    {
      if( i & b )
	{
	  r = mulM( r, a );
	}
      a = mulM( a, a );
    }
  return r;
}
int rev( int a )
{
  return powM( a, MOD - 2 );
}
int choice( int a, int b)
{
  int c = 1, d = 1;
  for( int i = 0 ; i < b ; ++i )
    {
      c = mulM( c, a - i );
      d = mulM( d, i + 1 );
    }
  return mulM( c, rev(d) );
}
int main()
{
  int n;
  scanf("%d", &n);
  int ans(0);
  for( int i = 1; i < n ; ++i )
    {
      int left = n - i;
      if( ( left & 1 ) == 0 )
	{
	  left >>= 1;
	  if( left >=6 )
	    {
	      left -= 6;
	      ans = addM( ans, choice(left + 5, 5) );
	    }
	}
    }
  printf("%d", ans);
  return 0;
}
