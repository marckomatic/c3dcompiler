#ifndef AST_H
#define AST_H

using namespace std;
#include <QList>
#include "sentencia.h"
#include "generadorcodigo3d.h"
namespace Proyecto1 {
class AST
{
public:
    AST();
    static AST *ast;
    static AST *getAST();

    std::string salida;
    QList<Sentencia> listaSentencias;
    std::string listaErrores;
    GeneradorCodigo3D generadorCodigo;
    void ejecutar();
};

}
#endif // AST_H
