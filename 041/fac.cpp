#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>

using namespace std;

typedef long long ll;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)

ll factorial(int n)
{
  if (n == 1) return 1;
  else
    return  n * factorial(n - 1);

}

int main()
{
  cout << factorial(5) << endl;
}