#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
int H, W;
vector< vector<int> > a;
vector< vector<int> > routes_cache;

ll calc_routes (int h, int w) {

  if (routes_cache[h][w] != -1) return routes_cache[h][w];

  ll routes = 1;
  vector<int> dw = {0, 1, 0, -1};
  vector<int> dh = {1, 0, -1, 0};

  for (int i = 0; i < 4; i++) {
    int th = h + dh[i], tw = w + dw[i];
    if (tw < 0 || tw >= W || th < 0 || th >= H) continue; // out of grid.
    if (a[h][w] < a[th][tw]) {
      routes += calc_routes(th, tw);
      routes %= mod;
    }
  }

  routes_cache[h][w] = routes;
  return routes;
}

int main(){
  cin >> H >> W;
  a = vector< vector<int> > (H, vector<int>(W));
  routes_cache = vector< vector<int> > (H, vector<int>(W, -1));
  for (int h = 0; h < H; h++) 
    for (int w = 0; w < W; w++)
      cin >> a[h][w];

  ll total_routes = 0;
  for (int h = 0; h < H; h++) 
    for (int w = 0; w < W; w++)
      total_routes += calc_routes(h, w);

  cout << total_routes % mod << endl;
}