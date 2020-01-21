#include <math.h>
#include <iostream>
#include <vector>

using namespace std;


int misteri (int n) {
  if (n == 1) return 1;
  return misteri(n-1) + 2*n - 1;
}


int main () {
  int n = 5;

  cout << misteri(n) << endl;
}
