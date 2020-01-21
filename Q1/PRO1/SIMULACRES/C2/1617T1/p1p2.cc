#include <iostream>
using namespace std;

int trobar (int n1, int n2) {
  string previ, actual;
  int suma = 0;
  cin >> previ;
  for (int i = 0; cin >> actual; i++){
    if (previ.length() == n1 and actual.length() == n2) suma++;
    previ = actual;
  }
  return suma;
}

int main (){
  string p1, p2;
  cin >> p1 >> p2;
  int n1 = p1.length();
  int n2 = p2.length();
  cout << trobar(n1,n2) << endl;

}
