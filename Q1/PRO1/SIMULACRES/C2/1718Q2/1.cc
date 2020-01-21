#include <iostream>
using namespace std;

int llegeixseq (string previ, string seguent, int n){
  int cont = 0;
  if(n != 0) cin >> previ;
  for (int i = 1; i < n; i++){
  cin >> seguent;
  if (previ == "donald" and seguent == "trump")cont++;
  previ = seguent;
  }
  return cont;
}

int main () {
  int n;
  string previ, seguent;
  while(cin >> n){
    cout << llegeixseq(previ,seguent,n) << endl;
  }
}
