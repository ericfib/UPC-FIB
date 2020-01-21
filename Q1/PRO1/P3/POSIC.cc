#include <iostream>
using namespace std;

int main () {
    int n, par = 0, sen = 0;
    
    cin >> n;
   
        for (int j = 2; n != 0; j++){
            if (j%2 == 0){
                par += (n%10);
                n = n / 10;
            } else {
                sen += (n%10);
                n = n / 10;
            }
        }
        cout << par << " " << sen << endl;
        
        int rel;
        if ((sen == 0) or (par == 0)){
        cout << "0 = 0 * " << par + sen << endl;
        } 
        else if (sen > par){
            rel = sen/par;
            if (sen%par == 0){
                cout << sen << " = " << rel << " * " << par << endl;
            }
                else cout << "res" << endl;
        } 
        else if (par > sen){
            rel = par/sen;
            if (par%sen == 0){
                 cout << par << " = " << rel << " * " << sen << endl;
            }
                else cout << "res" << endl;
            }
        else if (par == sen) cout << par << " = " << "1 * " << par << endl;
       
}
        
    
