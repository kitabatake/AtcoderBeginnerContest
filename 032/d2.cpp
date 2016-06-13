#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> baggage_t;
typedef baggage_t wv_pair;

ll N, W;
vector<baggage_t> baggages;

ll v_dp(){
  vector<vector<ll> > dp(2, vector<ll>(W + 1, 0));
  for (int n = 0; n < N; n++) {
    int c = n % 2, p = 1 - n % 2;
    ll cv = baggages[n].first, cw = baggages[n].second;

    for (ll w = 0; w <= W - cw; w++) dp[c][w] = dp[p][w];
    for (ll w = 0; w <= W - cw; w++) {
      dp[c][w + cw] = max(dp[p][w + cw], dp[p][w] + cv);
    }
  }

  return dp[(N-1) % 2][W];
}

ll w_dp(ll sum_v){
  ll ll_max = numeric_limits<ll>::max();
  vector<vector<ll> > dp(2, vector<ll>(sum_v + 1, ll_max));
  for (int n = 0; n < N; n++) {
    int c = n % 2, p = 1 - n % 2;
    ll cv = baggages[n].first, cw = baggages[n].second;
    dp[p][0] = 0;
    for (ll v = 0; v <= sum_v; v++) dp[c][v] = dp[p][v];
    for (ll v = 0; v <= sum_v; v++) {
      if (dp[p][v] != ll_max && (dp[p][v] + cw) <= W) {
        dp[c][v + cv] = min(dp[p][v + cv], dp[p][v] + cw);
      }
    }
  }

  ll ans = 0;
  for (ll v = 0; v <= sum_v; v++) 
    if (dp[(N - 1) % 2][v] != ll_max) ans = v;
  return ans;
}

ll divide_calc() {
  // 前半部分のデータを集計
  vector<wv_pair> first_wv;
  for (vector<int> comb: all_combinations(N / 2)) {
    ll sum_w = 0, sum_v = 0;
    for (int i : comb) {
      sum_v += baggages[i].first;
      sum_w += baggages[i].second;
    }

    if (sum_w <= W)
      first_wv.push_back(make_pair(W - sum_w, sum_v));
  }

  // 後半向けに、後半の使用Wに対する最大のVを表すように整理
  first_wv.push_back(make_pair(W, 0LL));
  sort(first_wv.begin(), first_wv.end());
  for (int i = first_wv.size() - 2; i >= 0; i--) {
    first_wv[i].second = max(first_wv[i + 1].second, first_wv[i].second);
  }
  
  // 後半の組み合わせ集計値と、上記で整理した値を組み合わせ、最大値を算出
  ll ans = first_wv[0].second;
  for (vector<int> comb: all_combinations(N - N / 2)) {
    ll sum_w = 0, sum_v = 0;
    for (int i : comb) {
      sum_v += baggages[i + N / 2].first;
      sum_w += baggages[i + N / 2].second;
    }

    if (sum_w <= W) {
      int first_index = lower_bound(first_wv.begin(), first_wv.end(), make_pair(sum_w, 0LL)) - first_wv.begin();
      ans = max(sum_v + first_wv[first_index].second, ans);
    }
  }

  return ans;
}

int main(){
  
  cin >> N >> W;
  baggages = vector<baggage_t>(N);
  ll sum_v = 0;
  for (int i = 0; i < N; i++) {
    cin >> baggages[i].first >> baggages[i].second;
    sum_v += baggages[i].first;
  }

  ll ans;
  if (N <= 30) ans = divide_calc();
  else if (W <= 200000) ans = v_dp();
  else ans = w_dp(sum_v);
  cout << ans << endl;
}
