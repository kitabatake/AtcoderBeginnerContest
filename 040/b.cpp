#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = INT_MAX;
  for (int w = 1; w <= n; w++) {
    int h = n / w;
    int rest = n % w;
    ans = min(abs(w - h) + rest, ans);
  }

  cout << ans << endl;
}