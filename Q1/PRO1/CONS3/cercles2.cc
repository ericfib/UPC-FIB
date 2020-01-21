#include<iostream>
#include<math.h>
using namespace std;

struct Punt {
  double x, y;
};
struct Cercle {
  Punt centre;
  double radi;
};
bool es_interior(const Punt& p, const Cercle& c){
  double distancia;
    Punt aux;
    aux.x = p.x - c.centre.x;
    aux.y = p.y - c.centre.y;

    distancia = sqrt((aux.x*aux.x)+(aux.y*aux.y));
    if (distancia > c.radi) return false;
    else return true;
}

void llegeix(Punt& p){
  cin >> p.x >> p.y;
}
void llegeix(Cercle& c){
  cin >> c.centre.x >> c.centre.y >> c.radi;
}
void desplaca(Punt& p1, const Punt& p2){
  p1.x += p2.x;
  p1.y += p2.y;
}

int main () {
  Cercle c;
  Punt p;
  cin >> c.centre.x >> c.centre.y >> c.radi;
  cin >> p.x >> p.y;
  int n;
  cin >> n;
  if (es_interior(p,c)) cout << "inicialment a dins" << endl;
  else cout << "inicialment a fora" << endl;
  for (int i = 1; i <= n; i++){
    bool dins = false;
    if (es_interior(p,c)){
      dins = true;
    }
    Punt p2;
    llegeix(p2);
    desplaca(p, p2);
    if (not dins and es_interior(p,c)) cout << "al pas " << i << " ha entrat a dins" << endl;
    else if (dins and not(es_interior(p,c))) cout << "al pas " << i <<" ha sortit a fora" << endl;
  }
}
