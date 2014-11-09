#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T = 30;
  cout << T << endl;
  for( int i = 0 ; i < T ; ++i )
    {
      cout << 9;
      for( int j = 0 ; j < 9; ++j )
	cout << (rand() % 10);
      cout << ' ' << ( ( rand() % 100000 ) + 1 ) << endl;
    }
  return 0;
}
