#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;

  for(int i = 1; i < s.size(); i++) {
    if (s[0] != s[i]) {
      cout << "DIFFERENT";
      break;
    }
    if (i == s.size() - 1) {
      cout << "SAME";
    }
  }

  cout << endl;
}