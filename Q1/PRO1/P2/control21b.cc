#include <iostream> 
using namespace std;

int main () {
    string a;
    cin >> a;
    int l = (a.length()) - 1, u;
    
    u = (a[l] - '0') + (a[l - 1] - '0') + (a[l - 2] - '0');
    
    cout << u << endl;
}
