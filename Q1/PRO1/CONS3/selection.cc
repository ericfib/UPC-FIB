#include<iostream>
#include<vector>
using namespace std;

void swap(int& a, int& b){
  int aux = a;
  a = b;
  b = aux;
}

void selectionsort(vector<int>& v, int n){
  for (int i = 0; i < n; i++){
    int k = i;
    for(int j = i+1; j< n; j++){
      if (v[j] < v[k]) k = j;
    }
    swap(v[i], v[k]);
  }
}
int main (){
  int n;
  cin >> n;
  vector<int> v (n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  selectionsort(v,n);
  for(int j = 0; j < n; ++j){
    cout << v[j];
    if (j != n-1) cout << " ";
  }
  cout << endl;
}
