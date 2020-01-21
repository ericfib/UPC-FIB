/** @file Cjt_idiomas.cc
    @brief Implementación de la clase Cjt_idiomas.hh
*/

#include "Cjt_idiomas.hh"

using namespace std;

Cjt_idiomas::Cjt_idiomas(){}

Cjt_idiomas::~Cjt_idiomas(){}

void Cjt_idiomas::codifica_I(string& key,string& text) const {
  cout << "Codifica en " << key << " el texto:" << endl;
  cout << text << endl;
  map<string,Idioma>:: const_iterator ite;
  ite = CJ_ID.find(key);
  if (ite != CJ_ID.end()){
    ite->second.codifica(text);
   }else{
    cout << "El idioma no existe" << endl;
  }
  cout << endl;
}

void Cjt_idiomas::decodifica_I(string& key, string& codi) const{
  cout << "Decodifica en " << key << " el texto:" << endl;
  cout << codi << endl;
  map<string,Idioma>:: const_iterator ite;
  ite = CJ_ID.find(key);
  if (ite != CJ_ID.end()){
    ite->second.ini_decodifica(codi);
   }else{
    cout << "El idioma no existe" << endl;
  }
  cout << endl;
}

void Cjt_idiomas::afegir_mod_idioma(string& key) {
  map<string,Idioma>::iterator it;
  int n;
  it = CJ_ID.find(key);
  if (it != CJ_ID.end()){
    cin >> n;
    (*it).second.modificaridioma(n);
    cout << "Modificado " << key << endl;
  }
  else{
    Idioma c;
    c.lee_idioma();
    CJ_ID[key] = c;
    cout << "Anadido " << key << endl;
  }
  cout << endl;
}

void Cjt_idiomas::print_taula(string key){
  map<string,Idioma>::iterator it;
  it = CJ_ID.find(key);
  cout << "Tabla de frecuencias de " << key << ":" << endl;
  if (it != CJ_ID.end()){
    (*it).second.tabla();
  }else{
    cout << "El idioma no existe" << endl;
  }
  cout << endl;
}

void Cjt_idiomas::print_lista(string key){
  map<string,Idioma>::iterator it;
  it = CJ_ID.find(key);
  cout << "Codigos de " << key << ":" << endl;
  if (it != CJ_ID.end()){
    (*it).second.codigos();
  }else{
     cout << "El idioma no existe" << endl;
   }
   cout << endl;
}

void Cjt_idiomas::print_code_op(string key, string key2){
  map<string,Idioma>::const_iterator ite;
  ite = CJ_ID.find(key);
  cout << "Codigo de " << key2 << " en " << key << ":" << endl;
  if (ite != CJ_ID.end()){
    ite->second.buscacodi(key2);
  }else{
    cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
  }
  cout << endl;
}

void Cjt_idiomas::print_I_treecode(string& key){
  map<string,Idioma>::iterator it;
  it = CJ_ID.find(key);
  cout << "Treecode de " << key << ":" << endl;
  if (it != CJ_ID.end()){
    (*it).second.print_treecode();
  } else {
    cout << "El idioma no existe" << endl;
  }
  cout << endl;
}

void Cjt_idiomas::read_conjunto(int n){
  for(int i = 0; i < n; i++){
    string b;
    cin >> b;
    Idioma a;
    a.lee_idioma();
    CJ_ID[b] = a;
  }
}
