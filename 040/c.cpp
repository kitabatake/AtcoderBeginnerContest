#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  vector<int> dp(N);
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  for (int i = 2; i < N; i++) {
    dp[i] = min(
      dp[i - 2] + abs(a[i - 2] - a[i]),
      dp[i - 1] + abs(a[i - 1] - a[i])
    );
  }

  cout << dp[N - 1] << endl;
}