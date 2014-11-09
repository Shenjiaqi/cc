#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll llgcd(ll a, ll b)
{
  return ( b == 0 ) ? a : llgcd( b, a % b);
}
class f
{
public:
  ll a, b;
  void norm()
  {
    if( a == 0 )
      b = 1;
    else
      {
	if( b < 0 )
	  a = -a, b = -b;
	ll tmp = llgcd( llabs(a), b );
	if( tmp > 1 )
	  a /= tmp, b /= tmp;
      }
  };
  void setF(ll aa, ll bb = 1){ a = aa, b = bb; norm(); };
  f(){ a = 0, b = 1;};
  f(ll aa, ll bb = 1){ a = aa, b = bb; norm();};
  f( const f& v)
  {
    a = v.a, b = v.b;// norm();
  };
  void addF(const f& v)
  {
    a = a * v.b + v.a * b;
    b = b * v.b;
    norm();
  };
  void subF(const f& v)
  {
    a = a * v.b - b * v.a;
    b *= v.b;
    norm();
  };
  void mulF(ll v)
  {
    a *= v;
    norm();
  };
  void mulF(const f& v)
  {
    a *= v.a, b *= v.b;
    norm();
  };
  void divF(ll v)
  {
    assert( v != 0 );
    b *= v;
    norm();
  };
  void divF(const f &v)
  {
    assert( v.a != 0 );
    a *= v.b;
    b *= v.a;
    norm();
  };
  void pt()
  {
    cout << a << '/' << b;
  };
};
const int N = 6;
void del( f a[], f b[], int idx )
{
  f mulV(a[idx]);
  mulV.divF( b[idx] );
  for( int i = 0 ; i < N + 1 ; ++i )
    if( b[i].a != 0 )
      {
	f tmp(b[i]);;
	tmp.mulF(mulV);
	a[i].subF(tmp);
      }
}
f b[N];
f cal(int n)
{
  f tmp(1);
  f ans;
  for( int i = 0 ; i < N ; ++i )
    {
      f v = tmp;
      v.mulF( b[i] );
      ans.addF( v );
      tmp.mulF(n);
    }
  return ans;
}

int main()
{
  f a[N][N + 1];
  ll sum(0);
  for( int i = 1 ; i <= N; ++i )
    {
      ll v = i * i;
      v *= v;
      sum += v;
      a[i - 1][N].setF(sum);
      v = 1;
      for( int j = 0 ; j < N; ++j )
	{
	  a[ i - 1 ][j].setF(v);
	  v *= i;
	}
    }

  for( int i = 0 ; i < N ; ++i )
    {
      for( int j = i ; j < N ; ++j )
	{
	  if( a[j][i].a != 0 )
	    {
	      for( int k = 0 ; k < N ; ++k )
		{
		  if( k != j && a[k][i].a != 0 )
		    {
		      del( a[k], a[j], i );
		    }
		}
	      break;
	    }
	}
    }
  for( int i = 0 ; i < N ; ++i )
    {
      for( int j = 0 ; ; ++j )
	{
	  if( a[i][j].a != 0 )
	    {
	      a[i][N].divF( a[i][j] );
	      a[i][j].setF( 1, 1);
	      break;
	    }
	}
    }
  for( int i = 0 ; i < N ; ++i )
    {
      for( int j = 0 ; j < N ; ++j )
	{
	  a[i][j].pt();
	  cout << "   ";
	}
      cout << "   ";
      a[i][N].pt();
      cout << endl;
    }

  for( int i = 0 ; i < N ; ++i )
    {
      b[i] = a[i][N];
    }
  cal(6).pt();
  cout << endl;
  cal(4).pt();
  return 0;
}
