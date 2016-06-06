#include <iostream>
#include <vector>

using namespace std;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}





typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> ruiseki(n + 1);
  ruiseki[0] = 1;
  int tmp  = 1;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    ruiseki[i + 1] = ruiseki[i] * tmp;
  }

  for (int ans  = n; ans > 0; ans--) {
    for (int i = ans - 1; i < n; i++) {
      if (ruiseki[i + 1] / ruiseki[i - ans + 1] <= k) {
        cout << ans << endl;
        return 0;
      }
   }
  }

  cout << 0 << endl;
}