/** @file TabFreq.hh
    @brief Especificación de la clase TabFreq
*/

#ifndef TAB_FREQ
#define TAB_FREQ

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

using namespace std;

/** @class TabFreq
    @brief Representa una tabla de frecuencias de los carácteres de un idioma.

    Unatabla de frecuencias es una estructura formada por los elementos del alfabeto de un idioma.
    Estos elementos son pares de strings y enteros, es decir, caracteres y sus frecuencias.
*/

class TabFreq
{
private:

  /** @brief Estructura interna de la tabla de frecuencias de un idioma */
  map <string,int> TF;

public:
  //Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una tabla de frecuencias.
      \pre <em>cierto</em>
      \post El resultado es una tabla de frecuencia vacía
      \coste Constante
  */
  TabFreq ();

  /** @brief Creadora copiadora.

      Permite declarar una tabla de frecuencias nueva como copia de otra ya existente.
      \pre <em>cierto</em>
      \post El resultado es una TabFreq igual que c
      \coste Lineal respecto al número de pares de c
  */
  TabFreq (const TabFreq& tf);

  /** @brief Destructora por defecto

      Se ejecuta automáticamente cuando el objeto local sale del ámbito de visibilidad
      \pre <em>cierto</em>
      \post El objeto local se ha borrado en salir del àmbito de visibilidad
      \coste Constante
  */
  ~TabFreq ();

  //Modificadoras

  /** @brief Operación que modifica el parámetro implícito, añadiendo los pares que hagan falta.

      \pre <em>cierto</em>
      \post Se ha modificado el parámetro implícito
      \coste Lineal
  */
  void modifica(int n);

  //Consultoras

  /** @brief Consultora que devuelve un iterador apuntando al inicio de la tabla.

      \pre <em>cierto</em>
      \post Devuelve un iterador apuntando al inicio del parámetro implícito
      \coste Logarítmico
  */
  map<string,int>::iterator inici();

  /** @brief Consultora que devuelve un iterador apuntando al final de la tabla.

      \pre <em>cierto</em>
      \post Devuelve un iterador apuntando al final del parámetro implícito
      \coste Logarítmico
  */
  map<string,int>::iterator fi();

  //Entrada/Salida

  /** @brief Operación de lectura.


      \pre <em>cierto</em>
      \post Se ha leído una tabla de n elementos por el canal de entrada estandar
      \coste Lineal en relación de cuantos elementos se lean
  */
  void read_tab (int n);

  /** @brief Operación de escritura.

      \pre <em>cierto</em>
      \post Se escribe por el canal de salida estandar el parámetro implícito
      \coste Lineal en relación a cuántos elementos tenga la tabla a imprimir
  */
  void print_tab () const;

};
#endif
