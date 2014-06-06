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
const int N = 1e6 + 7;
char s[N];
int main()
{
  ios::sync_with_stdio(false);

  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t )
    {
      scanf("%s", s);
      int ans(0), left(0);
      for( int i = 0, cnt = 0; s[i]; ++i )
	{
	  if( s[i] == '<' )
	    ++left, ++cnt;
	  else
	    {
	      --left;
	      if( left < 0 )
		break;
	      else if( left == 0 )
		ans += cnt * 2, cnt = 0;
	    }
	}
      printf("%d\n", ans);
    }
  return 0;
}
