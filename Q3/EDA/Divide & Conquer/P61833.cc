#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > MI;


void printmatriu (MI& m) {
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      if(j == 0) cout << m[i][j] << " ";
      if (j == 1) cout << m[i][j] << endl;
    }
  }
}
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

MI elevaciorapida (int n, int m, MI mat) {
    if (n == 0) {
      return {{1,0},{0,1}};
    }
    else if (n == 1){
      return {{mat[0][0]%m, mat[0][1]%m},{mat[1][0]%m, mat[1][1]%m}};
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
  MI matriu (2, vector<int>(2));


  while(cin >> matriu[0][0] >>  matriu[0][1] >> matriu[1][0] >> matriu[1][1]){
    int n, m;
    cin >> n >> m;

    MI result (2, vector<int>(2));
    result = elevaciorapida(n, m, matriu);
    printmatriu(result);
    cout << "----------" << endl;
  }
}
