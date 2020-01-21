#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int a, b, c, max, mid, min;
    string orden;
   
    cin >> a >> b >> c;
    cin >> orden;
   
    if ((a < b) and (a < c)) {
        min = a;
        if (b < c){
            max = c;
            mid = b;
        }else {
            max = b;
            mid = c;
        }
    }
    else if ((b < a) and (b < c)){
        min = b;
        if (a < c){
            max = c;
            mid = a;
        }else {
            max = a;
            mid = c;
        }
    }
    else if ((c < a) and (c < b)){
        min = c;
        if (a < b){
            max = b;
            mid = a;
        } else {
            max = a;
            mid = b;
        }
    }
    if (orden == "ABC") cout << min << " " << mid << " " << max << endl;
    else if (orden == "ACB") cout << min << " " << max << " " << mid << endl;
    else if (orden == "BCA") cout << mid << " " << max << " " << min << endl;
    else if (orden == "BAC") cout << mid << " " << min << " " << max << endl;
    else if (orden == "CAB") cout << max << " " << min << " " << mid << endl;
    else if (orden == "CBA") cout << max << " " << mid << " " << min << endl;
} 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
