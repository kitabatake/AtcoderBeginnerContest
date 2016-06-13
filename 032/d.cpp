#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

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

void lowW(vector< pair<ll, ll> > bagages){

  vector< vector<ll> >dp(2, vector<ll>(W + 1, 0));
  for(int n = 1; n <= N; n++) {

    int p = 1 - n % 2;
    int c = n % 2;

    ll c_v = bagages[n-1].first;
    ll c_w = bagages[n-1].second;

    for (int w = 0; w <= W; w++) {
      if (c_w > w) {
        dp[c][w] = dp[p][w];
        continue;
      }

      dp[c][w] = max(
        dp[p][w],
        dp[p][w - c_w] + c_v
      );
    }
  }

  cout << dp[N % 2][W] << endl;
}



#define W_MAX numeric_limits<ll>::max()

void lowV(vector< pair<ll, ll> > bagages, ll max_v){

  vector< vector<ll> >dp(N +1, vector<ll>(N * max_v + 1, W_MAX));
  
  for(int n = 1; n <= N; n++) {

    int p = 1 - n % 2;
    int c = n % 2;

    ll c_v = bagages[n-1].first;
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

/* N = 30は大きすぎるため、二つに分割し、後半部分の各組み合わせの総和と残り重量を、前半部分のベストなw, vに整理したものから
 * 算出したvを足し合わせ、ベストな価値を算出する
 */
void lowN(vector< pair<ll, ll> > bagages) {

  // まずは前半部分の価値あるw, vのペアを抽出する
  vector< pair<ll, ll> > first;
  first.push_back(make_pair(0, 0));
  map<ll, ll> worth_checker; // 同じweightでvalueが低いものを省くためのmap
  vector< vector<int> > first_combinations = all_combinations(N / 2);
  for (vector<int> combination: first_combinations) {
    ll w_sum = 0; 
    ll v_sum = 0;
    for (int i: combination) {
      w_sum += bagages[i].second;
      v_sum += bagages[i].first;
    }

    if (w_sum <= W && v_sum > worth_checker[w_sum]) {
      worth_checker[w_sum] = v_sum;
      first.push_back(make_pair(w_sum, v_sum));
    }
  }

  // より低いweightでvaluableなものがない状態に整理
  sort(first.begin(), first.end());
  for (int i = 0; i < first.size(); i++) {
    if (i == 0) continue;
    first[i].second = max(first[i - 1].second, first[i].second);
  }

  // 後半部分を掲載したものに、前半部分で有効な組み合わせを足し合わせ、価値が高いものを判定
  ll ans = 0;
  vector< vector<int> > second_conbinations = all_combinations(N - N/2);
  for (vector<int> combination: second_conbinations) {
    ll w_sum = 0;
    ll v_sum = 0;
    for( int i: combination) {
      w_sum += bagages[N/2 + i].second;
      v_sum += bagages[N/2 + i].first;
    }

    if (w_sum <= W) {
      int additonal_first_index = lower_bound(first.begin(), first.end(), make_pair(W - w_sum, 0LL)) - first.begin() - 1;
      // W-w_sum の値のfirst[w]が丁度あった際にadditonal_first_indexをイクリメント
      while (first[additonal_first_index + 1].first == (W - w_sum)) {
        additonal_first_index++;
      }

      if (additonal_first_index > 0) {
        ans = max(v_sum + first[additonal_first_index].second, ans);
      } else {
        ans = max(v_sum, ans);
      }
    } 
  }

  cout << ans << endl;
}

int main(){
  cin >> N >> W;
  vector< pair<ll, ll> > bagages(N);
  ll max_v = 0;
  for (int i = 0; i < N; i++) {
    ll v, w;
    cin >> v >> w;
    bagages[i] = pair<ll, ll>(v, w);
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