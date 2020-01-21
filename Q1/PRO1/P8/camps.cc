#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > matriz;

void funcion(matriz& campo, int x, int y) {
        for (int i = x; i < campo.size() ; ++i) {
                if (campo[i][y] != 0) {
                        for (int j = y; j < campo[0].size() ; ++j) {
                                if (campo[i][j] != 0) campo[i][j] = 0;
                                else {
                                        j = campo[0].size() ;
                                }
                        }
                }
                else i = campo.size() ;
        }
}

int main() {
        int f, c; // f = filas, c = columnas
        while (cin >> f >> c){ // leemos filas y columnas del campo
                matriz campo(f, vector<int>(c,0)); // creamos la matriz del campo
                for (int m = 0; m < f; ++m) {
                        for (int n = 0; n < c; ++n) { // para llenar cada posicion de la matriz campo
                                cin >> campo[m][n];
                        }
                }
                int contador = 0; // creamos el contador, que empieza en cero
                for (int i = 0; i < f; ++i) {
                        for (int j = 0; j < c; ++j) { // para pasar por cada posicion de la matriz campo
                                if (campo[i][j] != 0) {
                                        funcion(campo, i, j); // encontramos inicio rectángulo-> usamos la funcion para eliminarlo
                                        ++contador;
                                }
                        }
                }
                cout << contador << endl;
        }
}
