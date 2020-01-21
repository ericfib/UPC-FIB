#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

// reads an n x m integer matrix from the input, n >= 0, m >= 0
Matrix read_matrix(int n, int m) {
  Matrix M(n, Row(m));
  for (int i=0; i < n; ++i)
    for (int j=0; j < m; ++j)
      cin >> M[i][j];
  return M;
}

void is_submatrix(const Matrix& A, const Matrix& B,
    int ia, int ja,
    int& ib, int& jb, bool& occurs)
{
  int nA = A.size();
  int mA = A[0].size();
  int nB = B.size();
  int mB = B[0].size();
  occurs = true;
  for(ib = 0; occurs and ib < nB; ib++){
    for(jb = 0; occurs and jb < mB; jb++){
      if(ia+ib < nA and ja+jb < mA){
        if (B[ib][jb] != A[ia+ib][ja+jb]) occurs = false;
      }else occurs = false;
    }
  }
  ib--;
  jb--;
}

int main() {
  int na, ma;
  cin >> na >> ma;
  Matrix A = read_matrix(na, ma);
  int nb, mb;
  cin >> nb >> mb;
  Matrix B =  read_matrix(nb, mb);
  int ia, ja;
  while (cin >> ia >> ja) {
    int ib, jb;
    bool occurs;
    is_submatrix(A, B, ia, ja, ib, jb, occurs);
    if (occurs) cout << "yes" << endl;
    else cout << "no " << ib << " " << jb << endl;
  }
}
