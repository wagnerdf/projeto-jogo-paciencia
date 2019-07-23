//Aluno: Wagner A. Andrade
           
/*
Projeto de EDA
Objetivo.
Aplicar os conhecimentos adquiridos na disciplina de EDA na construção do jogo 
de cartas Paciência.

1. Requisitos.

1.1. O projeto deverá ser implementado na linguagem C.
1.2. Poderá ser desenvolvido em duplas.

2. Regras:
           
2.1. Definições
2.1.1. 1 O tabuleiro é composto de 13 pilhas sendo:
2.1.2. R1 a R4 – Pilhas de armazenamento. O Jogo acaba quando todas as cartas 
       estiverem armazenadas nestas pilhas. Cada pilha deverá receber cartas
       do mesmo naipe e na ordem crescente, de A a K.
2.1.3. D1 e D2. São as pilhas de distribuição de cartas. D1 contem as carta que
        serão jogadas. Todas estarão viradas de verso. D2 contem as cartas que 
        foram movidas de D1 para serem jogadas.
2.1.4. J1 a J7. Pilhas para jogo. Quando iniciado o jogo, cada uma receberá uma 
       carta conforme o seu número. Se a primeira, uma carta, se a segunda duas 
       cartas, e assim em diante.
2.2. Jogadas.
2.2.1. O jogo inicia com o embaralhamento das cartas e a distribuição nas 
       pilhas de jogo (J1 a J7).
2.2.2. O jogador deverá solicitar uma carta na pilha de distribuição D1 e o 
       programa deverá disponibilizar a carta na pilha D2.
2.2.3. As cartas para serem movimentadas deverão seguir as seguintes condições.
2.2.3.1. Entre a pilha D2 e as de jogo (J1 a J7). Deverá ser movimentada uma
        única carta de cada vez, alternando a cor das cartas e na ordem decrescente.
2.2.3.2. Entre as pilhas de jogo (J1 a J7). Pode ser movimentada a quantidade 
         que quiser desde que respeitada à condição das cores alternadas e 
         contagem decrescente.
2.2.3.3. Para as pilhas R1 a R4, as cartas deverão ser movimentadas na ordem
          crescente e empilhadas no seu naipe correspondente.
          
3. Etapas para o desenvolvimento:

3.1. Elaborar uma rotina para desenhar a carta do baralho na tela com a face 
     para frente e de verso.
3.2. Elaborar uma rotina para embaralhar as cartas e armazená-las na pilha D1.
3.3. Elaborar uma rotina para movimentar as cartas de uma pilha para outra.
3.3.1. Antes de movimentar a carta deverá, a rotina deverá validar o movimento.
3.3.2. Caso não seja possível a movimentação o programa deverá informar o 
       usuário da impossibilidade da ação pretendida.
3.3.3. Para movimentar mais de uma carta, utilize a pilha auxiliar.

4. Da entrega do Trabalho.

4.1. O trabalho deverá ser transferido para o ambiente virtual até a data limite.
4.2. O arquivo deverá ser em código fonte.

5. Requisitos do programa:

5.1. Todas as instruções do jogo deverão estar no código.
5.2. O código deverá ser todo documentado.
5.3. Durante a execução, deverá ser mostrado na tela inicial o nome dos 
     participantes e a disciplina.
           
 */


