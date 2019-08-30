#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define Y_MAXIMO 100
#define Y_MINIMO -100
#define X_MAXIMO 100
#define X_MINIMO -100

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

int keyboard[256];
int pause = 0;

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

void desenhaMinhaCena(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    desenhaPersonagem(link.posicao.x,link.posicao.y,link.proporcao.x, link.proporcao.y);
    glColor3f(1, 0, 0);
    desenhaPersonagem(ganon.posicao.x,ganon.posicao.y, ganon.proporcao.x, ganon.proporcao.y);
    glColor3f(0, 0, 0);
    desenhaBola(bola.posicao.x, bola.posicao.y,bola.proporcao.x,bola.proporcao.y);
    glutSwapBuffers();

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

    if(yb+ab == Y_MAXIMO || yb-ab == Y_MINIMO)
        bola.velocidade.y *= -1;
    if((xb-lb==xl+ll) && (yb <= yl+al && yb >= yl-al))
        bola.velocidade.x *= -1; 
    if((xb+lb==xg-lg) && (yb <= yg+ag && yb >= yg-ag))
        bola.velocidade.x *= -1; 

}

void atualizaCena(int valorQualquer){

    if(pause%2==0){
        atualizaVelocidade();
        if(keyboard['w'] && (link.posicao.y+link.proporcao.y < Y_MAXIMO))
            link.posicao.y+=5;
        if(keyboard['s'] && (link.posicao.y-link.proporcao.y > Y_MINIMO))
            link.posicao.y-=5;
        if(keyboard['o'] && (ganon.posicao.y+ganon.proporcao.y < Y_MAXIMO))
            ganon.posicao.y+=5;
        if(keyboard['l'] && (ganon.posicao.y-ganon.proporcao.y > Y_MINIMO))
            ganon.posicao.y-=5;

        bola.posicao.x+=bola.velocidade.x;
        bola.posicao.y+=bola.velocidade.y;
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
    link.proporcao.x=5;
    link.proporcao.y=15;
    ganon.posicao.x=90;
    ganon.posicao.y=0;
    ganon.proporcao.x=5;
    ganon.proporcao.y=15;
    bola.velocidade.x=1;
    bola.velocidade.y=1;
    bola.proporcao.x=3;
    bola.proporcao.y=3;

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

    glutCreateWindow("The Adventure of Zelda Pong");

    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaLiberada);
    glutDisplayFunc(desenhaMinhaCena);
    glutTimerFunc(33, atualizaCena, 0);
    inicializa();

    glutMainLoop();
    return 0;
}