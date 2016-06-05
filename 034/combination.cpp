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

void rec(int k, vector<string> currents, vector<string> rests, vector< vector<string> > &buf) {

  if (k == 0) {
    buf.push_back(currents);
    return;
  }

  k--;
  vector<string> n_currents = currents;
  vector<string> n_rests = rests;

  for (int i = 0; i < rests.size(); i++) {
    n_currents = currents;
    n_currents.push_back(n_rests[0]);
    n_rests.erase(n_rests.begin());

    rec(k, n_currents, n_rests, buf);
  }
}

int main(){
  vector<string> strs;
  int N, K;
  string c;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> c;
    strs.push_back(c);
  }

  

  vector< vector<string> > combinations;



  rec(K, {}, strs, combinations);

  cout << endl << combinations.size() << endl;
  debug_2vector(combinations);
}