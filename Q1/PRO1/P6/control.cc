#include <iostream>
using namespace std;

void morse(char c, int& n){
      if (c == 'a') cout << ".-";
      else if (c == 'e') cout << ".";
      else if (c == 'i') cout << "..";
      else if (c == 'o') cout << "---";
      else if (c == 'u') cout << "..-";
    }

int main (){
  char c;
  int n, cont = 1;
  cin >> n;
  while (cin >> c){
  morse(c,n);
  cont++;
  if (cont == n) cout << endl;
  }
  cout << "STOP" << endl;
}
