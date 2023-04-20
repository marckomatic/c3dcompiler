#ifndef GENERADORCODIGO3D_H
#define GENERADORCODIGO3D_H

using namespace std;
#include<string>

namespace Proyecto1 {
class GeneradorCodigo3D
{
public:
    GeneradorCodigo3D();

    int contadorTemporales;
    int contadorEtiquetas;


    string getTemporales();
    string getEtiquetas();
    string sumar(string direccionResultado, string temporalIzquierda, string temporalDerecha);
    string asignar(string direccionResultado, string valor);
    string generarIf(string temporalIzquierda, string temporalDerecha, string operador, string etiquetaDestino);
    string generarGoto(string etiquetaDestino);

};
}
#endif // GENERADORCODIGO3D_H
