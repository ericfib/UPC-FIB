#include <iostream>
#include <vector>
using namespace std;

int mitjavector (vector<int>& v, int n){
  int suma = 0;
  for (int i = 0; i < n; i++){
    cin >> v[i];
    suma += v[i];
  }
  return suma/n;
}

int last_position_of(const vector<int> &v, int x){
  int l = v.size(), pos = l;
  for (int i = 0; i < l; i++){
    if (v[i] == x) pos = i;
  }
  return pos;
}

int main (){
  int n;
  vector<int> v;
  while (cin >> n){
    v = vector<int> (0);
    v = vector<int> (n);
    cout << last_position_of(v,mitjavector(v,n)) << endl;
  }
}
