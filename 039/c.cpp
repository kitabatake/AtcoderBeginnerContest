#include <iostream>
#include <vector>

using namespace std;

int main(){
  string s;
  cin >> s;

  vector<string> pattern {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La" , "Si"};

  int firstWW = s.find("WW");
  int i;

  // if first WW is MiFa
  if (s.find("WW", firstWW + 1) - firstWW == 7) {
    i = 4 - firstWW;
  }
  // if first WW is SiDo
  else {
    i = 11 -firstWW;
  }
  if (i < 0) i = pattern.size() - 1 + i;

  cout << pattern[i] << endl;
}