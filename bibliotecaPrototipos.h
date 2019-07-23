//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Prototipos>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void desenhaMoldura(int linhaInicial, int colunaInicial, int linhaFinal, int colunaFinal, int corFundoAtual, int corLetraAtual); //Moldura para tela de seleção
void retornaCor(int corFundo,int corTexto);//Aplica cor a moldura 
char menuInicio(void);  // Desenhar a tela inicial do jogo
void embaralha(pilha *baralho); // embaralha as cartas na pilha
int f_naipe(int of); //Define nipe da carta
void push(pilha *baralho, carta crt); //inserir cartas
carta pop(pilha *baralho); //retirar cartas 
void desenhaCartaVazia(int coluna,int linha); //desenha uma carta vazia
void desenhaTabuleiro(pilha pilhasDeJogo[7], pilha pilhasDeNaipes[4], pilha baralho, pilha pilhaDeDescarte); //desenha a tela do jogo
int validaRegras(pilha *origem, pilha *destino, char tipo); // valida as regras de movimentacao da carta
void moveCartas(pilha *origem, pilha *destino, int quantidaDeCartas); //move cartas das pilhas de jogo, desacarte e naipes 
void viraCartaBaralho(pilha *baralho, pilha *pilhaDeDescarte); //vira as cartas do baralho
void viraCartaJogo(pilha *baralho); //Fvira cartas as cartas da pilha jogo
void limpaTela(pilha pilhasDeJogo[7], pilha pilhasDeNaipes[4], pilha baralho, pilha pilhaDeDescarte);
void desenhaCarta(int coluna,int linha,char valor,char naipe, int face); // desenha a carta 
void inicializaJogo(pilha pilhasDeJogo[7], pilha pilhasDeNaipes[4], pilha *baralho, pilha *pilhaDeDescarte );
void distribuiPilhaJogo(pilha *baralho, pilha pilhasDeJogo[7]); //distribui as cartas nas pilhas 
void transferePilha(pilha *origem, pilha *destino); 
void desenhaPilhasSuperior(pilha p, int linha, int coluna); // desenha as pilhas baralho, desacarte e naipes 
void desenhaPilhasInferior(pilha *p, int linha, int coluna); // desenha as pilhas de Jogo
