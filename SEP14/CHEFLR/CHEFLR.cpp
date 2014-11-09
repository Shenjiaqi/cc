#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
char s[N];
int p[N];
int addM(int a, int b)
{
  a += b;
  return ( a >= MOD ) ? ( a - MOD ) : a;
}
int mulM(ll a, int b)
{
  a *= b;
  return ( a >= MOD ) ? ( a % MOD ) : a;
}
int subM(int a, int b)
{
  a -= b;
  return a < 0 ? a + MOD : a;
}
int main()
{
  int T;
  scanf("%d", &T);
  p[0] = 1;
  for( int i = 1 ; i < N ; ++i )
    {
      p[i] = mulM( p[i - 1], 2);
    }
  for( int t = 0 ; t < T ; ++t )
    {
      scanf("%s", s);
      int len = strlen(s);
      int preCnt(0);
      for( int i = ( len & 1 ) ? 1 : 0; i < len ; i += 2 )
	{
	  preCnt = addM( preCnt, p[i]);
	}
      int befCnt = p[ len ];
      for( int i = 0 ; i < len ; ++i )
	{
	  if( s[i] == 'l' )
	    {
	      befCnt = subM( befCnt, p[ len - 1 - i ] );
	    }
	}
      int ans = addM( befCnt, preCnt );
      if( len & 1 )
	ans = mulM(ans, 2);
      else
	ans = subM( mulM( ans, 2), 1);
      printf("%d\n", ans);
    }
  return 0;
}
