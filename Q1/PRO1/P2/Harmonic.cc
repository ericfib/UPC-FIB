#include <iostream>
using namespace std;

int main () {
     cout.setf(ios::fixed); 
     cout.precision(4);
    
    double n,h = 0;
    cin >> n;
    double i = 1;
    
    while (i <= n){
        h = h + (1/i);
        ++i;
    }
        
    cout << h << endl;
    

    
}
