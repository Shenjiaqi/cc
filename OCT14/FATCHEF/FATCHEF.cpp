#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int cMod = 1e9 + 9;

int mulMod(int a, int b)
{
  return ((ll)a * b) % cMod;
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
    {
      int n, m;
      scanf("%d%d", &n, &m);

      vector<pair<int, char> > p;
      p.resize(m);
      for (int j = 0; j < m; ++j)
        {
          scanf("\n%c %d", &p[j].second, &p[j].first);
        }

      sort(p.begin(), p.end());

      int ans(1);
      if (!p.empty())
        {
          for (int j = 1, prePos = p[0].first, preCol = p[0].second; j < m; ++j)
            {
              char col = p[j].second;
              int pos = p[j].first;
              if (col != preCol)
                {
                  ans = mulMod(ans, pos - prePos);
                }

              prePos = pos, preCol = col;
            }
        }

      printf("%d\n", ans);
    }

  return 0;
}
