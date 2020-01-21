/** @file idioma.cc
    @brief Implementación de la clase idioma.hh
*/


#include "idioma.hh"
#include "TabFreq.hh"

using namespace std;

//Privadas

set<BinTree<pair<string,int>>> Idioma::sethojas(TabFreq& tab){
  set<BinTree<pair<string,int>>> conj;
  TabFreq d(tab);
  //d ahora es igual a la tabla de frecuencias del idioma
  map<string,int>::iterator ite = d.inici();

  /**
    el iterador apunta al primer elemento de tab y se pone en el par carry, para luego
    crear un BinTree sin hijos con ese valor
  */

    pair<string,int> carry;
    while(ite != d.fi()){
      carry.first = ite->first;
      carry.second = ite->second;
      BinTree<pair<string,int>> node(carry);
      conj.insert(node);
      ++ite;
    }
    return conj;
}

string Idioma::decodifica(const BinTree<pair<string,int>>& arbre, string& codi, int& i){
  if (i <= codi.length()){
    if (arbre.left().empty()) return arbre.value().first;
    else if (codi[i] == '0') {
      i++;
      return decodifica(arbre.left(),codi,i);
    }
    else{
      i++;
      return decodifica(arbre.right(),codi,i);
    }
  }else{
    return "no";
  }
}

void Idioma::create_codigos(const BinTree<pair<string,int>>& arbre, string& codi){
  if(arbre.left().empty()) lcodis[arbre.value().first]=codi;
  else{
    string ret = codi+"0";
    create_codigos(arbre.left(), ret);
    ret = codi+"1";
    create_codigos(arbre.right(), ret);
  }
}

void Idioma::create_treecode(set<BinTree<pair<string,int>>>& s_arbre){
  set<BinTree<pair<string,int>>>::iterator ite = s_arbre.begin();
  int tam = s_arbre.size();
  while (tam != 1){
    BinTree<pair<string,int>> l;  //left
    pair<string,int> lp; //parell que tindra el valor de left
    BinTree<pair<string,int>> r;  //right
    pair<string,int> rp; //parell que tindra el valor de right

    l = (*ite);
    lp = l.value();
    s_arbre.erase(ite);

    ite = s_arbre.begin();

    r = (*ite);
    rp = r.value();
    s_arbre.erase(ite);

    pair<string,int> comb;
    if (lp.first <= rp.first) comb.first = lp.first + rp.first;
    else comb.first = rp.first + lp.first;
    comb.second = lp.second + rp.second;

    BinTree<pair<string,int>> aaa (comb, l, r);
    s_arbre.insert(aaa);
    tam = s_arbre.size();
    ite = s_arbre.begin();
    }
  ite = s_arbre.begin();
  BinTree<pair<string,int>> arbre = (*ite);
  treecode = arbre;
}

//Públicas

Idioma::Idioma(){}

Idioma::~Idioma(){}


void Idioma::modificaridioma(int n){
  taula.modifica(n);
  set<BinTree<pair<string,int>>> s_arbre = sethojas(taula);
  create_treecode(s_arbre);
  string codis = "";
  create_codigos(treecode,codis);
}

void Idioma::ini_decodifica(string& codi) const{
  string result, a;
  int i = 0, i2 = 0;
  bool ok = true;
  while (ok and i < codi.length()){
    a = decodifica(treecode,codi,i);
    if (a == "no") ok = false;
    else{
      i2 = i;
      result += a;
    }
  }
  if (ok) cout << result << endl;
  else{
    cout << "El texto no procede de una codificacion del idioma;";
    cout << " ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << i2 << endl;
  }
}

void Idioma::buscacodi(string key) const{
  map<string,string>::const_iterator ite;
  ite = lcodis.find(key);
  if (ite != lcodis.end()){
    cout << ite->first << " " << ite->second << endl;
  }else{
    cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
  }
}

void Idioma::codifica (const string& text) const{
  string result = "", b;
  int i = 0;
  bool noexiste = false;
  map<string,string>::const_iterator it;
  while(not noexiste and i < text.length()){
    b = (text[i] < 0)? text.substr(i,2) : string(1,text[i]);
    it = lcodis.find(b);
    if (it != lcodis.end()){
      result += it->second;
    }else{
      noexiste = true;
    }
    i += (text[i] < 0)? 2 : 1;
  }
  if (noexiste) cout << "El texto no pertenece al idioma; primer caracter que falla: " << b << endl;
  else cout << result << endl;
}

void Idioma::tabla(){
  taula.print_tab();
}

void Idioma::print_treecode(){
  cout << "recorrido en preorden:" << endl;
  tree_pre(treecode);

  cout << "recorrido en inorden:" << endl;
  tree_in(treecode);
}

void Idioma::codigos(){
  for(map<string,string>::iterator it = lcodis.begin(); it != lcodis.end(); ++it){
    cout << it->first << " " << it->second << endl;
  }
}

void Idioma::tree_pre(const BinTree<pair<string,int>>& a){
  if (not a.empty()){
    cout << a.value().first << " " << a.value().second << endl;
    tree_pre(a.left());
    tree_pre(a.right());
  }
}

void Idioma::tree_in(const BinTree<pair<string,int>>& a){
  if(not a.empty()){
    tree_in(a.left());
    cout << a.value().first << " " << a.value().second << endl;
    tree_in(a.right());
  }
}

void Idioma::lee_idioma(){
    int num;
    cin >> num;
    if (num >= 2){
      string codis = "";
      taula.read_tab(num);
      set<BinTree<pair<string,int>>> s_arbre = sethojas(taula);
      create_treecode(s_arbre);
      create_codigos(treecode,codis);
    } else cout << "El número mínimo de carácteres es 2" << endl;
  }

//  Operator < para árboles binarios. He hecho esto para que el set se pueda ordenar automáticamente,
//  ya que la biblioteca BinTree.hh no tiene un operador < implementado

bool operator< (const BinTree<pair<string,int>>& a, const BinTree<pair<string,int>>& b){
  pair<string,int> p_a = a.value();
  pair<string,int> p_b = b.value();

  if (p_a.second == p_b.second){
    return (p_a.first < p_b.first);
  }else return (p_a.second < p_b.second);
}
