#include <iostream>
using namespace std;

int main () {
    int n, j, y;
    char c;
    
    cin >> n >> c;
    
    for (j = 0; j != n; j++){
        for (y = 0; y != n; y++)
            if ((j == y)) {
                cout << c;
            }else {
                cout << ".";
            }
            if (y == n - 4) cout << c;  
            cout << endl;
    }
}
