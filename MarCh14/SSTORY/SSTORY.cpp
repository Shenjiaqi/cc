#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <tuple>
#include <cassert>
#include <set>
#include <unordered_set>
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
const int S = 250007;
char s1[S],s2[S];
struct hV
{
  ll fir, sec;
  bool operator==(const hV & other) const
  {
    return fir == other.fir &&
      sec == other.sec;
  };
};
hV h1[S][19], h2[S][19];
inline ll hashLL( ll a, ll b, int off)
{
  return ( ( ( a << 2 ) + ( a >> 2 ) + ( b ^ 0x9e3779bLL ) ) & ( ( 1LL << 62 ) - 1 ) );
}
struct myHash {
  size_t operator()(const hV& x) const
  {
    return hash<ll>()( hashLL( x.fir, x.sec, 1 ) );
  }
};
void hashHV(hV & a, hV & b, hV &r)
{
  r.fir = hashLL( a.fir, b.fir, 3 );
  r.sec = hashLL( a.sec, b.sec, 7 );
}
int main()
{
  scanf("%s%s", s1, s2);
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  for( int i = 0; i < l1; ++i )
    // h1[i][0] = s1[i] * 1313;
    h1[i][0].fir = hashLL(s1[i], 171717, 1 ), h1[i][0].sec = hashLL(1313131313LL, s1[i], 1);
    // get<0>(h1[i][0]) = s1[i];
  for( int i = 0; i < l2; ++i )
    // h2[i][0] = s2[i] * 1313;
    h2[i][0].fir = hashLL(s2[i], 171717, 1), h2[i][0].sec = hashLL(1313131313LL, s2[i], 1);
    // get<0>(h2[i][0]) = s2[i];
  for( int i = 1; 1 << i <= l1; ++i )
    for( int j = 0; j + ( 1 << i ) <= l1; ++j )
      hashHV( h1[j][i - 1], h1[j + ( 1 << ( i - 1 ) ) ][ i - 1 ], h1[j][i]);
  for( int i = 1; 1 << i <= l2; ++i )
    for( int j = 0; j + ( 1 << i ) <= l2; ++j )
      hashHV( h2[j][i - 1], h2[j + ( 1 << ( i - 1 ) ) ][ i - 1 ], h2[j][i] );
  int maxId = l2;
  for(; maxId != ( maxId & (- maxId) ); )
    maxId ^= ( maxId & - maxId );
  maxId = __builtin_ctz(maxId);
  list<pair<hV,int> > matched1, matched2;
  for( ; maxId >= 0; --maxId )
    {
      unordered_set<hV, myHash> hash2;
      for( int j = 0; j + (1 << maxId) <= l2; ++j)
	hash2.insert( h2[j][maxId] );
      unordered_set<hV, myHash> matchedHash2;
      for( int j = 0 ; j + ( 1 << maxId ) <= l1; ++j )
	if( hash2.find( h1[j][maxId] ) != hash2.end() )
	  {
	    matched1.push_back( make_pair( h1[j][maxId], j + ( 1 << maxId ) ) );
	    matchedHash2.insert( h1[j][maxId] );
	  }
      if( !matched1.empty() )
	{
	  for( int j = 0; j + ( 1 << maxId ) <= l2; ++j )
	    if( matchedHash2.find( h2[j][maxId] ) != matchedHash2.end() )
	      matched2.push_back( make_pair( h2[j][maxId], 
					     j + ( 1 << maxId ) ) );
	  break;
	}
    }
  if( maxId >= 0 )
    {
      int ans = 1 << maxId;
      for( --maxId ; maxId >= 0; --maxId )
	{
	  unordered_set<hV, myHash> hash2;
	  for( auto i : matched2 )
	    {
	      int pos = i.second;
	      if( pos + ( 1 << maxId ) <= l2 )
		{
		  hV hashValue;
		  hashHV( i.first, h2[pos][maxId], hashValue );
		  hash2.insert( hashValue );
		}
	    }
	  list<pair<hV,int> > m1;
	  unordered_set<hV, myHash> matchedHash2;
	  for( auto i : matched1 )
	    {
	      int pos = i.second;
	      if( pos + ( 1 << maxId ) <= l1 )
		{
		  hV hashValue;
		  hashHV( i.first, h1[pos][maxId], hashValue );
		  if( hash2.find( hashValue ) != hash2.end() )
		    {
		      m1.push_back( make_pair( hashValue, 
					       pos + ( 1 << maxId ) ) );
		      matchedHash2.insert( hashValue );
		    }
		}
	    }
	  if( !m1.empty() )
	    {
	      matched1.swap(m1);
	      for( auto i = matched2.begin(); 
		   i != matched2.end(); )
		{
		  if( i->second + ( 1 << maxId ) <= l2 )
		    {
		      hV hashValue;
		      hashHV( i->first, h2[ i->second ][maxId], hashValue );
		      if( matchedHash2.find( hashValue ) == matchedHash2.end() )
			{
			  auto ii = i++;
			  matched2.erase(ii);
			}
		      else
			{
			  i->first = hashValue;
			  i->second += 1 << maxId;
			  ++i;
			}
		    }
		  else
		    {
		      auto ii = i++;
		      matched2.erase(ii);
		    }
		}
	      ans += 1 << maxId;
	    }
	}
      int ansPos = l2 + 1;
      hV hashValue;
      for( auto i : matched2 )
	if( ansPos > i.second )
	  ansPos = i.second, hashValue = i.first;
      int posIn1;
      for( auto i : matched1 )
      	if( hashValue == i.first )
      	  {
      	    posIn1 = i.second;
      	    break;
      	  }
      // for( int i = posIn1 - 1, j = ansPos - 1, k = 0; k < ans; ++k )
      // 	if( s1[i - k] != s2[j - k] )
      // 	  return 1;
      s1[ posIn1 ] = '\0';
      cout << ( s1 + posIn1 - ans ) << endl;
      s2[ ansPos ] = '\0';
      printf("%s\n%d", s2 + ansPos - ans, ans );
    }
  else printf("0");
  return 0;
}
