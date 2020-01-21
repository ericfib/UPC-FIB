#include <iostream>
using namespace std;

int main (){
  int n, p, q, k;
  while (cin >> n){
      for (p = n/7; ((k != n) and (p >= 0)); p--){
         
          for (q = n - (7*p); ((k != n) and (q >= 0)); q--){
            k = (7*p) + (4*q);
            if (k == n){
                cout << p << " " << q << endl;
            }
        }
    }
}
}
  
