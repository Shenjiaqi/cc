#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

struct ele
{
  int primeVal;
  int times;
  int primeMulTimes;
};

int p[N];
vector<ele> primeCount[N];

int addM(int a, int b, int mod)
{
  a += b;
  return a >= mod ? a - mod : a;
}

int mulM(ll a, ll b, int mod)
{
  a *= b;
  return a >= mod ? (a % mod) : a;
}

int powM(int a, ll b, int mod)
{
  int ans(1);

  for (; b; b >>= 1)
    {
      if (b & 1)
	{
	  ans = mulM(ans, a, mod);
	}

      a = mulM(a, a, mod);
    }

  return ans;
}

void eGcd(int a, int b, ll& x, ll& y)
{
  if (b == 1)
    {
      x = 0, y = 1;
      return ;
    }

  eGcd(b, a % b, y, x);
  y -= (a / b) * x;
}

int revM(int a, int mod)
{
  ll x, y;
  eGcd(a, mod, x, y);

  if (x < 0)
    {
      x = (mod + (x % mod));
    }

  return x >= mod ? x % mod : x;
}

void cal(int n, int mod)
{

  unordered_map<int, ll> mapp;

  for (int i(1), prePartAns(1); i * 2 <= n; ++i)
    {
      int mulNum(1);
      for (auto j: primeCount[n - i + 1])
	{
	  int primeNum = j.primeVal;
	  int times = j.times * (n - i + 1);
	  int primeNumTimes = j.primeMulTimes;

	  if (mod % primeNum)
	    {
	      mulNum *= primeNumTimes;
	    }
	  else
	    {
	      mapp[primeNum] += times;
	    }
	}
      mulNum = powM(mulNum, n - i + 1, mod);
      
      int divNum(1);
      for (auto j: primeCount[i])
	{
	  int primeNum = j.primeVal;
	  int times = j.times * i;
	  int primeMulTimes = j.primeMulTimes;
	  
	  if (mod % primeNum)
	    {
	      divNum *= primeMulTimes;
	    }
	  else
	    {
	      mapp[primeNum] -= times;
	    }
	}
      divNum = powM(divNum, i, mod);

      prePartAns = mulM(mulM(prePartAns, mulNum, mod), revM(divNum, mod), mod);

      p[i] = prePartAns;
      for (auto j: mapp)
	{
	  int primeNum = j.first;
	  ll times = j.second;

	  p[i] = mulM(p[i], powM(primeNum, times, mod), mod);
	}
    }
}

int main()
{
  // for each n, precalculate all prime x, which can devide n
  // and how many times
  for (int i = 2; i < N; ++i)
    {
      if (primeCount[i].empty())
	{
	  for (int j = i; j < N; j += i)
	    {
	      int num(0);
	      int val(1);
	      for (int tmpJ(j); tmpJ >= i && (tmpJ % i) == 0; tmpJ /= i)
		{
		  ++num;
		  val *= i;
		}

	      primeCount[j].push_back(ele{i, num, val});
	    }
	}
    }

  int T;
  scanf("%d", &T);

  for (; T; --T)
    {
      int n, m, q;
      scanf("%d%d%d", &n, &m, &q);

      cal(n, m);

      for (int i = 0; i < q; ++i)
	{
	  int r;
	  scanf("%d", &r);

	  printf("%d\n", p[min(r, n - r)]);
	}
    }

  return 0;
}
