#include <iostream>
#include <vector>
#include <numeric>  

using namespace std;
typedef long long ll;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);

  for (int i = 0; i < N; i++) cin >> a[i];

  // しゃくとり法. 部分文字列の開始点をsとし、sが0の時の和をあらかじめ計算する。
  // s > 0 の和の計算を 一つ前の和から - a[s-1] + a[s + k] とすることで、計算量を減らす。
  ll partial_sum = accumulate(a.begin(), a.begin() + K, 0); 
  ll total_sum = partial_sum;
  
  for (int s = 1; s < N - K + 1; s++) {
    partial_sum = partial_sum - a[s - 1] + a[s + K - 1];
    total_sum += partial_sum;
  }

  cout << total_sum << endl;
}