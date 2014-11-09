#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const int NB = 9;
const int base = 1e9;
class BigNum
{ 
public: 
  vector<int> a;
  BigNum(){};
  BigNum(const int);
  BigNum(const char*);
  BigNum(const BigNum &);
  BigNum &operator=(const BigNum &);

  void mulV( int v);
  void addV( int v);
  void subV( int v);
  void mulV( const BigNum &v);
  void divV( int v);
  int modV( int v);
  bool   operator>(const BigNum & T)const;   
  bool   operator<(const BigNum & T)const;
  bool operator ==(const BigNum & T)const;
  
  void norm();
  void print()const;
};
inline void BigNum::divV( int v)
{
  ll r(0);
  for( int i = a.size() - 1; i >= 0 ; --i )
    {
      r = r * base + a[i];
      a[i] = r / v;
      r %= v;
    }
  norm();
}
inline int BigNum::modV( int v)
{
  ll r(0);
  for( int i = a.size() - 1 ; i >= 0 ; --i )
    {
      r = ( r * base + a[i] ) % v;
    }
  a.resize(1);
  a[0] = r;
  return r;
}
inline void BigNum::mulV( int v)
{
  ll c(0);
  for( int i = 0, j = a.size(); i < j ; ++i )
    {
      c += v * (ll)a[i];
      if( c < base )
	{
	  a[i] = c;
	  c = 0;
	}
      else
	{
	  a[i] = c % base;
	  c /= base;
	}
    }
  if( c > 0 )
    a.push_back(c);
}
inline void BigNum::addV( int v)
{
  for(int i = 0, j = a.size() ; i < j && v > 0 ; ++i )
    {
      v += a[i];
      if( v < base )
	{
	  a[i] = v, v = 0;
	}
      else
	{
	  a[i] = v % base;
	  v /= base;
	}
    }
  if( v > 0 )
    a.push_back(v);
}
inline void BigNum::subV( int v)
{
  for( int i = 0 ; i < a.size() && v > 0; ++i )
    {
      a[i] -= v;
      if( a[i] < 0 )
	a[i] += base, v = 1;
      else
	v = 0;
    }
  norm();
}
inline void BigNum::mulV( const BigNum &v)
{
  vector<int> tmp;
  for( int i = 0 ; i < v.a.size() ; ++i )
    for( int j = 0 ; j < a.size();  ++j )
      {
	ll t = (ll)v.a[i] * a[j];
	if( tmp.size() <= i + j )
	  tmp.push_back(0);
	t += tmp[i + j];
	if( t < base )
	  {
	    tmp[i + j] = t;
	  }
	else
	  {
	    tmp[i + j] = t % base;
	    if( i + j + 1 >= tmp.size() )
	      {
		tmp.push_back(0);
	      }
	    tmp[i + j + 1] += t / base;
	  }
      }
  a = tmp;
}
bool BigNum::operator==(const BigNum &T)const
{
  if( a.size() == T.a.size() )
    {
      for( int i = a.size() - 1 ; i >= 0 ; --i )
	if( a[i] != T.a[i] )
	  return false;
      return true;
    }
  return false;
}
void BigNum::norm()
{
  for( int i = a.size() - 1 ; i >= 0 && a[i] == 0 ; --i )
    a.pop_back();
}
BigNum::BigNum(int b)
{ 
  a.resize(0);
  for( ; b > 0 ; b /= base )
    a.push_back( b % base );
  norm();
}
BigNum::BigNum(const char*s)
{
  for( int i = 0 ; s[i] ; )
    {
      int v(0);
      for(int j = 0 ; j < NB && s[i]; ++i, ++j )
	v = v * 10 + (s[i] - '0');
      a.push_back(v);
    }
}
BigNum::BigNum(const BigNum & T)
{ 
  a = T.a;
  norm();
} 
BigNum & BigNum::operator=(const BigNum & n)
{
  a = n.a;
  norm();
  return *this;
}

bool BigNum::operator>(const BigNum & T) const
{
  if( a.size() != T.a.size() )
  return a.size() > T.a.size();
  for( int i = a.size() - 1 ; i >= 0 ; --i )
    if( a[i] != T.a[i] )
      return a[i] > T.a[i];
  return false;
}
bool BigNum::operator<(const BigNum & T) const
{
  if( a.size() != T.a.size() )
    return a.size() < T.a.size();
  for( int i = a.size() - 1 ; i >= 0 ; --i )
    if( a[i] != T.a[i] )
      return a[i] < T.a[i];
  return false;
}
void BigNum::print() const
{ 
  if( a.empty() )
    printf("0");
  else
    {
      int i = a.size() - 1;
      printf("%d", a[i] );
      for( --i ; i >= 0 ; --i )
	printf("%08d", a[i]);
    }
  printf("\n");
}
BigNum cal( const BigNum &v )
{
  BigNum r = v;
  r.mulV(6);
  r.addV(15);
  r.mulV(v);
  r.addV(10);
  assert( r == v * ( v * 6 + 15) + 10);
  r.mulV(v);
  r.mulV(v);
  r.subV(1);
  r.mulV(v);
  return r;
}
int main(void)
{
  int T;
  scanf("%d", &T);
  for( ; T; --T )
    {
      char n[11];
      int m;
      scanf("%s %d", n, &m);
      BigNum v(n);
      ll ans(0);
      vector<BigNum > p;
      for( int i = 1 ; ; ++i)
	{
	  BigNum t = i;
	  t.mulV(i);
	  if( !( t > v ) )
	    {
	      t.modV(m);
	      t.a[0] = ( (ll)t.a[0] * t.a[0] ) % m;
	      BigNum tmp = v;
	      tmp.divV(i);
	      p.push_back(tmp);
	      tmp.mulV(t);
	      ans += ( tmp % m );
	      if( ans >= m )
		ans -= m;
	    }
	  else
	    {
	      p.push_back( v / i );
	      for( int j = 1 ; j < p.size(); ++j )
		{
		  BigNum num(j);
		  if( !( num < p[j - 1] ) )
		    break;
		  num = ( cal(p[j - 1]) - cal(p[j]) );
		  num.divV(30);
		  num.mulV(j);
		  ans += ( num.modV(m) );
		  if( ans >= m )
		    ans -= m;
		}
	      break;
	    }
	}
      printf("%d\n", (int)(ans % m));
    }
  return 0;
}
