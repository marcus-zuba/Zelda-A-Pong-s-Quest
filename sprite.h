#include<vetor2d.h>

struct sprite{
    
    struct vetor2d posicao;  // Posição atual
    struct vetor2d proporcao;  // Altura, largura
    
    int idTextura;  // id da textura utilizada
    
    int quadrosHorizontais;  // quantidade de quadros H
    int quadrosVerticais;   // quantidade de quadros V
    
    int quadroAtual;  // número do quadro atual 
}

