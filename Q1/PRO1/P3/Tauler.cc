#include <iostream>
using namespace std;

int main () {
    int y, cont = 0;
    char c;
    cin >> y;
    
    for (int j = 1; j != y + 1; j++){
        for (int l = 1; l != y + 1; l++){
            cin >> c;
            if  ((j == l) or (l == (y - l) + 1))
                cont = cont + int(c - '0'); 
            else if  ((j % 2 == 0) and (l % 2 == 0))
                cont = cont + int(c - '0'); 
        }
 }
 cout << cont << endl;
}
 
    
   
