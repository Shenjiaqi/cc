#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int p[107];
int main()
{
  int T = 3;
  cout << T << endl;
  srand(17);
  for( int i = 0;  i < T ; ++i )
    {
      int n = ( rand() % 100 ) + 1;
      ll k = ( rand() % ( 1 + ( n / 7 ) ) ) ;
      cout << n << ' ' << k << endl;
      for( int j = 0 ; j < n ; ++j )
	p[j] = j + 1;
      for( int j = 1 ; j < n ; ++j )
	swap( p[j], p[ rand() % j ]);
      for( int j = 0 ; j < n ; ++j )
	cout << p[j] << ' ';
      cout << endl;
    }
  return 0;
}
