#include<iostream>
#include<algorithm>
using namespace std;

int jugada(string s){
  char comp = s[0];
  int cont = 1;
  for(int i = 1; i < s.size(); i++){
    if(s[i] != comp) comp = s[i];
    else cont++;
  }
  if(cont == 1) return 0;
  else return cont+1;
}
int valor(string s){
  for(int i = 0; i < s.size(); i++){
    if (s[i] == 'A') rreturn 6;
    else if(s[i] == 'R') return 5;
    else if(s[i] == 'Q') return 4;
    else if(s[i] == 'C') return 3;
    else if(s[i] == 'D') return 2;
    else if(s[i] == 'N') return 1;
  }
}
bool comp1(string a,string b){
  bool trobatA = false;
  bool trobatB = false;
  int i = 0;
  while(not trobatA and not trobatB and i < 5){
    if (valor(a[i]) > valor(b[i])) trobatA = true;
    else if(valor(a[i]) < valor(b[i])) trobatB = false;
  }
  if (trobat == true) return true;
  else return false;
}
bool comp2(string a,string b){
  if(not comp1){
    int sumaA = 0, sumaB = 0;
    for(int i = 0; i < 5; i++){
      sumaA += valor(a[i]);
      sumaB += valor(b[i]);
    }
    if(sumaA >= sumaB) return true
  }
}

int main (){
  string A;
  string B;
  int contA = 0, contB = 0;
  while(cin >> A >> B){
    cout << comp << jugada(A) << jugada(B) << suma(A) << suma(B) << endl;
    if (comp){
      contA++;
      cout << "Anna" << endl;
    }else{
      contB++;
      cout << "Bernat" << endl;
    }
  }
  cout << "Guanyades per l'Anna: " << contA << endl;
  cout << "Guanyades per en Bernat: " << contB << endl;
}
