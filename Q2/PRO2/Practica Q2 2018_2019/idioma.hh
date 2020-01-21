/** @file idioma.hh
    @brief Especificación de la clase Idioma
*/


#ifndef IDIOMA
#define IDIOMA

#include "TabFreq.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"

#include <set>
#endif

/** @class Idioma
    @brief Representa un idioma.

    Un idioma está formado por un string para su nombre y una tabla de frecuencias con todos
    los carácteres de ese idioma y la frecuencia con la que aparece cada uno.
*/


class Idioma
{
private:
      /** @brief Tabla de frecuencias del parametro implícito */
      TabFreq taula;
      /** @brief Treecode del parámetro implícito */
      BinTree<pair<string,int>> treecode;
      /** @brief Estructura para la lista de códigos de un idioma */
      map <string,string> lcodis;

      /** @brief Operación de creación de un conjunto de árboles de cada carácter del idioma.

          \pre <em>cierto</em>
          \post Se crea un conjunto de árboles que contienen un carácter del
          idioma cada uno
          \coste Lineal dependiendo del número de carácteres
      */
      set<BinTree<pair<string,int>>> sethojas (TabFreq& tab);

      /** @brief Operación de decodificación de una linea de códigos de carácteres.

          \pre 0 <= i <= codi.length()
          \post Si el código es correcto, se ha decodificado y se ha impreso el string
          correspondiente
          \coste Lineal
      */
      static string decodifica (const BinTree<pair<string,int>>& arbre, string& codi, int& i);

      /** @brief Crea la lista de codigos del alfabeto de un idioma.

      \pre Codi es un string vacío
      \post Los codigos de cada carácter de un idioma se han creado y guardado
      \coste Lineal en proporción a la cantidad de carácteres del idioma
      */
      void create_codigos (const BinTree<pair<string,int>>& arbre, string& codi);

      /** @brief Crea el treecode de un idioma.

      \pre s_arbre contiene un conjunto con las hojas del treecode
      \post Se ha creado el treecode del parámetro implícito
      \coste Lineal
      */
      void create_treecode (set<BinTree<pair<string,int>>>& s_arbre);

public:
    // Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un idioma.
        \pre <em>cierto</em>
        \post Crea un idioma con el nombre y el numero de carácteres indicados
        \coste Constante
    */
    Idioma ();

    /** @brief Destructora por defecto

        Se ejecuta automáticamente cuando el objeto local sale del ámbito de visibilidad
        \pre <em>cierto</em>
        \post El objeto local se ha borrado
        \coste Constante
    */
    ~Idioma ();

    //Modificadora

    /** @brief Modificadora del parámetro implícito.

        \pre <em>cierto</em>
        \post Se han modificado el parámetro implícito
        \coste Lineal dependiendo del proceso interno "modifica"
    */
    void modificaridioma(int n);

    /** @brief Operación que inicia la decodificación de un código.

        \pre <em>cierto</em>
        \post Se ha iniciado y acabado la decodificación del código
        \coste Constante
    */
    void ini_decodifica(string& codi) const;

    //Consultoras

    /** @brief Consultora del código de un carácter del parámetro implícito.

        \pre <em>cierto</em>
        \post Devuelve el código del carácter deseado
        \coste Logarítmico
    */
    void buscacodi(string key) const;

    /** @brief Operación que codifica el texto introducido.

        \pre <em>cierto</em>
        \post Si el texto era válido para codificar, se imprime el resultado
        \coste Lineal
    */
    void codifica (const string& text) const;

    /** @brief Consultora de la tabla de frecuencias del parámetro implícito.

        \pre <em>cierto</em>
        \post Se imprime por el canal de salida la tabla de frecuencias del
        parámetro implícito
        \coste Lineal proporcional a la dimensión de la tabla
    */
    void tabla();

    /** @brief Consultora del treecode del idioma.

        \pre <em>cierto</em>
        \post Se ha impreso el treecode en preorden e inorden
        \coste Lineal
    */
    void print_treecode();

    //Entrada/Salida

    /** @brief Operación de escritura de los códigos del alfabeto del parámetro implícito.

        \pre <em>cierto</em>
        \post Se imprimen por el canal de salida los códigos de todos los carácteres
        del parámetro implícito
        \coste Lineal proporcional al número de códigos a imprimir
    */
    void codigos();

    /** @brief Operación de escritura en preorden del treecode de un idioma.

        \pre <em>cierto</em>
        \post Se imprime en preorden por el canal de salida el treecode del parámetro implícito.
        \coste Lineal dependiendo del mnúmero de nodos del treecode
    */
    void tree_pre(const BinTree<pair<string,int>>& a);

    /** @brief Operación de escritura en inorden del treecode del parámetro implícito.

        \pre <em>cierto</em>
        \post Se imprime en inorden por el canal de salida el treecode del parámetro implícito
        \coste Lineal dependiendo del mnúmero de nodos del treecode
    */
    void tree_in(const BinTree<pair<string,int>>& a);

    /** @brief Operación de lectura.

        \pre <em>cierto/em>
        \post EL parámetro implícito pasa a tener una tabla de frecuencias, un treecode y una lista códigos
        \coste Lineal
    */
    void lee_idioma ();
};
#endif
