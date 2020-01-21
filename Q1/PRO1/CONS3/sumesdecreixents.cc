#include <iostream>
#include <vector>
using namespace std;

typedef  vector<vector<int> > Mat;

Mat llegirMat(int n, int m) {
   Mat A(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> A[i][j];
      }
   }
   return A;
}

// IF YOU WRITE NEW FUNCTIONS/PROCEDURES, ADD THEM HERE
int sumafila(const Mat & A, int i){
  int m = A[0].size();
  int sum = 0;
  for(int j = 0; j < m; j++) sum += A[i][j];
  return sum;
}

bool sumes_decreixents (const Mat & A){
  int n = A.size();
  for(int i = 0; i < n-1; i++){
    if (sumafila(A,i) <= sumafila(A,i+1)) return false;
  }
  return true;
}

int main() {
   int n,m;
   while (cin >> n >> m) {
      Mat A = llegirMat(n,m);
      if (sumes_decreixents(A)) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}
