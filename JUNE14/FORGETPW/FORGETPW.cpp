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
const int L = 1000007;
char s[L];
char ans[L];
char mp[300];
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0 ; t < T ; ++t )
    {
      int n;
      scanf("%d", &n);
      for( int i = 0; i < 300; ++i )
	mp[i] = i;
      for( int i = 0; i < n; ++i )
	{
	  char c, p;
	  scanf("\n%c %c", &c, &p);
	  mp[c] = p;
	}
      scanf("%s", s);
      bool del = true, dot = false;
      int cnt(0);
      int lstNotZ(0);
      for( int i = 0 ; s[i]; ++i )
	{
	  if( mp[ s[i] ] != '0' )
	    {
	      del = false;
	      if( mp[ s[i] ] == '.' )
		dot = true;
	    }
	  else if( del )
	    {
	      continue;
	    }
	  if( !dot || ( mp[s[i]] != '0' && mp[s[i]] != '.' ) )
	    {
	      lstNotZ = cnt;
	    }
	  ans[cnt] = mp[s[i]];
	  ++cnt;
	}
      ans[cnt] = 0;
      if( dot )
	{
	  ans[ lstNotZ + 1 ] = 0;
	}
      if( ans[0] == 0 ||
	  ( ans[0] == '.' && ans[1] == 0 ) )
	printf("0\n");
      else
	printf("%s\n", ans);
    }
  return 0;
}
