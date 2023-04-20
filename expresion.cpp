#include "expresion.h"
#include "resultadotraduccionexpresion.h"
#include "ast.h"
namespace Proyecto1{
    Expresion::Expresion()
    {

    }

    Expresion::Expresion(Expresion* _operandoIzquierda, Expresion* _operandoDerecha, char _operador){
        this->operandoIzquierda = _operandoIzquierda;
        this->operandoDerecha = _operandoDerecha;
        this->operador = _operador;
    }

    ResultadoTraduccionExpresion* Expresion::traducir(){
        string codigo = "";
        string temporalResultado = "";
        string tipo = "";
        string mensajeError = "";


        switch(this->operador){
            case '>':
            {
                ResultadoTraduccionExpresion* resultadoIzquierda = this->operandoIzquierda->traducir();
                ResultadoTraduccionExpresion* resultadoDerecha = this->operandoDerecha->traducir();

                if(resultadoIzquierda->tipo.compare("error") == 0){
                    return resultadoIzquierda;
                }
                if(resultadoDerecha->tipo.compare("error")==0){
                    return resultadoDerecha;
                }
                if(resultadoIzquierda->tipo.compare("entero") == 0 && resultadoDerecha->tipo.compare("entero")==0){
                    temporalResultado = AST::getAST()->generadorCodigo.getTemporales();
                    codigo += resultadoIzquierda->codigo + "\n";
                    codigo += resultadoDerecha->codigo + "\n";
                    string etiquetaEsVerdadero = AST::getAST()->generadorCodigo.getEtiquetas();
                    string etiquetaFinIf = AST::getAST()->generadorCodigo.getEtiquetas();
                    codigo += AST::getAST()->generadorCodigo.generarIf(resultadoIzquierda->temporalResultado,
                                                                       resultadoDerecha->temporalResultado,
                                                                       ">", etiquetaEsVerdadero)+"\n";
                    codigo += AST::getAST()->generadorCodigo.asignar(temporalResultado, "0")+"\n";
                    codigo += AST::getAST()->generadorCodigo.generarGoto(etiquetaFinIf)+"\n";
                    codigo += etiquetaEsVerdadero + ":\n";
                    codigo += AST::getAST()->generadorCodigo.asignar(temporalResultado, "1")+"\n";
                    codigo += etiquetaFinIf + ":\n";
                    tipo = "booleano";
                    return new ResultadoTraduccionExpresion(codigo, temporalResultado, tipo, mensajeError);
                }else{
                    return new ResultadoTraduccionExpresion("", "", "error", "No se pueden comparar los tipos " + resultadoIzquierda->tipo + " y " + resultadoDerecha->tipo);

                }
                return 0;
            }
            case '+':
            {
                ResultadoTraduccionExpresion* resultadoIzquierda = this->operandoIzquierda->traducir();
                ResultadoTraduccionExpresion* resultadoDerecha = this->operandoDerecha->traducir();

                if(resultadoIzquierda->tipo.compare("error") == 0){
                    return resultadoIzquierda;
                }
                if(resultadoDerecha->tipo.compare("error")==0){
                    return resultadoDerecha;
                }
                if(resultadoIzquierda->tipo.compare("entero") == 0 && resultadoDerecha->tipo.compare("entero")==0){
                    temporalResultado = AST::getAST()->generadorCodigo.getTemporales();
                    codigo += resultadoIzquierda->codigo + "\n";
                    codigo += resultadoDerecha->codigo + "\n";

                    codigo += AST::getAST()->generadorCodigo.sumar(temporalResultado,
                                                                  resultadoIzquierda->temporalResultado,
                                                                  resultadoDerecha->temporalResultado);

                    tipo = "entero";
                    return new ResultadoTraduccionExpresion(codigo, temporalResultado, tipo, mensajeError);
                }else{
                    return new ResultadoTraduccionExpresion("", "", "error", "No se pueden sumar los tipos " + resultadoIzquierda->tipo + " y " + resultadoDerecha->tipo);

                }
                return 0;
            }
            case '-':
                return 0;
            case '*':
                return 0;
            case '/':
                return 0;
            case '#':
                return new ResultadoTraduccionExpresion("", this->valor, "entero", "");
            case 'f':
            {
                tipo = "booleano";
                temporalResultado = AST::getAST()->generadorCodigo.getTemporales();
                codigo += AST::getAST()->generadorCodigo.asignar(temporalResultado, "0") + "\n";
                return new ResultadoTraduccionExpresion(codigo, temporalResultado, tipo, "");

            }
            case 't':
            {
                tipo = "booleano";
                temporalResultado = AST::getAST()->generadorCodigo.getTemporales();
                codigo += AST::getAST()->generadorCodigo.asignar(temporalResultado, "1") + "\n";
                return new ResultadoTraduccionExpresion(codigo, temporalResultado, tipo, "");
            }


        }


    }

    int Expresion::evaluar(){
        switch(this->operador){
            case '+':
                return operandoIzquierda->evaluar() + operandoDerecha->evaluar();
            case '-':
                return operandoIzquierda->evaluar() - operandoDerecha->evaluar();
            case '*':
                return operandoIzquierda->evaluar() * operandoDerecha->evaluar();
            case '/':
                return operandoIzquierda->evaluar() / operandoDerecha->evaluar();
            case '#':
                return stoi(this->valor);

        }
        return 0;
    }


}
