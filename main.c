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


void desenhaFundinho(float x, float y, float l, float a, float r, float g, float b){ // x, y, largura, altura

    glColor3f(r,g,b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x-l,y-a);
    glVertex2f(x+l,y-a);
    glVertex2f(x+l,y+a);
    glVertex2f(x-l,y+a);
    glEnd();


}

void desenhaBotoes(){
    desenhaPersonagem(0, -40, 32.5, 15, idTexturaInici);

    desenhaPersonagem(0, -65, 20.5, 10, idTexturaSair);

    if(botaoAtual == START){
        desenhaPersonagem(0, -40, 32.5, 15, idSTART);
    }else{
        desenhaPersonagem(0, -65, 20.5, 10, idEXIT);
    }

}

void desenhaOpcoes(){


    Cl.quadroAtual=0;
    animaPersonagem(0, 0, 30, 15, Cl);


    animaPersonagem(-30, -55, 4, 7, tri);

    animaPersonagem(0, -55, 20, 25, fases);

    glPushMatrix();
    glTranslatef(30,-55,0);
    glRotatef(180,0,0,1);
    animaPersonagem(0, 0, 4, 7, tri2);
    glPopMatrix();


}

void desenhaBotoesEsc(){
    animaPersonagem(0, -10, 32.5, 15, Av);

    animaPersonagem(0, -55, 32.5, 15, Cl);

    if(botaoAtual == START){
        Av.quadroAtual=0;
        Cl.quadroAtual=1;
    }else{
        Cl.quadroAtual=0;
        Av.quadroAtual=1;
    }

}


void desenhaMinhaCena(){

    switch(telaAtual){
        case(CLASSICO):
            glClear(GL_COLOR_BUFFER_BIT);

            desenhaFundinho(0,-50,100,50,0.368,0.494,0.709);
            desenhaFundinho(0,50,100,50,0.560,0.721,0.917);
            desenhaFundinho(0,0,100,1,0.909,0.949,1);


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
                CeuX2=240;
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
                CeuX=240;
                MarI=0;
            }
            logo.quadroAtual=3;
            animaPersonagem(0, 60, 50, 25, logo);

            desenhaOpcoes();
            glutSwapBuffers();




        break;
        case(INTRO):

            glClear(GL_COLOR_BUFFER_BIT);

            desenhaPersonagem(MarX, -50, 140, 49.9, idMar);
            desenhaPersonagem(CeuX, 50, 140, 50, idCeu);

            MarX-=5;
            CeuX--;


            if(MarX==-40){
                MarX2=240;
                MarI++;
            }

                desenhaPersonagem(MarX2, -50, 140, 49.9, idZeldaL0);

            if(CeuX==-40){
                CeuX2=240;
                CeuI++;
            }

                desenhaPersonagem(CeuX2, 50, 140, 50, idZeldaL1);

            MarX2-=5;
            CeuX2--;


            if(MarX2==-40){
                MarX=240;
                MarI=0;
            }

            if(CeuX2==-40){
                CeuX=240;
                MarI=0;
            }
            logo.quadroAtual=3;
            animaPersonagem(0, 60, 50, 25, logo);


            desenhaBotoesEsc();
            glutSwapBuffers();



            break;
        case(ESCOLHA):

             glClear(GL_COLOR_BUFFER_BIT);
        
            desenhaFundinho(0,-50,100,50,0.368,0.494,0.709);
            desenhaFundinho(0,50,100,50,0.560,0.721,0.917);
            desenhaFundinho(0,0,100,1,0.909,0.949,1);


            desenhaPersonagem(MarX, -50, 140, 49.9, idMar);
            desenhaPersonagem(CeuX, 50, 140, 50, idCeu);

            MarX-=5;
            CeuX--;
            if(MarX==-40){
                MarX2=240;
                MarI++;
            }
                desenhaPersonagem(MarX2, -50, 140, 49.9, idZeldaL0);
            if(CeuX==-40){
                CeuX2=240;
                CeuI++;
            }
                desenhaPersonagem(CeuX2, 50, 140, 50, idZeldaL1);
            MarX2-=5;
            CeuX2--;
            if(MarX2==-40){
                MarX=240;
                MarI=0;
            }
            if(CeuX2==-40){
                CeuX=240;
                MarI=0;
            }
            logo.quadroAtual=3;
            animaPersonagem(0, 60, 50, 25, logo);
            desenhaBotoesEsc();
            glutSwapBuffers();



            break;
        case(MENU):
            if(!MusicaPrincipal){
                tocar_musica1("../Sounds/principal.ogg",-1);
                MusicaPrincipal=1;
            }
            glClear(GL_COLOR_BUFFER_BIT);

            desenhaFundinho(0,-50,100,50,0.368,0.494,0.709);
            desenhaFundinho(0,50,100,50,0.560,0.721,0.917);
            desenhaFundinho(0,0,100,1,0.909,0.949,1);
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
                CeuX2=240;
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
                CeuX=240;
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
/*            if(MusicaPrincipal){
                parar_musica();
                MusicaPrincipal=0;
            }*/
            glClear(GL_COLOR_BUFFER_BIT);

            animaPersonagem(0,0,100,100,backg);

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
            desenhaPersonagem(0,0,30,30,pausa);
            glutSwapBuffers();
            break;
        case(CONFIRMA):
           glColor3f(1,1,1);
            desenhaPersonagem(0,0,30,30,idZeldaNormal);
            glutSwapBuffers();
            break;
        case(VITORIA):
            glClear(GL_COLOR_BUFFER_BIT);
            animaPersonagem(0,0,100,100,backg);
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
            int som = rand()%4;
            switch(som){
                case(0):
                    tocar_musica2("../Sounds/way1.ogg",0);
                    break;
                case(1):
                    tocar_musica2("../Sounds/way2.ogg",0);
                    break;
                case(2):
                    tocar_musica2("../Sounds/way3.ogg",0);
                    break;
                case(3):
                    tocar_musica2("../Sounds/way4.ogg",0);
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
                    tocar_musica2("../Sounds/hue1.ogg",0);
                    break;
                case(1):
                    tocar_musica2("../Sounds/hue2.ogg",0);
                    break;
                case(2):
                    tocar_musica2("../Sounds/hue3.ogg",0);
                    break;
            }
        }
    }
}

