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

    idTexturaFundo = carregaTextura("../Texturas/fundo3.png");
    idTexturaFundo2 = carregaTextura("../Texturas/fundo2.png");
    idTexturaFundo3 = carregaTextura("../Texturas/fundo3.png");
    idTexturaFundo4 = carregaTextura("../Texturas/fundo4.png");
    idTexturaMenu = carregaTextura("../Texturas//back_menu.png");
    idTexturaInici = carregaTextura("../Texturas/botao_iniciar.png");
    idTexturaSair = carregaTextura("../Texturas/botao_exit.png");
    idLink = carregaTextura("../Texturas/Link.png");
    idGanon = carregaTextura("../Texturas/Ganons.png");
    idSTART = carregaTextura("../Texturas/botao_iniciarSE.png");
    idEXIT = carregaTextura("../Texturas/botao_exitSE.png");
    idZeldaNormal = carregaTextura("../Texturas/zelda_0.png");
    idZeldaW = carregaTextura("../Texturas/zelda_1.png");
    idZeldaL0 = carregaTextura("../Texturas/1411x274.png");
    idZeldaL1 = carregaTextura("../Texturas/1411x362.png");
    idLos = carregaTextura("../Texturas/victoryGanon.png");
    idVic = carregaTextura("../Texturas/victory.png");
    idMar = carregaTextura("../Texturas/1411x274.png");
    idCeu = carregaTextura("../Texturas/1411x362.png");

    ZeldaPresa.idTextura = carregaTextura("../Texturas/ZeldaPresas.png");
    ZeldaPresa.quadrosHorizontais =14;
    ZeldaPresa.quadroAtual=0;

    ZeldaPresaL.idTextura = carregaTextura("../Texturas/ZeldaPresa1.png");
    ZeldaPresaL.quadrosHorizontais =14;
    ZeldaPresaL.quadroAtual=0;

    ZeldaPresaW.idTextura = carregaTextura("../Texturas/ZeldaPresa2.png");
    ZeldaPresaW.quadrosHorizontais =14;
    ZeldaPresaW.quadroAtual=0;


    bola.idTextura = carregaTextura("../Texturas/bolaf.png");
    bola.quadrosHorizontais=3;
    bola.quadroAtual=1;

    ataqueLink.idTextura = carregaTextura("../Texturas//Link_Ataca.png");
    ataqueLink.quadrosHorizontais=3;
    ataqueLink.quadroAtual=0;

    ataqueGanon.idTextura = carregaTextura("../Texturas/g2.png");
    ataqueGanon.quadrosHorizontais=3;
    ataqueGanon.quadroAtual=2;

    andaLink.idTextura = carregaTextura("../Texturas/Link_Moveo.png");
    andaLink.quadrosHorizontais=6;
    andaLink.quadroAtual=0;

    andaGanon.idTextura = carregaTextura("../Texturas/ganon_sprite_mov.png");
    andaGanon.quadrosHorizontais=4;
    andaGanon.quadroAtual=0;

    fundomenu.idTextura = carregaTextura("../Texturas/anima_menu.png");
    fundomenu.quadrosHorizontais=2;
    fundomenu.quadroAtual=0;

    logo.idTextura = carregaTextura("../Texturas/fade_logos.png");
    logo.quadrosHorizontais =4;
    logo.quadroAtual=0;

    botaoAtual = START;
}
