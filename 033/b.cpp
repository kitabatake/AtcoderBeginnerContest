#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;

  float max = 0, sum = 0;
  string max_name;

  int tmp;
  string tmp_name;
  for (int i = 0; i < N; i++) {
    cin >> tmp_name >> tmp;
    if (tmp > max) {
      max = tmp;
      max_name = tmp_name;
    }
    sum += tmp;
  }

  if ((max / sum) > 0.5) {
    cout << max_name;
  }
  else {
    cout << "atcoder";
  }
  cout << endl;
}