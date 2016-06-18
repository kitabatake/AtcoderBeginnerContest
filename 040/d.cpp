#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}

struct Route {
  int from;
  int to;
  int created;
};

ostream &operator << (ostream &os, Route const &r) {
  return os << r.to << ":" << r.created;
}

struct Town {
  int no;
  vector<Route> routes;
};

vector<Town> towns;

int reach_town_num (Town t, int year, vector<bool> &reached) {
  int count = 1;
  for (Route r:t.routes) {

    if (!reached[r.to] && r.created >= year) {
      reached[r.to] = true;
      count += reach_town_num(towns[r.to], year, reached);
    }
  }

  return count;
}



int main() {

  int N, M, Q;
  cin >> N >> M;
  towns.resize(N);

  for (int i = 0; i < N; i++) towns[i].no = i;

  int a, b, y;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> y;
    towns[a - 1].routes.push_back({a - 1, b - 1, y});
    towns[b - 1].routes.push_back({b - 1, a - 1, y});
  }

  cin >> Q;
  vector<int> ans(Q);
  for (int i = 0; i < Q; i++) {
    int v, w;
    cin >> v >> w;

    vector<bool> reached(N, false);
    reached[v - 1] = true;
    ans[i] = reach_town_num(towns[v - 1], w + 1, reached);
    
  }

  for (int a:ans) cout << a << endl;

}