#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > Matrix;

// Pre: M is a square matrix
// Post: Returns true if the given matrix is converging, false if it is not.
//       If the matrix is converging, the convergence value is stored in x.

bool converging(const Matrix &M, int &x){
  int n = M.size();
  int k = n-1;
  n = n/2 + n%2;
  x = M[0][0];
  for(int i = 0; i < n; i++) {
    if (M[i][i] != M[i][k-i] or M[i][k-i] != M[k-i][k-i] or M[k-i][k-i] != M[k-i][i])
      return false;
    if (i != 0 and M[i][i] <= x)return false;
    x = M[i][i];
  }
  return true;
}
Matrix readMatrix(int n) {
    Matrix m(n,vector<int>(n));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> m[i][j];
    return m;
}

int main (){
  int n;
  while(cin >> n){
  Matrix kk = readMatrix(n);
  if (converging(kk,n)) cout << "yes " << n << endl;
  else cout << "no" << endl;
  }
}
