#include <iostream>
using namespace std;

void canvi_binari(int x){
    if (x < 2) cout << x;
    else {
        canvi_binari(x/2);
        cout << x%2;
    }
}
void canvi_octa(int x){
     if (x < 8) cout << x;
     else {
        canvi_octa(x/8);
        cout << x%8;
    }
}
void canvi_hexa (int x){
      if (x >= 16){
        canvi_hexa (x/16);
      }
        if (x%16 == 10) cout << 'A';
        else if (x%16 == 11) cout << 'B';
        else if (x%16 == 12) cout << 'C';
        else if (x%16 == 13) cout << 'D';
        else if (x%16 == 14) cout << 'E';
        else if (x%16 == 15) cout << 'F';
        else cout << x%16;
      }


int main () {
    int x;
    while (cin >> x){
      cout << x << " = ";
      canvi_binari(x);
      cout << ", ";
      canvi_octa(x);
      cout << ", ";
      canvi_hexa(x);
      cout << endl;
    }
}
