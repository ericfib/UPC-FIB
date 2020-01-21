#include <iostream>
#include <vector>
using namespace std;

int main (){
  int n, c;
  cin >> n;
  vector <int> v (n);
  int sumamax = 0,sumamin, max = 0, min = 0;
  for (int i = 0; i < n; i++){
    cin >> c;
    v[i] = c;
    sumamax += c;
    if (sumamax > max) max = sumamax;
  }
  for (int j = n-1; j >= 0; j--){

  }
  cout << max << ' ' << min << endl;
  }
