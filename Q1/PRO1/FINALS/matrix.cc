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
  int n = m.size();
  int comp = m[i][i];
  int pos = i;
  for(int j = i; j < n; j++){
      if (m[j][j] > comp){
        comp = m[j][j];
        pos = j;
      }
  }
  return pos;
}

// swap row i and row p in given matrix
void swaprow(Matrix &m, int i, int p) {
    int n = m.size();
    for(int j = 0; j < n; j++){
      int temp = m[i][j];
      m[i][j] = m[p][j];
      m[p][j] = temp;
    }
}

// swap column j and column p in given matrix
void swapcolumn(Matrix &m, int j, int p) {
  int n = m.size();
  for(int i = 0; i < n; i++){
    int temp = m[i][j];
    m[i][j] = m[i][p];
    m[i][p] = temp;
  }
}

// reorder matrix
void reorder(Matrix &m) {
    int p = m.size();
    for(int i = 0; i < p; i++){
      int pos = maxpos(m,i);
      swapcolumn(m,pos,i);
      swaprow(m,pos,i);
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
