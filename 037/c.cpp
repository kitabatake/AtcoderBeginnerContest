#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}

int main(){
  int N, K;
  cin >> N >> K;

  ll r = 0, t;
  vector<ll> ruiseki(N);
  for (int i = 0; i < N; i++) {
    cin >>t;
    r += t;
    ruiseki[i] = r;
  }

  // debug_vector(ruiseki);

  ll sum = 0;
  for (int i = 0; i < N - K + 1; i++) {
    if (i == 0) sum = ruiseki[K - 1];
    else {
      sum += ruiseki[i + K - 1] - ruiseki[i - 1];
    }
  }

  cout << sum << endl;
}