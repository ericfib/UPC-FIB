#include <iostream>
using namespace std;

int main () {
    int x, y, cont1 = 0, cont2 = 0, resta;
    char c;
    cin >> y;
    
    for (int j = 1; j != y + 1; j++){
        for (int l = 1; l != y + 1; l++){
            cin >> c;
            if  (((j % 2 == 1) and (l % 2 == 1)) or ((j % 2 == 0) and (l % 2 == 0)))
                cont1 = cont1 + int(c - '0'); 
            else 
                cont2 = cont2 + int(c - '0');
        }
 }
 resta = cont1 - cont2;
    cout << cont1 << "-" << cont2 << " = " << resta << endl;
}
