#include <iostream>
using namespace std;

 int suma(int x, int y){
     int suma = x + y;
     return suma;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << suma(a, b) << endl;
    
}
