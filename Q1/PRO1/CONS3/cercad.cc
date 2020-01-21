#include<iostream>
#include<vector>
using namespace std;

void swap(int a, int b){
  int aux = a;
  a = b;
  b = aux;
}
void llegeixvector(vector<int> v, int n){
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
}

void ordenaseleccio (vector<int>& v){
  int n = v.size();
  for(int i = 0; i < n - 1; i++){
    
  }
}
int cercadicotom (vector<int>& v, int x, int esq, int dre){
  if (esq > dre) return -1;
  else{
    int pos = (dre+esq)/2;
    if (x > v[pos]) return cercadicotom(v, x, pos + 1, dre);
    else if (x < v[pos]) return cercadicotom(v, x, esq, pos - 1);
    return pos;
  }
}
void printvector(const vector<int>& v, int n){
  for(int i = 0; i < n; i++){
    cout << v[i];
    if (i != n-1) cout << " ";
  }
  cout << endl;
}
int main (){
  int x, n;
  cin >> n >> x;
  vector<int> dic(n);
  llegeixvector(dic,n);
  ordenaseleccio(dic,n);
  printvector(dic,n);
  cout << cercadicotom(dic, x, 0, n) << endl;


}
