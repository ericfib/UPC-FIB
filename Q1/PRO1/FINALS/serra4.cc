#include<iostream>
using namespace std;

int main (){
  int prev, act, cont;
  bool saw = true;
  while(cin >> act){
    saw = true;
    cont = 0;
    prev = act+1;
    while(act != 0){
      if (saw){
        if (cont == 0 and act >= prev) saw = false;
        else if (cont == 1 and act <= prev) saw = false;
        else if (cont == 2){
          if (act <= prev) saw = false;
          cont = -1;
        }
        prev = act;
        cont++;
      }
      cin >> act;
    }
    if (saw) cout << "saw" << endl;
    else cout << "not saw" << endl;
  }
}
