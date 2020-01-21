#include <iostream>
using namespace std;

int main () {
    int n, m, x;
    bool primer = true;
    while (cin >> n >> m){
        if (not primer) cout << endl;
        primer = false;
        x = (n+m) % 5;
        for (int j = 0; j < n; ++j){
            for (int l = 0; l < m; ++l) cout << x;
            cout << endl;
        }
    }
}
