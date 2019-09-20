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

    idTexturaFundo = carregaTextura("fundo4.png");
    idTexturaFundo2 = carregaTextura("/fundo2.png");
    idTexturaFundo3 = carregaTextura("fundo3.png");
    idTexturaFundo4 = carregaTextura("fundo4.png");
    idTexturaMenu = carregaTextura("back_menu.png");
    idTexturaInici = carregaTextura("botao_iniciar.png");
    idTexturaSair = carregaTextura(" botao_exit.png");
    idLink = carregaTextura(" Link.png");
    idGanon = carregaTextura(" Ganons.png");
    idSTART = carregaTextura(" botao_iniciarSE.png");
    idEXIT = carregaTextura(" botao_exitSE.png");
    idZeldaNormal = carregaTextura(" sair.png");
    idZeldaW = carregaTextura(" zelda_1.png");
    idZeldaL0 = carregaTextura(" 1411x274.png");
    idZeldaL1 = carregaTextura(" 1411x362.png");
    idLos = carregaTextura(" victoryGanon.png");
    idVic = carregaTextura(" victory.png");
    idMar = carregaTextura(" 1411x274.png");
    idCeu = carregaTextura(" 1411x362.png");
    pausa = carregaTextura(" pause.png");

    ZeldaPresa.idTextura = carregaTextura(" zeldaPresas.png");
    ZeldaPresa.quadrosHorizontais =14;
    ZeldaPresa.quadroAtual=0;

    ZeldaPresaL.idTextura = carregaTextura(" zeldaPresa1.png");
    ZeldaPresaL.quadrosHorizontais =14;
    ZeldaPresaL.quadroAtual=0;

    ZeldaPresaW.idTextura = carregaTextura(" zeldaPresa2.png");
    ZeldaPresaW.quadrosHorizontais =14;
    ZeldaPresaW.quadroAtual=0;


    bola.idTextura = carregaTextura(" bolaf.png");
    bola.quadrosHorizontais=3;
    bola.quadroAtual=1;

    ataqueLink.idTextura = carregaTextura(" Link_Ataca.png");
    ataqueLink.quadrosHorizontais=3;
    ataqueLink.quadroAtual=0;

    ataqueGanon.idTextura = carregaTextura(" g2.png");
    ataqueGanon.quadrosHorizontais=3;
    ataqueGanon.quadroAtual=2;

    andaLink.idTextura = carregaTextura(" Link_Moveo.png");
    andaLink.quadrosHorizontais=6;
    andaLink.quadroAtual=0;

    andaGanon.idTextura = carregaTextura(" ganon_sprite_mov.png");
    andaGanon.quadrosHorizontais=4;
    andaGanon.quadroAtual=0;

    fundomenu.idTextura = carregaTextura(" anima_menu.png");
    fundomenu.quadrosHorizontais=2;
    fundomenu.quadroAtual=0;

    logo.idTextura = carregaTextura("logo-loz.png");
    logo.quadrosHorizontais = 4;
    logo.quadroAtual=0;

    Av.idTextura = carregaTextura("CBOTAO_Ave.png");
    Av.quadrosHorizontais =2;
    Av.quadroAtual=0;

    Cl.idTextura = carregaTextura("BOTAO_Cla.png");
    Cl.quadrosHorizontais =2;
    Cl.quadroAtual=0;

    heart.idTextura = carregaTextura(" heart.png");
    heart.quadrosHorizontais =11;

    heartG.idTextura = carregaTextura(" heart.png");
    heartG.quadrosHorizontais =11;

    linkop.idTextura = carregaTextura(" link_op_anim.png");
    linkop.quadrosHorizontais =4;
    linkop.quadroAtual=0;

    zeldaop.idTextura = carregaTextura(" zelda_op_anim.png");
    zeldaop.quadrosHorizontais =4;
    zeldaop.quadroAtual=0;

    hist.idTextura = carregaTextura(" historia.png");
    hist.quadrosHorizontais =24;
    hist.quadroAtual=0;

    tri.idTextura = carregaTextura(" triforce.png");
    tri.quadrosHorizontais = 4;
    tri.quadroAtual =0;

    botaoAtual = START;
}
