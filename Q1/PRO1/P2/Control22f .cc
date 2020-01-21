#include <iostream>
using namespace std;

int main(){
	int p,t,l = 0;
    
    cin >> p;
    
    while (cin >> t){
        if ((t%1000) == (p%1000)){
            l++;
            cout >> t;
        }
    cout << l << endl;
        
    }
