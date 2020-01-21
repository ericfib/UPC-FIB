#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int a, b, pot;
    
    while (cin >> a >> b){
        if (b == 0) pot = 1;
        else {
            pot = pow (a,b);
        }
        cout << pot << endl;
    }
    
}
