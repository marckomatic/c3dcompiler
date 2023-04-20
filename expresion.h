#ifndef EXPRESION_H
#define EXPRESION_H

using namespace std;
#include<string>
#include "resultadotraduccionexpresion.h"
namespace Proyecto1{
class Expresion
{
public:
    Expresion();
    Expresion(Expresion *_operandoIzquierda, Expresion *_operandoDerecha, char _operador);
    Expresion *operandoIzquierda;
    Expresion *operandoDerecha;

    ResultadoTraduccionExpresion *traducir();
    char operador;
    string valor;
    int evaluar();
};
}
#endif // EXPRESION_H
