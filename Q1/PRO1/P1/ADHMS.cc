#include <iostream>
using namespace std;

int main () {
    int anys,dies,hores,minuts,segons,total;
    cin >> anys; 
    cin >> dies;
    cin >> hores;
    cin >> minuts;
    cin >> segons; 
    total = (anys*31536000) + (dies*86400) + (hores*3600) + (minuts*60) + segons;
    cout << total << endl;
    
}
