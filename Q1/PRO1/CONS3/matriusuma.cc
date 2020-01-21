#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector <int> > Matrix;

Matrix read_matrix(int n, int m) {
  Matrix mat(n,vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> mat[i][j];
    }
  }
  return mat;
}

bool even_odds_matrix (const Matrix& M){
  int n = M.size();
  int m = M[0].size();
  int sumaparell = 0;
  int sumasenar = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if (i == 0 or i%2==0){
        if ((M[i][j] != 0) and (M[i][j]%2 == 0)) sumaparell+=M[i][j];
      }else{
        if ((M[i][j] != 0) and (M[i][j]%2 != 0)) sumasenar+=M[i][j];
      }
    }
  }
  if(sumaparell == sumasenar) return true;
  else return false;
}

int main() {
  int n, m;
  while(cin >> n >> m){
  Matrix mat(n, vector<int>(m));
  mat = read_matrix(n,m);
  if(even_odds_matrix(mat) == true) cout << "true" << endl;
  else cout << "false" << endl;
  }
}
