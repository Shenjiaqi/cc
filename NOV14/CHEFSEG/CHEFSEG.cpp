#include <cstdio>
#include <iostream>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{
  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      int x;
      ll k;
      scanf("%d%lld", &x, &k);
      
      ll num(1);
      for (; num < k; num <<= 1)
	{
	  k -= num;
	}

      ld ans = (ld)k / (ld)num * (ld)x;
      ans -= (x) / (ld)num / 2.0;

      printf("%.7lf\n", (double)ans);
    }

  return 0;
}
