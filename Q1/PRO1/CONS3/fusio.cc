#include<iostream>
#include<vector>
using namespace std;

void fusiona(vector<double>& v,vector<double>& v1, vector<double>& v2){
  int i = 0;
  int j = 0;
  int x = v1.size();
  int y = v2.size();
  int cont = 0;
  while (i < x and j < y) {
          if (v1[i] <= v2[j]){ v[cont] = v1[i];
          cont++;
          i++;
        }else{
            v[cont] = v2[j];
            cont++;
            j++;
        }
      }
      while (i < x){
        v[cont] = v1[i];
        cont++;
        i++;
      }
      while (j < y){
        v[cont] = v2[j];
        cont++;
        j++;
      }
  }

void ordena_per_fusio(vector<double>& v){
  int m = v.size();
  int a = m/2;
  if (m > 1){
    int u = 0;
    vector<double> v1(a);
    vector<double> v2(m-a);
    for(int i = 0; i < a; i++) v1[i] = v[i];
    for(int k = a; k < m; k++) v2[u++] = v[k];
    ordena_per_fusio(v1);
    ordena_per_fusio(v2);
    fusiona(v,v1,v2);
  }
  }


int main (){
  int n;
  cin >> n;
  vector<double> iii (n);
  for(int i = 0; i < n; i++){
    cin >> iii[i];
  }
  ordena_per_fusio(iii);
  for(int q = 0; q < n; q++){
    cout << iii[q];
    if (q != n-1) cout << " ";
  }
  cout << endl;
}
