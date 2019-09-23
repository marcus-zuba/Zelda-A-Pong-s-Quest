#include <SOIL/SOIL.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "desenhajogo.h"
#include "global.h"
#include "inicializa.h"
#include "musica.h"

#define Y_MAXIMO 75
#define Y_MINIMO -73
#define X_MAXIMO 75
#define X_MINIMO -72


void desenhaMinhaCena(){

    switch(telaAtual){
        case(CLASSICO):

            glClear(GL_COLOR_BUFFER_BIT);

            desenhaMarCeu();
            logo.quadroAtual=3;
            animaPersonagem(0, 60, 50, 25, logo);

            desenhaOpcoes();

            glutSwapBuffers();

        break;

        case(INTRO):

            timerHist++;

            if(hist.quadroAtual<13){
                glClear(GL_COLOR_BUFFER_BIT);

                desenhaMarCeu();

                animaPersonagem(0, -20, 40, 60, hist);


                if( hist.quadroAtual!=7 && hist.quadroAtual!=11 ){
                    if(timerHist%5==0)
                        hist.quadroAtual++;
                }
                if(hist.quadroAtual==7){
                    if(timerHist%70==0 )
                        hist.quadroAtual++;
                }
                if( hist.quadroAtual==11 ){
                    if(timerHist%70==0 )
                        hist.quadroAtual++;
                }
                if( hist.quadroAtual==13){
                    if(timerHist%50==0 )
                        hist.quadroAtual++;
                }
            }else if(hist.quadroAtual>=13){
                glClear(GL_COLOR_BUFFER_BIT);

                desenhaMarCeu();

                animaPersonagem(0, -20, 40, 60, hist1);

                if(hist1.quadroAtual!=1 && hist1.quadroAtual!=5 && hist1.quadroAtual!=9 && hist1.quadroAtual!=10){
                    if(timerHist%5==0)
                        hist1.quadroAtual++;
                }

                if(hist1.quadroAtual==5){
                    if(timerHist%70==0)
                        hist1.quadroAtual++;
                }

                if(hist1.quadroAtual==9){
                    if(timerHist%70==0  )
                        hist1.quadroAtual++;
                }

                if(hist1.quadroAtual==1){
                    if(timerHist%70==0)
                        hist1.quadroAtual++;
                }

                if(hist1.quadroAtual==10){
                    if(timerHist%100==0)
                        hist1.quadroAtual++;
                }
            }



            if(hist1.quadroAtual==13){
                progresso=1;
                telaAtual=JOGO;
            }

            if(hist1.quadroAtual>=1){
                animaPersonagem(-60,0, 30, 45, linkop);

                if(timerHist%10==0 && linkop.quadroAtual<3){
                    linkop.quadroAtual++;
                }
            }

            if(hist1.quadroAtual>=5){

                animaPersonagem(0,60, 45, 30, ganonop);

                if(timerHist%10==0 && ganonop.quadroAtual<3)
                    ganonop.quadroAtual++;

            }

            if(hist1.quadroAtual>=9){
                animaPersonagem(60,0, 30, 45, zeldaop);

                if(timerHist%10==0 && zeldaop.quadroAtual<3)
                    zeldaop.quadroAtual++;

            }

            glutSwapBuffers();

            break;

        case(ESCOLHA):

            glClear(GL_COLOR_BUFFER_BIT);

            desenhaMarCeu();
            logo.quadroAtual=3;
            animaPersonagem(0, 60, 50, 25, logo);

            desenhaBotoesEsc();

            glutSwapBuffers();

            break;
        case(MENU):
            if(!MusicaPrincipal){
                play_music(principal, 1, -1);
                MusicaPrincipal=1;
            }
            glClear(GL_COLOR_BUFFER_BIT);

            desenhaFundinho( 0, -50, 100, 50, 0.368, 0.494, 0.709);
            desenhaFundinho( 0, 50, 100, 50, 0.560, 0.721, 0.917);
            desenhaFundinho( 0, 0, 100, 1, 0.909, 0.949, 1);
            desenhaPersonagem(MarX, -50, 140, 49.9, idMar);
            desenhaPersonagem(CeuX, 50, 140, 50, idCeu);

            MarX-=5;
            CeuX--;
            if(MarX==-40){
                MarX2=240.00001;
                MarI++;
            }
                desenhaPersonagem( MarX2, -50, 140, 49.9, idZeldaL0);
            if(CeuX==-40){
                CeuX2=240;
                CeuI++;
            }
                desenhaPersonagem( CeuX2, 50, 140, 50, idZeldaL1);
            MarX2-=5;
            CeuX2--;
            if(MarX2==-40){
                MarX=240.000001;
                MarI=0;
            }
            if(CeuX2==-40){
                CeuX=239;
                MarI=0;
            }
            timerLogo++;
            if(timerLogo>240){
                animaPersonagem( 0, 60, 50, 25, logo);
                if(logo.quadroAtual<3 && tempoLogo>=0.1){
                    logo.quadroAtual++;
                    tempoLogo=0;
                }
                else if(logo.quadroAtual==3 && tempoLogo>=0.1){
                    tempoLogo=0;

                }
                tempoLogo+=0.028;
            }

            desenhaBotoes();

            glutSwapBuffers();

            break;

        case(JOGO):
            glClear(GL_COLOR_BUFFER_BIT);

            animaPersonagem( 0, 0, 100, 100, backg);

            animaPersonagem( 0, 70, 10, 25, ZeldaPresa);
            if(ZeldaPresa.quadroAtual<13 && tempoCristal>=0.1){
                ZeldaPresa.quadroAtual++;
                tempoCristal=0;
            }
            else if(ZeldaPresa.quadroAtual==13 && tempoCristal>=0.1){
                tempoCristal=0;
                ZeldaPresa.quadroAtual=0;
            }
            tempoCristal+=0.05;

            desenhaJogo();


            glutSwapBuffers();

            break;

        case(PAUSE):

            glColor3f(1,1,1);

            desenhaPersonagem( 0, 0, 30, 30,pausa);

            glutSwapBuffers();

            break;

        case(CONFIRMA):

            glColor3f(1,1,1);

            desenhaPersonagem( 0, 0, 30, 30,idZeldaNormal);

            glutSwapBuffers();

            break;

        case(VITORIA):

            glClear(GL_COLOR_BUFFER_BIT);

            animaPersonagem( 0, 0, 100, 100, backg);

            desenhaJogo();

            if(vitoriaLink){

                switch(modoAtual){
                    
                    case(AVENTURA):
                        
                        if(timerIdVitoria<50 && progresso!=4){
                            desenhaPersonagem(0, 0, 30,30, idVic);
                            timerIdVitoria++;
                        }
                        else{
                            timerIdVitoria=0;

                            if(progresso==1){
                                backg.quadroAtual=1;
                                progresso=2;
                                telaAtual=JOGO;
                                vitoriaLink=0;
                            }
                            else if(progresso==2){
                                backg.quadroAtual=2;
                                progresso=3;
                                telaAtual=JOGO;
                                vitoriaLink=0;

                            }
                            else if(progresso==3){ 
                                progresso=4;                                   
                                backg.quadroAtual=3;
                                telaAtual=JOGO;
                                vitoriaLink=0;
                            }
                            else if(progresso==4){
                                desenhaPersonagem(0, 0, 30,30, idVic);
                                animaPersonagem(0, 70, 10, 25, ZeldaPresaW);
                                if(ZeldaPresaW.quadroAtual<13 && tempoCristal>=0.1){
                                    ZeldaPresaW.quadroAtual++;
                                    tempoCristal=0;
                                }
                                else if(ZeldaPresa.quadroAtual==13 && tempoCristal>=0.1){
                                    tempoCristal=0;
                                }
                                tempoCristal+=0.05;
                            }
                        }            
                        break;
                    case(CLASS):
                        animaPersonagem(0, 70, 10, 25, ZeldaPresaW);
                        if(ZeldaPresaW.quadroAtual<13 && tempoCristal>=0.1){
                            ZeldaPresaW.quadroAtual++;
                            tempoCristal=0;
                        }
                        else if(ZeldaPresa.quadroAtual==13 && tempoCristal>=0.1){
                            tempoCristal=0;

                        }
                        tempoCristal+=0.05;

                        desenhaPersonagem(0, 0, 30,30, idVic);

                        break;
                }
            }
            if(vitoriaGanon){

                animaPersonagem(0, 70, 10, 25, ZeldaPresaL);
                if(ZeldaPresaL.quadroAtual<13 && tempoCristal>=0.1){
                    ZeldaPresaL.quadroAtual++;
                    tempoCristal=0;
                }
                else if(ZeldaPresa.quadroAtual==13 && tempoCristal>=0.1){
                    tempoCristal=0;
                    ZeldaPresaL.quadroAtual=12;
                }
                tempoCristal+=0.05;

                desenhaPersonagem(0, 0, 50, 30, idLos);
            }

            glutSwapBuffers();
            break;

        default:

            break;
    }
}

