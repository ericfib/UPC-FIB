#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

// Pre: mat is an n*n square matrix, where n >= 2
// Post: it returns true if mat is a zero-sum tridiagonal matrix,
//       false otherwise
bool is_zerosum_tridiagonal(const Matrix& mat) {
      int n;
      n = mat.size();
      int suma1, suma2;
      suma1 = suma2 = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if (j == i){
            suma1 += mat[i][j];
          }
          else if ((j == i-1) or (j == i+1)){
            suma2 += mat[i][j];
          }else{
            if (mat[i][j] != 0) return false;
          }
        }
      }
      if (suma1 == suma2) return true;
      else return false;
}


Matrix read_matrix(int n) {
    Matrix m(n, Row(n));
    for (int i=0; i < n; ++i)
          for (int j = 0; j < n; ++j)
               cin >> m[i][j];
    return m;
}

int main() {
    int n;
    while (cin >> n) {
          Matrix a = read_matrix(n);
          if (is_zerosum_tridiagonal(a)) cout << "TRUE" << endl;
          else cout << "FALSE" << endl;
    }
}
