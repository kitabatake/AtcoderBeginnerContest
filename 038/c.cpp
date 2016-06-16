#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  ll inclease = 0;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    inclease++;
    if (i == N - 1 || a[i] >= a[i + 1]) {
      for (ll j = inclease; j > 0; j--) ans += j;
      inclease = 0;
    }
  }

  cout << ans << endl;
}