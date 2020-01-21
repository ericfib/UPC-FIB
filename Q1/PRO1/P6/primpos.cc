#include <iostream>
using namespace std;

int main () {
  int n, cont = 1;
  bool trobat = false;
  while (not trobat and cin >> n){
    if (n%2 == 0) trobat = true;
    else cont++;
  }
  if (trobat) cout << cont << endl;
}
