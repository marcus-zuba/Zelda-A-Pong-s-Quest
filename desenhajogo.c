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
            if(linkCima){
                if(andaLink.quadroAtual<3)
                    andaLink.quadroAtual=3;
                if(timerLinkAnda>3){
                    if(andaLink.quadroAtual <5)
                        andaLink.quadroAtual++;
                    else if(andaLink.quadroAtual==5)
                        andaLink.quadroAtual=3;
                        timerLinkAnda=0;
                }
                timerLinkAnda++;
                animaPersonagem(link.posicao.x-10,link.posicao.y,link.proporcao.x+5, link.proporcao.y, andaLink);
            }
            else if(linkBaixo){
                if(andaLink.quadroAtual>2)
                    andaLink.quadroAtual=0;
                if(timerLinkAnda>3){
                    if(andaLink.quadroAtual <2)
                        andaLink.quadroAtual++;
                    else if(andaLink.quadroAtual==2)
                        andaLink.quadroAtual=0;
                        timerLinkAnda=0;
                }
                timerLinkAnda++;
                animaPersonagem(link.posicao.x-3,link.posicao.y,link.proporcao.x+5, link.proporcao.y, andaLink);
            }
            else
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

    }
}

void desenhaGanon(){
    switch(ganonAtual){
        case(PARADO):
            if(ganonCima){
                if(andaGanon.quadroAtual<2)
                    andaGanon.quadroAtual=2;
                if(timerGanonAnda>5){
                    if(andaGanon.quadroAtual <3)
                        andaGanon.quadroAtual++;
                    else if(andaGanon.quadroAtual==3)
                        andaGanon.quadroAtual=2;
                    timerGanonAnda=0;
                }
                timerGanonAnda+=0.1;
                animaPersonagem(ganon.posicao.x,ganon.posicao.y,ganon.proporcao.x, ganon.proporcao.y, andaGanon);
            }
            else if(ganonBaixo){
                if(andaGanon.quadroAtual>1)
                    andaGanon.quadroAtual=0;
                if(timerGanonAnda>5){
                    if(andaGanon.quadroAtual <1)
                        andaGanon.quadroAtual++;
                    else if(andaGanon.quadroAtual==1)
                        andaGanon.quadroAtual=0;
                    timerGanonAnda=0;
                }
                timerGanonAnda+=0.1;
                animaPersonagem(ganon.posicao.x,ganon.posicao.y,ganon.proporcao.x, ganon.proporcao.y, andaGanon);
            }
            else
                desenhaPersonagem(ganon.posicao.x,ganon.posicao.y, ganon.proporcao.x, ganon.proporcao.y, idGanon);
            timerGanonAnda++;
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

    if(SetsGanon<2||(SetsGanon==2 && timerMatchL<7)){
    stamina.quadroAtual= SetsGanon;
    animaPersonagem( -90, -70, 5, 12, stamina);
    }

    if(SetsLink<2||(SetsLink==2 && timerMatchG<7)){
    stamina.quadroAtual= SetsLink;
    animaPersonagem( 90,  -70, 5, 12, stamina);
    }

    if(PontuacaoGanon<10||(PontuacaoGanon==10 && timerMatchL<7)){
        heart.quadroAtual=PontuacaoGanon;
        animaPersonagem( -70, -90, 20, 4, heart);
    }
    if(PontuacaoLink<10||(PontuacaoLink==10 && timerMatchG<7)){
        heart.quadroAtual=PontuacaoLink;
        animaPersonagem( 70, -90, 20, 4,heart);
    }


    desenhaLink();
    desenhaGanon();


    glPushMatrix();
    glTranslatef(bola.posicao.x,bola.posicao.y,0);
    glRotatef(angulobola+=3*bola.velocidade.x,0,0,1);
    animaPersonagem(0, 0, bola.proporcao.x,bola.proporcao.y, bola);
    glPopMatrix();

}
