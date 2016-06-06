#include <iostream>
#include <algorithm>

using namespace std;

int main(){

  int a, b ,n;
  cin >> a >> b >> n;

  int larger = max(a, b);
  int lower = min(a, b);

  int ans = larger * (n / larger);

  if ( (n % larger) != 0) {
    ans += larger;
  }

  while(true) {
    if (ans % lower == 0) {
      break;
    }
      ans += larger;
  }

  cout << ans << endl;
}