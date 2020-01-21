/** @file TabFreq.cc
    @brief Implementación de la clase Tabfreq.hh
*/


#include "TabFreq.hh"
using namespace std;

TabFreq::TabFreq(){}

TabFreq::TabFreq(const TabFreq& c){
  TF = c.TF;
}

TabFreq::~TabFreq(){}

void TabFreq::modifica(int n){
  string key;
  int fr;
  for(int i = 0; i < n; i++){
    cin >> key >> fr;
    TF[key] += fr;
  }
}

map<string,int>::iterator TabFreq::inici(){
  return TF.begin();
}

map<string,int>::iterator TabFreq::fi(){
  return TF.end();
}

void TabFreq::read_tab(int n){
    string c;
    int fr;
    for(int i = 0; i < n; i++){
      cin >> c >> fr;
      TF[c] += fr;
    }
}

void TabFreq::print_tab() const{
  map<string,int>::const_iterator it;
  for(it = TF.begin(); it != TF.end(); ++it){
      cout << (*it).first << " " << (*it).second << endl;
  }
}
