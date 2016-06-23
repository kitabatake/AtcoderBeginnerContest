#include "./d_inc.cpp"
#include <cassert>

int main(){

  // test erase_referenced_chars;
  SampleData data {"356", "migoro"};

  SampleData erased = erase_referenced_chars(
    data,
    {
      {'3', "mi"}
    }
  );
  assert(erased.nums == "56");
  assert(erased.words == "goro");


  erased = erase_referenced_chars(
    data,
    {
      {'3', "hugagagaga"}
    }
  );
  assert(erased.nums == "");
  assert(erased.words == "migoro");


  // test infer
  vector<ref_t> valid_refs;
  make_valid_refs("356", "migoro", {}, valid_refs);
  assert(valid_refs.size() == 7);

  for (ref_t ref: valid_refs) {
    for (const auto &iter:ref) {
      cout << iter.first << ":" << iter.second << " ";
    }
    cout << endl;
  }

}