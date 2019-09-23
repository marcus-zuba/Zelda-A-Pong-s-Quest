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

GLuint carregaTextura(const char* arquivo) {

    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}



void desenhaFundo(float x, float y, float l, float a, GLuint idTextura){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glColor3f( 1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0, 0);
    glVertex2f( -100, -100);
    glTexCoord2f( 0, 1);
    glVertex2f( -100, 100);
    glTexCoord2f( 1, 1);
    glVertex2f( 100, 100);
    glTexCoord2f( 1, 0);
    glVertex2f( 100, -100);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void desenhaPersonagem(float x, float y, float l, float a, GLuint idTextura){ // x, y, largura, altura

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glColor3f( 1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0, 0);
    glVertex2f( x-l, y-a);
    glTexCoord2f( 1, 0);
    glVertex2f( x+l, y-a);
    glTexCoord2f( 1, 1);
    glVertex2f( x+l, y+a);
    glTexCoord2f( 0, 1);
    glVertex2f( x-l, y+a);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void animaPersonagem(float x, float y, float l, float a, struct sprite personagem){ // x, y, largura, altura

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, personagem.idTextura);
    glColor3f( 1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(personagem.quadroAtual/personagem.quadrosHorizontais,0);
    glVertex2f( x-l, y-a);
    glTexCoord2f((personagem.quadroAtual/personagem.quadrosHorizontais)+1/personagem.quadrosHorizontais,0);
    glVertex2f( x+l, y-a);
    glTexCoord2f((personagem.quadroAtual/personagem.quadrosHorizontais)+1/personagem.quadrosHorizontais,1);
    glVertex2f( x+l, y+a);
    glTexCoord2f(personagem.quadroAtual/personagem.quadrosHorizontais,1);
    glVertex2f( x-l, y+a);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}


void desenhaFundinho(float x, float y, float l, float a, float r, float g, float b){ // x, y, largura, altura

    glColor3f( r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f( x-l, y-a);
    glVertex2f( x+l, y-a);
    glVertex2f( x+l, y+a);
    glVertex2f( x-l, y+a);
    glEnd();
}

void desenhaBotoes(){
    desenhaPersonagem( 0, -40, 32.5, 15, idTexturaInici);

    desenhaPersonagem( 0, -65, 20.5, 10, idTexturaSair);

    if(botaoAtual == START){
        desenhaPersonagem( 0, -40, 32.5, 15, idSTART);
    }else{
        desenhaPersonagem( 0, -65, 20.5, 10, idEXIT);
    }
}

void desenhaOpcoes(){

    Cl.quadroAtual=0;
    animaPersonagem( 0, 0, 30, 15, Cl);

    animaPersonagem( -30, -55, 4, 7, tri);

    animaPersonagem( 0, -55, 20, 25, fases);

    glPushMatrix();
    glTranslatef( 30, -55, 0);
    glRotatef( 180, 0, 0, 1);
    animaPersonagem( 0, 0, 4, 7, tri2);
    glPopMatrix();
}

void desenhaBotoesEsc(){
    animaPersonagem( 0, -10, 32.5, 15, Av);

    animaPersonagem( 0, -55, 32.5, 15, Cl);

    if(botaoAtual == START){
        Av.quadroAtual=0;
        Cl.quadroAtual=1;
    }else{
        Cl.quadroAtual=0;
        Av.quadroAtual=1;
    }
}

void desenhaMarCeu(){

    desenhaFundinho( 0, -50, 100, 50, 0.368, 0.494, 0.709);
    desenhaFundinho( 0, 50, 100, 50, 0.560, 0.721, 0.917);
    desenhaFundinho( 0, 0, 100, 1, 0.909, 0.949, 1);

    desenhaPersonagem( MarX, -50, 140, 49.9, idMar);
    desenhaPersonagem( CeuX, 50, 140, 50, idCeu);
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
}

void desenhaMinhaCena(){

    switch(telaAtual){

		case(REINICIAR):

            glColor3f(1,1,1);

            desenhaPersonagem( 0, 0, 30, 30, reiniciar);

            glutSwapBuffers();

            break;
	
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



void atualizaVelocidade(){

    GLfloat yb = bola.posicao.y; // y da bola
    GLfloat xb = bola.posicao.x; // x da bola
    GLfloat yl = link.posicao.y; // y do link
    GLfloat xl = link.posicao.x; // x do link
    GLfloat yg = ganon.posicao.y; // y do ganon
    GLfloat xg = ganon.posicao.x; // x do ganon
    GLfloat ab = bola.proporcao.y; // altura da bola
    GLfloat lb = bola.proporcao.x; // largura da bola
    GLfloat al = link.proporcao.y; // altura do link
    GLfloat ll = link.proporcao.x; // largura do link
    GLfloat ag = ganon.proporcao.y; // altura do ganon
    GLfloat lg = ganon.proporcao.x; // largura do ganon

    if(yb+ab >= Y_MAXIMO || yb-ab <= Y_MINIMO)
        bola.velocidade.y *= -1;
    if(seColisao>10){
        if((xb-lb<=xl+ll-8) && (yb-ab <= yl+al && yb+ab >= yl-al)){ //colisao com a frente do link
            bola.velocidade.x *= -1;
            xb = xl + lg + 1 - lb;
            seColisao=0;
            linkAtual=ATACANDO;
            bola.quadroAtual=2;
            int som = rand()%4;
            switch(som){
                case(0):
                    play_music(way1, 2, 0);
                    break;
                case(1):
                    play_music(way2, 2, 0);
                    break;
                case(2):
                    play_music(way3, 2, 0);
                    break;
                case(3):
                    play_music(way4, 2, 0);
                    break;
            }
        }

        if((xb+lb>=xg-lg) && (yb-ab <= yg+ag && yb+ab >= yg-ag)){ //colisao com a frente do ganon
            bola.velocidade.x *= -1;
            xb = xg - lg - 1 + lb;
            seColisao=0;
            ganonAtual=ATACANDO;
            bola.quadroAtual=0;
            int som = rand()%3;
            switch(som){
                case(0):
                    play_music(hue1, 2, 0);
                    break;
                case(1):
                    play_music(hue2, 2, 0);
                    break;
                case(2):
                    play_music(hue3, 2, 0);
                    break;
            }
        }
    }
}

void atualizaPontuacao(){

    GLfloat xb = bola.posicao.x;
    GLfloat lb = bola.proporcao.x;

    if(xb-lb<=X_MINIMO ){
        PontuacaoGanon++;
        bola.posicao.x=0;
        bola.posicao.y=65;
        tempoBola=0;
        bola.quadroAtual=1;
        play_music(Lhit, 2, 0);
    }

    if(xb+lb>=X_MAXIMO ){
        PontuacaoLink++;
        bola.posicao.x=0;
        bola.posicao.y=65;
        tempoBola=0;
        bola.quadroAtual=1;
        play_music(Ghit, 2, 0);
    }

    if(PontuacaoLink==11){
        SetsLink++;
        PontuacaoLink=0;
    }

    if(PontuacaoGanon==11){
        SetsGanon++;
        PontuacaoGanon=0;
    }

    if(SetsLink==3){
        vitoriaLink=1;
        telaAtual=VITORIA;
        bola.posicao.x=5000;
        SetsLink=0;
        play_music(Glos, 2, 0);
    }

    if(SetsGanon==3){
        vitoriaGanon=1;
        bola.posicao.x=5000;
        telaAtual=VITORIA;
        SetsGanon=0;
        play_music(Lhit, 2, 0);
    }

}

void movimentaPersonagens(){
    if(keyboard['w'] && (link.posicao.y+link.proporcao.y < Y_MAXIMO)){
        link.posicao.y+=velocidadeLink;
    }
    else if(keyboard['s'] && (link.posicao.y-link.proporcao.y > Y_MINIMO)){
        link.posicao.y-=velocidadeLink;

    }
    if(keyboard['o'] && (ganon.posicao.y+ganon.proporcao.y < Y_MAXIMO)){
        ganon.posicao.y+=velocidadeGanon;

    }
    else if(keyboard['l'] && (ganon.posicao.y-ganon.proporcao.y > Y_MINIMO)){
        ganon.posicao.y-=velocidadeGanon;

    }
}

void atualizaCena(int valorQualquer){

    switch(telaAtual){

        case(INTRO):

            break;
        case(ESCOLHA):

            break;
        case(MENU):

            break;
        case(JOGO):
            if(PontuacaoLink==10){
                timerMatchG++;
            }
            else{
                timerMatchG=0;
            }
            if(timerMatchG==10)
                timerMatchG=0;
            if(PontuacaoGanon==10){
                timerMatchL++;
            }else{
                timerMatchL=0;
            }
            if(timerMatchL==10)
                timerMatchL=0;
            tempoBola++;
            seColisao++;
            srand(time(0));
            if(tempoBola<50){
                bola.velocidade.x=0;
                bola.velocidade.y=0;
            }
            else{
                if(tempoBola==50){
                    if(rand()%2==0){
                        bola.velocidade.x=-3.0;
                        bola.velocidade.y=-3.0;
                    }else{
                        bola.velocidade.x=3.0;
                        bola.velocidade.y=3.0;
                    }
                }
                if(bola.velocidade.x>0)
                    bola.velocidade.x+=0.01;
                else
                    bola.velocidade.x-=0.01;
                if(bola.velocidade.y>0)
                    bola.velocidade.y+=0.01;
                else
                    bola.velocidade.y-=0.01;
            }

            atualizaPontuacao();

            atualizaVelocidade();

            movimentaPersonagens();

            bola.posicao.x+=bola.velocidade.x;

            bola.posicao.y+=bola.velocidade.y;

            break;

        case(PAUSE):

            break;
        case(CONFIRMA):

            break;

        default:

            break;
    }

    glutPostRedisplay();

    glutTimerFunc(33, atualizaCena, 0);
}


void redimensionada(int width, int height){
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void reiniciaJogo(){
	telaAtual=MENU;
    link.posicao.x=-60;
    link.posicao.y=0;
    ganon.posicao.x=60;
    ganon.posicao.y=0;
    bola.velocidade.x=7;
    bola.velocidade.y=7;
    bola.posicao.x=0;
    bola.posicao.y=65;
	progresso=1;
    PontuacaoLink=0;
    PontuacaoGanon=0;
    SetsLink=0;
    SetsGanon=0;
    vitoriaGanon=0;
    vitoriaLink=0;
    seColisao=100;
    tempoBola=0;
    linkAtacando=0;
    ganonAtacando=0;
    timerMatchG=0;
    timerMatchL=0;
}


void teclaPressionada(unsigned char key, int x, int y){
    switch(telaAtual){
        case(CLASSICO):
            switch(key){
            case('w'):
                botaoAtual = START;
				play_music(opcaoescolha, 2, 0);
                break;
            case('s'):
                botaoAtual= CLA;
				play_music(opcaoescolha, 2, 0);
                break;
            case('d'):
				play_music(opcaoescolha, 2, 0);
                botaoAtual = START;
                fases.quadroAtual++;
                if(fases.quadroAtual>3)
                    fases.quadroAtual=0;
                if(fases.quadroAtual<0)
                    fases.quadroAtual=4;

                tri.quadroAtual=1;
                tri2.quadroAtual=0;
                break;
            case('a'):
				play_music(opcaoescolha, 2, 0);
                botaoAtual = START;
                fases.quadroAtual--;
                if(fases.quadroAtual>3)
                    fases.quadroAtual=0;
                if(fases.quadroAtual<0)
                    fases.quadroAtual=3;

                tri.quadroAtual=0;
                tri2.quadroAtual=1;
                break;
            case(13):
                botaoAtual = START;
                backg.quadroAtual=fases.quadroAtual;

                telaAtual=JOGO;

                break;

            default:
                break;
            }


        case(ESCOLHA):
            switch(key){
            case('w'):
                botaoAtual = START;
				play_music(opcaoescolha, 2, 0);
                break;
            case('s'):
                botaoAtual= CLA;
				play_music(opcaoescolha, 2, 0);
                break;
            case(13):
                if(botaoAtual == START){
                    telaAtual = INTRO;
                    modoAtual = AVENTURA;
                }
                if(botaoAtual == CLA){
                    telaAtual = CLASSICO;
                    modoAtual = CLASS;
                }
                break;

            default:
                break;

            }
            break;

        case(MENU):
            switch(key){
                case('w'):
					play_music(opcaoescolha, 2, 0);
                    botaoAtual = START;
                    break;
                case('s'):
					play_music(opcaoescolha, 2, 0);
                    botaoAtual = EXIT;
                    break;
                case(13):
                    if(botaoAtual == START)
                        telaAtual = ESCOLHA;
                    if(botaoAtual == EXIT)
                        exit(0);
                    break;
                default:
                    break;
            }
            break;
        case(JOGO):
            keyboard[key]=1;
            switch(key){
				case('r'):
				 	glutPostRedisplay();
                    telaAtual=REINICIAR;
                    break;
                case(27):
                    glutPostRedisplay();
                    telaAtual = CONFIRMA;
                    break;
                case('p'):
                    telaAtual = PAUSE;
                    glutPostRedisplay();
                    break;
                case('w'):
                    linkCima=1;
                    break;
                case('s'):
                    linkBaixo=1;
                    break;
                case('o'):
                    ganonCima=1;
                    break;
                case('l'):
                    ganonBaixo=1;
                    break;
                default:
                    break;
            }
            break;
		case(REINICIAR):
            switch(key){
                case('s'):
                    reiniciaJogo();
                    break;
                case('n'):
                    telaAtual=JOGO;
                    break;
				default:
					break;
			}
        case(PAUSE):
            switch(key){
                case('p'):

                    telaAtual = JOGO;
                    break;

                    default:
                    break;
            }
            break;
        case(VITORIA):
            switch(key){
                case(27):
                    exit(0);
                case('r'):
                    inicializa();
                    break;
                default:
                    break;
            }
            break;
        case(CONFIRMA):
            switch(key){
                case('s'):
                    exit(0);
                case('n'):
                    glColor3f(1, 1, 1);


                    telaAtual = JOGO;
                    break;
            }
            break;
        default:
            break;
    }

}

void teclaLiberada(unsigned char key, int x, int y){
    keyboard[key]=0;
    switch(telaAtual){
        case(JOGO):
            switch(key){
                case('w'):
                    linkCima=0;
                    break;
                case('s'):
                    linkBaixo=0;
                    break;
                case('o'):
                    ganonCima=0;
                    break;
                case('l'):
                    ganonBaixo=0;
                    break;
            }
            break;
    }

}


int main(int argc, char** argv){

    glutInit(&argc, argv);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1300, 1260);
    glutInitWindowPosition(300, 100);


    glutCreateWindow("Zelda - A Pong's Quest");

    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glutDisplayFunc(desenhaMinhaCena);
    glutTimerFunc(33, atualizaCena, 0);
    inicializa();


    glutMainLoop();
    return 0;

}
