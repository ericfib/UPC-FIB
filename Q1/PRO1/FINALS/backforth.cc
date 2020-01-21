#include<iostream>
using namespace std;

//funcio que ens retorna el total de vegades que es compleix el que mana el mode
int valor (string mode,string s1,string s2,int n){
  int cont = 0;
  string act,prev;
  cin >> prev;
  if (mode == "forth"){
    for(int i = 1; i < n; i++){
      cin >> act;
      if (prev == s1 and act == s2) cont++;
      prev = act;
    }
  }
  if (mode == "back"){
    for(int i = 1; i < n; i++){
      cin >> act;
      if (prev == s2 and act == s1) cont++;
      prev = act;
    }
  }
  return cont;
}


int main (){
  string mode,s1,s2;
  int cont,N;
  while(cin >> mode){
    cont = 0;
    cin >> s1 >> s2;
    cin >> N;
    if (N != 0){
      cont = valor(mode,s1,s2,N);
    }
    else cont = 0;
    cout << cont << endl;
  }
}
