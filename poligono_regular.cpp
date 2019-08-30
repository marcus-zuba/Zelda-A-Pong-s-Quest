#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>

int numlados= 3;

void desenhaCirculo(float raio, float x, float y, float z) {
    double ang=0;

    glBegin(GL_LINE_LOOP);
        for(int vert = 1; vert <= numlados; vert++){
            glVertex3f(x+ (cos(ang)*raio), y+ (sin(ang)*raio), z);
            ang = (2 * M_PI * vert )/ numlados;
        }
    glEnd();
    glFlush();

}

void desenhar(){

	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glLineWidth(3);
    desenhaCirculo(120,250,250,0);

}

void inicializa() {
    glClearColor(0.85, 0, 0, 0);

}


void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, width, 0, height, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y) {
    switch(key) {
    case 27:      // Tecla "ESC"
        exit(0);
        break;
    case '+':
        glutPostRedisplay();
        numlados++;
        break;
    case '-':
        if(numlados>3){
            glutPostRedisplay();
            numlados--;
        }
        break;
    }
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);

   glutCreateWindow("Ativ_3");

   glutDisplayFunc(desenhar);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);

   inicializa();
   glutMainLoop();
   return 0;
}
