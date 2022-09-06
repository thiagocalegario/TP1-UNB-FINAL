#ifndef CONTROLES_SERVICO_H
#define CONTROLES_SERVICO_H

#include <string>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"



class CntrServicoAutenticacao: public IServicoAutenticacao {

    public:
        bool autenticar(Email* email, Senha* senha) override;

};

//Usuario
class CntrServicoUsuario: public IServicoUsuario {
    public:
        bool descadastrar(Email *email) override;
        bool alterar(Usuario *usuario) override;
        bool cadastrar(Usuario *usuario) override;
        bool cadastrarEmHospedagem(Email *email, string hospedagem) override;
};

//Hospedagem
class CntrServicoHospedagem: public IServicoHospedagem {
    public:
        bool incluir(Hospedagem *hospedagem) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Hospedagem *hospedagem) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};

//Avaliacao
class CntrServicoAvaliacao: public IServicoAvaliacao {
    public:
        bool incluir(Avaliacao *avaliacao) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Avaliacao *avaliacao) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};




#endif // CONTROLES_SERVICO_H
