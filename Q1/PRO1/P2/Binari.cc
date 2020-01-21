#include <iostream>
using namespace std;

int main () {
    int n,b;
    cin >> n;
    
    while ((n > 1)) {
        b = n%2;
        cout << b;
        n = n/2;
    }
    cout << n << endl;
}
