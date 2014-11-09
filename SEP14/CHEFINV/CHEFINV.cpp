#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const int M = 2e5 + 7;
struct e
{
  bool grt;
  bool add;
  int val;
  int pos;
  e(bool g, bool a, int v, int p)
  {
    grt = g, add = a, val = v, pos = p;
  };
};
int p[N];
int q[N][2];
vector<e> que[N];
int s[N];
ll ans[M];
void add( int v, int val)
{
  for( ; v < N; v += ( v & (-v) ) )
    s[v] += val;
}
int query( int v )
{
  int ans(0);
  for( ; v; v ^= ( v & (-v) ) )
    ans += s[v];
  return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  scanf("%d%d", &n, &m);
  map<int,int> mapp;
  for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", p + i);
      mapp[ p[i] ] = 0;
    }
  int cnt = 0;
  for( auto &i : mapp )
    i.second = ++cnt;
  for( int i = 0 ; i < n ; ++i )
    p[i] = mapp[ p[i] ];
  for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d%d", &q[i][0], &q[i][1] );
      --q[i][0], --q[i][1];
      if( q[i][0] > q[i][1] )
	swap( q[i][0], q[i][1]);
      int a = q[i][0], b = q[i][1];
      int va = p[a], vb = p[b];
      que[a].push_back( e( false, true, va, i) );
      que[b].push_back( e( false, false, va, i) );
      que[a].push_back( e( true, false, va, i) );
      que[b].push_back( e( true, true, va, i) );
      que[a + 1].push_back( e( true, true, vb, i) );
      que[b].push_back( e( true, false, vb, i) );
      que[a + 1].push_back( e( false, false, vb, i) );
      que[b].push_back( e( false, true, vb, i) );
      if( va < vb )
	++ans[i];
      else if( va > vb )
	--ans[i];
    }
  ll sum(0);
  for( int i = 0 ; i <= n ; ++i )
    {
      for( auto j : que[i] )
	{
	  int val = j.val;
	  int add = j.add;
	  int grt = j.grt;
	  int pos = j.pos;
	  int lCnt;
	  if( grt )
	    lCnt = i - query(val);
	  else lCnt = query( val - 1 );
	  if( add )
	    ans[pos] += lCnt;
	  else ans[pos] -= lCnt;
	}
      if( i < n )
	{
	  sum += i - query( p[i] );
	  add( p[i], 1);
	}
    }
  for( int i = 0 ; i < m ; ++i )
    {
      cout << ( sum + ans[i] ) << '\n';
    }
  return 0;
}
