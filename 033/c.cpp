#include <iostream>
#include <vector>

using namespace std;

int main(){
  string S;
  cin >> S;

  for (int i = 1; i < S.size(); i+=2) {
    if (S[i] == '*') {
      if (S[i - 1] == '0' || S[i + 1] == '0') {
        S.erase(S.begin() + i, S.begin() + i + 2);
        S[i-1] = '0';
      }
      else {
        S.erase(S.begin() + i, S.begin() + i + 2);
        S[i-1] = '1';
      }
      i -= 2;
    }
  }

  int ans = 0;
  for(int i = 0; i < S.size(); i+=2) {
    if (S[i] != '0') ans++;
  }

  cout << ans << endl;
}