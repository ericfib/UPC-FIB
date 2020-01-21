#include <iostream>
using namespace std;

int main () {
    int x1, x2, x3, x4;
    int fold = 0, incr = 0;
    
    while (cin >> x1 >> x2 >> x3 >> x4){
        
    if ((x1 < x2) and (x2 < x3) and (x3 < x4)) incr++;
    
    if ((x1 == x3) and (x2 == x4)) fold++;
    }
    cout << "Increasing: " << incr << endl;
    cout << "Folded: " << fold << endl;
}
   
