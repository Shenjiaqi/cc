#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
    {
      int rgb[3], m;
      scanf("%d%d%d%d", rgb, rgb + 1, rgb + 2, &m);

      int mxRgb[3];
      for (int j = 0; j < 3; ++j)
        {
          mxRgb[j] = 0;

          for (int k = 0; k < rgb[j]; ++k)
            {
              int val;
              scanf("%d", &val);

              mxRgb[j] = max( mxRgb[j], val);
            }
        }

      int f = 0, l = max( max( mxRgb[0], mxRgb[1]), mxRgb[2]);
      for (; f <= l;)
        {
          int mid = ((ll)f + l) / 2;

          int leftM = m;
          for (int j = 0; leftM >= 0 && j < 3; ++j)
            {
              for (int k = mxRgb[j]; leftM >= 0 && k > mid; k >>= 1)
                {
                  --leftM;
                }
            }
          
          if (leftM >= 0 )
            {
              l = mid - 1;
            }
          else
            {
              f = mid + 1;
            }
        }
      
      printf("%d\n", f);
    }

  return 0;
}
