#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void llegeix(vector<int>& v, int n){
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
}
int main (){
    int n;
    while(cin >> n){
      vector<int> v(n);
      llegeix(v,n);
      sort(v.begin(),v.end());
      for(int i = n-1; i >= 0; i--){
        cout << v[i];
        if(i != 0) cout << " ";
      }
      cout << endl;
    }
}
