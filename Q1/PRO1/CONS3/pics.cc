#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int DELTA_TIME = 10;  // space in minute between samples

typedef struct {
  double magnitude;   // value of the peak
  int time;           // minutes from the origin (0 min.)
} Pic;

void llegir_mesures(vector<double> & vMesures) {
  int n = vMesures.size();
  for (int i = 0; i < n; ++i) cin >> vMesures[i];
}

// write the information of the pic p
void escriure_pic(const Pic& p) {
  cout << "(" << p.magnitude << "," << p.time << ")";
}

// returns the vector of peaks (<magnitude, time>)
vector<Pic> obte_pics(const vector<double> & vMesures) {
  vector<Pic> p(0);
  int m = vMesures.size();
  int posp = 0;
  for(int i = 0; i < m; i++){
    if((i-1 >= 0) and (i+1 <= m)){
      if((vMesures[i-1] < vMesures[i]) and (vMesures[i] > vMesures[i+1])){
      p[posp].magnitude = vMesures[i];
      p[posp].time = i*DELTA_TIME;
      posp++;
    }
  }
  return p;
}
}

// returns true iff the peak p1 is "greater" than peak p2
bool compare(const Pic& p1, const Pic& p2) {
  return p1.magnitude >= p2.magnitude;
}

int main() {
  int n;
  while (cin >> n) {
    vector<double> vm(n);
    llegir_mesures(vm);
    vector<Pic> vp = obte_pics(vm);
    sort(vp.begin(),vp.end(),compare);
    int p1,p2;
    while(cin >> p1 >> p2){
      if(p1 != 0 and p2 != 0){
        int llargvp = vp.size();
        if (p1 < llargvp and p2 < llargvp){
          escriure_pic(vp[p1]);
          cout << "-";
          escriure_pic(vp[p2]);
          cout << " : ";
          cout <<  abs(vp[p1].time - vp[p2].time) << endl;
        }
        else cout << "x" << endl;
      }
      else cout << endl;
    }
  }
}
