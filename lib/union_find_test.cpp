#include <iostream>
#include <cassert>
#include "./union_find.cpp"

int main(){
  UnionFind<int> uf{5};

  assert(uf.find(0) == 1);

  uf.connect(0, 1);
  assert(uf.find(0) == 2);

  uf.connect(0, 1);
  uf.connect(1, 0);
  assert(uf.find(0) == 2);

  uf.connect(2, 3);
  uf.connect(3, 4);
  assert(uf.find(2) == 3);

  uf.connect(0, 4);
  assert(uf.find(1) == 5);
} 