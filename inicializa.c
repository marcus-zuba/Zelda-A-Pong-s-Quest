#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "main.h"
#include "global.h"

void inicializa(){

    glClearColor(1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(3);
    link.posicao.x=-90;
    link.posicao.y=0;
    link.proporcao.x=2;
    link.proporcao.y=15;
    ganon.posicao.x=90;
    ganon.posicao.y=0;
    ganon.proporcao.x=2;
    ganon.proporcao.y=15;
    bola.velocidade.x=3.5;
    bola.velocidade.y=3.5;
    bola.proporcao.x=3;
    bola.proporcao.y=3;
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
    botaoAtual = START;
}
