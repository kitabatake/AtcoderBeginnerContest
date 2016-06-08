#include <iostream>
#include <vector>

using namespace std;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}

typedef double ll;


int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == 0) {
      cout << n << endl;
      return 0;
    }
  }

  ll ruiseki = 1, length = 0;
  for (int i = 0; i < n; i++) {

    if (i != 0) {
      ruiseki /= s[i - 1];
    }
    
    while (true) {
      if ((i + length) >= s.size()) break;
      ruiseki *= s[i + length];
      if (ruiseki > k) break;
      length++;
    }
  }

  cout << length << endl;
}