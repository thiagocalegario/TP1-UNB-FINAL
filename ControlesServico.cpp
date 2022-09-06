#include <unordered_map>
#include "ControlesServico.h"
#include "container.h"

using namespace std;


//=================================================================\\
//=========================Autenticacao==============================\\
//=================================================================\\


bool CntrServicoAutenticacao::autenticar(Email* email, Senha* senha){
    ContainerUsuario* cp = ContainerUsuario::getInstancia();
    Usuario *usuario = cp->pesquisar(email->getValor());

    if (usuario == nullptr){
        return false;
    }
    else{
        if (usuario->getSenha().getValor() == senha->getValor()){
            return true;
        }
        else{
            return false;
        }
    }
}


//=================================================================\\
//=========================Usuario==============================\\
//=================================================================\\


bool CntrServicoUsuario::descadastrar(Email *email){
    ContainerUsuario* cp = ContainerUsuario::getInstancia();

    return cp->remover(email->getValor());
}

bool CntrServicoUsuario::alterar(Usuario *usuario){
    ContainerUsuario* cp = ContainerUsuario::getInstancia();

    if (cp->atualizar(usuario)){
        return true;
    }
    else{
        return false;
    }
}

bool CntrServicoUsuario::cadastrar( Usuario *usuario){
    ContainerUsuario* cp = ContainerUsuario::getInstancia();
    return(cp->incluir(usuario));
}


bool CntrServicoUsuario::cadastrarEmHospedagem(Email *email, string hospedagem) {
    Hospedagem2Usuario *relacao = Hospedagem2Usuario::getInstancia();
    return relacao->incluir(hospedagem, email->getValor());
}


//=================================================================\\
//=========================Hospedagem==============================\\
//=================================================================\\

bool CntrServicoHospedagem::incluir(Hospedagem *hospedagem){
    ContainerHospedagem* cp = ContainerHospedagem::getInstancia();
	return cp -> incluir(hospedagem);
}

bool CntrServicoHospedagem::excluir(Codigo *codigo){
    ContainerHospedagem* cp = ContainerHospedagem::getInstancia();

	return cp->remover(codigo->getValor());
}

bool CntrServicoHospedagem::editar(Hospedagem *hospedagem){
    ContainerHospedagem* cp = ContainerHospedagem::getInstancia();
    if (cp->pesquisar(hospedagem->getCodigo().getValor()) == nullptr){
        return false;
    }
    return cp->atualizar(hospedagem);
}

string CntrServicoHospedagem::visualizar(Codigo *codigo){
    ContainerHospedagem* cp = ContainerHospedagem::getInstancia();
    Hospedagem* hospedagem = cp->pesquisar(codigo->getValor());
    if(hospedagem == nullptr)
        return "Hospedagem nao encontrada.";
    string saida = "Codigo: ";
    saida += hospedagem->getCodigo().getValor();
    saida += "\nPais: ";
    saida += hospedagem->getPais().getValor();
    saida += "\nNota: ";
    saida += hospedagem->getNota().getValor();
    saida += "\nCidade: ";
    saida += hospedagem->getCidade().getValor();
    return saida;
}


string CntrServicoHospedagem::listar(){
    ContainerHospedagem *cp = ContainerHospedagem::getInstancia();
    ContainerHospedagem::cmap mp = cp->getMap();
    string saida = "Hospedagens:";
    for(ContainerHospedagem::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}


//=================================================================\\
//=========================Avaliacao==============================\\
//=================================================================\\


bool CntrServicoAvaliacao::incluir(Avaliacao *avaliacao){
    ContainerAvaliacao* cs = ContainerAvaliacao::getInstancia();
    return cs-> incluir(avaliacao);
}

bool CntrServicoAvaliacao::excluir(Codigo *codigo){
    ContainerAvaliacao* cs = ContainerAvaliacao::getInstancia();

    return cs-> remover(codigo->getValor());
}

bool CntrServicoAvaliacao::editar(Avaliacao *avaliacao){
    ContainerAvaliacao* cs = ContainerAvaliacao::getInstancia();
    if (cs->pesquisar(avaliacao->getCodigo().getValor()) == nullptr){
        return false;
    }
    return cs->atualizar(avaliacao);
}

string CntrServicoAvaliacao::visualizar(Codigo *codigo){
    ContainerAvaliacao* cs = ContainerAvaliacao::getInstancia();
    Avaliacao* avaliacao = cs->pesquisar(codigo->getValor());
    if(avaliacao == nullptr)
        return "Avaliacao não encontrada";
    string saida = "Codigo: ";
    saida += avaliacao->getCodigo().getValor();
    saida += "\nDescricao: ";
    saida += avaliacao->getDescricao().getValor();
    saida += "\nNota: ";
    saida += avaliacao->getNota().getValor();
    return saida;
}


string CntrServicoAvaliacao::listar(){
    ContainerAvaliacao *cp = ContainerAvaliacao::getInstancia();
    ContainerAvaliacao::cmap mp = cp->getMap();
    string saida = "Avaliações:";
    for(ContainerAvaliacao::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}
