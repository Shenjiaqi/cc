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
//#include <unordered_set>
//#include <unordered_map>
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
bool vis[1000007];
int main()
{
  vector<int> p;
  for( int i = 2; i < 1000; ++i )
    if( !vis[i] )
      {
	p.push_back(i);
	for( int j = i * i; j < 1000; j += i )
	  vis[j] = true;
      }
  int T = 10;
  cout << T << endl;
  for( int i = 0 ; i < T ; ++i )
    {
      int n = 400;
      cout << n << endl;
      for( int j = 0 ; j < 2; ++j )
	{
	  for( int k = 0 ; k < n ; ++k )
	    {
	      ll val = 1;
	      for( int l = 0 ; l < 10 ; ++l )
		{
		  ll tmp = p[ rand() % (int)p.size() ];
		  if( val * tmp <= 1e9 )
		    val *= tmp;
		}
	      cout << val << ' ' ;
	    }
	  cout << endl;
	}
    }
  return 0;
}
