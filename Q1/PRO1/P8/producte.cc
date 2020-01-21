  #include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > Matriu;

Matriu producte(const Matriu& a, const Matriu& b){
    int nf = a.size();
    Matriu producte(nf, vector<int> (nf));
    for (int i = 0; i < nf; i++){
        for (int j = 0; j < nf; j++){
          int aux = 0;
            for (int l = 0; l < nf; l++){
                aux += a[i][l] * b[l][j];
            }
            producte[i][j] = aux;
          }
    }
    return producte;
}


int main () {
    int n;
    cin >> n;
    Matriu a(n,vector<int> (n));
    for (int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        cin >> a[i][j];
    }
    Matriu b(n,vector<int> (n));
    for (int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        cin >> a[i][j];
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; i++){
          cout << producte(a,b) [i][j] << " ";
      }
      cout << endl;
    }
}
