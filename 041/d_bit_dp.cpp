#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>
#include <queue>

using namespace std;

typedef long long ll;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)


template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}

template<typename T> void debug_2vector (vector< vector<T> > v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << i << ":";
    debug_vector(v[i]);
    cout << "\n";
  }
}



int N, M;

struct q_item {
  ll current;
  vector<int> rest;
};

vector<ll> dp;

bool contain(int mask, int pos)
{
  return (mask & (1 << pos)) != 0;
}

vector<bool> valid;


int main()
{
  cin >> N >> M;
  vector<int> rest;
  dp.resize((1 << N));
  valid.resize(1 << N);

  vector<int> x(M), y(M);

  REP(i, M) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  REP(i, (1 << N)) {
    valid[i] = true;
    REP(m, M) {
      if (contain(i, y[m]) && !contain(i, x[m])) valid[i] = false;
    }
  }

  dp[0] = 1;
  for (int mask = 1; mask < (1 << N); mask++) {
    if (!valid[mask]) continue;
    ll sum = 0;
    REP(n, N) {
      if (!contain(mask, n)) continue;
      int sub_mask = mask ^ (1 << n);
      if (valid[sub_mask]) sum += dp[sub_mask];
    }
    
    dp[mask] = sum;
  }

  cout << dp[(1 << N) - 1] << endl;
}