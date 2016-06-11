
using namespace std;

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



