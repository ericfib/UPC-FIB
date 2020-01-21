#include<iostream>
using namespace std;
int suma_digits(int x){
  int suma = 0;
  if (x < 10) return x;
  while(x != 0){
    suma+=x%10;
    x/=10;
  }return suma_digits(suma);
}
int reduccio_digits(int x){
  int p = x;
  while (p >= 10){
    p = suma_digits(p);
  }
  return p;
}
int main (){
  int n;
  while(cin >> n){
    cout << reduccio_digits(n) << endl;
  }
}
