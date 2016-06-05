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

/** Generic Programs **/

double calcDistance(vector<int> from, vector<int> to) {
  return sqrt(pow(to[0] - from[0], 2) + pow(to[1] - from[1], 2) );
}

double yogen(vector<int> A, vector<int> B, vector<int> C) {
  double a = calcDistance(B, C);
  double b = calcDistance(A, C);
  double c = calcDistance(A, B);
  return (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
}

void combination(vector<int> array, int k, vector<int> buff, vector< vector<int> >& com){
  if (k == 0) {
    com.push_back(buff);
    return;
  }

  k--;
  vector<int> tmp_combination;
  int selection;
  while (array.size() > 0) {
    tmp_combination = buff;
    selection = array[0];
    tmp_combination.push_back(selection);
    array.erase(array.begin());
    combination(array, k, tmp_combination, com);
  }
}



/** Specific Programs */

vector<vector<int> >dots;

int acute = 0, obtuse = 0, right_angle = 0;

void inspect_triangle(vector< vector<int> > dots){
  for (int i = 0; i < 3; i++) {
    double cosTarget = yogen(
      dots[i % 3], 
      dots[(i + 1) % 3],
      dots[(i + 2) % 3]
    );

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

  vector< vector<int> > combinations;
  combination(indexes, 3, {}, combinations);

  for (vector<int> com: combinations) {
    inspect_triangle(
      {
        dots[com[0]],
        dots[com[1]],
        dots[com[2]]
      }
    );
  }

  cout << acute << " " << right_angle << " " << obtuse << endl;
}
