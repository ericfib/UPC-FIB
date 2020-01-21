#include <iostream>
#include <vector>

using namespace std;

struct Casella {
  char tipus;  // 'X':wall, 'E':exit, '.':empty
  int energia;  // amount of energy drained in this position.
};

typedef vector<vector<Casella> > Laberint;

const char WALL='X';
const char FREE='.';
const char EXIT='E';

Laberint llegir_taula() {
   int n, m;
   cin >> n >> m;
   Laberint l (n, vector<Casella>(m));
   for (int i = 0; i < n ; ++i) {
      for (int j= 0;  j < m; ++j) {
         char t;
         cin >> t;
         if ('0'<=t and t<='9') {
            l[i][j].tipus = FREE;
            l[i][j].energia = int(t) - int('0');
         }
         else {
            l[i][j].tipus = t;
            l[i][j].energia = 0;
         }
      }
   }
   return l;
}

//buscarem si hi ha una posicio 'E' en les 4 direccions possibles
bool trobarexit(const Laberint& p, int& ei, int& ej){
  int n = p.size();
  int m = p[0].size();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if (p[i][j].tipus == 'E') {
        ei = i;
        ej = j;
        return true;
      }
    }
  }
  return false;
}
//boolea pe mirar si E esta en una direccio possible
char entradaok(const Laberint& p, int ei, int ej, int i, int j){
  if (ei == i and ej < j) return 'l';
  if (ei == i and ej > j) return 'r';
  if (ej == j and ei < i) return 'u';
  if (ej == j and ei > i) return 'd';
  return 'n';
}
//comprovem si quan passem de una casella amb energia, seguim tenint energia
bool energy(int a, int b){
  return a-b > 0;
}

int main() {
   // load labyrinth
   Laberint lab=llegir_taula();

   int x,y;  //posicio inicial
   int e; // energia incial
   while (cin>>x>>y>>e) {
       // for each starting position and energy
       // check for exit direction and print result.
       // ...
       // Add code here
       // ...
   }
}
