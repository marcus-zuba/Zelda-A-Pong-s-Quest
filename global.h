#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

int PontuacaoLink;
int PontuacaoGanon;
int SetsLink;
int SetsGanon;
int vitoriaLink;
int vitoriaGanon;
int velocidadeLink;
int velocidadeGanon;
int seColisao;
int tempoBola;
int linkAtacando;
int linkVoltando;
int timerAtaca;

enum Tela {MENU, JOGO, PAUSE, CONFIRMA, VITORIA};
enum Botao {START, EXIT};

enum Tela telaAtual;
enum Botao botaoAtual;

struct vetor2d{
  GLfloat x, y;
};

struct sprite{

    struct vetor2d posicao;  // Posição atual
    struct vetor2d proporcao;  // Altura, largura
    struct vetor2d velocidade;

    GLint idTextura;  // id da textura utilizada

    GLint quadrosHorizontais;  // quantidade de quadros H

    GLfloat quadroAtual;  // número do quadro atual
};


struct sprite link;
struct sprite ganon;
struct sprite bola;
struct vetor2d posicaoMouse;
struct vetor2d cMouse;
struct sprite ataqueLink;


int keyboard[256];

GLuint idTexturaFundo;
GLuint idTexturaMenu;
GLuint idTexturaInici;
GLuint idTexturaSair;
GLuint idLink;
GLuint idGanon;
GLuint idBola;
GLuint idSTART;
GLuint idEXIT;
GLuint idZeldaNormal;
GLuint idZeldaW;
GLuint idZeldaL0;
GLuint idZeldaL1;
GLint idVic;
GLint idLos;
GLfloat angulobola;

#endif
