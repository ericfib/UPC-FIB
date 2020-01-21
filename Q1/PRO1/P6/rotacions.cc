#include <iostream>
using namespace std;

int rotacio_dreta(int x, int k){
  int exp = 1;
  for (int i = x; i > 9; i/=10){
    exp*=10;
  }
  for (int j = 0; j < k; j++){
    x = x/10 + exp*(x%10);
  }
  return x;
}

int main () {
  int x, k;
  while (cin >> x >> k){
    cout << rotacio_dreta(x, k) << endl;
  }
}
