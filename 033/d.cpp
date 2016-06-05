#include <iostream>
#include <vector>
#include <math.h> 
#include <float.h>

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

vector<vector<int> >dots;

int acute = 0, obtuse = 0, right_angle = 0;
double calcDistance(vector<int> from, vector<int> to) {
  return sqrt(pow(to[0] - from[0], 2) + pow(to[1] - from[1], 2) );
}

void inspect(vector< vector<int> > dots){
  for (int i = 0; i < 3; i++) {
    vector< vector<int> > others = dots;
    vector<int> target = dots[i];
    others.erase(others.begin() + i);

    double a = calcDistance(others[0], others[1]);
    double b = calcDistance(target, others[0]);
    double c = calcDistance(target, others[1]);
    double cosTarget = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);

    cout << cosTarget << endl;

    if (fabs(cosTarget) < DBL_EPSILON) {
      right_angle++;
      return;
    }
    else if (cosTarget < 0) {
      obtuse++;
      return;
    }
  }

  acute++;
}



void combination(vector<int> array, int k, vector<int> com){
  if (k == 0) {
    debug_vector(com);
    inspect(
      {
        dots[com[0]],
        dots[com[1]],
        dots[com[2]]
      }
    );
    return;
  }

  k--;
  vector<int> tmp_combination;
  int selection;
  while (array.size() > 0) {
    tmp_combination = com;
    selection = array[0];
    tmp_combination.push_back(selection);
    array.erase(array.begin());
    combination(array, k, tmp_combination);
  }
}








int main(){

  int N;
  cin >> N;

  dots = vector< vector<int> > (N);
  vector<int> indexes(N);
  for (int i = 0; i < N; i++) {
    indexes[i] = i;
    int x, y;
    cin >> x >> y;
    dots[i] = {x, y};
  }



  combination(indexes, 3, {});
  cout << acute << " " << right_angle << " " << obtuse << endl;
}
