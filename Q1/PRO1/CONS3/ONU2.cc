#include<iostream>
#include<vector>
using namespace std;

struct Provincia {
  string nom;
  string capital;
  int habitants;
  int area;
  double pib;
 };
struct Pais {
   string nom;
   string capital;
   vector<Provincia> provs;
 };
typedef vector<Pais> Paisos;

int habitants(const Paisos& p, double x){
  int tam = p.size();
  int suma = 0;
  for(int i = 0; i < tam; i++){
    int condicio = 0;
    int tam2 = p[i].provs.size();
    for(int j = 0; j < tam2; j++){
      if (p[i].provs[j].pib <= x){
        condicio++;
      }
    }
    if (condicio >= 2){
      for(int y = 0; y < p[i].provs.size(); y++)
        suma += p[i].provs[y].habitants;
    }
  }
  return suma;
}

int main () {
    int n;    cin >> n;
    Paisos p(n);
    for (int i=0; i<n; ++i) {
        int np;
        cin >> p[i].nom >> p[i].capital >> np;
        p[i].provs = vector<Provincia>(np);
        for (int j=0; j<np; ++j) {
            cin >> p[i].provs[j].nom >> p[i].provs[j].capital >>
                p[i].provs[j].habitants >> p[i].provs[j].area >>
                p[i].provs[j].pib
            ;
        }
    }
    for (double x = 0; x<5000; x+=100) {
        cout << habitants(p,x) << endl;
    }
}
