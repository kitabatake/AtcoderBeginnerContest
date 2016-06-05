#include <iostream>
#include <vector>

using namespace std;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}


void hoge(vector<int> tmp){
  tmp.erase(tmp.begin());
}
int main(){

  vector<int> v{1, 3, 4};

  hoge(v);

  debug_vector(v);
}