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
const int A = 1e5;
const int G = A;
const int M = A;
int main()
{
  int n, m;
  n = 5000, m = 2000;
  srand( 190 );
  cout << n << ' ' << m << endl;
  int pri[] = { 911, 461, 383, 71, 23, 911, 317, 797, 47, 641 };
  int num = sizeof( pri ) / sizeof( pri[0] );
  for( int i = 0; i < n ; ++i )
    // cout << ( ( rand() % 100 ) + 1 ) * ( pri[ rand() % num ] )  << ' ';
    cout << ( rand() % A ) + 1 << ' ';
  cout << endl;
  for( int i = 0; i < m ; ++i )
    {
      int g = ( rand() % G ) + 1;
      // int g = pri[ rand() % num ] * ( ( rand() % 100 ) + 1 );
      int x = ( rand() % n ) + 1;
      int y;
      if( x == n )
	y = x;
      else y = ( rand() % ( n - x ) ) + x ;
      cout << g << ' ' << x << ' ' << y << endl;
    }
  return 0;
}
