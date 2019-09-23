#include <GL/glew.h>
#include <GL/freeglut.h>

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

int MusicaPrincipal=0;
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
int linkVoltando=0;
int timerAtaca=0;
int linkCima=0;
int linkBaixo=0;
int ganonCima=0;
int ganonBaixo=0;
int MarX2=1000;
int MarX=40;
int CeuX=40;
int CeuX2=1000;
int MarI=0;
int CeuI=0;
int progresso=0;
float tempoLogo =0;
float timerLogo =0;
float tempoCristal=0;
float timerGanonAnda=0;
float timerLinkAnda =0;
int timerHist =0;
int timerIdVitoria=0;

enum Tela {INTRO, ESCOLHA, MENU, JOGO, PAUSE, REINICIAR, CONFIRMA, VITORIA,CLASSICO};
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

GLuint idTexturaFundo;
GLuint idTexturaFundo2;
GLuint idTexturaFundo3;
GLuint idTexturaFundo4;
GLuint idLink;
GLuint idGanon;
GLuint idTexturaInici;
GLuint idTexturaSair;
GLuint idTexturaMenu;
GLuint idBola;
GLuint idSTART;
GLuint idEXIT;
GLuint idZeldaNormal;
GLuint idZeldaW;
GLuint idZeldaL0;
GLuint idZeldaL1;
GLint idVic;
GLint idLos;
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


GLfloat angulobola=0;
