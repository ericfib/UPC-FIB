#include <iostream>

using namespace std;

int main () {
    int h,m,s;
    cin >> h >> m >> s;
    s++;
    if (s >= 60) {
        m++;
        s = s - 60;
        
    }
    if (m >= 60) {
        h++;
        m = m - 60;
    }
    
    if  (h == 24)
        h = 00;
    
    if (h < 10) {
        cout << "0" << h << ":";
    }
    else cout << h << ":";
    
    if (m < 10) {
        cout << "0" << m << ":";
    }
    else cout << m << ":";
    
    if (s < 10)  {
        cout << "0" << s << endl;
    }
    else cout << s << endl;
}
