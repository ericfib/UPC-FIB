#include <iostream>
using namespace std;

int main (){
    int As, Ap, n, d;
    cin >> As >> Ap >> n;
    
    for (int i = 1; cin >> d; i++){
        if (i%2 == 0) n = n + Ap - d;
        else n = n + As - d;
        cout << n << endl;
        
    }
}
