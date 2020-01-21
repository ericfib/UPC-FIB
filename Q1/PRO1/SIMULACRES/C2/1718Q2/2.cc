#include <iostream>
using namespace std;

int binary2octal(int n) {
  if (n/1000 == 0){
    if (n%1000 == 000) return 0;
    else if (n%1000 == 001) return 1;
    else if (n%1000 == 010) return 2;
    else if (n%1000 == 011) return 3;
    else if (n%1000 == 100) return 4;
    else if (n%1000 == 101) return 5;
    else if (n%1000 == 110) return 6;
    else return 7;
  }else {
    if (n%1000 == 000) return binary2octal(n/1000);
    else if (n%1000 == 001) return 1 + binary2octal(n/1000);
    else if (n%1000 == 010) return 2 + binary2octal(n/1000);
    else if (n%1000 == 011) return 3 + binary2octal(n/1000);
    else if (n%1000 == 100) return 4 + binary2octal(n/1000);
    else if (n%1000 == 101) return 5 + binary2octal(n/1000);
    else if (n%1000 == 110) return 6 + binary2octal(n/1000);
    else return 7 + binary2octal(n/1000);
  }
}

int main(){
    int n;
    while (cin >> n){
        cout  << n << " is equivalent to " << binary2octal(n);
        cout  << " in base 8" << endl;
    }
}
