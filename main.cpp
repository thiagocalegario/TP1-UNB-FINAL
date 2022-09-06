#include <stdexcept>
#include <iostream>
#include <regex>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "ControlesApresentacao.h"
#include "ControlesServico.h"

using namespace std;


int main()
{
    CntrApresentacaoControle *CAC;
    IApresentacaoAutenticacao *CAA;
    IApresentacaoUsuario *CAP;
    IApresentacaoHA *CAPSS;

    IServicoAutenticacao *CSA;
    IServicoUsuario *CSPA;
    IServicoHospedagem *CSPE;
    IServicoAvaliacao *CSSE;

    CAC = new CntrApresentacaoControle();
    CAA = new CntrApresentacaoAutenticacao();
    CAP = new CntrApresentacaoUsuario();
    CAPSS = new CntrApresentacaoHA();

    CSA = new CntrServicoAutenticacao();
    CSPA = new CntrServicoUsuario();
    CSPE = new CntrServicoHospedagem();
    CSSE = new CntrServicoAvaliacao();

    CAC->setCntrApresentacaoAutenticacao(CAA);
    CAC->setCntrApresentacaoUsuario(CAP);
    CAC->setCntrApresentacaoHA(CAPSS);

    CAA->setCntrServicoAutenticacao(CSA);
    CAP->setCntrServicoUsuario(CSPA);
    CAPSS->setCntrServicoHospedagem(CSPE);
    CAPSS->setCntrServicoAvaliacao(CSSE);
    //CAPSS->setCntrServicoSala(CSSA);

    CAC->executar();

    return 0;
}


