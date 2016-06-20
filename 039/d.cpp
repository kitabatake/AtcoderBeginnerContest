#include <iostream>
#include <vector>

using namespace std;

vector< vector<char> > contractioned;

vector<int> dx {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> dy {1, 1, 1, 0, 0, -1, -1, -1};

int H, W;

bool can_expansion(int h, int w) {

  if (contractioned[h][w] == '.') return false;
  
  char t;
  for (int i = 0; i < 8; i++) {
    int th = h + dy[i];
    int tw = w + dx[i];
    if (th < 0 || th >= H || tw < 0 || tw >= W) continue;
    t = contractioned[th][tw];
    if (t == '.') return false;
  }

  return true;
}

void clear(int h, int w,  vector< vector<char> > &image) {
  for (int i = 0; i < 8; i++) {
    int th = h + dy[i];
    int tw = w + dx[i];
    if (th < 0 || th >= H || tw < 0 || tw >= W) continue;
    image[th][tw] = '.';
  }
  image[h][w] = '.';
}

int main(){
  cin >> H >> W;
  contractioned = vector< vector<char> > (H, vector<char>(W)); 
  char c;
  for (int h = 0; h < H; h++)
    for (int w = 0; w < W; w++)
      cin >> contractioned[h][w];

  vector< vector<char> > ans (H, vector<char>(W, '.'));
  vector< vector<char> > check_possible = contractioned;

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (can_expansion(h, w)) {
        clear(h, w, check_possible);
        ans[h][w] = '#';
      }
    }
  }

  bool possible = true;
  for (int h = 0; h < H; h++)
    for (int w = 0; w < W; w++)
      if (check_possible[h][w] == '#')
        possible = false;

  if (possible) {
    cout << "possible" << endl;
    for (int h = 0; h < H; h++) {
      for (int w = 0; w < W; w++) {
        cout << ans[h][w];
      }
      cout << endl;
    }
  }
  else {
    cout << "impossible" << endl;
  }
} 