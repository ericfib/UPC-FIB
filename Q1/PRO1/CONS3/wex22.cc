#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

// Pre: mat is an n*n square matrix, where n >= 2
// Post: it returns true if mat is a zero-sum tridiagonal matrix,
//       false otherwise
void is_zerosum_tridiagonal(const Matrix& mat) {
      int n;
      n = mat.size();
      int suma1, sumainferior, sumasuperior;
      suma1 = sumainferior = sumasuperior = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if (j == i){
            suma1 += mat[i][j];
          }
          else if (j == i-1){
            sumainferior += mat[i][j];
          }
          else if (j == i+1){
            sumasuperior += mat[i][j];
          }
        }
      }
      if (suma1 == (sumainferior+sumasuperior)) cout << 1 << endl;
      cout << suma1 << " " << sumainferior << " " << sumasuperior << " " << sumainferior+sumasuperior << " " << endl;


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
          is_zerosum_tridiagonal(a);
    }
}
