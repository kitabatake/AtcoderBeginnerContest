#include <iostream>
#include <vector>

using namespace std;

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


int main(){
  int W, H;
  cin >> W >> H;
  vector< vector<int> > dp(H, vector<int>(W, 1));

  for (int h = 1; h < H; h++){
    for (int w = 1; w < W; w++){
      dp[h][w] = (dp[h][w - 1] + dp[h - 1][w]) % 1000000007;
    }
  }

  // debug_2vector(dp);
  cout << dp[H - 1][W - 1] % 1000000007 << endl;
}