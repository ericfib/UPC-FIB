#include <iostream>
using namespace std;

int main () {
  int a, b, cont = 0, long1, long2;
  string previ, seguent;
  cin >> a >> b;
  cin >> previ;
  while (cin >> seguent){
    long1 = previ.length ();
    long2 = seguent.length();
    if (long1%a == 0 and long2%b == 0) cont++;
    previ = seguent;
  }
  cout << cont << endl;
}
