#include <iostream>
#include <cassert>
#include <vector>

#include "./vector_ex.cpp"

using namespace std;



void test_additional_operator() {

  vector<int> base {1 , 4};
  vector<int> add {3, 5};
  vector<int> expected {1, 4, 3, 5};

  assert(base + add == expected);
}

int main(){

  test_additional_operator();
}