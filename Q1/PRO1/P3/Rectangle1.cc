#include <iostream>
using namespace std;

int main (){
    int n, m, rect;
    bool primero = true;
    cin >> n >> m;
    
    while (cin >> n >> m){
        if (not primero) cout << endl;
        primero = false;
        rect = (n + m) % 5;
        for (int j = 0; j < n; j++){
            for (int l = 0; l < m; ++l){
                cout << rect;
        }
         cout << endl;
    }
  }
}
    
