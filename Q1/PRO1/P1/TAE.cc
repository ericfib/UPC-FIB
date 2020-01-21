#include <iostream> 
#include <cmath>

using namespace std;

int main () {
     cout.setf(ios::fixed);
     cout.precision(4);
     
     double i,tae;
     int t;
     string s;
     cin >> i >> s;
      i = i/100;
        
        if (s == "semestral") t = 2;
        
        if (s == "trimestral") t = 4;
         
        if (s == "mensual") t = 12;
        
        if (s == "setmanal") t = 52;
     
    tae = (pow((1 + (i/t)), t) - 1)*100;
     
        cout << tae << endl;
     
}



