#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(const vector<int>& v, int n){
  for(int i = 0; i < n; i++){
    cout << v[i];
    if (i != n-1) cout << " ";
  }
  cout << endl;
}

void reverseprint(const vector<int>& v, int n){
  for(int i = n - 1; i >= 0; i--){
    cout << v[i];
    if (i > 0) cout << " ";
  }
  cout << endl;
}

void fusio(vector<int>& v, int e, int m, int d){
  int n = d-e+1;
  vector<int> aux(n);
  int i = e;
  int j = m + 1;
  int k = 0;
  while (i <= m and j <= d){
    if (v[i] <= v[j]){
      aux[k] = v[i];
      i++;
      k++;
    }else{
      aux[k] = v[j];
      j++;
      k++;
    }
  }
  while (i <= m){
    aux[k] = v[i];
    i++;
    k++;
  }
  while(j <= d){
    aux[k] = v[j];
    j++;
    k++;
  }
  for(int l = 0; l < n; l++){
    v[e+l] = aux[l];
  }
}

void mergesort(vector<int>& v, int e, int d){
  if (e < d){
    int m = (e+d)/2;
    mergesort(v, e, m);
    mergesort(v, m+1, d);
    fusio(v,e,m,d);
  }
}

int main (){
    int n,np,ns;
    vector<int> parell;
    vector<int> senar;
    while (cin >> n){
      parell = vector<int> (0);
      senar = vector<int> (0);
      while (n != 0){
        if (n%2 == 0) parell.push_back(n);
        else senar.push_back(n);
        cin >> n;
    }
    ns = senar.size();
    np = parell.size();
    mergesort(parell, 0, np-1);
    mergesort(senar, 0, ns-1);
    print(parell,np);
    reverseprint(senar,ns);
  }
}
