#include <iostream>
using namespace std;

void llista_inversa(int& cont, int& n){
    string c;
    if (cin >> c){
      cont++;
      llista_inversa(cont, n);
      if(cont > n){
        cont--;
      }else {
        cout << c << endl;
        cont--;
      }
    }else n = cont/2;
}

int main () {
  int cont = 0, n = 0;
    llista_inversa(cont, n);
}
