#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>

using namespace std;

typedef long long ll;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)

int N, M;

vector <vector <int> > gl;

bool can_add(int l, vector<int> &rest)
{
  for (int g:gl[l]) {
    if (find(rest.begin(), rest.end(), g) != rest.end()) {
      return false;
    }
  }
  return true;
}

void calc_comb(vector<int> rest, ll& sum)
{
  if (rest.empty()) {
    sum++;
    return;
  }

  REP(i, rest.size()) {
    if (can_add(rest[i], rest)) {
      vector<int> t_rest = rest;
      t_rest.erase(t_rest.begin() + i);
      calc_comb(t_rest, sum);
    }
    
  }
}

int main()
{
  cin >> N >> M;

  gl.resize(N + 1);
  REP(i, M) {
    int g, l;
    cin >> g >> l;
    gl[l].push_back(g);
  }

  vector<int> rest;
  REP(i, N) rest.push_back(i + 1);

  ll ans = 0;
  calc_comb(rest, ans);
  cout << ans << endl;
}