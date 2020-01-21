#include <iostream>
using namespace std;

int main () {
    int y, cont = 0;
    char c;
    cin >> y;
    
    for (int j = 0; j != y; j++){
        for (int l = 0; l != y; l++){
            cin >> c;
            if  ((j == l) or (l == (y - 1 - j)))
                cont = cont + int(c - '0');
        }
 }
 cout << cont << endl;
}
