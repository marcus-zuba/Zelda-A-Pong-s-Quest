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

    if(!linkAtacando)
    animaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x+5, link.proporcao.y, ataqueLink);
//   desenhaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x, link.proporcao.y, ataqueLink.idTextura);
    else
    animaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x+5, link.proporcao.y, ataqueLink);
    
    desenhaPersonagem(ganon.posicao.x,ganon.posicao.y, ganon.proporcao.x, ganon.proporcao.y, idGanon);
    glPushMatrix();
    glTranslatef(bola.posicao.x,bola.posicao.y,0);
    glRotatef(angulobola+=3*bola.velocidade.x,0,0,1);
    desenhaBola(0, 0,bola.proporcao.x,bola.proporcao.y, idBola);
    glPopMatrix();
    if(linkVoltando==1 && ataqueLink.quadroAtual>0){
        ataqueLink.quadroAtual--;
    }
    else if(ataqueLink.quadroAtual==0 && linkVoltando==1)
        linkVoltando=0;
    if(ataqueLink.quadroAtual==2){
        linkVoltando=1;
        linkAtacando=0;
    }
    if(linkAtacando && timerAtaca>=3){
        ataqueLink.quadroAtual++;
        timerAtaca=0;
    }
    timerAtaca++;
}
