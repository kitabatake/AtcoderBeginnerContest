#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

template<typename T> void debug_vector (vector<T> v) {
  for (int i = 0, s = v.size(); i < s; i++) {
    cout << v[i];
    if (i < s - 1) cout << "\t"; else cout << endl;
  }
}



class Box {
public:
  int width;
  int height;
  vector<Box> children;
  Box(int width, int height) {
    this->width = width;
    this->height = height;
  }

  bool can_include(Box target) {
    return target.width < this->width && target.height < this->height;
  }

  void insert(Box &target) {
    bool inserted = false;
    for (auto it = this->children.begin(); it != this->children.end();) {
      Box &child = *it;
      if (target.can_include(child)) {
        target.insert(child);
        it = this->children.erase(it);
        continue;
      }
      if (child.can_include(target)) {
        child.insert(target);
        inserted = true;
      }
      it++;
    }

    if (!inserted) {
      this->children.push_back(target);
    }
  }

  int length() {
    int length = 0;
    for (Box child:this->children) {
      length = max(1 + child.length(), length);
    }
    return length;
  }
};


bool operator>(const Box &box1, const Box &box2) {
  return (box1.width + box1.height) > (box2.width + box2.height);
}

ostream &operator << (ostream &os, Box const &box) {
  return os << box.width << ":" << box.height;
}

int main(){
  int N;
  cin >> N;

  vector<Box> boxes;

  Box container {INT_MAX, INT_MAX};
  for (int i = 0; i < N; i++) {
   int w, h;
   cin >> w >> h;
   Box b {w, h};
   boxes.push_back(b);
  }

  sort(boxes.begin(), boxes.end(), greater<Box>());
  for (Box &box:boxes) {
    container.insert(box);
  }

  cout << container.length() << endl;
}

