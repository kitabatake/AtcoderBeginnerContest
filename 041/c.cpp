#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>

using namespace std;

typedef long long ll;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)



int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  map<int, int> b;
  REP(i, N) {
    cin >> a[i];
    b[a[i]] = i + 1;
  }
  sort(a.begin(), a.end(), greater<int>());

  REP(i, N) {
    cout << b[a[i]] << endl;
  }
}