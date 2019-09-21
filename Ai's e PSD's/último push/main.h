#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

void escrevePontuacao(void * , int , float , float );
void escreveSet(void * , int , float , float );
void desenhaPersonagem(float , float , float , float , GLuint);
void desenhaBola(float , float , float , float , GLuint);
void animaPersonagem(float x, float y, float l, float a, struct sprite personagem); // x, y, largura, altura

GLuint carregaTextura(const char* );


int main();

#endif
