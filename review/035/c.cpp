#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;

  // ひっくり返し作業の開始点と終了点をメモする。（ひっくり返し作業の圧縮:いもす法）
  vector<int> operation_compression(N + 1);
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    operation_compression[l - 1]++;
    operation_compression[r]--;
  }

  // 上記のメモから各点の状態を再現する
  int operation_restoration = 0;
  for (int i = 0; i < N; i++) {
    operation_restoration += operation_compression[i];
    cout << operation_restoration % 2;
  }

  cout << endl;
}