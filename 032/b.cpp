#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  map<string, bool> memo;
  string s;
  int k;
  cin >> s >> k;

  k = min((int)s.size(), k);

  for (int i = 0; i < s.size() - k + 1; i++) {
    memo[s.substr(i, k)] = true;
  }

  cout << memo.size() << endl;
}