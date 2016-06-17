#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
  int width;
  int height;
};

bool operator<(const Box &b1, const Box &b2) {
  return b1.width < b2.width;
}

ostream &operator << (ostream &os, Box const &box) {
  return os << box.width << ":" << box.height;
}

int main(){
  int N;
  cin >> N;
  vector<Box> boxes(N);
  int w, h;
  for (int i = 0; i < N;i ++) {
    cin >> w >> h;
    boxes[i] = {w, h};
  }

  sort(boxes.begin(), boxes.end());
  
  vector<int> dp(N);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int max_num = 1;
    for (int j = 0; j < i; j++) {
      if (boxes[i].width > boxes[j].width && boxes[i].height > boxes[j].height) {
        max_num = max(dp[j] + 1, max_num);
      }
    }
    dp[i] = max_num;
    ans = max(max_num, ans);
  }

  cout << ans << endl;
}