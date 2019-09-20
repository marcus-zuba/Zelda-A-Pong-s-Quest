#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "main.h"
#include "global.h"

void inicializa(){

    glClearColor(1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(3);
    link.posicao.x=-60;
    link.posicao.y=0;
    link.proporcao.x=7;
    link.proporcao.y=12;
    ganon.posicao.x=60;
    ganon.posicao.y=0;
    ganon.proporcao.x=15;
    ganon.proporcao.y=10;
    bola.velocidade.x=3.5;
    bola.velocidade.y=3.5;
    glColor3f(1,1,1);
    bola.proporcao.x=4.5;
    bola.proporcao.y=2.8;
    bola.posicao.x=0;
    bola.posicao.y=65;
    telaAtual = MENU;
    PontuacaoLink=0;
    PontuacaoGanon=0;
    SetsLink=0;
    SetsGanon=0;
    vitoriaGanon=0;
    vitoriaLink=0;
    velocidadeLink=8;
    velocidadeGanon=6;
    seColisao=100;
    tempoBola=0;
    linkAtacando=0;
    ganonAtacando=0;

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaFundo = carregaTextura("OI fundo4.png");
    idTexturaFundo2 = carregaTextura("OI fundo2.png");
    idTexturaFundo3 = carregaTextura("OI fundo3.png");
    idTexturaFundo4 = carregaTextura("OI fundo4.png");
    idTexturaMenu = carregaTextura("OI back_menu.png");
    idTexturaInici = carregaTextura("OI botao_iniciar.png");
    idTexturaSair = carregaTextura("OI botao_exit.png");
    idLink = carregaTextura("OI Link.png");
    idGanon = carregaTextura(" OI Ganons.png");
    idSTART = carregaTextura("OI botao_iniciarSE.png");
    idEXIT = carregaTextura("OI botao_exitSE.png");
    idZeldaNormal = carregaTextura("OI sair.png");
    idZeldaW = carregaTextura("OI zelda_1.png");
    idZeldaL0 = carregaTextura(" OI 1411x274.png");
    idZeldaL1 = carregaTextura("OI 1411x362.png");
    idLos = carregaTextura("OI victoryGanon.png");
    idVic = carregaTextura("OI victory.png");
    idMar = carregaTextura(" OI 1411x274.png");
    idCeu = carregaTextura(" OI 1411x362.png");
    pausa = carregaTextura(" OI pause.png");

    ZeldaPresa.idTextura = carregaTextura(" OI zeldaPresas.png");
    ZeldaPresa.quadrosHorizontais =14;
    ZeldaPresa.quadroAtual=0;

    ZeldaPresaL.idTextura = carregaTextura(" OI zeldaPresa1.png");
    ZeldaPresaL.quadrosHorizontais =14;
    ZeldaPresaL.quadroAtual=0;

    ZeldaPresaW.idTextura = carregaTextura(" OI zeldaPresa2.png");
    ZeldaPresaW.quadrosHorizontais =14;
    ZeldaPresaW.quadroAtual=0;


    bola.idTextura = carregaTextura("OI bolaf.png");
    bola.quadrosHorizontais=3;
    bola.quadroAtual=1;

    ataqueLink.idTextura = carregaTextura(" OI Link_Ataca.png");
    ataqueLink.quadrosHorizontais=3;
    ataqueLink.quadroAtual=0;

    ataqueGanon.idTextura = carregaTextura("OI g2.png");
    ataqueGanon.quadrosHorizontais=3;
    ataqueGanon.quadroAtual=2;

    andaLink.idTextura = carregaTextura("OI Link_Moveo.png");
    andaLink.quadrosHorizontais=6;
    andaLink.quadroAtual=0;

    andaGanon.idTextura = carregaTextura("OI ganon_sprite_mov.png");
    andaGanon.quadrosHorizontais=4;
    andaGanon.quadroAtual=0;

    fundomenu.idTextura = carregaTextura("OI anima_menu.png");
    fundomenu.quadrosHorizontais=2;
    fundomenu.quadroAtual=0;

    logo.idTextura = carregaTextura("OI logo-loz.png");
    logo.quadrosHorizontais = 4;
    logo.quadroAtual=0;

    Av.idTextura = carregaTextura("OI CBOTAO_Ave.png");
    Av.quadrosHorizontais =2;
    Av.quadroAtual=0;

    Cl.idTextura = carregaTextura("OI BOTAO_Cla.png");
    Cl.quadrosHorizontais =2;
    Cl.quadroAtual=0;

    heart.idTextura = carregaTextura("OI  heart.png");
    heart.quadrosHorizontais =11;

    heartG.idTextura = carregaTextura("OI heart.png");
    heartG.quadrosHorizontais =11;

    linkop.idTextura = carregaTextura(" OI link_op_anim.png");
    linkop.quadrosHorizontais =4;
    linkop.quadroAtual=0;

    zeldaop.idTextura = carregaTextura(" OI zelda_op_anim.png");
    zeldaop.quadrosHorizontais =4;
    zeldaop.quadroAtual=0;

    hist.idTextura = carregaTextura("OI  historia.png");
    hist.quadrosHorizontais =24;
    hist.quadroAtual=0;

    tri.idTextura = carregaTextura("OI triforce.png");
    tri.quadrosHorizontais = 4;
    tri.quadroAtual =0;

    botaoAtual = START;
}
