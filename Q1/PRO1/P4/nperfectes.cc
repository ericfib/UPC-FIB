#include <iostream>
#include <math.h>
using namespace std;

bool es_perfecte(int n) {
    int div = 2, sum = 1, aux, res;
    aux = n;
    if ((n == 0) or (n == 1)) return false;
    else {
        while (div <= sqrt (n)){
        res = aux % div;
        if (res == 0) sum += div + (n/div);
        div++;
        aux = n;
    }
    if (sum == n) return true;
    else return false;
}
}


int main (){
    int n;
    while (cin >> n){
        cout << es_perfecte (n) << endl;
    }
}
