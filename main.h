#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

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

void escrevePontuacao(void * , int , float , float );
void escreveSet(void * , int , float , float );
void desenhaPersonagem(float , float , float , float );
void desenhaBola(float , float , float , float );

int main();

#endif