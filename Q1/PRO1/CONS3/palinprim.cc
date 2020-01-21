#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool es_capicua(int n){
  int n1, n2;
  n1 = n;
  n2 = 0;
  while (n1 > 0){
    n2 = n*10 + n1%10;
    n1 /= 10;
  }
  return n == n2;
}

bool esprimer(int n){
  vector<bool> aux (9817189+1, true);
  aux[0] = aux[1] = false;
  for (int i = 2; i*i <= 9817189; i++){
   for (int j = i*2; j <= 9817189; j += i){

   }
  }
}


int main (){
  vector<bool> aux (9817189+1, true);
  aux[0] = aux[1] = false;
  for (int i = 2; i*i <= 9817189; i++){
   for (int j = i*2; j <= 9817189; j += i){
     aux [j] = false;
   }
  }
  vector<int> primpal;
  for (int i = 0; primpal.size() < 750; i++){
    if (aux[i] and es_capicua(i)) primpal.push_back(i);
  }
  int n;
  while (cin >> n){
    cout << primpal[n] << endl;
  }
}
