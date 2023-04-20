#include "sentencia.h"
#include "ast.h"
#include "resultadotraduccionexpresion.h"
namespace Proyecto1 {
Sentencia::Sentencia()
{

}

Sentencia::Sentencia(Expresion *_expresion){
    this->expresion = _expresion;
}

void Sentencia::ejecutar(){

    ResultadoTraduccionExpresion *resultadoExpresion = this->expresion->traducir();
    if(resultadoExpresion != 0 && resultadoExpresion->tipo.compare("error")!=0){
        AST::getAST()->salida += resultadoExpresion->codigo;
    }
}

}
