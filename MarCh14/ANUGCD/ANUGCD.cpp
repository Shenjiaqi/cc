#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 100007;
const int M = 100007;
vector<pair<int,ll> > segTree[N * 4];
int segTree2[N * 4][3], segTreeTag;
int n, m;
int a[N];
int query[M][3];
vector<int> divisor[N];
const int lim = 317;
int ans[M][2];
queue<int> dQ[N];
queue<int> rQ[M];
void insertSegTree(int from, int to, int idx, int pos, int val)
{
  if( from > pos || to < pos )
    return;
  if( segTree2[idx][1] == segTreeTag )
    {
      if( segTree2[idx][0] < val )
	segTree2[idx][0] = val, segTree2[idx][2] = 1;
      else if( segTree2[idx][0] == val )
	++segTree2[idx][2];
    }
  else
    segTree2[idx][1] = segTreeTag, segTree2[idx][0] = val,
      segTree2[idx][2] = 1;
  if( from < to )
    {
      int mid = ( from + to ) >> 1;
      if( pos <= mid )
	insertSegTree( from, mid, idx << 1, pos, val );
      else
	insertSegTree( mid + 1, to, ( idx << 1 ) + 1, pos, val );
    }
}
void querySegTree(int from, int to, int idx, int x, int y, 
		  int &ansV, int &ansNum)
{
  if( to < x || from > y || segTree2[idx][1] != segTreeTag )
    return ;
  if( x <= from && to <= y )
    {
      if( ansV < segTree2[idx][0] )
	ansV = segTree2[idx][0], ansNum = segTree2[idx][2];
    }
  else //if( from < to )
    {
      int mid = (from + to ) >> 1;
      querySegTree( from, mid, idx << 1, x, y, ansV, ansNum );
      int t1, t2;
      t1 = t2 = -1;
      querySegTree( mid + 1, to, ( idx << 1 ) + 1, x, y, t1, t2);
      if( t1 != -1 )
	{
	  if( t1 > ansV )
	    ansV = t1, ansNum = t2;
	  else if( t1 == ansV )
	    ansNum += t2;
	}
    }
}
void initTree( int from, int to, int idx)
{
  if( from < to )
    {
      int mid = ( from + to ) >> 1;
      int idx1 = idx << 1;
      int idx2 = idx1 + 1;
      initTree( from, mid, idx1);
      initTree( mid + 1, to, idx2 );
      auto i1 = segTree[idx1].begin();
      auto i2 = segTree[idx2].begin();
      for(; i1 != segTree[idx1].end() && i2 != segTree[idx2].end(); )
	{
	  if( i1->first == i2->first )
	    {
	      int val1 = i1->second >> 30;
	      int val2 = i2->second >> 30;
	      if( val1 > val2 )
		segTree[idx].push_back( *i1 );
	      else if( val1 < val2 )
		segTree[idx].push_back( *i2 );
	      else
		segTree[idx].push_back( 
				       make_pair( i1->first, 
						  i1->second + i2->second - 
						  ( (ll)val1 << 30 ) ) );
	      ++i1, ++i2;
	    }
	  else if( i1->first < i2->first )
	    segTree[idx].push_back( *i1 ), ++i1;
	  else segTree[idx].push_back( *i2 ), ++i2;
	}
      for(; i1 != segTree[idx1].end(); ++i1)
	segTree[idx].push_back( *i1 );
      for(; i2 != segTree[idx2].end(); ++i2)
	segTree[idx].push_back( *i2 );
      // if( from <= 2525 && to >= 2524 )
      // 	for( auto i : segTree[idx] )
      // 	  if( i.first == 79 )
      // 	    cout << ( i.second >> 30 ) << "!" << endl;
    }
  else
    {
      for( auto i : divisor[a[from]] )
	if( i < lim )
	  {
	    segTree[idx].push_back( make_pair( i, ( (ll)a[from] << 30 ) | 1 ) );
	  }
    }
}
void que( int val, int x, int y, int from, int to, int idx, 
	  int &ansV, int &ansNum)
{
  if( y < from || x > to )
    return ;
  if( x <= from && to <= y )
    {
      auto div = divisor[val].begin();
      int num = segTree[idx].size();
      if( num > 0 )
	{
	  for( int maxV = segTree[idx][num - 1].first, i = 0; 
	   i < num && div != divisor[val].end(); ++div)
	    if( *div <= maxV )
	      {
		int j = num - i - 1;
		for(; j > 0; )
		  if( j + i < num && segTree[idx][i + j].first <= *div )
		    {
		      i += j;
		      if( segTree[idx][i].first == *div )
			break;
		    }
		  else j >>= 1;
		if( segTree[idx][i].first == *div )
		  {
		    if( ansV < ( segTree[idx][i].second >> 30 ) )
		      ansV = segTree[idx][i].second >> 30,
			ansNum = segTree[idx][i].second & ( ( 1LL << 30 ) - 1 );
		  }
	      }
	    else break;
	}
    }
  else if( from < to )
    {
      int mid = (from + to ) >> 1;
      que( val, x, y, from, mid, idx << 1, ansV, ansNum);
      int t1, t2;
      t1 = t2 = -1;
      que( val, x, y, mid + 1, to, ( idx << 1 ) + 1, t1, t2);
      if( t1 != -1 )
	{
	  if( t1 > ansV )
	    ansV = t1, ansNum = t2;
	  else if( t1 == ansV )
	    ansNum += t2;
	}
    }
}
int main()
{
  scanf("%d%d", &n, &m);
  for( int i = 0 ; i < n ; ++i )
    scanf("%d", a + i + 1);
  for( int j = 0 ; j < m ; ++j )
    scanf("%d%d%d", &query[j][0], &query[j][1], &query[j][2]);
  for(int i = 2; i < N ; ++i )
    if( divisor[i].size() == 0 )
      for( int j = i; j < N; j += i )
	divisor[j].push_back(i);
  initTree(1, n, 1);
  for( int j = 0; j < m; ++j )
    {
      ans[j][0] = ans[j][1] = -1;
      que( query[j][0], query[j][1], query[j][2], 1, n, 1, 
      	   ans[j][0], ans[j][1] );
      int val = query[j][0];
      if( val >= lim )
	{
	  int maxDivisor = divisor[val][ divisor[val].size() - 1 ];
	  if( maxDivisor >= lim )
	    rQ[maxDivisor].push(j);
	}
    }
  for( int i = 1; i < N; ++i )
    {
      int v = a[i];
      if( v >= lim )
	{
	  int d = divisor[v][ divisor[v].size() - 1 ];
	  if( d >= lim && !rQ[d].empty() )
	    dQ[d].push(i);
	}
    }
  for( int i = lim; i < N; ++i )
    if( !rQ[i].empty() )
      {
	segTreeTag = i;
	for( ; !dQ[i].empty(); dQ[i].pop() )
	  {
	    int id = dQ[i].front();
	    insertSegTree(1, n, 1, id, a[id] );
	  }
	for( ; !rQ[i].empty(); rQ[i].pop() )
	  {
	    int id = rQ[i].front();
	    int t1, t2;
	    t1 = t2 = -1;
	    querySegTree(1, n, 1, query[id][1], query[id][2], t1, t2);
	    if( t1 > ans[id][0] )
	      ans[id][0] = t1, ans[id][1] = t2;
	    // else if( t1 == ans[id][0] )
	    //   assert( t2 == ans[id][1] );
	  }
      }
  for( int i = 0 ; i < m; ++i )
    printf("%d %d\n", ans[i][0], ans[i][1] );
  return 0;
}
