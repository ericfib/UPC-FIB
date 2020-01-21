#include <iostream>
using namespace std;

int main (){
  int n, cont = 1, primer;
  cin >> primer;
  for (int i = 1; cin >> n; i++){
    if (i%2==0 and n==primer) cont++;
  }
  cout << cont << endl;
}
