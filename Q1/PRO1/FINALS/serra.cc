#include<iostream>
using namespace std;

int main (){
  int anter, n, cont = 0; // n = actual, n1 = penultim
  bool saw = true;
  while(cin >> n and n != 0){
    if (cont == 0){
      cont++;
      anter = n;
    }
    else if (cont < 3){
      if (anter >= n){
        saw = false;
      }
      else cont++; anter = n;
    }
    else if (cont == 3){
      if (anter <= n) saw = false;
      else {
        anter = n;
        cont == 1;
      }
    }
  }
  if (saw) cout << "saw" << endl;
  else cout << "not saw" << endl;
}
