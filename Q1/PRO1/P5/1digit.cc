#include <iostream>
using namespace std;

int suma_digits(int x){
    int suma = 0;
    if (x < 10) return x;
    else {
        while (x != 0){
        suma += x%10;
        x /= 10;
        }
        return suma_digits(suma);
    }
}
int reduccio_digits(int x){
    int redfin = x;
    while (redfin >= 10)  {
        redfin = suma_digits(redfin);
    }
    return redfin;
}

int main (){
    int x;
    while (cin >> x){
        cout << reduccio_digits(x) << endl;
    }
}
