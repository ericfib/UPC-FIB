#include <iostream>
#include <math.h>
using namespace std;

void escriu_barres (int n){
  if (n != 0){
    escriu_barres (n-1);
    for (int i = 0; i != n; i++){
      cout << '*';
    }cout << endl;
    escriu_barres (n - 1);
  }
}
int main () {
    int c;
    cin >> c;
    escriu_barres (c);


}
