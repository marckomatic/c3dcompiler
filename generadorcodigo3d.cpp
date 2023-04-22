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
    return direccionResultado + " = " + temporalIzquierda + " + " + temporalDerecha + ";\n";
}


string GeneradorCodigo3D::asignar(string direccionResultado, string valor){
    return direccionResultado + " = " + valor + ";\n";
}

string GeneradorCodigo3D::generarIf(string temporalIzquierda, string temporalDerecha, string operador, string etiquetaDestino){
    return "if(" + temporalIzquierda + operador + temporalDerecha + ") goto " + etiquetaDestino + ";\n";
}

string GeneradorCodigo3D::generarGoto(string etiquetaDestino){
    return "goto " + etiquetaDestino + ";\n";
}

string GeneradorCodigo3D::getEtiquetas(){
    string etiqueta = "L"+ to_string(this->contadorEtiquetas);
    this->contadorEtiquetas++;
    return etiqueta;
}


string GeneradorCodigo3D::generarObtenerDeStack(string destino, string posicionARecuperar){
    return destino + " = stack[(int)" + posicionARecuperar +"];\n";
}

string GeneradorCodigo3D::generarObtenerDeHeap(string destino, string posicionARecuperar){
    return destino + " = heap[(int)" + posicionARecuperar +"];\n";
}







//aqui se generan las funciones nativas


string GeneradorCodigo3D::generarPrintCadena(){
    string temporalIndex = this->getTemporales();
    string etiquetaInicioCiclo = this->getEtiquetas();
    string etiquetaFinCiclo = this->getEtiquetas();
    string temporalCaracterAImprimir = this->getTemporales();

    string salida = "void native96_PrintString(){\n";
    salida += "\t" + this->generarObtenerDeStack(temporalIndex, "P") + "\n";
    salida += "\t" + etiquetaInicioCiclo + ":\n";
    salida += "\t" + this->generarObtenerDeHeap(temporalCaracterAImprimir, temporalIndex);
    salida += "\t" + this->generarIf(temporalCaracterAImprimir, "-1", "==", etiquetaFinCiclo) + ";\n";
    salida += "\tprintf(\"%c\", (int)" + temporalCaracterAImprimir + ");\n";
    salida += "\t" + this->sumar(temporalIndex, temporalIndex, "1");
    salida += "\t" + this->generarGoto(etiquetaInicioCiclo);
    salida += "\t" + etiquetaFinCiclo + ":\n";


    salida += "}\n";
    return salida;
}

}

