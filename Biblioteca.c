#include <stdio.h>
#include <ctype.h>
#include <time.h>

#include "EstruturaCarta.c"
#include "bibliotecaPrototipos.h"  


//****************************************************************************//
//Objetivo  :Selecionar uma opção na tela inicial                             //
//****************************************************************************//
char menuInicio(void){
int Opcao=1;
char T1;

     textbackground(9); 
     textcolor(0);
     gotoxy(31,10);       
     printf("JOGO PACIENCIA Ver. 1.3");
     gotoxy(29,13);       
     printf("[ENTER] - JOGAR PACIENCIA ");
     gotoxy(30,15);        
     printf(" [ESC]   - SAIR DO JOGO \n\n\n");
    gotoxy(38,21);      
    textbackground(7); 
     textcolor(0);  
     printf("Desenvolvido por Wagner A. Andrade\n\n");
     T1 = getch();
 for(;;){
      fflush(stdin); 
     if(T1==27){
           system("cls"); 
           gotoxy(25,10);
           textbackground(9);
           textcolor(0); 
           printf("FIM DE JOGO - VOLTE SEMPRE...");
           gotoxy(18,12);
           system("pause");
           exit(0);
           }
     if(T1==13)
          break;    
     T1 = getch();      
  }

}


//****************************************************************************//
// Objetivo: desenhaMoldura                                                   //
//****************************************************************************//

void desenhaMoldura(int linhaInicial, int colunaInicial, int linhaFinal, int colunaFinal,
          int corFundoAtual, int corLetraAtual)
{
    int i=0,qtdeLinhas,qtdeColunas;
    
    qtdeLinhas  = linhaFinal - linhaInicial ;
    qtdeColunas = colunaFinal - colunaInicial ;
    textbackground(1);
    textcolor(11);
    // faz a borda superior
    gotoxy(colunaInicial,linhaInicial);
    for(i=0;i<=qtdeColunas;i++)
    {
        printf("\xCD");
    }

    // faz a borda inferior
    gotoxy(colunaInicial,linhaInicial+qtdeLinhas);
    for(i=0;i<=qtdeColunas;i++)
    {
        printf("\xCD");
    }

    // faz a lateral esquerda    
    for(i=0;i<=qtdeLinhas;i++)
    {
        gotoxy(colunaInicial,linhaInicial+i);
        printf("\xBA");
    }
    // faz a lateral direita
    for(i=0;i<=qtdeLinhas;i++)
    {
        gotoxy(colunaInicial+qtdeColunas,linhaInicial+i);
        printf("\xBA");
    }
     
    // fecha os cantos da moldura
    gotoxy(colunaInicial,linhaInicial);
    printf("\xC9");
    gotoxy(colunaInicial+qtdeColunas,linhaInicial);
    printf("\xBB");
    gotoxy(colunaInicial,linhaInicial+qtdeLinhas);
    printf("\xC8");
    gotoxy(colunaInicial+qtdeColunas,linhaInicial+qtdeLinhas);
    printf("\xBC");
    retornaCor(corFundoAtual, corLetraAtual);
    menuInicio();
}

//****************************************************************************//
//objetivo  : retornaCor                                                      // 
//****************************************************************************//
void retornaCor(int corFundo,int corTexto)
{
    textbackground(corFundo);
    textcolor(corTexto);
}    

