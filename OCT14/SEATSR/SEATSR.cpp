#include <bits/stdc++.h>

using namespace std;

const int S = 100007;
const int W = 100007;

const int inf = 101;

char s[S], w[W];

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
    {
      int a, b, limK;
      scanf("\n%s\n%s\n%d%d%d", s, w, &a, &b, &limK);

      int ls = strlen(s);
      int lw = strlen(w);

      if (a == 0)
        {
          printf("%d\n", 0);
        }
      else if(abs(ls - lw) * a > limK)
        {
          printf("-1\n");
        }
      else
        {
          const int off = 200;
          int dp[2][2 * off + 1];
          int f, t;
          f = 0, t = 1;

          int minV = - (limK - (lw - ls));
          int maxV = limK + (lw - ls);
          for (int j = 0; j <= maxV; ++j)
            {
              dp[f][j + off] = j * a;
            }

          bool cnt = true;
          for (int j = 0; cnt && j < ls; ++j)
            {
              cnt = false;
              for (int k = max( minV, -j);
                   k <= min( maxV, lw - 1 - j); ++k)
                {
                  if (j + k == 0)
                    {
                      dp[t][k + off] = j * a + (s[j] == w[j + k] ? 0 : b);
                    }
                  else
                    {
                      dp[t][k + off] = dp[f][k + off] + 
                        (s[j] == w[j + k] ? 0 : b);
                    }

                  if (k + 1 <= min( maxV, lw - 1 - (j - 1)))
                    {
                      dp[t][k + off] = min(dp[t][k + off], 
                                           dp[f][k + 1 + off] + a);
                    }

                  if (k - 1 >= max( minV, -j))
                    {
                      dp[t][k + off] = min(dp[t][k + off],
                                           dp[t][k + off - 1] + a);
                    }

                  dp[t][k + off] = min( dp[t][k + off], inf);

                  if (dp[t][k + off] <= limK)
                    {
                      cnt = true;
                    }
                }

              swap( f, t);
            }
          
          int ans = inf;

          if (cnt)
            {
              for (int j = max( minV, -(ls - 1)); j <= min( maxV, lw - ls); ++j)
                {
                  ans = min( ans, dp[f][j + off] + (lw - (ls + j)) * a);
                }
            }

          printf("%d\n", (ans <= limK ? ans : -1));
        }
    }

  return 0;
}
