#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<float, long> bin;

int main(){
  int K, N;
  cin >> N >> K;

  priority_queue<bin, vector<bin>, less<bin> > pq;

  long w;
  int p;
  for (int i = 0; i < N; i++) {
    cin >> w >> p;
    pq.push({p, w}); 
  }

  float p_sum = 0, w_sum = 0;
  for(int i = 0; i < K; i++){
    bin tmp = pq.top(); pq.pop();
    p_sum += ((float)tmp.second / 100) * tmp.first;
    w_sum += tmp.second;
  }

  cout << endl << p_sum << ", " << w_sum << endl;

  cout << (p_sum / w_sum) * 100 << endl;
}