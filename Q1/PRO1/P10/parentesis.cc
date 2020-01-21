#include<iostream>
using namespace std;

int main (){
  char ent, seq;
  int nC1, nC2, nP1, nP2;
  nC1 = nC2 = nP1 = nP2 = 0;
  while(cin >> ent){
    if (ent == '[' or ent == '('){
      if (ent == '[') nC1++;
      else if (ent == '(') nP1++;
      while (cin >> seq){
        if (seq == '[') nC1++;
        else if (seq == ']') nC2++;
        else if (seq == '(') nP1++;
        else if (seq == ')') nP2++;
      }
    }
    if (nC1 == nC2 and nP1 == nP2) cout << "si" << endl;
    else cout << "no" << endl;
  }
}
