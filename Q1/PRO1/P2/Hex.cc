#include <iostream>
using namespace std;

int main () {
    int n,b;
    cin >> n;
    
    
    while ((n >= 16 )) {
        b = n%16;
        if (b == 10) cout << "A";
        else if (b == 11) cout << "B";
        else if (b == 12) cout << "C";
        else if (b == 13) cout << "D";
        else if (b == 14) cout << "E";
        else if (b == 15) cout << "F";
        else cout << b;
        n = n/16;
        
    }
    if (n == 10) cout << "A";
    else if (n == 11) cout << "B";
    else if (n == 12) cout << "C";
    else if (n == 13) cout << "D";
    else if (n == 14) cout << "E";
    else if (n == 15) cout << "F";
    else cout << n;

    
        cout << endl;
}
        
