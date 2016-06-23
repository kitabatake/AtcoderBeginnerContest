#include <iostream>
#include <vector>

using namespace std;

int main(){
  int L, H, N;
  cin >> L >> H >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) {
    if (a[i] > H) cout << -1 << endl;
    else if (a[i] >= L && a[i] <= H) cout << 0 << endl;
    else cout << L - a[i] << endl;
  }
}