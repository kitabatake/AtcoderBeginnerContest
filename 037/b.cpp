#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, q, s, e, t; 
  cin >> n >> q;

  vector<int> v(n);
  for (int i = 0; i < q; i++) {
    cin >> s >> e >> t;
    for (int j = s - 1; j < e; j++) {
      v[j] = t;
    }
  }

  for (int i :v) {
    cout << i << endl;
  }
}