#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

struct Punt { double x, y; };
struct Cercle { Punt centre; double radi; };
void llegeix(Cercle& c){
  cin >> c.centre.x >> c.centre.y >> c.radi;
}

void escala(Cercle& c, double esc){
    c.radi *= esc;
}
void desplaca(Punt& p1, const Punt& p2){
  p1.x += p2.x;
  p1.y += p2.y;
}
double distancia(const Punt& a, const Punt& b){
  double res;
  res = ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
  return sqrt(res);
}
bool es_interior(const Punt& p, const Cercle& c) {
  int t = int(distancia(c.centre, p));
  if (t <= c.radi) return true;
  else return false;
}

int relacio(const Cercle& c1, const Cercle& c2) {
   if (es_interior(c1.centre, c2) and c1.radi < c2.radi) return 1;
   else if (es_interior(c2.centre, c1) and c2.radi < c1.radi) return 2;
   else if ((not es_interior(c1.centre, c2)) and (distancia(c1.centre, c2.centre) < (c1.radi+c2.radi))) return 3;
   else if ((not es_interior(c2.centre, c1)) and (distancia(c1.centre, c2.centre) < (c1.radi+c2.radi))) return 3;
   else return 0;
}

int main () {
  vector<Cercle> c(2);
  llegeix (c[0]);
  llegeix (c[1]);
  if(relacio(c[0], c[1]) == 1) cout << "el primer cercle es interior al segon" << endl;
  else if(relacio(c[0], c[1]) == 2) cout << "el segon cercle es interior al primer" << endl;
  else if(relacio(c[0], c[1]) == 3) cout << "els cercles intersecten" << endl;
  else if(relacio(c[0], c[1]) == 0) cout << "els cercles no intersecten" << endl;
  int m;
  while(cin >> m){
    string accio;
    cin >> accio;
    if(accio == "escala"){
      double esc;
      cin >> esc;
      escala (c[m-1],esc);
    }
    if (accio == "mou"){
      Punt p1;
      cin >> p1.x >> p1.y;
      desplaca(c[m-1].centre, p1);
    }
    if(relacio(c[0], c[1]) == 1) cout << "el primer cercle es interior al segon" << endl;
    else if(relacio(c[0], c[1]) == 2) cout << "el segon cercle es interior al primer" << endl;
    else if(relacio(c[0], c[1]) == 3) cout << "els cercles intersecten" << endl;
    else if(relacio(c[0], c[1]) == 0) cout << "els cercles no intersecten" << endl;
  }
}
