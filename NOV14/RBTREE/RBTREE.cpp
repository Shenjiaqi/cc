#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

char cmd[7];

int bitLen(ll v)
{
  int len(0);

  for (; v; v >>= 1)
    {
      ++len;
    }

  return len;
}

int main()
{
  int Q;
  scanf("%d", &Q);

  for (bool rootBlack(true); Q; --Q)
    {
      scanf("%s", cmd);

      if (cmd[1] == 'i')
	{
	  rootBlack = !rootBlack;
	}
      else
	{
	  int x, y;
	  scanf("%d%d", &x, &y);

	  int lx = bitLen(x), ly = bitLen(y);
	  int redCount(0), allCount(0);

	  for (; x != y;)
	    {
	      if (x > y)
		{
		  if (lx & 1)
		    {}
		  else
		    {
		      ++redCount;
		    }
		  ++allCount;
		  --lx;
		  x >>= 1;
		}
	      else
		{
		  if (ly & 1)
		    {}
		  else
		  {
		    ++redCount;
		  }
		  ++allCount;
		  --ly;
		  y >>= 1;
		}
	    }

	  // x == y, lx == ly
	  ++allCount;
	  if (lx & 1)
	    {}
	  else
	    {
	      ++redCount;
	    }

	  if (!rootBlack)
	    {
	      redCount = allCount - redCount;
	    }

	  printf("%d\n", cmd[1] == 'r' ? redCount : allCount - redCount);
	}
    }

  return 0;
}
