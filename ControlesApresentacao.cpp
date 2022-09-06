#include <string>
#include <iostream>
#include <stdexcept>
#include "ControlesApresentacao.h"

using namespace std;

// Menu Principal
void CntrApresentacaoControle::executar(){
    // Mensagens a serem apresentadas na tela inicial.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar usuario.";
    char texto4[] = "3 - Acessar dados sobre hospedagens.";
    char texto5[] = "4 - Acessar dados sobre avaliacoes.";
    char texto12[] = "5 - Listar hospedagens";
    char texto13[] = "4 - Acessar dados sobre avaliacoes.";
    char texto6[] = "5 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de selecao de servico.

    char texto7[] = "Selecione um dos servicos : ";
    char texto8[] = "1 - Selecionar servicos de usuarios.";
    char texto9[] = "2 - Selecionar servicos relacionados a hospedagens.";
    char texto10[] = "3 - Encerrar sessao.";

    char texto11[] = "Falha na autenticacao. Digite algo para continuar."; // Mensagem a ser apresentada.

    int campo;

    bool apresentar = true;

    while (apresentar)
    {

        // Apresenta tela inicial.

        system("clear"); // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cout << texto6 << endl; // Imprime nome do campo.

        //campo = getchar() - 48; // Leitura do campo de entrada e conversao de ASCII.
        cin >>campo;
        switch (campo)
        {
            case 1:
                if (cntrApresentacaoAutenticacao->autenticar(&email))
                { // Solicita autenticacao.
                    bool apresentar = true;
                    while (apresentar)
                    {

                        // Apresenta tela de sele��o de servi�o.

                        //system("clear"); // Limpa janela.

                        cout << texto7 << endl;  // Imprime nome do campo.
                        cout << texto8 << endl;  // Imprime nome do campo.
                        cout << texto9 << endl;  // Imprime nome do campo.
                        cout << texto10 << endl; // Imprime nome do campo.

                        int campo;
                        system("clear"); // Leitura do campo de entrada e conversao de ASCII.
                        cin >>campo;
                        switch (campo)
                        {
                            case 1:
                                cntrApresentacaoUsuario->executar(&email); // Solicita servico de usuario.
                                break;
                            case 2:
                                cntrApresentacaoHA->executar(&email); // Solicita servico de hospedagem.
                                break;
                            case 3:
                                apresentar = false;
                                break;
                        }
                    }
                }
                else
                {
                    system("clear");                // Limpa janela.
                    cout << texto11 << endl; // Imprime mensagem.
                    getchar();                 // Leitura de caracter digitado.
                }
                break;
            case 2:
                cntrApresentacaoUsuario->cadastrar();
                break;
            case 3:
                cntrApresentacaoHA->executar();
                break;
            case 4:
                break;
            case 5:
                apresentar = false;
                break;
        }
    }
    return;
}


bool CntrApresentacaoAutenticacao::autenticar(Email *email)
{

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[] = "Digite o email  : ";
    char texto2[] = "Digite a senha   : ";
    char texto3[] = "Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha; // Instancia a classe Senha.

    while (true)
    {

        // Apresenta tela de autenticacao.

        system("clear"); // Limpa janela.

        cout << texto1 << " "; // Imprime nome do campo.
        cin >> campo1;         // Le valor do campo.
        cout << texto2 << " "; // Imprime nome do campo.
        cin >> campo2;         // Le valor do campo.

        try
        {
            email->setValor(string(campo1)); // Atribui valor ao CPF.
            senha.setValor(string(campo2));  // Atribui Valor a senha.
            break;                           // Abandona laco em caso de formatos corretos.
        }
        catch (invalid_argument &exp)
        {                           // Captura excecao devido a formato incorreto.
            system("clear");               // Limpa janela.
            cout << texto3 << endl; // Informa formato incorreto.
            getchar();                // Le caracter digitado.
        }
    }
    return (cntr->autenticar(email, &senha)); // Solicita servico de autenticacao.
}

