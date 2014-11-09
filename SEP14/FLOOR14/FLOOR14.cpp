#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void modM( ll &a, ll &b, int mod )
{
  a = ( llabs(a) >= mod ) ? ( a % mod ) : a;
  b = ( llabs(b) >= mod ) ? ( b % mod ) : b;
  a = ( a < 0 ) ? ( a + mod ) : a;
  b = ( b < 0 ) ? ( b + mod ) : b;
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
const int base = 1e8;
void addV(vector<int> &to, const vector<int>& from )
{
  for( int i = 0, s = max( to.size(), from.size() ); i < s ; ++i )
    {
      if( i >= to.size() )
	to.push_back(0);
      if( i < from.size() )
	to[i] += from[i];
      if( to[i] >= base )
	{
	  if( i + 1 >= to.size() )
	    to.push_back(0);
	  to[i + 1] += to[i] / base;
	  to[i] %= base;
	}
    }
}
void mulV( vector<int> &v, ll val )
{
  if( val >= base )
    {
      vector<int> tmp = v;
      ll a = val / 100000;
      ll b = val % 100000;
      mulV( tmp, base );
      mulV( tmp, a);
      mulV( v, b);
      addV( v, tmp);
    }
  else
    {
      int c = 0;
      for( int i = 0, s = v.size() ; i < s ; ++i )
	{
	  ll tmp = v[i] * (ll)val + c;
	  v[i] = tmp % base;
	  c = tmp / base;
	}
      if( c > 0 )
	v.push_back(c);
    }
  for( int i = v.size() - 1; i > 0 && v[i] == 0 ; --i )
    v.pop_back();
}
void addV( vector<int> &v, int val)
{
  assert( val < base );
  vector<int>tmp;
  tmp.push_back(val);
  addV(v, tmp);
  // v[0] += val;
  // for( int i = 0 ; v[i] >= base; ++i )
  //   {
  //     v[i] -= base;
  //     if( i + 1 >= v.size() )
  // 	v.push_back(0);
  //     ++v[i + 1];
  //   }
}
void subV( vector<int> &v, int val )
{
  assert( val < base );
  v[0] -= val;
  for( int i = 0 ; v[i] < 0 ; ++i)
    {
      v[i] += base;
      --v[ i + 1 ];
    }
  for( int i = v.size() - 1; i > 0 && v[i] == 0 ; --i )
    v.pop_back();
}
void pt(const vector<int> &v )
{
  int i = v.size() - 1;
  cout << v[i];
  for( --i ; i >= 0 ; --i )
    printf("%09d", v[i] );
  cout << endl;
}
void divV( vector<int> &v, int val )
{
  ll r = 0;
  for( int i = v.size() - 1 ; i >= 0 ; --i )
    {
      r = base * r + v[i];
      v[i] = r / val;
      r %= val;
    }
  assert( r == 0 );
  for( int i = v.size() - 1 ; i > 0 && v[i] == 0 ; --i )
    v.pop_back();
}
int modV(const vector<int> &v, int val)
{
  ll r = 0;
  for( int i = v.size() - 1; i >= 0 ; --i )
    {
      r = r * base + v[i];
      r %= val;
    }
  return r;
}

int ss(ll v, int mod)
{
  vector<int> ans;
  ans.push_back(1);
  mulV(ans, v);
  mulV(ans, 6);
  addV(ans, 15);
  mulV( ans, v);
  addV( ans, 10);
  mulV( ans, v);
  mulV( ans, v);
  subV( ans, 1);
  mulV( ans, v);
  divV( ans, 30);
  return modV( ans, mod );
}
int s4( ll v, int mod )
{
  v = ( v >= mod ) ? ( v % mod ) : v;
  v *= v;
  v = ( v >= mod ) ? ( v % mod ) : v;
  v *= v;
  return ( v >= mod ) ? ( v % mod ) : v;
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
  ios::sync_with_stdio(false);
  for( ; T; --T)
    {
      ll n;
      int m;
      cin >> n >> m;
      int ans(0);
      ll sn;
      for( int i = 1 ; ; ++i )
	{
	  if( i * (ll)i > n )
	    {
	      sn = i;
	      break;
	    }
	  ans = addM( ans, mulM( s4(i, m), divM( n, i, m ), m ), m );
	}
      ll t = n;
      // cout << ans << endl;
      for( int i = 1; i <= n / sn ; ++i )
	{
	  // cout << ans << endl;
	  ll f = n / ( i + 1 ) + 1;
	  int det = subM( ss(t, m), ss( f - 1, m ), m);
	  // cout << det << endl;
	  // cout << f << ' ' << t << ' ' << det << ' ' << i << endl;
	  ans = addM( ans, mulM( det, i, m ), m );
	  t = f - 1;
	}
      printf("%d\n", ans);
    }
  return 0;
}
