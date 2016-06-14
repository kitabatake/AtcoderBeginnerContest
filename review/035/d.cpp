/*
 * 複数の街に滞在する形は最善にはならない。(効率の良い街1つに滞在するのがベスト)
 * 効率の良い街を見つけ、そこで稼げる額を求める。
 * 1番目のから各街への行き、帰りそれぞれの最短所要時間を調べ、Tから効率の良い街を判別する
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Route {
  int cost;
  int from;
  int to;
};

struct Town {
  int earnings;
  vector<Route> going_routes;
  vector<Route> return_routes;
  ll going_cost;
  ll return_cost;
};

typedef pair<ll, int> pq_item; // <towns[0]からの所要時間, town index>

vector<Town> towns;
vector<Route> routes;

int main(){
  int N, M, T;
  cin >> N >> M >> T;

  towns = vector<Town>(N);
  routes = vector<Route>(M);

  int earnings;
  for (int i = 0; i < N; i++) {
    cin >> earnings;
    towns[i] = {earnings, {}, {}, -1, -1};
  }

  int cost, from, to;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;
    towns[from - 1].going_routes.push_back({cost, from - 1, to - 1});
    towns[to - 1].return_routes.push_back({cost, to - 1, from - 1});
  }

  // 行き道の最短所要時間
  priority_queue<pq_item, vector<pq_item>, greater<pq_item> > pq;
  pq_item item;
  pq.push({0, 0});
  while (!pq.empty()) {
    item = pq.top(); pq.pop();
    ll cost = item.first;
    Town &town = towns[item.second];
    if (town.going_cost != -1) continue; // 既に歳たん所要時間が決まっている
    town.going_cost = cost;
    for (Route route : town.going_routes) {
      pq.push(make_pair(cost + route.cost, route.to));
    }
  }

  // もどり道の最短所要時間
  pq.push({0, 0});
  while (!pq.empty()) {
    item = pq.top(); pq.pop();
    ll cost = item.first;
    Town &town = towns[item.second];
    if (town.return_cost != -1) continue; // 既に最短所要時間が決まっている
    town.return_cost = cost;
    for (Route route : town.return_routes) {
      pq.push(make_pair(cost + route.cost, route.to));
    }
  }

  // calc max earnings
  ll max_earnings = 0;
  for (Town town: towns) {
    max_earnings = max<long long>((T - town.going_cost - town.return_cost) * town.earnings, max_earnings);
  }

  cout << max_earnings << endl;
}