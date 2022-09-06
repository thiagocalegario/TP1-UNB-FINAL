#include "dominios.h"

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes dom�nio.

void Email::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Senha::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Codigo::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Cidade::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Nome::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Pais::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Nota::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Descricao::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Aniversario::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Idioma::validar(string valor){
    if(valor.length() > 1000)
        throw invalid_argument("Valor invalido");
}

void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}
