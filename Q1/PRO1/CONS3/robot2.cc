#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > Matriu;
void interpretaordre(string ordre, Matriu mat, int x1, int y1){
  int tam = mat.size();
  if (ordre)
}

bool ordreok(string ordre){
  if(ordre == "amunt" or ordre == "esquerra" or ordre == "dreta" or
    ordre == "avall") return true;
  else return false;
}

int main (){
  int n,m,x1,y1;
  cin >> n >> m;
  Matriu mat(n, vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int k = 0; k < m; k++){
      mat[i][k] = 1;
    }
  }
  cin >> x1 >> x2;
  string ordre;
  while(cin >> ordre){
    if (ordreok){

    }
    else cout << "ordre incorrecte" << endl;
  }
}
