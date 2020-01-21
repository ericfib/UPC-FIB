#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void llegeix(vector<int>& v){for(int i = 0; i < v.size(); i++) cin >> v[i]; }


int main (){
    int n;
    while(cin >> n){
      vector<int> v(n);
      llegeix(v);
      sort(v.begin(), v.end());
      int comp = v[0];
      int cont = 1;
      for(int i = 1; i < n; i++){
        if(v[i] != comp) ++cont;
        comp = v[i];
      }
      cout << cont << endl;
      }
    }
