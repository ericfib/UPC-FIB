#include<iostream>
using namespace std;


int main () {
  int n,vel1,vel2;
  int cont, max;
  while(cin >> n){
    max = cont = 0;
    if (n >= 1){
      cin >> vel2;
      for(int i = 1; i < n; i++){
        cin >> vel1;
        if (vel1 > vel2) cont++;
        else {
          cont = 0;
        }
        if (max < cont) max = cont;
        vel2 = vel1;
      }

    }
    cout << max << endl;
  }
}