#include <stdio.h>
#include <time.h>
#include <conio.c>
#include "EstruturaCarta.c"
#include "bibliotecaPrototipos.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Inicio>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main(void){    
  pilha baralho=NULL,pilhasDeNaipes[4],pilhaDeDescarte=NULL;
  pilha pilhasDeJogo[7];
  int quantidaDeCartas=0, origem, destino;
  char opcao,subopcao;
  carta ctr;
  int validaCartas=0; 
  char tipo;
 
  

  
   desenhaMoldura(5,5,22,73,VERMELHO,AMARELO);        

  do{    
           inicializaJogo(pilhasDeJogo,pilhasDeNaipes, &baralho, &pilhaDeDescarte);    
           embaralha(&baralho);       
           distribuiPilhaJogo(&baralho,pilhasDeJogo);    
           desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
       
    do{
      
      textbackground(9);
      textcolor(0); 
      gotoxy(1,1); 
      printf("<<< JOGO PACIENCIA>>>     \n");
      printf("  ESCOLHA UMA OPCAO        \n");
      printf("                           \n");
      printf("                           \n");
      printf("     1 - Virar Carta      \n");
      printf("     2 - Mover Carta      \n");
      printf("     3 - Sair             \n");
      printf(" \n");
      printf("     Opcao: ");
      fflush(stdin);
      opcao=toupper(getch());
      limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
      switch(opcao){
            case '1':
             do{
              gotoxy(1,1);
              textbackground(9);   
              textcolor(0); 
              printf("<<< JOGO PACIENCIA>>>     \n");
              printf("  ESCOLHA UMA OPCAO        \n");
              printf("                           \n");                 
              printf("  1 - Vira Carta Baralho   \n");  
              printf("  2 - Voltar Baralho       \n"); 
              printf("  3 - Vira Carta do Jogo   \n"); 
              printf("  V - Voltar               \n"); 
              printf("                           \n");
              printf("     Opcao: ");
              fflush(stdin);

              subopcao=toupper(getch());
              switch(subopcao){
              case '1':  // vira a carta da Pilha Baralho               
                       if(baralho!=NULL){ 
                           viraCartaBaralho(&baralho,&pilhaDeDescarte);   
                           desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                        }
                        limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);    
                                        
                  break;
                  case '2': 
                        if(baralho==NULL){ 
                            while(pilhaDeDescarte!=NULL){  
                                                                     
                               viraCartaBaralho(&pilhaDeDescarte,&baralho);
                               desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
                            }
                         }
                         limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);                                   
                  break;                    
                  case '3': 
                         printf("Da pilha J: "); 
                         scanf("%d",&origem);
                         origem--; // decrementa o origem, para armazenar no vetor que inicia do zero
                         
                         viraCartaJogo(&pilhasDeJogo[origem]); 
                         desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                         limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);                                     
                  break; 
                  case 'V':               
                  break;
                  default:    printf("Opcao incorreta!\n");
                              getch();
                              limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);

              } 
             }while(subopcao!='V');
      break;              
      case '2':
           do{ 
              gotoxy(1,1); 
              textbackground(9);
              textcolor(0); 
              printf("<<< JOGO PACIENCIA>>>     \n");
              printf("  ESCOLHA UMA OPCAO        \n");
              printf("                           \n"); 
              printf("Mover:                        \n"); 
              printf("  1 - D para J              \n"); 
              printf("  2 - D para R              \n"); 
              printf("  3 - J para J              \n"); 
              printf("  4 - J para R              \n"); 
              printf("  5 - R para J              \n"); 
              printf("  V - Voltar                  \n"); 
              printf("  Opcao:                     \n"); 
              fflush(stdin);
              subopcao=toupper(getch()); 
                     
              switch(subopcao){
              case '1': 
                       printf("Pilha destino J: "); 
                       scanf("%d",&destino);
                       while(destino<1 || destino>7){ 
                           printf("Pilha invalida!\n");                
                           printf("Pilha destino J: ");
                           scanf("%d",&destino);
                       }
                       destino--; 
                       validaCartas=validaRegras(&pilhaDeDescarte,&pilhasDeJogo[destino],'A');          
                      
                       if(validaCartas==1){   
                         moveCartas(&pilhaDeDescarte,&pilhasDeJogo[destino],1);     
                         desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
                       }
                       limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                       
   
                  break;
                  
                  case '2': 
                       printf("Pilha destino PN: "); 
                       scanf("%d",&destino);
                       while(destino<1 || destino>4){ 
                           printf("Pilha invalida!\n");                
                           printf("Pilha destino R \n");
                           scanf("%d",&destino);
                       }
                       destino--; 
                       validaCartas=validaRegras(&pilhaDeDescarte,&pilhasDeNaipes[destino],'B');
                      
                       if(validaCartas==1){
                           moveCartas(&pilhaDeDescarte,&pilhasDeNaipes[destino],1);     
                           desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
                       }
                       limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                  break;
                  case '3': 
                
                       printf("Pilha origem J: "); 
                       scanf("%d",&origem);
                       
                       while(origem<1 || origem>7){ // valida o valor digitado
                           printf("Pilha invalida!\n");                
                           printf("Pilha origem J: ");
                           scanf("%d",&origem);                                 
                       }
                       origem--;  // decrementa a origem, para armazenar no vetor que inicia do zero                      
                       printf("Pilha destino PJ: ");
                       scanf("%d",&destino);
                       while(destino<1 || destino>7){ 
                           printf("Pilha invalida \n");                
                           printf("Pilha destino J: \n");
                           scanf("%d",&destino);
                       }
                       destino--;           
                       
                       printf("Qtd de cartas: "); // quantidade de cartas a serem movidas para a pilha de destino
                       scanf("%d",&quantidaDeCartas);
                      
                       validaCartas=validaRegras(&pilhasDeJogo[origem],&pilhasDeJogo[destino],'C');
                      
                       if( validaCartas==1){
                         moveCartas(&pilhasDeJogo[origem],&pilhasDeJogo[destino],quantidaDeCartas);
                         desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);                          
                       }
                       limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                       
                                     
                  break;
                  case '4': 
                        printf("Pilha origem J: ");
                        scanf("%d",&origem);
                        while(origem<1 || origem>7){ // valida o valor digitado
                           printf("Pilha invalida!\n");                
                           printf("Pilha origem J: ");
                           scanf("%d",&origem);
                        }
                        origem--;  
                        printf("Pilha destino R: "); 
                        scanf("%d",&destino);
                        while(destino<1 || destino>4){ 
                           printf("Pilha invalida!\n");                
                           printf("Pilha destino R: ");
                           scanf("%d",&destino);
                        }
                        destino--; // 
                        validaCartas=validaRegras(&pilhasDeJogo[origem],&pilhasDeNaipes[destino],'B');
                        
                        if( validaCartas==1){        
                          moveCartas(&pilhasDeJogo[origem],&pilhasDeNaipes[destino],1);     
                          desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
                        }
                        limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                  break;  
                  case '5': 
                       printf("Pilha origem R: "); 
                       scanf("%d",&origem);
                       while(origem<1 || origem>4){ // valida o valor digitado
                           printf("Pilha invalida!\n");                
                           printf("Pilha origem R: ");
                           scanf("%d",&origem);
                       }
                       origem--; 
                       printf("Pilha destino J: "); // escolha da pilha de jogo, valores de 1 a 7
                       scanf("%d",&destino);
                       while(destino<1 || destino>7){ // valida o valor digitado, caso usario digite um valor invalido, o mesmo é informado
                           printf("Pilha invalida!\n");                
                           printf("Pilha destino J: ");
                           scanf("%d",&destino);
                       }
                       destino--; 
                       validaCartas=validaRegras(&pilhasDeNaipes[origem],&pilhasDeJogo[destino],'A');
   
                       if(validaCartas==1){           
                         moveCartas(&pilhasDeNaipes[origem],&pilhasDeJogo[destino],1);
                         desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
                       }
                       limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);      
                  break;  
                  case 'V':              
                  break;
                  default:
                       printf("Opcao incorreta! \n");
                       getch();
                       limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
               }
                
             }while(subopcao!='V');
             limpaTela(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
                                                                                                                          
      break; 
                           

      case '3': //abandona o programa
             system("cls"); 
             gotoxy(25,10);
             textbackground(9);
             textcolor(0); 
             printf("FIM DE JOGO - VOLTE SEMPRE...");
             gotoxy(18,12);
             system("pause");
           exit(0);
      break;
      default:
                  gotoxy(1,1); 
                  textbackground(9); 
                  textcolor(0);   
                  printf("Opcao incorreta!\n");
                  getch();
      }       
                           
     }while(opcao!='3');
     while(pilhaDeDescarte!=NULL){  
        viraCartaBaralho(&pilhaDeDescarte,&baralho);
        desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte); 
     }     
     
     menuInicio();
     
 }while(menuInicio()!='1');      
}



