#include <iostream>
using namespace std;

string dia_de_la_setmana (int d, int m, int a){
    int C, Y, F;
    m = m - 2;
    if (m <= 0){
        m = m + 12;
        a = a - 1;
    }
    C = a/100;
    Y = a%100;
    F = ((2.6 * m) - 0.2);
    F = F + d + Y + (Y/4) + (C/4) - (2*C);
    while (F < 0) F = F + 7;
    F = F % 7;
    if (F == 0) return "diumenge";
    else if (F == 1) return "dilluns";
    else if (F == 2) return "dimarts";
    else if (F == 3) return "dimecres";
    else if (F == 4) return "dijous";
    else if (F == 5) return "divendres";
    else return "dissabte";
}

int main () {
    int d, m, a;
    cin >> d >> m >> a;
    
    cout << dia_de_la_setmana (d, m, a) << endl;
}
