#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED


#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

int MusicaPrincipal;
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
int progresso;
int timerMatchG;
int timerMatchL;
float tempoLogo;
float timerLogo;
float tempoCristal;
float timerGanonAnda;
float timerLinkAnda;
int timerHist;
int timerIdVitoria;


enum Tela {INTRO, ESCOLHA, MENU, JOGO, PAUSE, REINICIAR, CONFIRMA, VITORIA, CLASSICO};
enum Botao {START, EXIT, CLA};
enum Personagem {PARADO, ATACANDO, COMEMORANDO};
enum Modo {AVENTURA, CLASS};

enum Tela telaAtual;
enum Botao botaoAtual;
enum Personagem linkAtual;
enum Personagem ganonAtual;
enum Modo modoAtual;


struct vetor2d{
  GLfloat x, y;
};

struct sprite{

    struct vetor2d posicao;  // Posi��o atual
    struct vetor2d proporcao;  // Altura, largura
    struct vetor2d velocidade;

    GLint idTextura;  // id da textura utilizada

    GLfloat quadrosHorizontais;  // quantidade de quadros H

    GLfloat quadroAtual;  // n�mero do quadro atual
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
struct sprite Av;
struct sprite Cl;
struct sprite heart;
struct sprite linkop;
struct sprite zeldaop;
struct sprite hist;
struct sprite hist1;
struct sprite tri;
struct sprite tri2;
struct sprite heartG;
struct sprite fases;
struct sprite backg;
struct sprite stamina;
struct sprite ganonop;

int keyboard[256];


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
GLuint pausa;
GLuint reiniciar;

Mix_Chunk * opcaoescolha; 

Mix_Chunk * way1; 
Mix_Chunk * way2; 
Mix_Chunk * way3; 
Mix_Chunk * way4; 

Mix_Chunk * principal; 
 
Mix_Chunk * hue1; 
Mix_Chunk * hue2; 
Mix_Chunk * hue3; 

Mix_Chunk * Lhit;
Mix_Chunk * Ghit;
Mix_Chunk * Glos;


#endif
