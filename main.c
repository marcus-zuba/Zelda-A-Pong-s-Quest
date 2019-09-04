#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>

#define Y_MAXIMO 100
#define Y_MINIMO -100
#define X_MAXIMO 100
#define X_MINIMO -100

int PontuacaoLink;
int PontuacaoGanon;
int SetsLink;
int SetsGanon;
int botaoStart;
int botaoExit;
int vitoriaLink;
int vitoriaGanon;
int velocidadeLink;
int velocidadeGanon;

enum Tela {MENU, JOGO, PAUSE, VITORIA};

enum Tela telaAtual;

struct vetor2d{
  GLfloat x, y;
};

struct sprite{
    
    struct vetor2d posicao;  // Posição atual
    struct vetor2d proporcao;  // Altura, largura
    struct vetor2d velocidade;

    GLint idTextura;  // id da textura utilizada
    
    GLint quadrosHorizontais;  // quantidade de quadros H
    GLint quadrosVerticais;   // quantidade de quadros V
    
    GLint quadroAtual;  // número do quadro atual 
};

struct sprite link;
struct sprite ganon;
struct sprite bola;
struct vetor2d posicaoMouse;
struct vetor2d cMouse;

int keyboard[256];
int pause = 0;

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
    if(botaoStart)
        glColor3f(0,0,1);
    else
        glColor3f(0,0,0);
    desenhaPersonagem(0,30,20,10);
    if(botaoExit)
        glColor3f(0 ,0 ,1);
    else
        glColor3f(0,0,0);
    desenhaPersonagem(0,-30,20,10);
}

void desenhaJogo(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    escrevePontuacao(GLUT_BITMAP_HELVETICA_18,PontuacaoLink, -80, 80);
    escrevePontuacao(GLUT_BITMAP_HELVETICA_18,PontuacaoGanon, 80, 80);
    escreveSet(GLUT_BITMAP_HELVETICA_18,SetsLink, -80, 90);
    escreveSet(GLUT_BITMAP_HELVETICA_18,SetsGanon, 80, 90);                    
    glColor3f(0, 1, 0);
    desenhaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x, link.proporcao.y);
    glColor3f(1, 0, 0);
    desenhaPersonagem(ganon.posicao.x,ganon.posicao.y, ganon.proporcao.x, ganon.proporcao.y);
    glColor3f(0, 0, 0);
    desenhaBola(bola.posicao.x, bola.posicao.y,bola.proporcao.x,bola.proporcao.y);
}

void desenhaMinhaCena(){

    switch(telaAtual){

        case(MENU):
            desenhaBotoes();
            glutSwapBuffers();
            break;
        case(JOGO):
            desenhaJogo();
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

void detectaMouse(){

    if((posicaoMouse.y>=20 && posicaoMouse.y<=40) && 
        (posicaoMouse.x>=-20 && posicaoMouse.x<=20))
            botaoStart=1;
    else
            botaoStart=0;
    if((posicaoMouse.y<=-20 && posicaoMouse.y>=-40) && 
        (posicaoMouse.x>=-20 && posicaoMouse.x<=20))
            botaoExit=1;
    else
            botaoExit=0;
    if((cMouse.y>=20 && cMouse.y<=40) && 
        (cMouse.x>=-20 && cMouse.x<=20))
            telaAtual=JOGO;
    if((cMouse.y<=-20 && cMouse.y>=-40) && 
        (cMouse.x>=-20 && cMouse.x<=20))
            exit(0);

}

void atualizaCena(int valorQualquer){
    switch(telaAtual){
        case(MENU):
            detectaMouse();
            break;
        case(JOGO):
            if(pause%2==0){
                atualizaPontuacao();
                atualizaVelocidade();
                movimentaPersonagens();
                bola.posicao.x+=bola.velocidade.x;
                bola.posicao.y+=bola.velocidade.y;
            }
            break;
        default:
            break;
    }

    glutPostRedisplay();
    glutTimerFunc(33, atualizaCena, 0);
}

void inicializa(){

    glClearColor(1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(3);
    link.posicao.x=-90;
    link.posicao.y=0;
    link.proporcao.x=2;
    link.proporcao.y=15;
    ganon.posicao.x=90;
    ganon.posicao.y=0;
    ganon.proporcao.x=2;
    ganon.proporcao.y=15;
    bola.velocidade.x=3.5;
    bola.velocidade.y=3.5;
    bola.proporcao.x=3;
    bola.proporcao.y=3;
    telaAtual = MENU;
    PontuacaoLink=0;
    PontuacaoGanon=0;
    SetsLink=0;
    SetsGanon=0;
    botaoStart=0;
    botaoExit=0;
    vitoriaGanon=0;
    vitoriaLink=0;
    velocidadeLink=10;
    velocidadeGanon=10;
}

void movimentoMouse(int x, int y){
    posicaoMouse.x=x;
    posicaoMouse.y=y;
}

void cliqueMouse(int button, int state, int x, int y){
    cMouse.x=x;
    cMouse.y=y;
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
                case(32):
                    telaAtual=JOGO;
                    break;
                case(27):
                    exit(0);
                default:
                    break;
            }      
        case(JOGO):
            keyboard[key]=1;
            switch(key){
                case(27):
                    exit(0);
                    break;
                case('p'):
                    pause++;
                    break;
                default:
                    break;
            }
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
    glutPassiveMotionFunc(movimentoMouse);
    glutMouseFunc(cliqueMouse);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glutDisplayFunc(desenhaMinhaCena);
    glutTimerFunc(33, atualizaCena, 0);
    inicializa();

    glutMainLoop();
    return 0;
}