#include<iostream>
#include<vector>
using namespace std;

vector<bool> Garbell(int n){
  vector<bool> aux(n+1,true);
  aux[0] = aux[1] = false;
  for(int i = 2; i*i <= n; i++){
    if(aux[i]){
      for(int p = i*i; p <= n; p+=i){
        aux[p] = false;
      }
    }
  }
  return aux;
}

int main (){
  int n;
  cin >> n;
  vector<bool> v = Garbell(7919);
  for(int i = 0; i < n; i++){
    if(v[i]) cout << i << endl;
  }
}
