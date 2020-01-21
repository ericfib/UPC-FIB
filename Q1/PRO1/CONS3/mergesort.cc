#include<iostream>
#include<vector>
using namespace std;

void ordena(vector<int>& v, int d, int m, int e){
  int n = d+e+1;
  vector<int> aux (n);
  int i = e;
  int j = m+1;
  int k = 0;
  while (i <= m and j <= d) {

  }
}
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  mergesort(v);
  for(int j = 0; j < n; j++){
    cout << v[j];
    if(j != n-1) cout << " ";
  }
  cout << endl;
}
