#include <iostream>
#include <vector>

using namespace std;

int main(){
  string S;
  cin >> S;

  // 掛け算を処理していく。 0 か 0以外を区別できれば良いので、0以外には1を入れる。
  for (int i = 1; i < S.size(); i += 2) {
    if (S[i] == '+') continue;

    if (S[i - 1] == '0' || S[i + 1] == '0') {
      S.erase(i, 2);
      S[i - 1] = '0';
    } else {
      S.erase(i, 2);
      S[i - 1] = '1';
    }

    i -= 2;
  }

  int ans = 0;
  for (int i = 0; i < S.size(); i += 2) {
    if (S[i] != '0') ans++;
  }

  cout << ans << endl;
}