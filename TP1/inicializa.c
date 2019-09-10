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

    idTexturaFundo = carregaTextura("C:/Users/felip/TP1-CG/TP1/fundo.png");
    idTexturaMenu = carregaTextura("C:/Users/felip/TP1-CG/TP1/back_menu.png");
    idTexturaInici = carregaTextura("C:/Users/felip/TP1-CG/TP1/botao_iniciar.png");
    idTexturaSair = carregaTextura("C:/Users/felip/TP1-CG/TP1/botao_exit.png");
    idLink = carregaTextura("C:/Users/felip/TP1-CG/TP1/Link.png");
    idGanon = carregaTextura("C:/Users/felip/TP1-CG/TP1/ganons.png");
    idBola = carregaTextura("C:/Users/felip/TP1-CG/TP1/bola.png");
    idSTART = carregaTextura("C:/Users/felip/TP1-CG/TP1/botao_iniciarSE.png");
    idEXIT = carregaTextura("C:/Users/felip/TP1-CG/TP1/botao_exitSE.png");
    idZeldaNormal = carregaTextura("C:/Users/felip/TP1-CG/TP1/zelda_0.png");
    idZeldaW = carregaTextura("C:/Users/felip/TP1-CG/TP1/zelda_1.png");
    idZeldaL0 = carregaTextura("C:/Users/felip/TP1-CG/TP1/zelda_2.png");
    idZeldaL1 = carregaTextura("C:/Users/felip/TP1-CG/TP1/zelda_3.png");
    idLos = carregaTextura("C:/Users/felip/TP1-CG/TP1/victoryGanon.png");
    idVic = carregaTextura("C:/Users/felip/TP1-CG/TP1/victory.png");

    botaoAtual = START;
}
