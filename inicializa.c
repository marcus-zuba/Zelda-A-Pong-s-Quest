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
    bola.velocidade.x=7;
    bola.velocidade.y=7;
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
    timerMatchG=0;
    timerMatchL=0;

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaMenu = carregaTextura("C:/Users/felip/TP1-CG/Texturas/back_menu.png");
    idTexturaInici = carregaTextura("C:/Users/felip/TP1-CG/Texturas/botao_iniciar.png");
    idTexturaSair = carregaTextura("C:/Users/felip/TP1-CG/Texturas/botao_exit.png");
    idLink = carregaTextura("C:/Users/felip/TP1-CG/Texturas/Link.png");
    idGanon = carregaTextura("C:/Users/felip/TP1-CG/Texturas/Ganons.png");
    idSTART = carregaTextura("C:/Users/felip/TP1-CG/Texturas/botao_iniciarSE.png");
    idEXIT = carregaTextura("C:/Users/felip/TP1-CG/Texturas/botao_exitSE.png");
    idZeldaNormal = carregaTextura("C:/Users/felip/TP1-CG/Texturas/sair.png");
    idZeldaW = carregaTextura("C:/Users/felip/TP1-CG/Texturas/zelda_1.png");
    idZeldaL0 = carregaTextura("C:/Users/felip/TP1-CG/Texturas/mar.png");
    idZeldaL1 = carregaTextura("C:/Users/felip/TP1-CG/Texturas/ceu.png");
    idLos = carregaTextura("C:/Users/felip/TP1-CG/Texturas/victoryGanon.png");
    idVic = carregaTextura("C:/Users/felip/TP1-CG/Texturas/victory.png");
    idMar = carregaTextura("C:/Users/felip/TP1-CG/Texturas/mar.png");
    idCeu = carregaTextura("C:/Users/felip/TP1-CG/Texturas/ceu.png");
    pausa = carregaTextura("C:/Users/felip/TP1-CG/Texturas/pause.png");

    ZeldaPresa.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/zeldaPresas.png");
    ZeldaPresa.quadrosHorizontais =14;
    ZeldaPresa.quadroAtual=0;

    ZeldaPresaL.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/zeldaPresa1.png");
    ZeldaPresaL.quadrosHorizontais =14;
    ZeldaPresaL.quadroAtual=0;

    ZeldaPresaW.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/zeldaPresa2.png");
    ZeldaPresaW.quadrosHorizontais =14;
    ZeldaPresaW.quadroAtual=0;


    bola.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/bolaf.png");
    bola.quadrosHorizontais=3;
    bola.quadroAtual=1;

    ataqueLink.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/Link_Ataca.png");
    ataqueLink.quadrosHorizontais=3;
    ataqueLink.quadroAtual=0;

    ataqueGanon.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/g2.png");
    ataqueGanon.quadrosHorizontais=3;
    ataqueGanon.quadroAtual=2;

    andaLink.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/Link_Moveo.png");
    andaLink.quadrosHorizontais=6;
    andaLink.quadroAtual=0;

    andaGanon.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/ganon_sprite_mov.png");
    andaGanon.quadrosHorizontais=4;
    andaGanon.quadroAtual=0;

    fundomenu.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/anima_menu.png");
    fundomenu.quadrosHorizontais=2;
    fundomenu.quadroAtual=0;

    logo.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/logo-loz.png");
    logo.quadrosHorizontais = 4;
    logo.quadroAtual=0;

    Av.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/BOTAO_Ave.png");
    Av.quadrosHorizontais =2;
    Av.quadroAtual=0;

    Cl.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/BOTAO_Cla.png");
    Cl.quadrosHorizontais =2;
    Cl.quadroAtual=0;

    heart.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/heart.png");
    heart.quadrosHorizontais =11;

    heartG.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/heart.png");
    heartG.quadrosHorizontais =11;

    linkop.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/link_op_anim.png");
    linkop.quadrosHorizontais =4;
    linkop.quadroAtual=0;

    zeldaop.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/zelda_op_anim.png");
    zeldaop.quadrosHorizontais =4;
    zeldaop.quadroAtual=0;

    hist.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/historia1.png");
    hist.quadrosHorizontais =14;
    hist.quadroAtual=0;

    hist1.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/historia2.png");
    hist1.quadrosHorizontais =14;
    hist1.quadroAtual=0;

    tri.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/triforce.png");
    tri.quadrosHorizontais = 4;
    tri.quadroAtual =0;

    tri2.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/triforce.png");
    tri2.quadrosHorizontais = 4;
    tri2.quadroAtual =0;

    fases.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/fases.png");
    fases.quadrosHorizontais = 4;
    fases.quadroAtual =0;

    backg.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/back.png");
    backg.quadrosHorizontais = 4;
    backg.quadroAtual =0;

    stamina.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/stamina.png");
    stamina.quadrosHorizontais = 4;
    stamina.quadroAtual =0;

    ganonop.idTextura = carregaTextura("C:/Users/felip/TP1-CG/Texturas/ganon_op.png");
    ganonop.quadrosHorizontais = 4;
    ganonop.quadroAtual =0;


    botaoAtual = START;
}
