#include <iostream>
using namespace std;

int main () {
    int b, seq, div;
    cin >> b;
    
    while (cin >> seq){
        int n = seq, suma = 0;
        while (n / b != 0){
            suma = suma + (n % b);
            n = n / b;
        }
        if ((n / b) == 0) suma = suma + n;
        cout << seq << ": " << suma << endl;
    }
    
}
