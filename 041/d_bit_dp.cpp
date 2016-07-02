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

queue<q_item> qu;
vector<ll> dp;

vector <vector<int>> gl;

// nを末尾とした際に、restにnより後ろに来るようなものがあったらinvalid.
bool is_valid(int n, int front_mask)
{
  vector<int> lesses = gl[1 << n];
  REP(i, lesses.size()) {
    if (((front_mask >> lesses[i]) & 1) != 0)
      return false;
  }
  return true;
}


ll cumpute_dp(ll &current, vector<int> &rest)
{
  if (current == 0) return 1;
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    
    if (((current >> i) & 1) == 0) continue;
    int mask = current ^  (1 << i);
    if (!is_valid(i, mask)) continue;
    sum += dp[mask];
  }

  return sum;
}

void bfs(ll current, vector<int> rest)
{
  dp[current] = cumpute_dp(current, rest);

  if (rest.empty()) {
    return;
  }

  vector<int> tmp_rest = rest;
  REP(i, rest.size()) {
    ll tmp_current = current | (1 << rest[i]);
    tmp_rest.erase(tmp_rest.begin());
    qu.push({tmp_current, tmp_rest});
  }
}


int main()
{
  cin >> N >> M;
  vector<int> rest;
  dp.resize((1 << N));
  gl.resize(1 << N);

  REP(i, M) {
    int g, l;
    cin >> g >> l;
    gl[1 << (g - 1)].push_back(l - 1);
  }

  REP(i, N) rest.push_back(i);

  qu.push({0, rest});

  while(qu.size() > 0) {
    q_item qi = qu.front(); qu.pop();
    bfs(qi.current, qi.rest);
  }

  cout << dp[(1 << N) - 1] << endl;
}