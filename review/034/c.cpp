/* 
 * (h, w) までの経路は, (h -1, w)までの経路足す、(h, w-1)までの経路。
 */
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int W, H;
const int mod = 1000000007;
vector< vector<ll> > routes_memo;

int main(){
  cin >> W >> H;
  routes_memo = vector< vector<ll> >(H, vector<ll>(W, -1));
  routes_memo[0][0] = 1;
  for (int w = 1; w < W; w++) routes_memo[0][w] = 1;
  for (int h = 1; h < H; h++) routes_memo[h][0] = 1;
  for (int h = 1; h < H; h++) {
    for (int w = 1; w < W; w++) {
      routes_memo[h][w] = (routes_memo[h - 1][w] + routes_memo[h][w - 1]) % mod;
    }
  }
  cout << routes_memo[H - 1][W - 1] << endl;
}