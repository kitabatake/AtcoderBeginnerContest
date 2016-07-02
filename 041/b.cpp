#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>

using namespace std;

typedef long long ll;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)

#define MOD 1000000007

int main()
{
  ll A, B, C;
  cin >> A >> B >> C;

  ll ans = (A * B % MOD) * C;
  cout << ans % MOD << endl;
}