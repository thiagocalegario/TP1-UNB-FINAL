#include "container.h"

ContainerUsuario* ContainerUsuario::instancia = nullptr;
ContainerHospedagem* ContainerHospedagem::instancia = nullptr;
ContainerAvaliacao* ContainerAvaliacao::instancia = nullptr;
Hospedagem2Usuario* Hospedagem2Usuario::instancia = nullptr;

//=================================================================\\
//=====================Containers========================\\
//=================================================================\\

ContainerUsuario* ContainerUsuario::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}


ContainerHospedagem* ContainerHospedagem::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerHospedagem();
    return instancia;
}


ContainerAvaliacao* ContainerAvaliacao::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerAvaliacao();
    return instancia;
}




Hospedagem2Usuario* Hospedagem2Usuario::getInstancia(){
    if(instancia == nullptr)
        instancia = new Hospedagem2Usuario();
    return instancia;
}

//====================================================\\
//=====================Usuario========================\\
//=====================================================\\

bool ContainerUsuario::incluir(Usuario* usuario){
    bool valor = true;
    string key = usuario->getEmail().getValor();
    if(container.count(key) < 1)
        container[key] = *usuario;
    else
        valor = false;
    return valor;
}


bool ContainerUsuario::remover(string key){
    Hospedagem2Usuario *relacao = Hospedagem2Usuario::getInstancia();
    relacao->removerUsuario(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Usuario* ContainerUsuario::pesquisar(string key){
    Usuario* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerUsuario::atualizar(Usuario* usuario){
    string key = usuario->getEmail().getValor();
    container[key] = *usuario;
    return true;
}

//======================================================\\
//=====================Hospedagem========================\\
//=======================================================\\

bool ContainerHospedagem::incluir(Hospedagem* hospedagem){
    bool valor = true;
    string key = hospedagem->getCodigo().getValor();
    if(container.count(key) < 1)
        container[key] = *hospedagem;
    else
        valor = false;
    return valor;
}


bool ContainerHospedagem::remover(string key){
    Hospedagem2Usuario *r1 = Hospedagem2Usuario::getInstancia();
    r1->removerHospedagem(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Hospedagem* ContainerHospedagem::pesquisar(string key){
    Hospedagem* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerHospedagem::atualizar(Hospedagem* hospedagem){
    string key = hospedagem->getCodigo().getValor();
    container[key] = *hospedagem;
    return true;
}


int ContainerHospedagem::contar(string key){
    return container.count(key);
}


//=================================================================\\
//==========================Avaliacao==============================\\
//=================================================================\\

bool ContainerAvaliacao::incluir(Avaliacao* avaliacao){
    string key = avaliacao->getCodigo().getValor();
    if(!(incluir(avaliacao)))
        return false;

    bool valor = true;;
    if(container.count(key) < 1)
        container[key] = *avaliacao;
    else
        valor = false;
    return valor;
}


bool ContainerAvaliacao::remover(string key){
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Avaliacao* ContainerAvaliacao::pesquisar(string key){
    Avaliacao* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerAvaliacao::atualizar(Avaliacao* avaliacao){
    string key = avaliacao->getCodigo().getValor();
    container[key] = *avaliacao;
    return true;
}
//=================================================================\\
//=====================Hospedagem & Usuario========================\\
//=================================================================\\

bool Hospedagem2Usuario::incluir(string hospedagem, string usuario){
    bool valor = true;
    ContainerHospedagem *cp = ContainerHospedagem::getInstancia();
    if(cp->contar(hospedagem) == 0)
        return false;
    if(container.count(hospedagem) <= 10)
        container.insert({{hospedagem, usuario}});
    else
        valor = false;
    return valor;
}


void Hospedagem2Usuario::removerHospedagem(string hospedagem){
    container.erase(hospedagem);
}


void Hospedagem2Usuario::removerUsuario(string usuario){
    for(map::iterator i=container.begin(); i!=container.end(); i++){
        if(i->second == usuario){
            container.erase(i);
            break;
        }
    }
}


int Hospedagem2Usuario::contar(string usuario){
    return container.count(usuario);
}
//=================================================================\\
//=================================================================\\
//=================================================================\\