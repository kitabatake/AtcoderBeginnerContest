#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}



#define MAX_H 100000

struct Box {
  int width;
  int height;
};

bool operator<(const Box &b1, const Box &b2) {
  if (b1.width == b2.width) return b1.height > b2.height; // if width equals, sort height greter.
  return b1.width < b2.width;
}

ostream &operator << (ostream &os, Box const &box) {
  return os << box.width << ":" << box.height;
}


template<typename T>
class SegmentTree {
private:
  vector<T> v;
  int v_size;
  int bottom_size;
public:
  SegmentTree (int max_size)
  {
    v_size = 2;
    bottom_size = 1;
    while (bottom_size < max_size) {
      bottom_size *= 2;
      v_size += bottom_size;
    }
    this->v = vector<T>(v_size);
  }
  T max (int height = -1)
  {
    if (height == -1) height = bottom_size;
    return search_max(0, height, 1, 0, bottom_size - 1);
  }

  T search_max (int target_l, int target_r, int i, int search_l, int search_r)
  {
    if (target_l <= search_l && target_r >= search_r) return v[i]; // if search range between target range, return segmented value.
    if (search_l == search_r) return v[i];

    T max = 0;
    int c = (search_l + search_r) / 2;
    if (target_r > c) {
      max = std::max(search_max(target_l, target_r, i * 2 + 1, c + 1, search_r), max);
    }
    if (target_l <= c) {
      max = std::max(search_max(target_l, target_r, i * 2, search_l, c), max);
    }

    return max;
  }

  T get(int i)
  {
    return v[bottom_size + i];
  }

  void update(int height, int num)
  {
    int i = bottom_size + height;
    while (i > 0) {
      v[i] = num;
      if (num < v[i / 2]) break;
      i /= 2;
    }
  }

  void output() {
    int i = 1, lf = 1;
    for (int i = 0; i < v_size; i++) {
      cout << v[i];
      if (i == lf) {
        cout << endl;
        lf = lf * 2 + 1;
      }
      else {
        cout << "\t";
      }
    }
    cout << endl;
  }
};

int main(){
 
  int N;
  cin >> N;
  vector<Box> boxes(N);
  int w, h;
  for (int i = 0; i < N;i ++) {
    cin >> w >> h;
    boxes[i] = {w, h};
  }
  sort(boxes.begin(), boxes.end());

  SegmentTree<int> st {MAX_H};

  for(int i = 0; i < N; i++) {
    int max_num = st.max(boxes[i].height - 1) + 1;
    if (max_num > st.get(boxes[i].height)) {
      st.update(boxes[i].height, max_num);
    }
  }

  cout << st.max() << endl;
}