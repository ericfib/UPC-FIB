#include<iostream>
using namespace std;

int main (){
  int prev1, prev2, act, pos;
  bool trobat = false;
  while(cin >> prev2 >> prev1 and not trobat){
      int conta = 0;
      cin >> act;
      while (act != 0 and not trobat){
        if(prev1%2 != prev2%2 and act%2 != prev2%2)
          conta++;
        trobat = (conta==3);
        prev2 = prev1;
        prev1 = act;
        cin >> act;
      }
      pos++;
  }
  if (trobat) cout << pos << endl;
  else cout << "none" << endl;
}
