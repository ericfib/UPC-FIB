#include <iostream>
#include <math.h>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    double x, p, pol = 0, exp = 0;
    
    cin >> x;
    while (cin >> p){
        pol += p*(pow(x,exp));
        exp += 1;
    }
    cout << pol << endl;
}
