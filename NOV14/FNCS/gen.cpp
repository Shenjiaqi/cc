#include <iostream>

using namespace std;

int N = 3;
int Q = 30;

int main()
{
  srand(20);

  cout << N << endl;

  for (int i = 0 ;i < N; ++i)
    {
      cout << (1 + (rand() % 1000000000)) << endl;
    }

  for (int i = 0; i < N; ++i)
    {
      int from((rand() % N) + 1), to((rand() % N) + 1);
      if (from > to)
	{
	  swap(from, to);
	}

      cout << from << ' ' << to << endl;
    }

  cout << Q << endl;
  for (int i = 0; i < Q; ++i)
    {
      int type = (1 + (rand() % 2));

      int a, b;
      if (type == 1)
	{
	  a = (rand() % N) + 1;
	  b = rand() % 1000000000;
	}
      else
	{
	  b = (rand() % N) + 1;
	  a = (rand() % b) + 1;
	}

      cout << type << ' ' << a << ' ' << b << endl;
    }

  return 0;
}
