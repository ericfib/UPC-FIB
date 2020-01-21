#include <iostream>
#include <vector>
using namespace std;

int num_vocals (string& paraula){
  int cont;
  for (int i = 0; i<paraula.length(); i++){
    if (paraula.substr(i) == "a" or paraula.substr(i) == "e" or
        paraula.substr(i) == "i" or paraula.substr(i) == "o" or
        paraula.substr(i) == "u") cont++;
  }
  return cont;
}

void LlegirParaules(vector<string>& cas, string& paraula) {
   while (paraula != "FI") {
      cas.push_back(paraula);
      cin >> paraula;
   }
}
bool compara_paraules (vector<string>& cas,string& paraula){
  int l = cas.size();
  int comp1, comp2;
  for (int i = 0; i < l; i++){
    num_vocals(paraula[i]) = comp1;
    num_vocals(paraula[i]) = comp2;
    if (comp1 == comp2) return true;
    else comp2 = comp1;
  }
  return false;
}

int main () {
  int num;
  vector<string> cas;
  string paraula;
  LlegirParaules(cas,paraula);
  if (compara_paraules(cas,paraula)){
    cout << paraula << "," << num_vocals(paraula) << endl;
}
}
