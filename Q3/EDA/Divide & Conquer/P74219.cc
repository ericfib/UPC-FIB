#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector<int>> MI;

MI mult(const MI& a, const MI& b, int m) {
  MI res (2, vector<int>(2));
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++){
        res[i][j] += a[i][k] * b[k][j];
      }
      res[i][j] = res[i][j]%m;
    }
  }
  return res;
}

MI elevaciorapida (int n, int m, const MI& mat) {
    if (n <= 1){
      return mat;
    }
    else{
      MI multipl = elevaciorapida(n/2, m, mat);

      if (n%2 == 0) {
        return mult(multipl, multipl, m);
      }
      if (n%2 != 0) {
        return mult(mult(multipl, multipl, m), mat, m);
      }
    }
}

int main() {
  MI ini = {{1,0},{0,0}};
  MI powermat = {{1,1},{1,0}};
  int n, m;

  while (cin >> n >> m) {

      if (n < 2){
        cout << n << endl;
      }else{

        MI mat_elev = elevaciorapida(n-1, m, powermat);

        MI res = mult(mat_elev, ini, m);
        cout << res[0][0] << endl;
      }
  }
}
