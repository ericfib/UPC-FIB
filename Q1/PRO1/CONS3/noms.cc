#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Data {
    int dia, mes, any;
};

bool menor(const Data& d1, const Data& d2){
  if (d1.any == d2.any){
    if (d1.mes == d2.mes) return d1.dia < d2.dia;
    return d1.mes < d2.mes;
  }
  return d1.any < d2.any;
}
void readdata(Data& d){
  char barra;
  cin >> d.dia >> barra >> d.mes >> barra >> d.any;
}

int main (){
  int n;
  bool trobat = false;
  Data d1, d2;
  cin >> n;
  if (n >= 3){
    readdata(d1);
    readdata(d2);
    int cont = 2;
    while(cont != n and not trobat){
      if (menor(d1,d2)){
        d1.dia = d2.dia;
        d1.mes = d2.mes;
        d1.any = d2.any;
        cont++;
        readdata(d2);
        if (menor(d1,d2)){
           cout << d2.dia << "/" << d2.mes << "/" << d2.any << endl;
           trobat = true;
         }
      }
      else if (menor(d2,d1)){
        d1.dia = d2.dia;
        d1.mes = d2.mes;
        d1.any = d2.any;
        cont++;
        readdata(d2);
        if (menor(d2,d1)){
           cout << d1.dia << "/" << d1.mes << "/" << d1.any << endl;
           trobat = true;
        }
      }else{
        d1.dia = d2.dia;
        d1.mes = d2.mes;
        d1.any = d2.any;
        readdata(d2);
        cont++;
      }
    }
  }
  if (not trobat) cout << "cap data trobada" << endl;
}
