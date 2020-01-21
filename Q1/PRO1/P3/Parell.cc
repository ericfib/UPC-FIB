#include <iostream> 
using namespace std;

int main () {
    int n, cont = 0, a = 0, b = 0;
    cin >> n;

    for (int aux = n; aux != 0; aux = aux/10) ++cont;
    
    if ((cont % 2) != 0 or n == 0) cout << "res" << endl;
    else {
        cont = cont / 2;
        for (int m1 = cont; m1 != 0; --m1){
            a = m1 + (n%10);
            n = n / 10;
        }
        for (int m2 = cont; m2 != 0; --m2){
            b = m2 + (n%10);
            n = n / 10;
        }
        
	}
        if (a > b) cout << b << " < " << a << endl;
		else if (a < b) cout <<  b << " > " << a << endl;
		else cout << b << " = " << a << endl;
}
    
