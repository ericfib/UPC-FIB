#include <iostream>
using namespace std;

int main (){
    int d,n,t,a,r = 0;
    cin >> d >> n >> t;
    
    for (int i = 0; i < t; i++){
        cin >> a;
        if ((n + a) - d > 0) r++;
        n = n + a - d;
    }
    cout << r << endl;
}
