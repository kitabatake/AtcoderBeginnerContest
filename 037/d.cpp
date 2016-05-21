#include <iostream>
#include <vector>

using namespace std;

typedef long l;
const int mod = 1000000007;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}

template<typename T> void debug_2vector (vector< vector<T> > v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    debug_vector(v[i]);
    cout << "\n";
  }
}

vector< vector<l> > nodes;
vector< vector<l> > dp;

l rec(int h, int w){

  // cout << h << ", " << w << endl;
  if (dp[h][w] != 0) {
    return dp[h][w];
  }

  vector <int> dx {0, 1, 0, -1};
  vector <int> dy {-1, 0, 1, 0};

  int r = 1;
  for (int i = 0; i < 4; i++) {
    if (nodes[h + 1][w + 1] < nodes[1 + h + dy[i]][1 + w + dx[i]]) {
      // cout << "call: " << h + dy[i] << ", " << w +dx[i] << endl;
      r += rec(h + dy[i], w + dx[i]);
      r %= mod;
    }
  }

  dp[h][w] = r;

  return r;
}

int main(){
  int H, W;
  cin >> H >> W;
  
  nodes = vector< vector<l> >(H + 2, vector<l>(W + 2, 0));
  for (int h = 0; h < H; h++){
    for (int w = 0; w < W; w++){
      l tmp;
      cin >> tmp;
      nodes[h + 1][w + 1] = tmp;
    }
  }

  dp = vector< vector<l> > (H, vector<l>(W, 0));
  for (int h = 0; h < H; h++){
    for (int w = 0; w < W; w++){
      dp[h][w] = rec(h, w);
    }
  }

  l sum = 0;
  for (vector<l> row: dp) {
    for (l n: row) {
      sum += n;
      sum %= mod;
    }
  }

  cout << sum % mod << endl;
}

