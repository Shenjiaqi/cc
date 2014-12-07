#include <cstdio>
#include <string.h>

const int N = 1e5 + 7;
char s[N];

bool check(int a, int b)
{
  for (; a < b; ++a, --b)
    {
      if (s[a] != s[b])
	{
	  return false;
	}
    }
  return true;
}

int main()
{
  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      scanf("%s", s);

      int len = strlen(s);
      
      bool ok = true;
      for (int i = 0, j = len - 1; i < j; ++i, --j)
	{
	  if (s[i] != s[j])
	    {
	      if (!check(i + 1, j) && !check(i, j - 1))
		{
		  ok = false;
		}
	      break;
	    }
	}
      
      printf("%s\n", ok ? "YES" : "NO");
    }

  return 0;
}
