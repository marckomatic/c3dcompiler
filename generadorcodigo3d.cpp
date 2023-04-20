#include "generadorcodigo3d.h"
#include <string>

namespace Proyecto1 {
GeneradorCodigo3D::GeneradorCodigo3D()
{
    this->contadorTemporales=0;
    this->contadorEtiquetas=0;

}

string GeneradorCodigo3D::getTemporales(){
    string temporal = "t"+ to_string(this->contadorTemporales);
    this->contadorTemporales++;
    return temporal;
}

string GeneradorCodigo3D::sumar(string direccionResultado, string temporalIzquierda, string temporalDerecha){
    return direccionResultado + " = " + temporalIzquierda + " + " + temporalDerecha + ";";
}


string GeneradorCodigo3D::asignar(string direccionResultado, string valor){
    return direccionResultado + " = " + valor + ";";
}

string GeneradorCodigo3D::generarIf(string temporalIzquierda, string temporalDerecha, string operador, string etiquetaDestino){
    return "if(" + temporalIzquierda + operador + temporalDerecha + ") goto " + etiquetaDestino + ";";
}

string GeneradorCodigo3D::generarGoto(string etiquetaDestino){
    return "goto " + etiquetaDestino + ";";
}

string GeneradorCodigo3D::getEtiquetas(){
    string etiqueta = "L"+ to_string(this->contadorEtiquetas);
    this->contadorEtiquetas++;
    return etiqueta;
}
}

