#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

// Pre: mat is an n*n square matrix, where n >= 2
// Post: returns true if mat is an ascending tridiagonal matrix,
// false otherwise
bool is_asc_tridiagonal(const Matrix& mat){
      int n = mat.size();
      for(int i = 2; i < n; i++){
        for(int j = 0; j < i - 1; j++){
          if (mat[i][j] != 0 or mat[j][i] != 0) return false;
        }
      }
      for(int i = 1; i < n-1; i++){
        if (mat[i][i] < mat[i-1][i-1] or mat[i+1][i] < mat[i][i-1] or mat[i][i+1] < mat[i-1][i]) return false;
      }
      return mat[n-2][n-2] <= mat[n-1][n-1];
}

Matrix read_matrix(int n) {
    Matrix m(n, Row(n));
    for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
               cin >> m[i][j];
    return m;
}

int main() {
    int n;    // dimension of the matrix
    while (cin >> n) {
          Matrix a = read_matrix(n);
          if (is_asc_tridiagonal(a)) cout << "TRUE" << endl;
          else cout << "FALSE" << endl;
     }
}
