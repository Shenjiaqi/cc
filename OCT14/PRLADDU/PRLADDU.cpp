#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
    {
      int n;
      scanf("%d", &n);

      ll ans(0);

      for (int j = 0, k = 0; j < n; ++j)
        {
          ans += abs(k);

          int d;
          scanf("%d", &d);

          k += d;
        }

      printf("%lld\n", ans);
    }

  return 0;
}