//****************************************************************************//
//Objetivo  : Embaralha o baralho                                             //
//****************************************************************************//
void embaralha(pilha *baralho)
{
   //Estrutura Numeros
   struct numeros
   {
      char carta;
      int indice;
   };                    
  //Declarações     
   int i, j, of, stime, continua, naipe, cont = 1, coluna = 1, linha = 1;
   long ltime;
   carta crt; 
   struct numeros cartas[52]=
   {{'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'X',10},{'J',11},{'Q',12},{'K',13},
   {'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'X',10},{'J',11},{'Q',12},{'K',13},
   {'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'X',10},{'J',11},{'Q',12},{'K',13},
   {'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'X',10},{'J',11},{'Q',12},{'K',13}};

   ltime = time(NULL);
   stime = (unsigned) ltime/2;
   srand(stime);
   of = (rand() % 52);  // Gera um valor aleatório entre 0 e 51;   
   do{  
      //Naipe recebe um valor;
      naipe = f_naipe(of);
      // Insere uma carta sorteada na pilha baralho
      if (cartas[of].carta != (char) NULL)
      { 
         crt.naipe=naipe;
         crt.valor=cartas[of].carta;
         crt.face=Verso; // ja atribui a face verso nas cartas a serem empilahadas na pilha baralho
         crt.indice=cartas[of].indice;   
         push(baralho, crt);    // insere a carta na pilha baralho
      }
      cartas[of].carta =(char) NULL;
      cont++;  
      of = (rand() % 52);
      continua = 0;
      for (j=0;j<52;j++)
      {    
         if (cartas[j].carta != (char) NULL)
         {
            continua = 1;
            break;
         }
      }
   }while(continua);
}

//****************************************************************************//
//Objetivo  : Determinar o naipe das cartas do jogo                           //
//****************************************************************************//
int f_naipe(int of)
{    
  if(of < 13)
      return(C);
  else if(of > 12 && of < 26)
     return(O);  
  else if(of > 25 && of < 38)
     return(P);    
  else if(of > 37 && of < 52)
     return(E);
}
//****************************************************************************//
//Objetivo  : Inserir as cartas nas pilhas                                    //
//****************************************************************************//
void push(pilha *baralho, carta crt)
{
   pilha temp;
   //Aloca um espaço na memôria para a variável temp
   temp = (pilha)malloc(sizeof(carta)); 
   temp->valor = crt.valor;      
   temp->indice = crt.indice;    
   temp->naipe = crt.naipe;      
   temp->face = crt.face;
   // O novo elemento aponta para a o valor incial da lista        
   temp->prox = (*baralho); 
   //O começo da lista passa a ser o novo elemento     
   (*baralho) = temp;	         
}
//****************************************************************************//
//Objetivo  : Retirar as cartas das pilhas                                    //
//****************************************************************************//
carta pop(pilha *baralho)
{
   pilha temp;
   carta crt;
   temp=(*baralho);
   //aponta para o proximo elemento da lista
   (*baralho) = (*baralho)->prox;
   crt.naipe = temp->naipe;
   crt.valor=temp->valor;
   crt.indice=temp->indice;
   crt.face=temp->face;
   free(temp);
   return crt;
}   

//****************************************************************************//
//Objetivo  : Desenhar a carta                                                //
//****************************************************************************//
void desenhaCarta(int coluna,int linha,char valor,char naipe, int face)
{
   int i,cont = 0,cartaNaipe;    
   textbackground(2); textcolor(0);gotoxy(coluna,linha);printf("%c%c%c%c%c%c",218,196,196,196,196,191);//superior
   for(i=1;i<6;i++)
   {
      textbackground(2);gotoxy(coluna,linha+i);printf("%c    %c",179,179);
      cont=linha+i;      
   }
   textcolor(0);gotoxy(coluna,cont);printf("%c%c%c%c%c%c",192,196,196,196,196,217);
   if(face==Frente)
   {
      if((naipe==O)||(naipe==C))
      {                         
         textcolor(12);
         gotoxy(coluna+=1,linha+=1);
         printf("%c%c",valor,naipe);
         gotoxy(coluna+=2,cont-=1);
         printf("%c%c",valor,naipe);
      }
      else if((naipe==E)||(naipe==P))
      {
         textcolor(0);
         gotoxy(coluna+=1,linha+=1);
         printf("%c%c",valor,naipe);
         gotoxy(coluna+=2,cont-=1);
         printf("%c%c",valor,naipe);
      }
   }
   else
   {
      for(i=1;i<5;i++)
      {
         textbackground(9);gotoxy(coluna+1,linha+i);printf("%c%c%c%c",178,178,178,178);
         cont=linha+i;      
      }
   }  
}

//****************************************************************************//
//Objetivo  : Inicializar as pilhas do jogo                                   //
//****************************************************************************//
void inicializaJogo(pilha pilhasDeJogo[7], pilha pilhasDeNaipes[4], pilha *baralho, pilha *pilhaDeDescarte){

     pilhasDeNaipes[0]=NULL,pilhasDeNaipes[1]=NULL,pilhasDeNaipes[2]=NULL,pilhasDeNaipes[3]=NULL;

     pilhasDeJogo[0]=NULL,pilhasDeJogo[1]=NULL,pilhasDeJogo[2]=NULL,pilhasDeJogo[3]=NULL,pilhasDeJogo[4]=NULL,pilhasDeJogo[5]=NULL,pilhasDeJogo[6]=NULL;
        
}

//****************************************************************************//
//Objetivo  : Distribui as cartas da pilha baralho para as 7 pilhas de jogo   //
//****************************************************************************//
void distribuiPilhaJogo(pilha *baralho, pilha pilhasDeJogo[7])
{
   int I, J;
   carta aux;
   
   for(I=0; I<7; I++){  
     for(J=I; J<7; J++)
     {
        aux=pop(baralho); // retira a carta da pilha baralho e armazena na carta aux
        if(J==I)
        {
           aux.face=Frente; // vira a primeira carta (carta do topo)
        }
        else
        {
           aux.face=Verso;           
        }          
        push(&pilhasDeJogo[J],aux); // pega a carta aux e insere na pilha jogo     
     }         
   }    
}

//****************************************************************************//
//Objetivo  : Transfere cartas de uma pilha para outra                        //
//****************************************************************************//
void transferePilha(pilha *origem, pilha *destino)
{
   carta aux;
   while(*origem!=NULL)
   {
     //Retira da origem;                  
     aux=pop(origem); 
    //insere no destino;
     push(destino, aux);
   }
}
  
//****************************************************************************//
//Objetivo  : Desenha as cartas das Pilhas de baralho, desacarte e naipes     //
//****************************************************************************//
void desenhaPilhasSuperior(pilha p, int linha, int coluna)
{
   if(p==NULL)
      desenhaCartaVazia( coluna,linha);
   else
      desenhaCarta(coluna, linha,p->valor,p->naipe,p->face);   
}

//****************************************************************************//
//Objetivo  : Desenha as cartas das Pilhas Jogo                               //
//****************************************************************************//
void desenhaPilhasInferior(pilha *p, int linha, int coluna)
{
   pilha aux=NULL, tmp;   

   transferePilha(p,&aux);    
   tmp=aux;
   while(tmp!=NULL)
   {
      desenhaCarta(coluna, linha,tmp->valor,tmp->naipe,tmp->face);
      linha=linha+2;
      tmp=tmp->prox;
   }
   transferePilha(&aux,p);
}

//****************************************************************************//
//Objetivo  : Desenha carta vazia                                             //
//****************************************************************************//
void desenhaCartaVazia(int coluna,int linha)
{    
   int i,cont = 0;    
   textbackground(15); textcolor(0);gotoxy(coluna,linha);printf("%c%c%c%c%c%c",218,196,196,196,196,191);//superior
   for(i=1;i<6;i++)
   {
      textbackground(15);gotoxy(coluna,linha+i);printf("%c    %c",179,179);// parte branca meio
      cont=linha+i;      
   }
   textcolor(0);gotoxy(coluna,cont);printf("%c%c%c%c%c%c",192,196,196,196,196,217);//Inferior                  
   textcolor(3);
   gotoxy(coluna+=1,linha+=1);
}

//****************************************************************************//
//Objetivo  : Desenha o tabuleiro do jogo                                     //
//****************************************************************************//
void desenhaTabuleiro(pilha pilhasDeJogo[7], pilha pilhasDeNaipes[4], pilha baralho, pilha pilhaDeDescarte)
{
   textbackground(9);
   textcolor(0);         
   clrscr();
   gotoxy(34,1);

   printf("D1     D2           R1      R2     R3     R4");      
   // desenha a pilha passando o endereço da pilha a linha e coluna onde será impresso
   desenhaPilhasSuperior(baralho,2 ,32);
   desenhaPilhasSuperior(pilhaDeDescarte,2,39);
   desenhaPilhasSuperior(pilhasDeNaipes[0],2,53);
   desenhaPilhasSuperior(pilhasDeNaipes[1],2,60);
   desenhaPilhasSuperior(pilhasDeNaipes[2],2,67);
   desenhaPilhasSuperior(pilhasDeNaipes[3],2,74);
   textbackground(9);
   textcolor(0);

   gotoxy(33,9); 
   printf("J1      J2     J3     J4     J5     J6     J7");
   // desenha pilha de jogo passando o endereço da pilha a linha e coluna onde será impresso
   desenhaPilhasInferior(&pilhasDeJogo[0],10,32);
   desenhaPilhasInferior(&pilhasDeJogo[1],10,39);
   desenhaPilhasInferior(&pilhasDeJogo[2],10,46);
   desenhaPilhasInferior(&pilhasDeJogo[3],10,53);
   desenhaPilhasInferior(&pilhasDeJogo[4],10,60);
   desenhaPilhasInferior(&pilhasDeJogo[5],10,67) ;
   desenhaPilhasInferior(&pilhasDeJogo[6],10,74);    
}

//****************************************************************************//
//Objetivo  : Valida as regras de movimentacao das cartas                     //
//****************************************************************************//
int validaRegras(pilha *origem, pilha *destino, char tipo)
{      
  carta aux;
  pilha temp = NULL;
  int naipeOrigem = 0, naipeDestino = 0;
  int indiceOrigem = 0, indiceDestino = 0;
    
    // valida regra da Pilha de Descarte, ou da pilha de Naipe para a Pilha de Jogo
    if (tipo=='A'){                   
           
       if(*destino!=NULL){ 
          aux=pop(destino);
          push(destino, aux); 
          naipeDestino = aux.naipe;
          indiceDestino = aux.indice;
       }
      
       if(*origem!=NULL){ 
          aux=pop(origem);   
          naipeOrigem = aux.naipe;
          indiceOrigem = aux.indice;
          push(&temp, aux);    
       }
       //devolve para a pilha de origem 
       while(temp!=NULL){          
         aux=pop(&temp); 
         push(origem, aux); 
       }
       //verifica se a pilha de origem está vazia        
       if(*origem==NULL){  
         printf("Pilha vazia!");
         getch();                       
       }
       // Quando uma pilha de jogo ficar vazia, ela só poderá receber um Rei
      else if (indiceOrigem==R && (*destino)==NULL)
        return 1;  
        
      else if (((naipeOrigem==P) || (naipeOrigem==E))&& ((naipeDestino==C) || (naipeDestino==O)) && (indiceOrigem+1==indiceDestino)) 
          return 1;              
      else if (((naipeOrigem==C) || (naipeOrigem==O))&& ((naipeDestino==P) || (naipeDestino=E)) && (indiceOrigem+1==indiceDestino))
         return 1;
      else{
           printf("Movimento invalido!\n");
           getch(); 
      } 
    }   
     

    if (tipo=='B'){ 
     
     if(*destino!=NULL){
       aux =pop(destino);
       push(destino, aux); 
       naipeDestino = aux.naipe;
       indiceDestino = aux.indice;
      }
     // retira  carta da pilha origem e guarda o naipe e o numero (indice) da carta, 
     //e depois devolve para a pilha de origem  
    if(*origem!=NULL){
       aux=pop(origem);   
       naipeOrigem = aux.naipe;
       indiceOrigem = aux.indice;    
       push(&temp, aux);
    } 
    //devolve para a pilha de origem   
    while(temp!=NULL){          
       aux=pop(&temp); 
       push(origem, aux); 
    }
    if(*origem==NULL){ //verifica se a pilha de origem está vazia
       printf("Pilha vazia!");
       getch();                       
    } 
    // Quando uma pilha de naipe esitiver vazia, ela só poderá receber um As
    else if ((indiceOrigem==A)&& (*destino)==NULL)
       return 1; 
       
  
    else if ((naipeOrigem==naipeDestino) && (indiceOrigem==indiceDestino+1))
       return 1; 
       
      else{
        printf("Movimento invalido!");
        getch();
      }
    }
    
   // valida regra da Pilha de Jogo para a Pilha de Jogo 
    if (tipo=='C'){ 
    
       if(*destino!=NULL){               
         aux =pop(destino);
         push(destino, aux); 
         naipeDestino = aux.naipe;
         indiceDestino = aux.indice;
       } 
       
     
       while(*origem!=NULL ){     
       //Retira da origem; 
        aux=pop(origem); 
        if(aux.face==Frente){                
          naipeOrigem = aux.naipe;
          indiceOrigem = aux.indice; 
          push(&temp, aux);
      
         }
         else{
           push(&temp, aux); //devolve para a pilha de temp
           break;
         }                    
       }   
    //devolve para a pilha de origem    
     while(temp!=NULL){          
       aux=pop(&temp); 
       push(origem, aux); 
     }
    
     if(*origem==NULL){ //verifica se a pilha de origem está vazia
       printf("Pilha vazia!");
       getch();                       
     } 
     // Quando uma pilha de jogo ficar vazia, ela só poderá receber um Rei que esteja aberto.  
     else if (indiceOrigem==R && (*destino)==NULL)
       return 1;
   
     else if (((naipeOrigem==P) || (naipeOrigem==E))&& ((naipeDestino==C) || (naipeDestino==O)) && (indiceOrigem+1==indiceDestino)) 
       return 1;
         
     else if (((naipeOrigem==C) || (naipeOrigem==O))&& ((naipeDestino==P) || (naipeDestino==E)) && (indiceOrigem+1==indiceDestino)) 
       return 1; 
       else{
          printf("Movimento invalido!         ");
         getch(); 
        }               
    }        
    return 0;  
}

//****************************************************************************//
//Objetivo  : Mover a carta da pilha origem para a pilha destino              //
//****************************************************************************//
void moveCartas(pilha *origem, pilha *destino, int quantidaDeCartas)
{
   carta aux;
   pilha temp = NULL;
   int cartasMovidasOrigem =0; 
   int Face=0;         
   while(*origem!=NULL)
   {
      //Retira da origem;                    
      aux=pop(origem);   
      if (aux.face==Frente) 
      {
         push(&temp, aux);
         cartasMovidasOrigem++; // incrementa contador sempre que a face carta estiver virada 
      } 
      else // entra aqui quando o usuario tenta mover cartas com face verso
      {
         push(origem, aux);
         printf("Movimento Invalido!\n");
         printf("Mova apenas cartas viradas.\n");
         getch();
         Face=1;
         break;
      }
      if( cartasMovidasOrigem >= quantidaDeCartas) 
      {        
         break;
      }         
   } 
   
   if(Face==1) // se existir carta com face verso, devolve as cartas para a pilha origem
   {
      while(temp!=NULL)
      {          
         aux=pop(&temp); 
         push(origem, aux); 
      } 
   }
   else  // se todas as cartas da pilha estiverem com face virada, move para a pilha de destino
   {
     while(temp!=NULL){          
          aux=pop(&temp); 
          push(destino, aux); 
    }  
   }           
}


//****************************************************************************//
//Objetivo  : Vira carta baralho uma carta do baralho para a da pilha descarte//
//****************************************************************************//
void viraCartaBaralho(pilha *baralho, pilha *pilhaDeDescarte)
{
   carta aux;
     if(*baralho!=NULL){
        aux=pop(baralho);
          
        if (aux.face==Verso) 
          aux.face=Frente; 
        else     // viram as cartas que estao na pilha descarte e voltam para a pilha do baralho
          aux.face=Verso; 
          
        push(pilhaDeDescarte,aux);  
      }
                  
}          

//****************************************************************************//
//Objetivo  : Virar a carta do Jogo principal                                 //
//****************************************************************************//
void viraCartaJogo(pilha *baralho) 
{
   pilha temp;
   temp=(*baralho);
   if (temp->face==Verso) 
      temp->face=Frente; 
   else {
      temp->face=Frente;
      printf("Carta ja virada!\n");
      getch();
   }        
}


//****************************************************************************//
//Objetivo  : Limpar a tela do jogo                                           //
//****************************************************************************//
void limpaTela(pilha pilhasDeJogo[7], pilha pilhasDeNaipes[4], pilha baralho, pilha pilhaDeDescarte)
{
   clrscr();
   desenhaTabuleiro(pilhasDeJogo,pilhasDeNaipes,baralho,pilhaDeDescarte);
     
}


