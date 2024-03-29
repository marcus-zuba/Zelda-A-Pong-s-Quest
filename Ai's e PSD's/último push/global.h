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
int ganonAtacando;
int linkVoltando;
int timerAtaca;
int linkCima;
int linkBaixo;
int ganonCima;
int ganonBaixo;
int MarX;
int MarX2;
int CeuX;
int CeuX2;
int MarI;
int CeuI;
float tempoLogo;
float timerLogo;
float tempoCristal;
float timerGanonAnda;
float timerLinkAnda;


enum Tela {MENU, JOGO, PAUSE, CONFIRMA, VITORIA};
enum Botao {START, EXIT};
enum Personagem {PARADO, ATACANDO, COMEMORANDO};

enum Tela telaAtual;
enum Botao botaoAtual;
enum Personagem linkAtual;
enum Personagem ganonAtual;

struct vetor2d{
  GLfloat x, y;
};

struct sprite{

    struct vetor2d posicao;  // Posição atual
    struct vetor2d proporcao;  // Altura, largura
    struct vetor2d velocidade;

    GLint idTextura;  // id da textura utilizada

    GLfloat quadrosHorizontais;  // quantidade de quadros H

    GLfloat quadroAtual;  // número do quadro atual
};


struct sprite link;
struct sprite ganon;
struct sprite bola;
struct vetor2d posicaoMouse;
struct vetor2d cMouse;
struct sprite ataqueLink;
struct sprite ataqueGanon;
struct sprite andaLink;
struct sprite andaGanon;
struct sprite logo;
struct sprite fundomenu;
struct sprite ZeldaPresa;
struct sprite ZeldaPresaW;
struct sprite ZeldaPresaL;

int keyboard[256];

GLuint idTexturaFundo;
GLuint idTexturaFundo2;
GLuint idTexturaFundo3;
GLuint idTexturaFundo4;
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
GLuint idMar;
GLuint idCeu;

#endif
