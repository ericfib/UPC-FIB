#include<iostream>
using namespace std;
bool sequencies (string& p, char ref, int n){
  bool trobat = false;
  for(int i = 0; i < n; i++){
    cin >> p;
    if (not trobat and p[0] == ref) trobat = true;
  }
  if (trobat) return true;
  else return false;
}
int main (){
  string cas;
  int n, cont = 0;
  char ref = 'a';
  while(cin >> n){
    if(sequencies(cas,ref,n)) cont++;
    else cout << "Could not find a match for " << ref << endl;
    ref++;
    if (ref > 'z') ref = 'a';
  }
  cout << cont << endl;
}
