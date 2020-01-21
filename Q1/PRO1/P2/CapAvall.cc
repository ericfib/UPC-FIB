#include <iostream>
using namespace std;

int main () {
    int a,b;
    cin >> a >> b;
    
    if (a > b){
        int i = a;
        while (i >= b){
            cout << i << endl;
            i--;
        }
    }
    else if (b > a){
        int o = b;
        while (o >= a){
            cout << o << endl;
            o--;
        }
    }
    else if (a == b) cout << a << endl;
   
}
