#include "resultadotraduccionexpresion.h"
namespace Proyecto1 {

ResultadoTraduccionExpresion::ResultadoTraduccionExpresion()
{

}

ResultadoTraduccionExpresion::ResultadoTraduccionExpresion(string _codigo, string _temporalResultado,
                                                           string _tipo, string _mensajeError)
{
    this->codigo = _codigo;
    this->temporalResultado = _temporalResultado;
    this->mensajeError = _mensajeError;
    this->tipo = _tipo;
}
}
