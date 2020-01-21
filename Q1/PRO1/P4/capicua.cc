#include <iostream>
#include <math.h>
using namespace std;

bool es_capicua(int n){
    int res, sum2 = 0, cont = -1, aux;
    aux = n;
    while (aux != 0){
        aux /= 10;
        cont++;
    }
    aux = n;
    for (int i = cont; i >= 0; i--){
        res = aux % 10;
        sum2 = sum2 + ((res * pow(10,i)));
        aux /= 10;
    }
    if (sum2 == n)return true;
    else return false;
}




int main () {
    int n;
    cin >> n;
    
    cout << es_capicua (n) << endl;
}
