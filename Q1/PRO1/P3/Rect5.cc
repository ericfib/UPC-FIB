#include <iostream> 
using namespace std;

int main () {
    int f, c, num1 = 0, num2 = 1, cont = 0;
    
    cin >> f >> c;
    
    for (int j = 1; j <= f; ++j){
        num1 = cont;
        for (int y = 1; y <= c; ++y){
            if (j == y) cout << "0";
            else if (y < j){
                cout << num1;
                num1--;
                if (num1 == -1) num1 = 9;
            }
            else{
                cout << num2;
                num2++;
                if (num2 == 10) num2 = 0;   
            }
        }
        cout << endl;
        num2=1;
        ++cont;
        if(cont==10)cont=0;
    }
}
