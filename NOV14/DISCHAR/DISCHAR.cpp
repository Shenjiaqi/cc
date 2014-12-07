#include <cstdio>

const int N = 1e5 + 7;
char s[N];

int main()
{
  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      scanf("%s", s);

      int count['z' - 'a' + 1] = {0};

      int ans(0);
      for (int i = 0; s[i]; ++i)
	{
	  if (count[s[i] - 'a'] == 0)
	    {
	      ++ans;
	    }
	  ++count[s[i] - 'a'];
	}

      printf("%d\n", ans);
    }

  return 0;
}
