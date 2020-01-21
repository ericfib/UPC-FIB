#include <iostream>
using namespace std;

int main () {
    int n, cont = 0;
    string c;
    
    cin >> n;
    
    while (cin >> c) {
        cont += 1;
        if (cont %n == 0) cout << c << endl;
    }
}
  
