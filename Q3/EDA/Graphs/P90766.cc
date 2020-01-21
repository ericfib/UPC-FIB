#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef vector<vector<char>> MC;
typedef vector<int> VI;
typedef vector<vector<bool>> MB;

VI next_i = {-1, 0, 1, 0};
VI next_j = {0, -1, 0, 1};

bool pos_ok(int i, int j, int limx, int limy) {
  if (i >= 0 and i < limy and j >= 0 and j < limx) return true;
  return false;
}

int DFS_busca(const MC& map, int i, int j) {
  int n = map.size();
  int m = map[0].size();
  stack<pair<int,int>> S;
  S.push({i,j});
  MB vis (n, vector<bool>(m,false));
  int cont = 0;

  while (not S.empty()){
      int si = S.top().first;
      int sj = S.top().second;
      S.pop();
      if (not vis[si][sj]) {
          vis[si][sj] = true;

          if (map[si][sj] == 't') cont++;

          for(int i = 0; i < 4; i++) {
            int new_i = si+next_i[i];
            int new_j = sj+next_j[i];

            if (pos_ok(new_i, new_j, m, n)) {
              if (map[new_i][new_j] != 'X') {
                S.push({new_i, new_j});
              }
            }
          }
      }
  }
  return cont;
}

int main() {
  int nrow, ncol;
  cin >> nrow >> ncol;
  MC mapa (nrow, vector<char>(ncol));

  for(int i = 0; i < nrow; i++) {
    for(int j = 0; j < ncol; j++) {
      cin >> mapa[i][j];
    }
  }

  int orig_i, orig_j;
  cin >> orig_i >> orig_j;

  int ntresors = 0;

  ntresors = (DFS_busca(mapa, orig_i-1, orig_j-1));

  cout << ntresors << endl;

}
