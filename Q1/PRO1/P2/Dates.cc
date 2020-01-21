#include <iostream>
using namespace std;

int main (){
   int d, m, a;
   bool data;
   
   while (cin >> d >> m >> a){
       data = false;
    if ((m == 2) and (d > 0) and (d <= 28))data = true;
    else if ((m == 2) and (d == 29)){
        if (((a%4 == 0) and (a%100 != 0)) or (a%400 == 0)) data = true;
    }
    else if ((m > 0) and (m <= 7) and (m != 2)){
        if ((m%2 == 0) and (d > 0) and (d <= 30)) data = true;
        else if ((m%2 != 0) and (d > 0) and (d <= 31)) data = true;
    }
    else if ((m >= 8) and (m <= 12)){
        if ((m%2 == 0) and (d > 0) and (d <= 31)) data = true;
        else if ((m%2 != 0) and (d > 0) and (d <= 30)) data = true;
    }
    if (data == true){
        cout << "Data Correcta" << endl;
    }
    else cout << "Data Incorrecta" << endl;
}
}
