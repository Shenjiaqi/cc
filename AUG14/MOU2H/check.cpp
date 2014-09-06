#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
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
#include <unordered_set>
#include <unordered_map>
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
int main()
{
  int T;
  scanf("%d", &T);
  for( ; T ; --T )
    {
      int n;
      scanf("%d", &n);
      vector<int> cc;
      map<int,int> mapp;
      for( int i = 0, pre = 0; i < n ; ++i )
	{
	  int v;
	  scanf("%d", &v);
	  if( i > 0 )
	    {
	      cc.push_back( v - pre );
	      mapp[ v - pre ] = 0;
	    }
	  pre = v;
	}
      int ccc = 0;
      for( auto &i : mapp )
	i.second = ++ccc;
      unordered_set<ll> sett0, sett1;
      unordered_set<int> ap;
      unordered_map<int,int> pa;
      int cnt(0);
      for( int i = 0; i < cc.size() ; ++i )
	{
	  int v = mapp[ cc[i] ];
	  if( ap.find( v ) == ap.end() )
	    {
	      vector<int> tmp;
	      for( auto i : sett0 )
		tmp.push_back(i);
	      for( auto i : tmp )
		sett0.insert( i * 10 + v);
	      sett0.insert(v);
	      tmp.resize(0);
	      for( auto i : sett1 )
		tmp.push_back(i);
	      for( auto i : tmp )
		sett1.insert( i * 10 + v );
	      ap.insert(v);
	    }
	  else
	    {
	      vector<int> tmp, tt;
	      for( auto i : sett0 )
		tmp.push_back(i);
	      for( auto i : tmp )
		{
		  ll val = i * 10 + v;
		  if( sett0.find(val) != sett0.end() )
		    {
		      sett0.erase(val);
		      tt.push_back(val);
		    }
		  else
		    {
		      sett0.insert(val);
		    }
		}
	      if( sett0.find(v) != sett0.end() )
		{
		  sett0.erase(v);
		  tt.push_back(v);
		}
	      for( auto i : sett1 )
		{
		  ll val = i * 10 + v;
		  tt.push_back( val );
		}
	      for( auto i : tt )
		{
		  sett1.insert(i);
		  if( sett0.find(i) != sett0.end() )
		    sett0.erase(i);
		}
	    }
	  cout << sett0.size() << ' ' << sett1.size() << endl;
	  // if( i == 3 )
	  //   {
	  //     for( auto i : sett0 )
	  // 	{
	  // 	  cout << i << ' ';
	  // 	}
	  //     cout << endl;
	  //     for( auto i : sett1 )
	  // 	{
	  // 	  cout << i << ' ';
	  // 	}
	  //     cout << endl;
	  //   }
	}
      printf("%d", (int)( sett0.size() + sett1.size() ) ) ;
    }
  return 0;
}
