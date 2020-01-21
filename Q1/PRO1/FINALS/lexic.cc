#include<iostream>
using namespace std;

bool sequencies(string& p, int n, char ref){
  bool trobat = false;
  for(int i = 0; i < n; i++){
      cin >> p;
      if (not trobat and p[0] == ref) trobat = true;
  }
  if (trobat) return true;
  else return false;
}

int main (){
  int n;
  string p;
  int cont2 = 0;
  char ref = 'a';
  while(cin >> n){
    if (sequencies(p,n,ref)) cont2++;
    else cout << "Could not find a match for " << ref << endl;
    ref++;
    if (ref > 'z') ref = 'a';
  }
  cout << cont2 << endl;
}
