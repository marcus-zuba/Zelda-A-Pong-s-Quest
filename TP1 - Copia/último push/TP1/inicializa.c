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
    link.proporcao.x=10;
    link.proporcao.y=15;
    ganon.posicao.x=60;
    ganon.posicao.y=0;
    ganon.proporcao.x=20;
    ganon.proporcao.y=15;
    bola.velocidade.x=3.5;
    bola.velocidade.y=3.5;glColor3f(1,1,1);
    bola.proporcao.x=11;
    bola.proporcao.y=10;
    telaAtual = MENU;
    PontuacaoLink=0;
    PontuacaoGanon=0;
    SetsLink=0;
    SetsGanon=0;
    vitoriaGanon=0;
    vitoriaLink=0;
    velocidadeLink=10;
    velocidadeGanon=10;

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaFundo = carregaTextura("fundo.png");
    idTexturaMenu = carregaTextura("back_menu.png");
    idTexturaInici = carregaTextura("botao_iniciar.png");
    idTexturaSair = carregaTextura("botao_exit.png");
    idLink = carregaTextura("Link.png");
    idGanon = carregaTextura("ganons.png");
    idBola = carregaTextura("bola.png");
    idSTART = carregaTextura("botao_iniciarSE.png");
    idEXIT = carregaTextura("botao_exitSE.png");
    idZeldaNormal = carregaTextura("zelda_0.png");
    idZeldaW = carregaTextura("zelda_1.png");
    idZeldaL0 = carregaTextura("zelda_2.png");
    idZeldaL1 = carregaTextura("zelda_3.png");
    idLos = carregaTextura("victoryGanon.png");
    idVic = carregaTextura("victory.png");

    botaoAtual = START;
}
