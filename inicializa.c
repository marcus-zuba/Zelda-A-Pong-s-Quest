#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "main.h"
#include "global.h"

void inicializa(){

    glClearColor(1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(3);
    link.posicao.x=-65;
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
    bola.proporcao.x=8;
    bola.proporcao.y=7;
    telaAtual = MENU;
    PontuacaoLink=0;
    PontuacaoGanon=0;
    SetsLink=0;
    SetsGanon=0;
    vitoriaGanon=0;
    vitoriaLink=0;
    velocidadeLink=10;
    velocidadeGanon=10;
    seColisao=100;
    tempoBola=50;
    linkAtacando=0;

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaFundo = carregaTextura("/home/marcus/CG/TP1/TP1-CG/fundo.png");
    idTexturaMenu = carregaTextura("/home/marcus/CG/TP1/TP1-CG/back_menu.png");
    idTexturaInici = carregaTextura("/home/marcus/CG/TP1/TP1-CG/botao_iniciar.png");
    idTexturaSair = carregaTextura("/home/marcus/CG/TP1/TP1-CG/botao_exit.png");
    idLink = carregaTextura("/home/marcus/CG/TP1/TP1-CG/Link.png");
    idGanon = carregaTextura("/home/marcus/CG/TP1/TP1-CG/Ganons.png");
    bola.idTextura = carregaTextura("/home/marcus/CG/TP1/TP1-CG/bola.png");
    idSTART = carregaTextura("/home/marcus/CG/TP1/TP1-CG/botao_iniciarSE.png");
    idEXIT = carregaTextura("/home/marcus/CG/TP1/TP1-CG/botao_exitSE.png");
    idZeldaNormal = carregaTextura("/home/marcus/CG/TP1/TP1-CG/zelda_0.png");
    idZeldaW = carregaTextura("/home/marcus/CG/TP1/TP1-CG/zelda_1.png");
    idZeldaL0 = carregaTextura("/home/marcus/CG/TP1/TP1-CG/zelda_2.png");
    idZeldaL1 = carregaTextura("/home/marcus/CG/TP1/TP1-CG/zelda_3.png");
    idLos = carregaTextura("/home/marcus/CG/TP1/TP1-CG/victoryGanon.png");
    idVic = carregaTextura("/home/marcus/CG/TP1/TP1-CG/victory.png");
    ataqueLink.idTextura = carregaTextura("/home/marcus/CG/TP1/TP1-CG/Link_Ataca.png");
    ataqueLink.quadrosHorizontais=3;
    ataqueLink.quadroAtual=0;
    bola.quadroAtual=1;
    botaoAtual = START;
}
