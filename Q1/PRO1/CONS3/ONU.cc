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

double pib(const Paisos& p, char c, double d){
  double suma = 0.0;
  int tam = p.size();
  for(int i = 0; i < tam; i++){
    if(p[i].nom[0] == c){
      int tam2 = p[i].provs.size();
        for(int j = 0; j < tam2; ++j){
          double hab = p[i].provs[j].habitants;
          double area = p[i].provs[j].area;
          if (hab/area > d){
            suma += p[i].provs[j].pib;
          }
        }
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
                  p[i].provs[j].pib;
          }
      }
      cout << pib(p,'A',10) << endl;
      cout << pib(p,'A',20) << endl;
      cout << pib(p,'A',30) << endl;
      cout << pib(p,'A',40) << endl;
      cout << pib(p,'E',10) << endl;
      cout << pib(p,'E',20) << endl;
      cout << pib(p,'E',30) << endl;
      cout << pib(p,'E',40) << endl;
      cout << pib(p,'C',40) << endl;
}
