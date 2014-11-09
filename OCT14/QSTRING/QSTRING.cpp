#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

typedef long long ll;

char str[N];

int rnk[N][20];
ll count[N];
int seq[N];
int height[N];
int bet[N];
ll lSeq[N];

int main()
{
  scanf("%s%d", str);

  int n(0);
  for (; str[n]; ++n)
    {
      ++count[str[n] - 'a'];
      rnk[n][0] = str[n] - 'a';
    }
  int maxCnt = 'z' - 'a';
  for (int i = 1; i <= maxCnt; ++i)
    {
      count[i] += count[i - 1];
    }

  int maxI(0);;
  for (int i = 1; (1 << i) <= n; ++i)
    {
      maxI = i;
      for (int j = n - 1; j >= 0; --j)
        {
          int idx = --count[rnk[j][i - 1]];
          seq[idx] = j;
        }

      for (int j = 0; j <= maxCnt; ++j)
        {
          count[j] = 0;
        }

      maxCnt = 0;
      rnk[seq[0]][i] = 0;
      for (int j = 1; j < n; ++j)
        {
          int idx = seq[j];
          int preIdx = seq[j - 1];

          bool eq = false;
          if (rnk[idx][i - 1] == rnk[preIdx][i - 1])
            {
              idx += (1 << (i - 1));
              preIdx += (1 << (i - 1));
              if ((idx >= n && preIdx >= n) ||
                  (idx < n && preIdx <n && 
                   rnk[idx][i - 1] == rnk[preIdx][i - 1]))
                {
                  eq = true;
                }
            }

          idx = seq[j];
          if (eq)
            {
              rnk[idx][i] = maxCnt;
            }
          else
            {
              rnk[idx][i] = ++maxCnt;
            }
          ++count[maxCnt];
        }

      for (int j = 1; j <= maxCnt; ++j)
        {
          count[j] += count[j - 1];
        }
    }

  for (int i = n - 1; i >= 0; --i)
    {
      seq[--count[rnk[i][maxI]]] = i;
    }

  for (int i = 0, preH = 0; i < n; ++i)
    {
      int r = rnk[i][maxI];

      if (r > 0)
        {
          int preRIdx = seq[r - 1];
          int h = max(0, preH - 1);
          preRIdx += h;
          int idx = i + h;
          for (; preRIdx < n && idx < n && str[preRIdx] == str[idx];
               ++preRIdx, ++idx, ++h)
            ;
          height[i] = preH = h;
        }
      else
        {
          height[i] = 0;
        }
    }

  memset(count, 0, sizeof(count));

  for (int i = n - 1; i >= 0; --i)
    {
      int idx = seq[i];
      ++count[i];

      if (i > 0)
        {
          int preIdx = seq[i - 1];
          if (height[i] == preIdx + 1)
            {
              count[i - 1] += count[i];
              bet[i] = idx - preIdx - 1;
            }
          else
            {
              bet[i] = idx;
            }
        }
    }

  for (int i = 1; i < n; ++i)
    {
      int idx = seq[i];

      lSeq[i] = lSeq[i - 1] + count[i] * bet[i] + count[i - 1];
    }

  int m;
  scanf("%d", &m);

  for (int i = 0; i < m; ++i)
    {
      static char cmd[10];
      scanf("%s", cmd);

      if (cmd[0] == 'R')
        {
          int l, r;
          scanf("%d%d", &l, &r);

        }
    }
  return 0;
}