bool CntrApresentacaoUsuario::cadastrar(){
    string texto1 ="Preencha os seguintes campos:";
    string texto2 ="Email       : ";
    string texto3 ="Nome         : ";
    string texto4 ="Senha         : ";
    string texto5 ="Idioma         : ";
    string texto6 ="Aniversario     : ";
    string texto7 ="Descricao        : ";
    string texto9 ="Dados em formato incorreto. Digite algo.";


    string dado1, dado2, dado3, dado4, dado5, dado6, dado7;

    Usuario usuario;
    Idioma idioma;
    Email email;
    Nome nome;
    Senha senha;
    Aniversario aniversario;
    Descricao descricao;

    system("clear");

    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto4;
    cin >> dado3;
    cout << texto5;
    cin >> dado4;
    cout << texto6;
    cin >> dado5;
    cout << texto7;
    cin >> dado6;

    //  Talvez precise de cin.ignore()

    try{
        email.setValor(dado1);
        nome.setValor(dado2);
        senha.setValor(dado3);
        idioma.setValor(dado4);
        aniversario.setValor(dado5);
        descricao.setValor(dado6);
    }
    catch(invalid_argument &exp){
        cout << texto9 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    usuario.setEmail(email);
    usuario.setNome(nome);
    usuario.setIdioma(idioma);
    usuario.setSenha(senha);
    usuario.setDescricao(descricao);
    usuario.setAniversario(aniversario);

    return (cntr->cadastrar(&usuario));

}


void CntrApresentacaoUsuario::executar(Email *email){
    // Mensagens a serem apresentadas na tela de selecao de servico..

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Editar Dados do Usuario.";
    char texto3[] = "2 - Excluir Cadastro do Usuario.";
    char texto4[] = "3 - Retornar.";
    string texto6 = "Usuario descadastrado com sucesso.";
    string texto7 = "Falha em descadastrar o usuario.";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {

        // Apresenta tela de selecao de servico.

        system("clear");                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.


        int campo; // Leitura do campo de entrada e conversao de ASCII.
        cin >> campo;
        switch (campo)
        {
            case 1:
                editar(email);
                break;
            case 2:
                if(cntr->descadastrar(email))
                    cout << texto6 << endl;
                else
                    cout << texto7 << endl;
                cin.ignore();
                cin.ignore();
                apresentar = false;
                break;
            case 3:
                apresentar = false;
                break;
        }
    }
}

bool CntrApresentacaoUsuario::editar(Email *email) {
    string texto1 ="Preencha os seguintes campos:";
    string texto2 ="Novo nome         : ";
    string texto3 ="Nova senha         : ";
    string texto4 ="Novo idioma         : ";
    string texto5 ="Aniversario          : ";
    string texto6 ="Nova descricao        : ";
    string texto7 ="Dados em formato incorreto. Digite algo.";


    string dado1, dado2, dado3, dado4, dado5;

    Usuario usuario;
    Idioma idioma;
    Nome nome;
    Senha senha;
    Aniversario aniversario;
    Descricao descricao;

    system("clear");

    cout << texto1 << endl;
    cout << texto2;
    cin >> dado1;
    cout << texto3;
    cin >> dado2;
    cout << texto4;
    cin >> dado3;
    cout << texto5;
    cin >> dado4;
    cout << texto6;
    cin >> dado5;

    //  Talvez precise de cin.ignore()

    try{
        nome.setValor(dado1);
        senha.setValor(dado2);
        idioma.setValor(dado3);
        aniversario.setValor(dado4);
        descricao.setValor(dado5);
    }
    catch(invalid_argument &exp){
        cout << texto7 << endl;                                                            // Informa formato incorreto
        cin.ignore();
        cin.ignore();
        return false;
    }

    usuario.setNome(nome);
    usuario.setIdioma(idioma);
    usuario.setSenha(senha);
    usuario.setDescricao(descricao);
    usuario.setAniversario(aniversario);

    return (cntr->cadastrar(&usuario));

}
void CntrApresentacaoHA::executar(){

    // Mensagens a serem apresentadas na tela simplificada de hospedagem.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar hospedagens.";
    char texto3[] = "2 - Retornar.";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de la�o.

    while (apresentar)
    {
        // Apresenta tela simplificada de hospedagem.

        system("clear");                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.

        campo = getchar() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
            case 1:
                cout << cntrHospedagem->listar() << endl;
                break;
            case 2:
                apresentar = false;
                break;
        }
    }
}
bool CntrApresentacaoHA::editarHospedagem() {
    {
        // Mensagens a serem apresentadas na tela de cadastramento.

        char texto1[] = "Preencha os seguintes campos: ";
        char texto2[] = "Codigo da hospedagem que você quer editar          :";
        char texto3[] = "Pais          :";
        char texto4[] = "Cidade            :";
        char texto5[] = "Descricao          :";
        char texto6[] = "Dados em formato incorreto. Digite algo.";
        char texto7[] = "Sucesso no cadastramento. Digite algo.";
        char texto8[] = "Falha no cadastramento. Digite algo.";

        char campo0[80], campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

        // Instancia os dominios.
        Codigo codigo;
        Pais pais;
        Cidade cidade;
        Descricao descricao;

        // Apresenta tela de cadastramento.

        system("clear"); // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cin >> campo0;          // Le valor do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cin >> campo1;          // Le valor do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cin >> campo2;          // Le valor do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cin >> campo3;          // Le valor do campo.
        try {
            codigo.setValor(campo0);
            pais.setValor(campo1);
            cidade.setValor(campo2);
            descricao.setValor(campo3);
        }
        catch (invalid_argument &exp) {
            cout << texto6 << endl; // Informa formato incorreto.
            // Desabilita eco.
            getchar(); // Leitura de caracter digitado.
            // Habilita eco.
        }

        // Instancia e inicializa entidades.

        Hospedagem hospedagem;

        hospedagem.setCodigo(codigo);
        hospedagem.setPais(pais);
        hospedagem.setCidade(cidade);
        hospedagem.setDescricao(descricao);

        if (cntrHospedagem->editar(&hospedagem)) {
            cout << texto7 << endl; // Informa sucesso.

            getchar();;
        }

        cout << texto8 << endl; // Informa falha.

        getchar();

    }
}

