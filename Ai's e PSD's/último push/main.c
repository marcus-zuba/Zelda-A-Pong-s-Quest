#include <SOIL/SOIL.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include<time.h>

#include "desenhajogo.h"
#include "global.h"
#include "inicializa.h"

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


void escreveTexto(void * font, char *s, float x, float y) {
    int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void escrevePontuacao(void * font, int pontuacao, float x, float y){
    glRasterPos2f(x,y);
    char c = pontuacao + 48;
    glutBitmapCharacter(font, c);
}

void escreveSet(void * font, int set, float x, float y){
    glRasterPos2f(x,y);
    char c = set + 48;
    glutBitmapCharacter(font, c);
}

void desenhaFundo(float x, float y, float l, float a, GLuint idTextura){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0,0);
    glVertex2f(-100,-100);
    glTexCoord2f(0,1);
    glVertex2f(-100,100);
    glTexCoord2f(1,1);
    glVertex2f(100,100);
    glTexCoord2f(1,0);
    glVertex2f(100,-100);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void desenhaPersonagem(float x, float y, float l, float a, GLuint idTextura){ // x, y, largura, altura

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0,0);
    glVertex2f(x-l,y-a);
    glTexCoord2f(1,0);
    glVertex2f(x+l,y-a);
    glTexCoord2f(1,1);
    glVertex2f(x+l,y+a);
    glTexCoord2f(0,1);
    glVertex2f(x-l,y+a);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void animaPersonagem(float x, float y, float l, float a, struct sprite personagem){ // x, y, largura, altura

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, personagem.idTextura);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(personagem.quadroAtual/personagem.quadrosHorizontais,0);
    glVertex2f(x-l,y-a);
    glTexCoord2f((personagem.quadroAtual/personagem.quadrosHorizontais)+1/personagem.quadrosHorizontais,0);
    glVertex2f(x+l,y-a);
    glTexCoord2f((personagem.quadroAtual/personagem.quadrosHorizontais)+1/personagem.quadrosHorizontais,1);
    glVertex2f(x+l,y+a);
    glTexCoord2f(personagem.quadroAtual/personagem.quadrosHorizontais,1);
    glVertex2f(x-l,y+a);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}


/*void desenhaBola(float x, float y, float l, float a, GLuint idTextura){ // x, y, largura, altura

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0,0);
    glVertex2f(x-l,y-a);
    glTexCoord2f(1,0);
    glVertex2f(x+l,y-a);
    glTexCoord2f(1,1);
    glVertex2f(x+l,y+a);
    glTexCoord2f(0,1);
    glVertex2f(x-l,y+a);
    glEnd();
    glDisable(GL_TEXTURE_2D);


}*/

void desenhaBotoes(){
    desenhaPersonagem(0, -40, 32.5, 15, idTexturaInici);

    desenhaPersonagem(0, -65, 20.5, 10, idTexturaSair);

    if(botaoAtual == START){
        desenhaPersonagem(0, -40, 32.5, 15, idSTART);
    }else{
        desenhaPersonagem(0, -65, 20.5, 10, idEXIT);
    }

}



void desenhaMinhaCena(){

    switch(telaAtual){

        case(MENU):
            glClear(GL_COLOR_BUFFER_BIT);

            desenhaPersonagem(MarX, -50, 140, 49.9, idMar);
            desenhaPersonagem(CeuX, 50, 140, 50, idCeu);

            MarX-=5;
            CeuX--;


            if(MarX==-40){
                MarX2=240.00001;
                MarI++;
            }

                desenhaPersonagem(MarX2, -50, 140, 49.9, idZeldaL0);

            if(CeuX==-40){
                CeuX2=240.000001;
                CeuI++;
            }

                desenhaPersonagem(CeuX2, 50, 140, 50, idZeldaL1);

            MarX2-=5;
            CeuX2--;


            if(MarX2==-40){
                MarX=240.000001;
                MarI=0;
            }

            if(CeuX2==-40){
                CeuX=240.000001;
                MarI=0;
            }

            timerLogo++;
            if(timerLogo>240){
                animaPersonagem(0, 60, 50, 25, logo);
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

            desenhaFundo(2,3,4,5,idTexturaFundo);

            animaPersonagem(0, 70, 10, 25, ZeldaPresa);
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
            escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "PAUSE - PARA REINICIAR PRESSIONE P", -30,60);
            glutSwapBuffers();
            break;
        case(CONFIRMA):
            glColor3f(1,1,1);
            escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "DESEJA MESMO SAIR? APERTE S PARA SIM OU N PARA NAO", -50,60);
            glutSwapBuffers();
            break;
        case(VITORIA):
            glClear(GL_COLOR_BUFFER_BIT);
            desenhaFundo(2,3,4,5,idTexturaFundo);
            desenhaJogo();

            if(vitoriaLink){

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
        }
        if((xb+lb>=xg-lg) && (yb-ab <= yg+ag && yb+ab >= yg-ag)){ //colisao com a frente do ganon
            bola.velocidade.x *= -1;
            xb = xg - lg - 1 + lb;
            seColisao=0;
            ganonAtual=ATACANDO;
            bola.quadroAtual=0;
        }
    }
}

