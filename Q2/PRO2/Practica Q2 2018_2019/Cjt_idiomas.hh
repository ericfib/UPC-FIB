/** @file Cjt_idiomas.hh
    @brief Especificación de la clase Cjt_idiomas
*/

#ifndef CJT_IDI
#define CJT_IDI

#include "idioma.hh"
#endif


/** @class Cjt_idiomas
    @brief Representa un conjunto de idiomas.

*/

class Cjt_idiomas
{
private:
    /** @brief Estructura del conjunto de idiomas */
    map<string,Idioma> CJ_ID;

public:

    //Constructora
    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de idiomas.
        \pre <em>cierto</em>
        \post Crea un conjunto de idiomas
        \coste Constante
    */
    Cjt_idiomas ();

    /** @brief Destructora por defecto

        Se ejecuta automáticamente cuando el objeto local sale del ámbito de visibilidad
        \pre <em>cierto</em>
        \post El objeto local se ha borrado
        \coste Constante
    */
    ~Cjt_idiomas ();

    //Modificadora

    /** @brief Modificadora del conjunto de idiomas.

        \pre <em>cierto</em>
        \post Si el parámetro implícito no contiene un idioma con el mismo nombre
        que el introducido, se añade. En caso contrario, se modifica el ya existente
        añadiendo nuevos elementos. Para ambos casos se trabaja el treecode adecuadamente.
        \coste Lineal dependiendo de la cantidad de elementos que contiene el
        nuevo idioma o la cantidad de elementos a añadir al ya existente
    */
    void afegir_mod_idioma (string& key);

    //Consultoras

    /** @brief Consultora de la codificación del texto introducido en un idioma contreto.

        \pre <em>cierto</em>
        \post Se muestra el codigo del texto introducido y se muestra por el canal de salida
        \coste Lineal dependiendo del tamaño del conjunto y del texto
    */
    void codifica_I (string& key,string& text) const;

    /** @brief Consultora de la decodificación del código introducido en un idioma concreto.

        \pre <em>cierto</em>
        \post Se ha decodificado el texto introducido y se muestra por el canal de salida
        \coste Lineal dependiendo del tamaño del conjunto y del codigo
    */
    void decodifica_I (string& key, string& codi) const;

    /** @brief Consultora de la tabla de frecuencias de un idioma del conjunto.

        \pre El parámetro implícito no esta vacío y hay un string preparado para encontrar
        el idioma deseado
        \post Se ha impreso el contenido de la tabla de frecuencias del idioma deseado
        \coste Logarítmico
    */
    void print_taula (string key);

    /** @brief Consultora de la lista de códigos de un idioma del conjunto.

        \pre El parámetro implícito no esta vacío y hay un string preparado para encontrar
        el idioma deseado
        \post Se ha impreso la lista de codigos del idioma deseado
        \coste Logarítmico
    */
    void print_lista (string key);

    /** @brief Consultora del código de un  carácter de un idioma del conjunto.

        \pre El parámetro implícito no esta vacío y hay dos string preparados para encontrar
        el idioma y carácter deseados
        \post Se ha impreso el código del carácter deseado
        \coste Logarítmico
    */
    void print_code_op (string key, string key2);

    /** @brief Consultora del treecode de un idioma del conjunto.

        \pre <em>cierto</em>
        \post Se ha impreso el treecode del idioma deseado
        \coste Logarítmico
    */
    void print_I_treecode (string& key);

    //Entrada/Salida

    /** @brief Operación de lectura.

        \pre <em>cierto</em>
        \post Se guardan los datos introducidos en el parámetro implícito
        \coste Lineal dependiendo de cuantos idiomas se quieran leer
    */
    void read_conjunto (int n);
};