bool CntrApresentacaoHA::editarAvaliacao() {
    {
        // Mensagens a serem apresentadas na tela de edicao.

        char texto1[] = "Preencha os seguintes campos: ";
        char texto2[] = "Codigo da avaliacao que você quer editar          :";
        char texto3[] = "Nova nota          :";
        char texto4[] = "Nova Descricao            :";
        char texto5[] = "Codigo da Hospedagem          :";
        char texto6[] = "Dados em formato incorreto. Digite algo.";
        char texto7[] = "Sucesso no cadastramento. Digite algo.";
        char texto8[] = "Falha no cadastramento. Digite algo.";

        char campo0[80], campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

        // Instancia os dominios.
        Codigo codigo;
        Nota nota;
        Descricao descricao;
        Codigo codigoHospedagem;

        // Apresenta tela de cadastramento.

        system("clear"); // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cin >> campo0;          // Le valor do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cin >> campo1;          // Le valor do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cin >> campo2;          // Le valor do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cin >> campo3;          // Le valor do campo.
        try {
            codigo.setValor(campo0);
            nota.setValor(campo1);
            descricao.setValor(campo2);
            codigoHospedagem.setValor(campo3);
        }
        catch (invalid_argument &exp) {
            cout << texto6 << endl; // Informa formato incorreto.
            // Desabilita eco.
            getchar(); // Leitura de caracter digitado.
            // Habilita eco.

        }

        // Instancia e inicializa entidades.

        Avaliacao avaliacao;

        avaliacao.setCodigo(codigo);
        avaliacao.setNota(nota);
        avaliacao.setDescricao(descricao);

        if (cntrAvaliacao->editar(&avaliacao)) {
            cout << texto7 << endl; // Informa sucesso.

            getchar();

        }

        cout << texto8 << endl; // Informa falha.

        getchar();

    }
}

