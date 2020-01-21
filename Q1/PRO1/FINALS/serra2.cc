#include<iostream>
using namespace std;

int main () {
  int x2, x1, cont = 0;
  bool trobat = false;
  while(cin >> x2){
    if (x2 != 0){
      int prev = x2;
      while(cin >> x1 and x1 != 0){
        cont++;
        if (cont == 3){
          if (x1 >= prev) trobat = true;
          cont = 0;
        }else{
          if (prev >= x1) trobat = true;
        }
        prev = x1;
      }
      if (trobat) cout << "not saw" << endl;
      else cout << "saw" << endl;
    }
  else cout << "not saw" << endl;
  }
}
