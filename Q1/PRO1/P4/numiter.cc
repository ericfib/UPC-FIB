#include <iostream>
using namespace std;

int nombre_digits(int n) {
    int cont = 0;
    if (n == 0) cont = 1;
    else {
         for (int i = 0; n != 0; i++){
        n /= 10;
        cont++;
        }
    }
   
    return cont;
}



int main () {
    int n;
    cin >> n;
    
    cout << nombre_digits (n) << endl;
}
