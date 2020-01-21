#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n,t;
    cin >> n;
    
    for (int y = 1; y <= n; ++y){
        t = n * y;
        cout << n << " " << "x" << " " << y << " " <<  "=" << " " << t << endl;
    }
}
