#include <iostream>

using namespace std;

int main () {
    int a1,b1,a2,b2;
    cin >> a1 >> b1 >> a2 >> b2;
    
    if ((a2 > a1) and (a2 > b1))
        cout << "[]" << endl;
    else if ((b2 < a1) and (b2 < b1))
        cout << "[]" << endl;
   
    else {
        
        if (a1 >= a2) {
            if (b1 <= b2) 
                cout << "[" << a1 << ","<< b1 << "]" << endl;
            else cout << "[" << a1 << ","<< b2 << "]" << endl;
        }
        else {
            if (b1 <= b2) 
                cout << "[" << a2 << ","<< b1 << "]" << endl;
            else cout << "[" << a2 << ","<< b2 << "]" << endl;
        }
            
    }
}

