#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > Matriu;

void punts(){
  cout << "-----" << endl;
}
void swap(int a, int b){
  int aux = a;
  a = b;
  b = aux;
}
void intercanvia(Matriu& mat, int j, int k){
  int a = mat.size();
  for(int i = 0; i < a; i++){
    int temp = mat[i][j];
    mat[i][j] = mat[i][k];
    mat[i][k] = temp;
  }
  int b = mat[0].size();
  for(int i = 0; i < a; ++i){
    for(int y = 0; y < b; y++){
      cout << mat[i][y];
      if(y+1 != b) cout << " ";
    }
    cout << endl;
  }
}

int main (){
  int n,m,j,k;
  cin >> n >> m;
  Matriu p(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int h = 0; h < m; h++){
    cin >> p[i][h];
    }
  }
  punts();
  for(int i = 0; i < n; i++){
    for(int l = 0; l < m; l++){
    cout << p[i][l];
    if (l+1 != m) cout << " ";
    }
    cout << endl;
  }

  while (cin >> j >> k){
    punts();
    intercanvia(p,j,k);
  }
  punts();
}
