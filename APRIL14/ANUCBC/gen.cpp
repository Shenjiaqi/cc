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
  int T = 1;
  cout << T << endl;
  for( int i = 0; i < T; ++i )
    {
      int n = 10000;
      int q = 3;
      cout << n << ' ' << q << endl;
      for( int j = 0; j < n; ++j )
	cout << ( rand() % 1000000000 ) << ' ';
      cout << endl;
      for( int j = 0; j < q; ++j )
	cout << ( 1 + ( rand() % 100 ) ) << ' ';
      cout << endl;
    }
  return 0;
}
