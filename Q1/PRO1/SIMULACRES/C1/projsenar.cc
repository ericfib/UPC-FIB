#include <iostream>
using namespace std;

int extract_odd_digits(int x) {
   while (cin >> x) {
       int cont = 0, dig;
       cont += 1;
       dig = x%10;
       x = x/10;
}
}

int main() {
    int N;
    int suma = 0;
    while (cin >> N) {
        suma += extract_odd_digits(N);
    }
    cout << suma << endl;
}
