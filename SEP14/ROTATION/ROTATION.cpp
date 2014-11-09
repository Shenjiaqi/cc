#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int p[N];
int addM( int a, int b, int m)
{
  a += b;
  return ( a >= m ) ? ( a - m ) : a;
}
int subM( int a, int b, int m)
{
  a -= b;
  return ( a < 0 ) ? ( a + m ) : a;
}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for( int i = 0 ; i < n ; ++i )
    scanf("%d", p + i);
  for( int i = 0, q = 0 ; i < m ; ++i )
    {
      char c;
      int v;
      scanf("\n%c%d", &c, &v);
      if( c == 'C' )
	{
	  q = addM( q, v, n);
	}
      else if( c == 'A' )
	{
	  q = subM( q, v, n);
	}
      else
	{
	  printf("%d\n", p[ addM( q, v - 1, n)] ); 
	}
    }
  return 0;
}