void CntrApresentacaoHA::editar(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Editar Hospedagem";
    string texto3 = "2 - Editar Avaliacao";
    string texto4 = "3 - Voltar.";
    string texto5 = "Hospedagem modificada com sucesso.";
    string texto6 = "Avaliacao modificada com sucesso.";
    string texto7 = "Falha em modificar Hospedagem.";
    string texto8 = "Falha em modificar Avaliacao.";


    string codigo;
    int op;
    bool apresentar = true;

    while (apresentar){
        system("clear");
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        cin >> op;
        switch(op){
            case 1:
                if(editarHospedagem())
                    cout << texto5 << endl;
                else
                    cout << texto7 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                if(editarAvaliacao())
                    cout << texto6 << endl;
                else
                    cout << texto8 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }

}

bool CntrApresentacaoHA::incluirHospedagem() {
    {
        // Mensagens a serem apresentadas na tela de cadastramento.

        char texto1[] = "Preencha os seguintes campos: ";
        char texto2[] = "Codigo              :";
        char texto3[] = "Pais                 :";
        char texto4[] = "Cidade                :";
        char texto5[] = "Descricao              :";
        char texto6[] = "Dados em formato incorreto. Digite algo.";
        char texto7[] = "Sucesso no cadastramento. Digite algo.";
        char texto8[] = "Falha no cadastramento. Digite algo.";

        char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

        // Instancia os dominios.
        Codigo codigo;
        Pais pais;
        Cidade cidade;
        Descricao descricao;

        // Apresenta tela de cadastramento.

        system("clear"); // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cin >> campo1;          // Le valor do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cin >> campo2;          // Le valor do campo.

        cout << texto4 << endl; // Imprime nome do campo.
        cin >> campo3;          // Le valor do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cin >> campo4;          // Le valor do campo.

        try {
            // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
            codigo.setValor(campo1);
            pais.setValor(campo2);
            cidade.setValor(campo3);
            descricao.setValor(campo4);
        }
        catch (invalid_argument &exp) {
            cout << texto6 << endl; // Informa formato incorreto.
            // Desabilita eco.
            getchar(); // Leitura de caracter digitado.
            // Habilita eco.

        }

        // Instancia e inicializa entidades.

        Hospedagem hospedagem;

        hospedagem.setCodigo(codigo);
        hospedagem.setPais(pais);
        hospedagem.setCidade(cidade);
        hospedagem.setDescricao(descricao);
        // avaliacao.setIdioma(idioma);

        if (cntrHospedagem->incluir(&hospedagem)) {
            cout << texto7 << endl; // Informa sucesso.

            getchar();
            return true;
        }

        cout << texto8 << endl; // Informa falha.

        getchar();
    }
}
bool CntrApresentacaoHA::incluirAvaliacao(){
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Codigo              :";
    char texto3[] = "Nota                :";
    char texto4[] = "Descricao             :";
    char texto5[] = "Codigo da Hospedagem  :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.
    Codigo codigo;
    Nota nota;
    Descricao descricao;
    Codigo codigoHospedagem;

    // Apresenta tela de cadastramento.

    system("clear"); // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo1;          // Le valor do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    int icampo2;

    cout << texto4 << endl; // Imprime nome do campo.
    cin >> campo3;          // Le valor do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cin >> campo4;          // Le valor do campo.

    try {
        // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
        codigo.setValor(campo1);
        nota.setValor(to_string(icampo2));
        descricao.setValor(campo3);
        codigoHospedagem.setValor(campo4);
    }
    catch (invalid_argument &exp) {
        cout << texto6 << endl; // Informa formato incorreto.
        // Desabilita eco.
        getchar(); // Leitura de caracter digitado.
        // Habilita eco.

    }

    // Instancia e inicializa entidades.

    Avaliacao avaliacao;

    avaliacao.setCodigo(codigo);
    avaliacao.setNota(nota);
    avaliacao.setDescricao(descricao);

    if (cntrAvaliacao->incluir(&avaliacao)) {
        cout << texto7 << endl; // Informa sucesso.

        getchar();
        return true;
    }

    cout << texto8 << endl; // Informa falha.

    getchar();
}


void CntrApresentacaoHA::incluir(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Cadastrar Hospedagem.";
    string texto3 = "2 - Cadastrar Avaliacao.";
    string texto4 = "3 - Voltar.";
    string texto5 = "Hospedagem cadastrada com sucesso.";
    string texto6 = "Avaliacao cadastrada com sucesso.";
    string texto7 = "Falha em cadastrar hospedagem.";
    string texto8 = "Falha em cadastrar avaliacao.";

    int op;
    bool apresentar = true;

    while (apresentar){
        system("clear");
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        cin >> op;
        switch(op){
            case 1:
                if(incluirHospedagem())
                    cout << texto5 << endl;
                else
                    cout << texto7 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                if(incluirAvaliacao())
                    cout << texto6 << endl;
                else
                    cout << texto8 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                apresentar = false;
                break;
        }
    }

}

void CntrApresentacaoHA::excluir(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Descadastrar Hospedagem.";
    string texto3 = "2 - Descadastrar Avaliacao.";
    string texto4 = "3 - Voltar.";
    string texto5 = "Hospedagem descadastrada com sucesso.";
    string texto6 = "Avaliacao descadastrada com sucesso.";
    string texto7 = "Falha em descadastrar hospedagem.";
    string texto8 = "Falha em descadastrar avaliacao.";

    int op;
    bool apresentar = true;

    while (apresentar){
        system("clear");
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        cin >> op;
        switch(op){
            case 1:
                if(excluirHospedagem())
                    cout << texto5 << endl;
                else
                    cout << texto7 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                if(excluirAvaliacao())
                    cout << texto6 << endl;
                else
                    cout << texto8 << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                apresentar = false;
                break;
        }
    }

}

bool CntrApresentacaoHA::excluirHospedagem() {
    {
        // Mensagens a serem apresentadas na tela de descadastramento.
        char texto1[] = "Descadastrar hospedagem: ";
        char texto2[] = "Codigo da hospedagem         :";
        char texto3[] = "Dado em formato incorreto. Digite algo.";
        char texto4[] = "Sucesso no descadastramento. Digite algo.";
        char texto5[] = "Falha no descadastramento. Digite algo.";

        char campo1[80];

        Codigo codigo;

        system("clear");                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cin >> campo1;          // L valor do campo.

        try {
            codigo.setValor(campo1);
        }
        catch (invalid_argument &exp) {
            cout << texto3 << endl; // Informa falha.
            // Desabilita eco.
            getchar(); // Leitura de caracter digitado.
            // Habilita eco.
        }

        if (cntrHospedagem->excluir(&codigo)) {
            cout << texto4 << endl; // Informa sucesso.

            getchar();

        }

        cout << texto5 << endl; // Informa falha.

        getchar();

    }
}

bool CntrApresentacaoHA::excluirAvaliacao() {
    {
        // Mensagens a serem apresentadas na tela de descadastramento.
        char texto1[] = "Descadastrar avaliacao: ";
        char texto2[] = "Codigo da avaliacao         :";
        char texto3[] = "Dado em formato incorreto. Digite algo.";
        char texto4[] = "Sucesso no descadastramento. Digite algo.";
        char texto5[] = "Falha no descadastramento. Digite algo.";

        char campo1[80];

        Codigo codigo;

        system("clear");                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cin >> campo1;          // L valor do campo.

        try {
            codigo.setValor(campo1);
        }
        catch (invalid_argument &exp) {
            cout << texto3 << endl; // Informa falha.
            // Desabilita eco.
            getchar(); // Leitura de caracter digitado.
            // Habilita eco.
        }

        if (cntrAvaliacao->excluir(&codigo)) {
            cout << texto4 << endl; // Informa sucesso.

            getchar();

        }

        cout << texto5 << endl; // Informa falha.

        getchar();

    }
}


    void CntrApresentacaoHA::visualizar(){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Visualizar Hospedagens";
    string texto3 = "2 - Visualizar Avaliacoes";
    string texto4 = "3 - Voltar";
    string texto6 = "Digite o código da Hospedagens que deseja visualizar: ";
    string texto7 = "Digite o código da Avaliacoes que deseja visualizar: ";

    string cod;
    Codigo codigo;
    int op;
    bool apresentar = true;

    while(apresentar){
        system("clear");
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        cin >> op;
        switch(op){
            case 1:
                cout << texto6 << endl;
                cin >> cod;
                codigo.setValor(cod);
                cout << cntrHospedagem->visualizar(&codigo) << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 2:
                cout << texto7 << endl;
                cin >> cod;
                codigo.setValor(cod);
                cout << cntrAvaliacao->visualizar(&codigo) << endl;
                cin.ignore();
                cin.ignore();
                break;
            case 3:
                apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoHA::executar(Email *email){
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Cadastrar hospedagem ou avaliacao.";
    string texto3 = "2 - Excluir hospedagem ou avaliacao.";
    string texto4 = "3 - Editar hospedagem ou avaliacao.";
    string texto5 = "4 - Visualizar Hospedagem ou avaliacao";
    string texto6 = "5 - Listar Hospedagem ou avaliacao";
    string texto7 = "6 - Voltar.";

    int op;
    bool apresentar = true;

    while(apresentar){
        system("clear");
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;

        cin >> op;

        switch(op){
            case 1:
                incluir();
                cin.ignore();
                break;
            case 2:
                excluir();
                cin.ignore();
                break;
            case 3:
                editar();
                cin.ignore();
                break;
            case 4:
                visualizar();
                cin.ignore();
                break;
            case 5:
                executar();
                cin.ignore();
                break;
            case 6:
                apresentar = false;
                break;
        }
    }

}