//l�gica aqui para baixo um pouco zoada

void atualizaPontuacao(){

    GLfloat xb = bola.posicao.x; // x da bola
    GLfloat lb = bola.proporcao.x; // largura da bola

    if(xb-lb<=X_MINIMO ){
        PontuacaoGanon++;
        bola.posicao.x=0;
        bola.posicao.y=65;
        tempoBola=0;
        bola.quadroAtual=1;
        tocar_musica2("../Sounds/Lhit1.ogg",0);
    }

    if(xb+lb>=X_MAXIMO ){
        PontuacaoLink++;
        bola.posicao.x=0;
        bola.posicao.y=65;
        tempoBola=0;
        bola.quadroAtual=1;
        tocar_musica2("../Sounds/Ghit1.ogg",0);
    }

    if(PontuacaoLink==11){
        SetsLink++;
        PontuacaoLink=0;
    }

    if(PontuacaoGanon==11){
        SetsGanon++;
        PontuacaoGanon=0;
    }

    if(SetsLink==2){
        vitoriaLink=1;
        telaAtual=VITORIA;
        bola.posicao.x=5000;
        SetsLink=0;
        tocar_musica2("../Sounds/Glos.ogg",0);
        tocar_musica2("../Sounds/Wlink.ogg",0);
    }

    if(SetsGanon==2){
        vitoriaGanon=1;
        bola.posicao.x=5000;
        telaAtual=VITORIA;
        SetsGanon=0;
        tocar_musica2("../Sounds/Lhit1.ogg",0);
        tocar_musica2("../Sounds/Wganon.ogg",0);
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
//        ganonAtual=BAIXO
    }
//    else if(ganonAtual==CIMA || ganonAtual==BAIXO)
//        ganonAtual=PARADO;
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

void teclaPressionada(unsigned char key, int x, int y){
    switch(telaAtual){
        case(CLASSICO):
            switch(key){
            case('w'):
                botaoAtual = START;
                break;
            case('s'):
                botaoAtual= CLA;
                break;
            case('d'):
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
                break;
            case('s'):
                botaoAtual= CLA;
                break;
            case(13):
                if(botaoAtual == START)
                    telaAtual = JOGO;

                if(botaoAtual == CLA)
                    telaAtual = CLASSICO;
                break;

            default:
                break;

            }
            break;

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
