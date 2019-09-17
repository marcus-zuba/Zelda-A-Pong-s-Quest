#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include "global.h"
#include "main.h"
#include "inicializa.h"

void desenhaLink(){
    switch(linkAtual){

        case(PARADO):
            animaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x+5, link.proporcao.y, ataqueLink);
            break;
        case(ATACANDO):
            animaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x+5, link.proporcao.y, ataqueLink);
            timerAtaca++;
            if(linkVoltando==1 && ataqueLink.quadroAtual>0 && timerAtaca>=2){
                ataqueLink.quadroAtual--;
                timerAtaca=0;
            }
            if(ataqueLink.quadroAtual==0 && linkVoltando==1 && timerAtaca>=1){
                linkVoltando=0;
                linkAtual=PARADO;
                timerAtaca=0;
            }
            if(ataqueLink.quadroAtual==2)
                linkVoltando=1;
            if(timerAtaca>=1 && !linkVoltando){
                ataqueLink.quadroAtual++;
                timerAtaca=0;
            }
            break;
//        case(CIMA):
//            animaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x+5, link.proporcao.y, andaLink);
//            break;




    }
}

void desenhaGanon(){
    switch(ganonAtual){
        case(PARADO):
            desenhaPersonagem(ganon.posicao.x,ganon.posicao.y, ganon.proporcao.x, ganon.proporcao.y, idGanon);
            break;
        case(ATACANDO):
            animaPersonagem(ganon.posicao.x,ganon.posicao.y,ganon.proporcao.x, ganon.proporcao.y, ataqueGanon);
            timerAtaca++;
            if(timerAtaca>=5){
                ganonAtual=PARADO;  
                timerAtaca=0;
            }
            break;
    }
}

void desenhaJogo(){

    glColor3f(0, 0, 0);
    escrevePontuacao(GLUT_BITMAP_HELVETICA_18,PontuacaoLink, -80, 80);
    escrevePontuacao(GLUT_BITMAP_HELVETICA_18,PontuacaoGanon, 80, 80);
    escreveSet(GLUT_BITMAP_HELVETICA_18,SetsLink, -80, 90);
    escreveSet(GLUT_BITMAP_HELVETICA_18,SetsGanon, 80, 90);

    desenhaLink();
    desenhaGanon();

    glPushMatrix();
    glTranslatef(bola.posicao.x,bola.posicao.y,0);
    glRotatef(angulobola+=3*bola.velocidade.x,0,0,1);
    desenhaBola(0, 0,bola.proporcao.x,bola.proporcao.y, idBola);
    glPopMatrix();

}
