#include "./d_inc.cpp"

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