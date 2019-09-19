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

    idTexturaFundo = carregaTextura("C:/Users/felip/TP1-CG/fundo3.png");
    idTexturaFundo2 = carregaTextura("C:/Users/felip/TP1-CG/fundo2.png");
    idTexturaFundo3 = carregaTextura("C:/Users/felip/TP1-CG/fundo3.png");
    idTexturaFundo4 = carregaTextura("C:/Users/felip/TP1-CG/fundo4.png");
    idTexturaMenu = carregaTextura("C:/Users/felip/TP1-CG//back_menu.png");
    idTexturaInici = carregaTextura("C:/Users/felip/TP1-CG/botao_iniciar.png");
    idTexturaSair = carregaTextura("C:/Users/felip/TP1-CG/botao_exit.png");
    idLink = carregaTextura("C:/Users/felip/TP1-CG/Link.png");
    idGanon = carregaTextura("C:/Users/felip/TP1-CG/Ganons.png");
    idSTART = carregaTextura("C:/Users/felip/TP1-CG/botao_iniciarSE.png");
    idEXIT = carregaTextura("C:/Users/felip/TP1-CG/botao_exitSE.png");
    idZeldaNormal = carregaTextura("C:/Users/felip/TP1-CG/zelda_0.png");
    idZeldaW = carregaTextura("C:/Users/felip/TP1-CG/zelda_1.png");
    idZeldaL0 = carregaTextura("C:/Users/felip/TP1-CG/1411x274.png");
    idZeldaL1 = carregaTextura("C:/Users/felip/TP1-CG/1411x362.png");
    idLos = carregaTextura("C:/Users/felip/TP1-CG/victoryGanon.png");
    idVic = carregaTextura("C:/Users/felip/TP1-CG/victory.png");
    idMar = carregaTextura("C:/Users/felip/TP1-CG/1411x274.png");
    idCeu = carregaTextura("C:/Users/felip/TP1-CG/1411x362.png");

    ZeldaPresa.idTextura = carregaTextura("C:/Users/felip/TP1-CG/ZeldaPresas.png");
    ZeldaPresa.quadrosHorizontais =14;
    ZeldaPresa.quadroAtual=0;

    ZeldaPresaL.idTextura = carregaTextura("C:/Users/felip/TP1-CG/ZeldaPresa1.png");
    ZeldaPresaL.quadrosHorizontais =14;
    ZeldaPresaL.quadroAtual=0;

    ZeldaPresaW.idTextura = carregaTextura("C:/Users/felip/TP1-CG/ZeldaPresa2.png");
    ZeldaPresaW.quadrosHorizontais =14;
    ZeldaPresaW.quadroAtual=0;


    bola.idTextura = carregaTextura("C:/Users/felip/TP1-CG/bolaf.png");
    bola.quadrosHorizontais=3;
    bola.quadroAtual=1;

    ataqueLink.idTextura = carregaTextura("C:/Users/felip/TP1-CG//Link_Ataca.png");
    ataqueLink.quadrosHorizontais=3;
    ataqueLink.quadroAtual=0;

    ataqueGanon.idTextura = carregaTextura("C:/Users/felip/TP1-CG/g2.png");
    ataqueGanon.quadrosHorizontais=3;
    ataqueGanon.quadroAtual=2;

    andaLink.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Link_Moveo.png");
    andaLink.quadrosHorizontais=6;
    andaLink.quadroAtual=0;

    andaGanon.idTextura = carregaTextura("C:/Users/felip/TP1-CG/ganon_sprite_mov.png");
    andaGanon.quadrosHorizontais=4;
    andaGanon.quadroAtual=0;

    fundomenu.idTextura = carregaTextura("C:/Users/felip/TP1-CG/anima_menu.png");
    fundomenu.quadrosHorizontais=2;
    fundomenu.quadroAtual=0;

    logo.idTextura = carregaTextura("C:/Users/felip/TP1-CG/fade_logos.png");
    logo.quadrosHorizontais =4;
    logo.quadroAtual=0;

    botaoAtual = START;
}
