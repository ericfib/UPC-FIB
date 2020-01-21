#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pos(double x,const vector<double>& v, int esq, int dre){
  if (esq>dre) return esq+1;
  if (esq==v.size()) return esq;
  int q = (esq+dre)/2;
  if (x > v[q]) return pos(x,v,q+1,dre);
  if (x < v[q]) return pos(x,v,esq,q-1);
  return q+1;
}

void llegeixvector (vector<double>& t, int n){
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }
}
bool comp(double& a, double& b){
  return a < b;
}

int main (){
  int n;
  double cas;
  cin >> n;
  if (n != 0){
    vector<double> temps(n);
    llegeixvector(temps, n);
    sort(temps.begin(),temps.end(),comp);
    while(cin >> cas){
      if (cas < 0){
        cout << "Time mark " << cas << " would get position " << pos(cas,temps,0,n-1) << endl;
      }
    }
  }
  else cout << endl;
}
