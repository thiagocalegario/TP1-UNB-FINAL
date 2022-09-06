#include "Dominios.h"

#ifndef ENTIDADES_H
#define ENTIDADES_H

class Usuario {
    private:
        Email email;
        Nome nome;
        Idioma idioma;
        Senha senha;
        Aniversario aniversario;
        Descricao descricao;

    public:

        void setEmail(const Email &valor);
        Email getEmail();
        void setNome(const Nome &valor);
        Nome getNome();
        void setIdioma(const Idioma &valor);
        Idioma getIdioma();
        void setSenha(const Senha &valor);
        Senha getSenha();
        void setAniversario(const Aniversario &valor);
        Aniversario getAniversario();
        void setDescricao(const Descricao &valor);
        Descricao getDescricao();
};

inline void Usuario::setEmail(const Email &valor){
    email = valor;
}

inline Email Usuario::getEmail(){
    return email;
}

inline void Usuario::setNome(const Nome &valor){
    nome = valor; 
}

inline Nome Usuario::getNome(){
    return nome;
}

inline void Usuario::setIdioma(const Idioma &valor){
    idioma = valor;
}

inline Idioma Usuario::getIdioma(){
    return idioma;
}

inline void Usuario::setAniversario(const Aniversario &valor){
    aniversario = valor;
}

inline Aniversario Usuario::getAniversario() {
    return aniversario;
}

inline void Usuario::setDescricao(const Descricao &valor) {
    descricao = valor;
}

inline Descricao Usuario::getDescricao() {
    return descricao;
}

inline void Usuario::setSenha(const Senha &valor){
    senha = valor; 
}

inline Senha Usuario::getSenha(){
    return senha;
}


class Hospedagem {
    private:
        Codigo codigo;
        Cidade cidade;
        Pais pais;
        Nota nota;
        Descricao descricao;

    public:
        void setCodigo(const Codigo &valor);
        Codigo getCodigo();
        void setCidade(const Cidade &valor);
        Cidade getCidade();
        void setPais(const Pais &valor);
        Pais getPais();
        void setNota(const Nota &valor);
        Nota getNota();
        void setDescricao(const Descricao &valor);
        Descricao getDescricao();
};

inline void Hospedagem::setCodigo(const Codigo &valor) {
    codigo = valor;
}

inline Codigo Hospedagem::getCodigo() {
    return codigo;
}

inline void Hospedagem::setCidade(const Cidade &valor) {
    cidade = valor;
}

inline Cidade Hospedagem::getCidade() {
    return cidade;
}

inline void Hospedagem::setPais(const Pais &valor){
    pais = valor;
}

inline Pais Hospedagem::getPais() {
    return pais;
}

inline void Hospedagem::setNota(const Nota &valor){
    nota = valor;
}

inline Nota Hospedagem::getNota() {
    return nota;
}
inline void Hospedagem::setDescricao(const Descricao &valor) {
    descricao = valor;
}

inline Descricao Hospedagem::getDescricao() {
    return descricao;
}


class Avaliacao {
    private:
        Codigo codigo;
        Nota nota;
        Descricao descricao;

    public:
        void setCodigo(const Codigo &valor);
        Codigo getCodigo();
        void setNota(const Nota &valor);
        Nota getNota();
        void setDescricao(const Descricao &valor);
        Descricao getDescricao();
};

inline void Avaliacao::setCodigo(const Codigo &valor) {
    codigo = valor;
}

inline Codigo Avaliacao::getCodigo() {
    return codigo;
}

inline void Avaliacao::setNota(const Nota &valor) {
    nota = valor;
}

inline Nota Avaliacao::getNota(){
    return nota;
}

inline void Avaliacao::setDescricao(const Descricao &valor){
    descricao = valor;
}

inline Descricao Avaliacao::getDescricao() {
    return descricao;
}

#endif
