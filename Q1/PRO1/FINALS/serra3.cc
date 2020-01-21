#include<iostream>
using namespace std;


int main (){
  int previ,act,cont;
  bool saw;
  while (cin >> act){
    cont = 0;
    saw = true;
    previ = act + 1;
    while (act != 0){
      if (saw){
        if (cont == 0 and act >= previ) saw = false;
        else if (cont == 1 and act <= previ) saw = false;
        else if (cont == 2){
          if (act <= previ) saw = false;
          cont = -1;
        }
        previ = act;
        cont++;
      }
      cin >> act;
    }
    if (saw) cout << "saw" << endl;
    else cout << "not saw" << endl;
  }
}
