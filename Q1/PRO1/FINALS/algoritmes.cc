#include<iostream>
#include<vector>
using namespace std;

void fusiona(vector<double>& v,int e, int m, int d){
  int n = d-e+1;
  int i, j, k;
  vector<double> aux (n);
  i = e;
  j = m+1;
  k = 0;
  while(i <= m and j <= d){
    if (v[i] <= v[j]){
      aux[k] = v[i];
      i++;
      k++;
    }else{
      aux[k] = v[j];
      j++;
      k++;
    }
  }
  while(i <= m){
    aux[k] = v[i];
    i++;
    k++;
  }
  while(j <= d){
    aux[k] = v[j];
    j++;
    k++;
  }
  for(int l = 0; l < n; l++){
    v[e+l] = aux[l];
  }
}


void ordenafusio(vector<double>& v, int e, int d){
    if (e < d){
      int m = (e+d)/2;
      ordenafusio(v,e,m);
      ordenafusio(v,m+1,d);
      fusiona(v,e,m,d);
    }
}

int main (){
    int n;
    cin >> n;
    vector<double> iii (n);
    for(int i = 0; i < n; i++){
      cin >> iii[i];
    }
    ordenafusio(iii,0,n);
    for(int q = 1; q <= n; q++){
      cout << iii[q];
      if (q != n) cout << " ";
    }
    cout << endl;
}
