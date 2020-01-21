#include <iostream>
using namespace std;

int main(){
    string x;
    
    cin >> x;
    int l = (x.length()) - 1,t,y,p,cont = 0;
    
    t = x[l];
    y = x[l - 1];
    p = x[l - 2];
    cout << "nombres que acaben igual que " << x << ":" << endl;
    
    
    while (cin >> x){
        l = (x.length()) - 1;
        int z = x[l];
        int v = x[l - 1];
        int o = x[l - 2];
        if ((z == t) and (v == y) and (o == p)){
            cont++;
            
            cout << x << endl;
        }
    }
    cout << "total: "  << cont << endl;    
    
    
    
}
	
