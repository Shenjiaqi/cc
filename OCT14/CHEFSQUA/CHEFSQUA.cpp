#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll encode(int x, int y)
{
  x += 1e6, y += 1e6;
  return (((ll)x) << 30) | y;
}

int main()
{
  int n;
  scanf("%d", &n);

  unordered_set<ll> sett;

  typedef pair<int,int> point;
  vector<point> p;
  p.resize(n);

  for (int i = 0; i < n; ++i)
    {
      int x, y;
      scanf("%d%d", &x, &y);

      p[i].first =x, p[i].second = y;
      sett.insert(encode(x, y));
    }

  if (n == 0)
    {
      printf("4");
    }
  else if(n == 1)
    {
      printf("3");
    }
  else
    {
      sort(p.begin(), p.end());

      bool t0, t1;
      t0 = t1 = false;

      for (int i = 0; !t0 && i < n; ++i)
        {
          for (int j = i + 1; !t0 && j < n; ++j)
            {
              if (p[i].first == p[j].first)
                {
                  int x = p[i].first;
                  int y0 = p[i].second, y1 = p[j].second;
                  int d = abs(y0 - y1);

                  for (int k = -d; k <= d; k += 2 * d)
                    {
                      int cornerCnt(0);

                      if (sett.find(encode(x + k, y0)) != sett.end())
                        {
                          ++cornerCnt;
                        }
                      if (sett.find(encode(x + k, y1)) != sett.end())
                        {
                          ++cornerCnt;
                        }

                      if (cornerCnt > 0)
                        {
                          t1 = true;
                          if (cornerCnt > 1)
                            {
                              t0 = true;
                            }
                        }
                    }
                }
            }
        }

      if (t0)
        {
          printf("0");
        }
      else if(t1)
        {
          printf("1");
        }
      else printf("2");
    }
  return 0;
}
