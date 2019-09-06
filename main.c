#include <SOIL/SOIL.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>

#include "desenhajogo.h"
#include "global.h"
#include "inicializa.h"

#define Y_MAXIMO 100
#define Y_MINIMO -100
#define X_MAXIMO 100
#define X_MINIMO -100

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

void desenhaFundo(float x, float y, float l, float a){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaFundo);
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

void desenhaPersonagem(float x, float y, float l, float a){ // x, y, largura, altura


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x-l,y-a);
    glVertex2f(x+l,y-a);
    glVertex2f(x+l,y+a);
    glVertex2f(x-l,y+a); 
    glEnd();
    

}

void desenhaBola(float x, float y, float l, float a){ // x, y, largura, altura

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x-l,y-a);
    glVertex2f(x+l,y-a);
    glVertex2f(x+l,y+a);
    glVertex2f(x-l,y+a); 
    glEnd();
    

}

void desenhaBotoes(){
    glClear(GL_COLOR_BUFFER_BIT);
    if(botaoAtual == START)
        glColor3f(0,0,1);
    else
        glColor3f(0,0,0);
    desenhaPersonagem(0,30,20,10);
    if(botaoAtual == EXIT)
        glColor3f(0 ,0 ,1);
    else
        glColor3f(0,0,0);
    desenhaPersonagem(0,-30,20,10);
}


void desenhaMinhaCena(){

    switch(telaAtual){

        case(MENU):
            desenhaBotoes();
            glutSwapBuffers();
            break;
        case(JOGO):
            glClear(GL_COLOR_BUFFER_BIT);
            desenhaFundo(2,3,4,5);
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
            glColor3f(0, 0, 0);
            if(vitoriaLink)
                escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "VITORIA DO LINK!", -40,80);
            if(vitoriaGanon)
                escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "VITORIA DO GANON!", -40,80);
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
    if((xb-lb<=xl+ll) && (yb <= yl+al && yb >= yl-al))
        bola.velocidade.x *= -1; 
    if((xb+lb>=xg-lg) && (yb <= yg+ag && yb >= yg-ag))
        bola.velocidade.x *= -1; 


}

void atualizaPontuacao(){

    GLfloat xb = bola.posicao.x; // x da bola
    GLfloat lb = bola.proporcao.x; // largura da bola

    if(xb-lb<=X_MINIMO && PontuacaoGanon<3){
        PontuacaoGanon++;
        bola.posicao.x=0;
        bola.posicao.y=0;
    }

    if(xb+lb>=X_MAXIMO && PontuacaoLink<3){
        PontuacaoLink++;
        bola.posicao.x=0;
        bola.posicao.y=0;
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
        SetsLink=0;
    }

    if(SetsGanon==2){
        vitoriaGanon=1;
        telaAtual=VITORIA;
        SetsGanon=0;
    }

}

void movimentaPersonagens(){
    if(keyboard['w'] && (link.posicao.y+link.proporcao.y < Y_MAXIMO))
        link.posicao.y+=velocidadeLink;
    if(keyboard['s'] && (link.posicao.y-link.proporcao.y > Y_MINIMO))
        link.posicao.y-=velocidadeLink;
    if(keyboard['o'] && (ganon.posicao.y+ganon.proporcao.y < Y_MAXIMO))
        ganon.posicao.y+=velocidadeGanon;
    if(keyboard['l'] && (ganon.posicao.y-ganon.proporcao.y > Y_MINIMO))
        ganon.posicao.y-=velocidadeGanon;
}

void atualizaCena(int valorQualquer){
    switch(telaAtual){
        case(MENU):
            break;
        case(JOGO):
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
                    sleep(1);
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "2", 0,0);
                    glutSwapBuffers();
                    sleep(1);
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "1", 5,0);
                    glutSwapBuffers();
                    sleep(1);                    
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
                    sleep(1);
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "2", 0,0);
                    glutSwapBuffers();
                    sleep(1);
                    glColor3f(1, 1, 1);
                    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "1", 5,0);
                    glutSwapBuffers();
                    sleep(1);                    
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
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1600, 900);
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