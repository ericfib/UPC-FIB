#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

Matriu suma(const Matriu& a, const Matriu& b){
  int tam = a.size();
  Matriu suma(tam, Fila(tam));
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
      suma[i][j] = a[i][j] + b[i][j];
    }
  }
  return suma;
}

int main (){}
