#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;

class Dominio {
    private:
        string valor;
        virtual void validar(string valor) = 0;

    public:
        virtual ~Dominio(){};

        void setValor(string valor);
        string getValor();

};
inline string Dominio::getValor(){
    return valor;
}

class Cidade: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

class Pais: public Dominio {
    private:
        void validar(string valor);
};


class Descricao: public Dominio {
    private:
        void validar(string valor) override;
};


class Codigo: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Nota: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};



class Email: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Aniversario: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Nome: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Senha: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Idioma: public Dominio {
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

#endif // DOMINIOS_H
