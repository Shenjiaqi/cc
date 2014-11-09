#include <bits/stdc++.h>

using namespace std;

const int A = 107;

int a[A];

int main()
{
  int T;
  scanf("%d", &T);
  
  for (int i = 0; i < T; ++i)
    {
      int n, m;
      scanf("%d%d", &n, &m);

      int maxA = 0;
      for (int j = 0; j < n; ++j)
        {
          scanf("%d", a + j);
          maxA = max(maxA, a[j]);
        }

      for (int j = 0; j < n && m >= 0; ++j)
        {
          m -= maxA - a[j];
        }

      printf("%s\n", ((m >= 0 && (m % n) == 0) ? "Yes" : "No"));
    }
  
  return 0;
}
