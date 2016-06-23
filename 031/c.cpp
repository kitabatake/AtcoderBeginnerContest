#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  int t_max = INT_MIN, partial_t_max, partial_a_max;
  for (int t = 0; t < N; t++) {
    partial_a_max = INT_MIN;
    partial_t_max = INT_MIN;
    for (int a = 0; a < N; a++) {
      if (a == t) continue;
      int s = min(t, a);
      int e = max(t, a);
      vector<int> sum(2);
      for (int i = 0; i <= e - s; i++) {
        sum[i % 2] += S[s + i];
      }

      if (sum[1] > partial_a_max) {
        partial_a_max = sum[1];
        partial_t_max = sum[0];
      }
    }

    if (partial_t_max > t_max) {
      t_max = partial_t_max;
    }
  }

  cout << t_max << endl;
}