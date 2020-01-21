#include <iostream>
using namespace std;

int main() {
    int x;
    while (cin >> x) {
        int prod = 1;
        if (x < 10) cout << "El producte dels digits de " << x << " es " << x << "." << endl;
        else {
            while (x >= 10) {
                int tmp = x;
                while (x > 0) {  
                    prod *= x % 10;
                    x /= 10;
                }
                cout << "El producte dels digits de " << tmp << " es " << prod << "." << endl;
                x = prod;
                prod = 1;
            }
        }
        cout << "----------" << endl;
    }
}
