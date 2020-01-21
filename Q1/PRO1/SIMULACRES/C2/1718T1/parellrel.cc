#include <iostream>
using namespace std;

int main () {
  int n, primer,segon, cont = 1;

  cin >> primer >> segon;
  for (int i = 1; cin >> n; i++){
    if (i%2==0){
      if (n == segon) cont++;
    }
  }
  cout << cont << endl;
}
