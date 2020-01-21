#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int b, n;
    
   while (cin >> b >> n){
        int c = 0;
        while (n > 0){
            n = n / b;
            c++;
        }
        cout << c << endl;
    }
}
