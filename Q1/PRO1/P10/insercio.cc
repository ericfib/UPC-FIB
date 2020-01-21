#include <iostream>
#include <vector>
using namespace std;


void insereix(vector<double>& v) {
        int tam = v.size();
        for (int i = 1; i < tam; ++i)  {
                double x = v[i];
                int j = i;
                while (j > 0 && x < v[j - 1]) {
                        v[j] = v[j - 1];
                        --j;
                }
                v[j] = x;
        }
}


int main (){
  int n;
  cin >> n;
  vector<double> v (n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  insereix(v);
  for(int i = 0; i < n; i++){
    cout << v[i];
    if (i != n-1) cout << " ";
  }
  cout << endl;
}
