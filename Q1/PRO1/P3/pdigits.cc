#include <iostream>
using namespace std;

int main () {
    int n, cont, prod = 1;
    
    while (cin >> n){
        if (n < 10) {
            cout << "El producte dels digits de " << n << " es " << n << "." << endl;
    }else {
        while (n >= 10){
            cont = n;
            while (n > 10){
                prod = prod * (n % 10);
                n = n / 10;
            }
            cout << "El producte dels digits de " << cont << " es " << prod << "." << endl;
            n = prod;
            prod = 1;
        }
    }
    cout << "----------" << endl;
    }
}
