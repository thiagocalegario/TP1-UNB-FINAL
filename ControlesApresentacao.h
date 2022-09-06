#ifndef CONTROLES_APRESENTACAO_H
#define CONTROLES_APRESENTACAO_H

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"

#ifdef _WIN32   // OS Windows
#define CLR system("CLS")
#elif __linux__  // OS Linux
#define CLR system("clear")
#endif


//=================================================================\\
//=================================================================\\
//=================================================================\\


class CntrApresentacaoControle {
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoUsuario *cntrApresentacaoUsuario;
        IApresentacaoHA *cntrApresentacaoHA;

    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {cntrApresentacaoAutenticacao = cntr;};
        void setCntrApresentacaoUsuario(IApresentacaoUsuario *cntr) {cntrApresentacaoUsuario = cntr;};
        void setCntrApresentacaoHA(IApresentacaoHA *cntr) {cntrApresentacaoHA = cntr;};
};


//=================================================================\\
//=================================================================\\
//=================================================================\\


class CntrApresentacaoAutenticacao: public IApresentacaoAutenticacao {
    private:
        IServicoAutenticacao *cntr;

    public:
        bool autenticar(Email *email) override;
        void setCntrServicoAutenticacao(IServicoAutenticacao *cntr) override {this->cntr = cntr;};

};


//=================================================================\\
//=================================================================\\
//=================================================================\\


class CntrApresentacaoUsuario: public IApresentacaoUsuario {
    private:
        IServicoUsuario *cntr;

    public:
        bool editar(Email *email);
        bool cadastrar() override;
        void executar(Email *email) override;
        void setCntrServicoUsuario(IServicoUsuario *cntr) override {this->cntr = cntr;};
};


//=================================================================\\
//=================================================================\\
//=================================================================\\


class CntrApresentacaoHA: public IApresentacaoHA {
    private:
        void editar();
        bool editarHospedagem();
        bool editarAvaliacao();

        void incluir();
        bool incluirHospedagem();
        bool incluirAvaliacao();

        void excluir();
        bool excluirHospedagem();
        bool excluirAvaliacao();

        void visualizar();

        IServicoHospedagem *cntrHospedagem;
        IServicoAvaliacao *cntrAvaliacao;

    public:
        void executar(Email *email) override;
        void executar() override;
        void setCntrServicoHospedagem(IServicoHospedagem *cntrHospedagem) override {this->cntrHospedagem = cntrHospedagem;};
        void setCntrServicoAvaliacao(IServicoAvaliacao *cntrAvaliacao) override {this->cntrAvaliacao = cntrAvaliacao;};
};


#endif // CONTROLES_APRESENTACAO_H
