#include <iostream>
using namespace std;

int main () {
    char c;
    
    cin >> c;
    
    if (((c >= 'a') and (c <= 'z')) or ((c >= 'A') and (c <= 'Z'))) cout << "lletra";
    else if (((c >= '0') and (c <= '9'))) cout << "digit";
    else cout << "res";
    
    cout << endl;
}
