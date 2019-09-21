#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include "global.h"
#include "main.h"
#include "inicializa.h"


void desenhaJogo(){
    glColor3f(0, 0, 0);
    escrevePontuacao(GLUT_BITMAP_HELVETICA_18,PontuacaoLink, -80, 80);
    escrevePontuacao(GLUT_BITMAP_HELVETICA_18,PontuacaoGanon, 80, 80);
    escreveSet(GLUT_BITMAP_HELVETICA_18,SetsLink, -80, 90);
    escreveSet(GLUT_BITMAP_HELVETICA_18,SetsGanon, 80, 90);

    desenhaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x, link.proporcao.y, idLink);

    desenhaPersonagem(ganon.posicao.x,ganon.posicao.y, ganon.proporcao.x, ganon.proporcao.y, idGanon);

    desenhaPersonagem(0, 70, 15, 30, idZeldaNormal);

    desenhaBola(bola.posicao.x, bola.posicao.y,bola.proporcao.x,bola.proporcao.y, idBola);
}
