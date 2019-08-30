/*
Compilado e executado no terminal do Ubuntu
Compilação: $ gcc poligono_regular.c -lglut -lGLU -lGL -lGLEW -lSOIL -lm
Execução: $ ./a.out 
*/

#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>


int num_lados=3;

struct personagem{
    int x;
    int y;
};

struct personagem p1;
struct personagem p2;


void desenhaBarra(float x, float y){

    glBegin(GL_LINE_LOOP);
    glVertex2f(x+30, y);
    glVertex2f(x+30, y+20);
    glVertex2f(x-30,y+20);
    glVertex2f(x-30, y);    
    glEnd();
    glFlush();

}

void desenhaMinhaCena(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    desenhaBarra(p1.x,p1.y);
    desenhaBarra(p2.x,p2.y);

}

void atualizaCena(int valorQualquer){

    glutPostRedisplay();
 
    glutTimerFunc(33, atualizaCena, 0);

}

void inicializa(){

    glClearColor(1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(3);
    p1.x=0;
    p1.y=-250;
    p2.x=0;
    p2.y=250;

}

void redimensionada(int width, int height){
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -300, 300, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y){

    switch(key){
    case 27:
        exit(0);
        break;
    case 'a':
        glutPostRedisplay();
        p1.x-=5;
        break;
    case 'd':
        glutPostRedisplay();
        p1.x+=5;
        break;
    case 'w':
        glutPostRedisplay();
        p1.y+=5;
        break;
    case 's':
        glutPostRedisplay();
        p1.y-=5;
        break;
    default:
        break;
    }
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
    glutDisplayFunc(desenhaMinhaCena);

    inicializa();

    glutMainLoop();
    return 0;
}