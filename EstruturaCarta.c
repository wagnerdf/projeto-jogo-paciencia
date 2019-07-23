#ifndef ESTRUTURA_ALUNOS
#define ESTRUTURA_ALUNOS
// declaração de um novo tipo de dado
typedef struct cel_Carta{
    char valor;
    int naipe;
    int face;
    int indice;
    struct cel_Carta *prox;
}carta;


typedef carta* pilha;
// definições
#define Verso  0
#define Frente 1

//Define naipe P=PAUS, O=OUROS, C=COPAS, E=ESPADAS, A=AS, R=REIS
#define P   5
#define O   4
#define C   3
#define E   6
#define A     1
#define R    13

#define BRANCO    15
#define PRETO      0
#define VERMELHO   4
#define AMARELO   14

#endif
