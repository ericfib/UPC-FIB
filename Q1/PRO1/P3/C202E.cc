#include <iostream>
using namespace std;

int main () {
   int n;
   cin >> n;
   
   for (int y = 0; y != n; y++){
    for (int j = 0; j != (n - 1) - y; j++){
         cout << "+";
    }
    cout << "/";
    for (int j = 0; j != y; j++){
         cout << "*";
    }
    cout << endl;
   }
}
