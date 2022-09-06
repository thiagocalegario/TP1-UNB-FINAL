#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <unordered_map>
#include "Dominios.h"
#include "Entidades.h"
using namespace std;

//=================================================================\\
//=================================================================\\
//=================================================================\\


class ContainerUsuario {
    public:
        typedef unordered_map<string, Usuario> cmap;
        static ContainerUsuario* getInstancia();
        bool incluir(Usuario* usuario);
        bool remover(string key);
        Usuario* pesquisar(string key);
        bool atualizar(Usuario* usuario);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerUsuario *instancia;
        ContainerUsuario(){};
};


//=================================================================\\
//=================================================================\\
//=================================================================\\


class ContainerHospedagem {
    public:
        typedef unordered_map<string, Hospedagem> cmap;
        static ContainerHospedagem* getInstancia();
        bool incluir(Hospedagem* hospedagem);
        bool remover(string key);
        Hospedagem* pesquisar(string key);
        bool atualizar(Hospedagem* hospedagem);
        int contar(string key);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerHospedagem *instancia;
        ContainerHospedagem(){};
};


//=================================================================\\
//=================================================================\\
//=================================================================\\


class ContainerAvaliacao {
    //200023314
    public:
        typedef unordered_map<string, Avaliacao> cmap;
        static ContainerAvaliacao* getInstancia();
        bool incluir(Avaliacao* avaliacao);
        bool remover(string key);
        Avaliacao* pesquisar(string key);
        bool atualizar(Avaliacao* avaliacao);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerAvaliacao *instancia;
        ContainerAvaliacao(){};
};


//=================================================================\\
//=================================================================\\
//=================================================================\\


class Hospedagem2Usuario {
    private:
        typedef unordered_multimap<string, string> map;
        map container;
        static Hospedagem2Usuario *instancia;

    public:
        static Hospedagem2Usuario* getInstancia();
        bool incluir(string hospedagem, string usuario);
        void removerHospedagem(string hospedagem);
        void removerUsuario(string usuario);
        int contar(string hospedagem);
};



#endif // CONTAINER_H