void atualizaPontuacao(){

    GLfloat xb = bola.posicao.x; // x da bola
    GLfloat lb = bola.proporcao.x; // largura da bola

    if(xb-lb<=X_MINIMO && PontuacaoGanon<3){
        PontuacaoGanon++;
        bola.posicao.x=0;
        bola.posicao.y=65;
        tempoBola=0;
        bola.quadroAtual=1;
    }

    if(xb+lb>=X_MAXIMO && PontuacaoLink<3){
        PontuacaoLink++;
        bola.posicao.x=0;
        bola.posicao.y=65;
        tempoBola=0;
        bola.quadroAtual=1;
    }

    if(PontuacaoLink==3){
        SetsLink++;
        PontuacaoLink=0;
    }

    if(PontuacaoGanon==3){
        SetsGanon++;
        PontuacaoGanon=0;
    }

    if(SetsLink==2){
        vitoriaLink=1;
        telaAtual=VITORIA;
        bola.posicao.x=5000;
        SetsLink=0;
    }

    if(SetsGanon==2){
        vitoriaGanon=1;
        bola.posicao.x=5000;
        telaAtual=VITORIA;
        SetsGanon=0;
    }

}

void movimentaPersonagens(){
    if(keyboard['w'] && (link.posicao.y+link.proporcao.y < Y_MAXIMO) /*&& linkAtual==PARADO*/){
        link.posicao.y+=velocidadeLink;
//        linkAtual=CIMA;
    }
    else if(keyboard['s'] && (link.posicao.y-link.proporcao.y > Y_MINIMO) /*&& linkAtual==PARADO*/){
        link.posicao.y-=velocidadeLink;
//        linkAtual=BAIXO;
    }
//    else if(linkAtual==CIMA || linkAtual==BAIXO)
//        linkAtual=PARADO;
    if(keyboard['o'] && (ganon.posicao.y+ganon.proporcao.y < Y_MAXIMO)/* && ganonAtual==PARADO*/){
        ganon.posicao.y+=velocidadeGanon;
//        ganonAtual=CIMA;
    }
    else if(keyboard['l'] && (ganon.posicao.y-ganon.proporcao.y > Y_MINIMO)/* && ganonAtual==PARADO*/){
        ganon.posicao.y-=velocidadeGanon;
//        ganonAtual=BAIXO;
    }
//    else if(ganonAtual==CIMA || ganonAtual==BAIXO)
//        ganonAtual=PARADO;
}

void atualizaCena(int valorQualquer){
    switch(telaAtual){
        case(MENU):
            break;
        case(JOGO):
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

void teclaPressionada(unsigned char key, int x, int y){
    switch(telaAtual){
        case(MENU):
            switch(key){
                case('w'):
                    botaoAtual = START;
                    break;
                case('s'):
                    botaoAtual = EXIT;
                    break;
                case(13):
                    if(botaoAtual == START)
                        telaAtual = JOGO;
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
        case(PAUSE):
            switch(key){
                case('p'):
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "3", -5,0);
                    glutSwapBuffers();
                    //sleep(1);
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "2", 0,0);
                    glutSwapBuffers();
                    //sleep(1);
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "1", 5,0);
                    glutSwapBuffers();
                    //sleep(1);
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
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "3", -5,0);
                    glutSwapBuffers();

                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "2", 0,0);
                    glutSwapBuffers();

                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "1", 5,0);
                    glutSwapBuffers();

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
    glutInitWindowPosition(200, 100);

    glutCreateWindow(" ");

    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glutDisplayFunc(desenhaMinhaCena);
    glutTimerFunc(33, atualizaCena, 0);
    inicializa();

    glutMainLoop();
    return 0;
}
