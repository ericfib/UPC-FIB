#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Mat;

Mat llegirMat(int n, int m) {
   Mat A(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> A[i][j];
      }
   }
   return A;
}

void escriureMat(const Mat &A) {
   for (int i = 0; i < A.size(); ++i) {
      cout << A[i][0];
      for (int j = 1; j < A[i].size(); ++j) cout << " " << A[i][j];
      cout << endl;
   }
}

void trafo_veins (Mat& A) {
    int n = A.size();
    int m = A[0].size();
    Mat AUX (n, vector<int>(m));
    AUX = A;
      for(int i = 0; i < n; i++){
        AUX[i][0] = A[i][1];
      }
      for(int i = 0; i < n; i++){
        AUX[i][m-1] = A[i][m-2];
    }
    for(int i = 0; i < n; i++){
      for(int j = 1; j < m-1; j++){
        AUX[i][j] = A[i][j-1]+A[i][j+1];
      }
    }
    A = AUX;
}

int main() {
   int n,m;
   while (cin >> n >> m) {
      Mat A = llegirMat(n,m);
      trafo_veins(A);
      escriureMat(A);
      cout << endl;
   }
}
