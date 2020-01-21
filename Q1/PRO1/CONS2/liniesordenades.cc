#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, ultim, linia;
    linia = ultim = 0;
    while (cin >> n) {
        ++linia;
        bool ordenada = true;
        string s1;
        if (n > 0) cin >> s1;
        for (int i = 1; i < n; ++i) {
            string seq;
            cin >> seq;
            if (s1 > seq) ordenada = false;
            else s1 = seq;
        }
        if (ordenada) ultim = linia;
    }
    if (ultim == 0) cout << "No hi ha cap linia ordenada creixentment." << endl;
    else cout << "L'ultima linia ordenada creixentment es la " << ultim << '.' << endl;
}
