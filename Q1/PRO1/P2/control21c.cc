#include <iostream>
using namespace std;

int main (){
    int n,t,v = 0;
    
    cin >> n;
    
    while (cin >> t){
        if (t % n == 0){
            v++;
        }
    }
     cout << v << endl;
}
