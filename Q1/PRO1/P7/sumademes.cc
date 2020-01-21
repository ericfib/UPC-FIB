#include <iostream>
#include <vector>
using namespace std;

bool es_igual(const vector<int>& v, int n, int suma){
  for(int i = 0; i < n; i++){
    if(suma - v[i]  == v[i]) return true;
  }
  return false;
}

int main () {
  int n;
  while (cin >> n){
    vector<int> v (n);
    int suma = 0;
    for (int i = 0; i < n; i++){
      int entrada;
      cin >> entrada;
      v[i] = entrada;
      suma += entrada;
    }
    if (es_igual(v,n,suma)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
