#include <bits/stdc++.h>
using namespace std;
const int Q = 1e5 + 7;
int c[Q][5];

int main()
{
  int n;
  scanf("%d", &n);
  map<int,int> mapp;
  for( int i = 0 ; i < n ; ++i )
    {
      char cmd;
      scanf("\n%c", &cmd);
      c[i] = cmd;
      if( cmd == 'D' )
	scanf("%d", &c[i][1] );
      else
	{
	  scanf("%d%d%d%d", &c[i][1], &c[i][2], &c[i][3], &c[i][4] );
	  for( int j = 0 ; j < 4 ; ++j )
	    mapp[ c[i][j + 1] ] = 0;
	}
    }
  int cnt(0);
  for( auto i : mapp )
    i.second = ++cnt;
  for( int i = 0 ; i < n ; ++i )
    {
    }
}
