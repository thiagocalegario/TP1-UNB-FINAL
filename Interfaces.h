#ifndef INTERFACES_H
#define INTERFACES_H
#include <string>
#include "Dominios.h"
#include "Entidades.h"

class IServicoAutenticacao;
class IServicoUsuario;
class IServicoHospedagem;
class IServicoAvaliacao;


class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){};
};



class IApresentacaoUsuario {
    public:
        virtual bool cadastrar() = 0;
        virtual void executar(Email*) = 0;
        virtual void setCntrServicoUsuario(IServicoUsuario*) = 0;
        virtual ~IApresentacaoUsuario(){};
};



class IApresentacaoHA {
    public:
        virtual void executar(Email*) = 0;
        virtual void executar() = 0;
        virtual void setCntrServicoHospedagem(IServicoHospedagem*) = 0;
        virtual void setCntrServicoAvaliacao(IServicoAvaliacao*) = 0;
        virtual ~IApresentacaoHA(){};

};



class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email*, Senha*) = 0;
};



class IServicoUsuario {
    public:
        virtual bool descadastrar(Email*) = 0;
        virtual bool alterar(Usuario*) = 0;
        virtual bool cadastrar(Usuario*) = 0;
        virtual bool cadastrarEmHospedagem(Email*, string) = 0;
};


class IServicoHospedagem{
    public:
        virtual bool incluir(Hospedagem*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Hospedagem*) = 0;
        virtual string visualizar(Codigo*) = 0;
        virtual string listar() = 0;

};


class IServicoAvaliacao{
    public:
        virtual bool incluir(Avaliacao*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Avaliacao*) = 0;
        virtual string visualizar(Codigo*) = 0;
        virtual string listar() = 0;

};

#endif // INTERFACES_H
