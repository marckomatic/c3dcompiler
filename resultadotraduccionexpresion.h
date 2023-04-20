#ifndef RESULTADOTRADUCCIONEXPRESION_H
#define RESULTADOTRADUCCIONEXPRESION_H

using namespace std;
#include<string>

namespace Proyecto1 {

class ResultadoTraduccionExpresion
{
public:
    ResultadoTraduccionExpresion();
    ResultadoTraduccionExpresion(string _codigo, string _temporalResultado, string _tipo, string _mensajeError);
    string codigo; //aqui se guarda el codigo de la traduccion
    string temporalResultado;
    string tipo;
    string mensajeError;


};
}
#endif // RESULTADOTRADUCCIONEXPRESION_H
