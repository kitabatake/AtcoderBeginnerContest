#include <iostream>

using namespace std;

int main(){
  int x, y;
  cin >> x >> y;

  if (x < y) cout << "Better";
  if (x > y) cout << "Worse";
  cout << endl;
}