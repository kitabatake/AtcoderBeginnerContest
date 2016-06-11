#include <vector>
#include <iostream>
#include "./vector_ex.cpp"

using namespace std;

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