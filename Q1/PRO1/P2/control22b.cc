#include <iostream>
#include <cmath>

using namespace std;

int main (){
    cout.setf(ios::fixed); 
    cout.precision(2);
    double n,l,o,a,t,p = 0;
    double v = 0;

    
    cin >> n;
    
    while (cin >> t){
        v = v + pow (t,2);
        p = p + t; 
    }
   o = ((1/(n - 1))*v);
   a = ((1/(n*(n - 1)))) * (pow(p,2));
   l = o - a;
   cout << l << endl;
   
}
