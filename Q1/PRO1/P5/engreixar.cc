#include <iostream>
using namespace std;

 int engreixa(int x){
   if (x/10 != 0) {
     int n = engreixa(x/10);
     if (n%10 > x%10) return n*10 + n%10;
     else return n*10 + x%10;
   }return x;
 }
 int main () {
   int x;
   cin >> x;
   cout << engreixa(x) << endl;
 }
