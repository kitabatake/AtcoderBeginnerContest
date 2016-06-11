#include <iostream>
#include <vector>

using namespace std;
typedef  long long ll;


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

template<typename T> vector<T> operator+(const vector<T>& base, const vector<T>& add) {
  vector<T> ret = base;
  ret.insert(ret.end(), add.begin(), add.end());
  return ret;
}

/* this means nC1 ... nCn. 
 * order is pow(2, n)
 */
vector< vector<int> > all_combinations(int num) {
  vector< vector<int> > base;
  vector< vector<int> > all;

  for (int i = 0; i < num; i++) {

    vector<int> pure{i};
    all.push_back(pure);
    for (vector<int> base_item: base) {
      vector<int> add{i};
      all.push_back(base_item + add);
    }

    base = all;
  }

  return all;
}




int N, W;

void lowW(vector< pair<int, ll> > bagages){

  vector< vector<ll> >dp(2, vector<ll>(W + 1, 0));
  for(int n = 1; n <= N; n++) {

    int p = 1 - n % 2;
    int c = n % 2;

    int c_v = bagages[n-1].first;
    ll c_w = bagages[n-1].second;

    for (int w = 0; w <= W; w++) {
      if (bagages[n-1].second > w) {
        dp[c][w] = dp[p][w];
        continue;
      }

      dp[c][w + c_w] = max(
        dp[c][w + c_w],
        dp[c][w] + c_v
      );

      dp[c][w] = max(
        dp[p][w],
        dp[p][w - bagages[n-1].second] + bagages[n-1].first
      );
    }
  }

  cout << dp[N % 2][W] << endl;
}



#define W_MAX LLONG_MAX

void lowV(vector< pair<int, ll> > bagages, ll max_v){

  vector< vector<ll> >dp(N +1, vector<ll>(N * max_v + 1, W_MAX));
  
  for(int n = 1; n <= N; n++) {

    int p = 1 - n % 2;
    int c = n % 2;

    int c_v = bagages[n-1].first;
    ll c_w = bagages[n-1].second;

    dp[p][0] = 0;
    for (int v = 0; v <= N * max_v; v++) {

      if (dp[p][v] != W_MAX )  {

        if ((dp[p][v] + c_w) <= W) {
          dp[c][v + c_v] = min(
            dp[p][v + c_v],
            dp[p][v]+ c_w
          );
        }

        dp[c][v] = min(dp[c][v], dp[p][v]);
      }
      
    }
  }

  ll ans = 0;
  for (ll v = 0; v < N * max_v; v++) {
    if (dp[N%2][v] != W_MAX) {
      ans = max(ans, v);
    }
  }

  cout << ans << endl;
}

void lowN(vector< pair<int, ll> > bagages) {

  vector< vector<int> > all = all_combinations(N);

  int max = 0;

  for (vector<int> com: all) {
    int w_sum = 0, v_sum = 0;
    for (int i:com) {
      w_sum += bagages[i].second;
      v_sum += bagages[i].first;
    }

    if (w_sum <= W && v_sum > max) {
      max = v_sum;
    }
  }

  cout << max << endl;
}

int main(){
  cin >> N >> W;
  vector< pair<int, ll> > bagages(N);
  int max_v = 0;
  for (int i = 0; i < N; i++) {
    int v, w;
    cin >> v >> w;
    bagages[i] = pair<int, ll>(v, w);
    max_v = max(v, max_v);
  }

  if (N <= 30) {
    lowN(bagages);
  }
  else if (W < 200000) {
    lowW(bagages);
  }
  else if (max_v * N < 200000) {
    lowV(bagages, max_v);
  }
}