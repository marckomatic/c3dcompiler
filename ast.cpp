#include "ast.h"

namespace Proyecto1 {
AST* AST::ast;

AST::AST()
{
    this->listaErrores = "";
    this->listaSentencias = QList<Sentencia>();
}

AST* AST::getAST(){
    if(AST::ast == nullptr){
        AST::ast = new AST();
    }
    return AST::ast;
}

void AST::ejecutar(){
    this->salida = "#include <stdio.h>\n double heap[100000];\n double stack[100000];\n double P;\n double H;\n double ";

    for(int i=0; i<this->generadorCodigo.contadorTemporales; i++){
        this->salida += "t" + i;
        if(i < this->generadorCodigo.contadorTemporales - 2){
            this->salida += ", ";
        }
        if(i % 13 == 0){
            this->salida += "\n ";

        }
    }
    this->salida += ";\n";

    for(int i=0; i<this->listaSentencias.length(); i++){
        listaSentencias[i].ejecutar();
    }
}

}
