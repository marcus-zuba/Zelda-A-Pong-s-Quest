#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

void escrevePontuacao(void * , int , float , float );
void escreveSet(void * , int , float , float );
void desenhaPersonagem(float , float , float , float , GLuint);
void desenhaBola(float , float , float , float , GLuint);
GLuint carregaTextura(const char* );


int main();

#endif
