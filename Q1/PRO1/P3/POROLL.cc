#include <iostream>
using namespace std;

int main () {
    int n, xf = 0, a = 0, b = 0;
    
    cin >> n;
    
    for (int i = n; i != 0; i = i/10) ++xf;
    if (xf % 2 != 0 or n == 0) cout << "res" << endl;
    else {
        xf = xf/2;
        for (int j = 0; j != xf; ++j){
            a += (n%10);
            n /= 10;
        }
        for (int k = 0; k != xf; ++k){
            b += (n%10);
            n /= 10;
        }
    if (a > b) cout << b << " < " << a << endl;
    else if (a < b) cout << b << " > " << a << endl;
    else if (a == b) cout << b << " = " << a << endl;
    }
    
}
