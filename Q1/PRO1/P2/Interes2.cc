#include <iostream>
#include <cmath>
using namespace std;

int main () {
    cout.setf(ios::fixed); 
    cout.precision(4);
    double c,i,r = 0;
    int t;
    string v;
    
    cin >> c >> i >> t >> v;
    
    i = i / 100;
     if (v == "compost"){
         while (r <= t)
             r = r + (c*(pow((1 + i),t)));
         cout << r << endl;
    }
     else {
        while (r <= t)
             r = r + (c + (c*i*t));
         cout << r << endl;
    }    
}
