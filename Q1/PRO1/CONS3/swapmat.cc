#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

// read matrix NxN from cin
Matrix readMatrix(int n) {
    Matrix m(n,vector<int>(n));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> m[i][j];
    return m;
}

// print given matrix to cout
void printMatrix(const Matrix &m) {
    int n = m.size();
    for (int i=0; i<n; ++i) {
        cout << m[i][0];
        for (int j=1; j<n; ++j)
            cout << " " << m[i][j];
        cout << endl;
    }
    cout << endl;
}

// find position of largest element in diagonal, from position (i,i) to the end.
// If there are more than one elements with maximum value, return position
// of the first one.
int maxpos(const Matrix &m, int i) {
    int max = m[i][i];
    int pos = i;
    for(int j = i; j < m.size(); i++){
      if (m[j][j] > max) pos = j;
    }
  return pos;
}

// swap row i and row p in given matrix
void swaprow(Matrix &m, int i, int p) {
  for(int l = 0; l < m.size(); l++){
    int temp = m[i][l];
    m[i][l] = m[p][l]
    m[p][l] = temp;
  }
}

// swap column j and column p in given matrix
void swapcolumn(Matrix &m, int j, int p) {
  for(int l = 0; l < m.size(); l++){
    int temp = m[l][i];
    m[l][i] = m[l][p]
    m[l][p] = temp;
  }
}

// reorder matrix
void reorder(Matrix &m) {
    int tam = m.size();
    int tam2 = m[0].size();
    for(int i = 0; i < tam; i++){
      for(int j = 0; j < tam2; j++){
        int o,u;
        o = i;
        u = j;
        for(int k )
      }
    }
}

int main() {
    int n;
    while (cin>>n) {
        Matrix m = readMatrix(n);
        reorder(m);
        printMatrix(m);
    }
}
