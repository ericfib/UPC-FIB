/**
 * @mainpage Entrega final: documentación completa.

En esta práctica se construye un programa modular que ofrece un menú de opciones para gestionar un codificador y decodificador de textos en diversos idiomas. Se introducen las clases <em>Cjt_idiomas</em>, <em>Idioma</em> y <em>TabFreq</em>.

Se documenta la especificación y la implementación de los métodos públicos y los privados de cada clase.
*/


/** @file program.cc
    @brief Programa principal de la práctica
*/


#include "Cjt_idiomas.hh"

using namespace std;

int main (){
  int NI; //NI es nombre de idiomes
  string opcio;
  cin >> NI;
  Cjt_idiomas c1;
  c1.read_conjunto(NI);
  cin >> opcio;
  while(opcio != "fin"){
    if (opcio == "anadir/modificar"){
      string nomI;
      cin >> nomI;
      c1.afegir_mod_idioma(nomI);
    }

    else if (opcio == "codifica"){
      string text, nomI;
      cin >> nomI >> text;
      c1.codifica_I(nomI,text);
    }

    else if (opcio == "decodifica"){
      string codi, nomI;
      cin >> nomI >> codi;
      c1.decodifica_I(nomI,codi);
    }

    else if (opcio == "tabla_frec"){
      string nomI;
      cin >> nomI;
      c1.print_taula(nomI);
      }

    else if (opcio == "treecode"){
      string nomI;
      cin >> nomI;
      c1.print_I_treecode(nomI);
    }

    else if (opcio == "codigos"){
      string nomI, opcio2;
      cin >> nomI >> opcio2;
      if (opcio2 == "todos")
        c1.print_lista(nomI);
      else c1.print_code_op(nomI,opcio2);
    }
    cin >> opcio;
  }
}
