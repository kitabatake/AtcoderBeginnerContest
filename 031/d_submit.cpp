#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;

struct SampleData {
  string nums;
  string words;
};

vector< SampleData > sample_data;
typedef map<char, string> ref_t;


void input_process(){
  cin >> K >> N;
  sample_data.resize(N);
  for (int i = 0; i < N; i++) {
    string v, w;
    cin >> v >> w;
    sample_data[i] = {v, w};
  }
}

void debug_ref (ref_t ref)
{
  for (const auto &iter:ref) {
    cout << iter.first << ":" << iter.second << " ";
  }
}

void debug_refs (vector<ref_t>refs) {
  for (ref_t ref: refs) {
    debug_ref(ref);
    cout << endl;
  }
}



SampleData erase_referenced_chars(SampleData data, ref_t ref)
{
  SampleData erased = data;
  for (int n = 0; n < data.nums.size(); n++) {
    char c = data.nums[n];
    if (ref[c].size()) {
      if (erased.nums.find(c) != -1 && erased.words.find(ref[c]) != -1) {
        erased.nums.erase(erased.nums.find(c), 1);
        erased.words.erase(erased.words.find(ref[c]), ref[c].size());
      }
      else {
        // transform explicity invalid reference
        return {data.nums, ""};
      }
    }
  }

  return erased;
}

/**
 * make valid reference by nums and words pair.
 * make all possibly inference and stack valid reference.
 */
void make_valid_refs(string nums, string words, ref_t ref, vector<ref_t> &valid_refs)
{
  if (nums.empty() && words.empty()) {
    valid_refs.push_back(ref);
    return;
  }

  if (nums.empty() || words.empty()) return;

  for (int i = 1; i <= 3; i++) {

    if (words.size() < i) break;
    string tmp_w = words;
    ref_t tmp_ref = ref;
    tmp_ref[nums[0]] = tmp_w.substr(0, i);
    tmp_w.erase(0, i);
    make_valid_refs(nums.substr(1), tmp_w, tmp_ref, valid_refs);
  }
}

void infer(int n, ref_t ref, vector<ref_t> &valid_refs)
{
  if (n == N) {
    valid_refs.push_back(ref);
    return;
  }

  SampleData data = sample_data[n];
  data = erase_referenced_chars(data, ref);
  
  vector<ref_t> refs;
  make_valid_refs(data.nums, data.words, ref, refs);

  for (ref_t r: refs) {
    infer(n + 1, r, valid_refs);
  }
}


int main(){
  input_process();
  vector<ref_t> valid_refs;
  infer(0, {}, valid_refs);

  sort(valid_refs.begin(), valid_refs.end());

  if (!valid_refs.empty()) {
    for (auto &ref: valid_refs[0]) {
      cout << ref.second << endl;
    }
  }
  
}