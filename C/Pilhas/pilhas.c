#include<stdio.h>
#include<stdlib.h>

#define T 5

/* Pilha Vazia - OK
 * Pilha Cheia - OK
 * Inicializar Pilha - OK
 * Consultar Pilha - OK
 * Empilhar Pilha - OK
 * Desempilhar Pilha - OK
 * Listar Pilha - OK
 * Sair - Ok 
 * 
 * Melhorar as validacoes de pilha cheia e pilha vazia
 * Verificar limpa_tela em meus codigos, utilizados no linux
 */

//Funções Auxiliares
int pilha_vazia(int);
int pilha_cheia(int);
//Funções Verbos
int inicializar_pilha(int*,int);
void consultar_pilha(int*,int);
int empilhar_elemento(int*, int*, int, int);
int desempilhar_elemento(int*, int);
void listar_pilha(int*, int*, int, int);

int main(void){
  
    int topoImpar = -1, topoPar = -1,opc = -1, opcPilha = 0, elemento = -1;
    int pilhaImpar[T], pilhaPar[T];
    int *pI = pilhaImpar, *pP = pilhaPar, *pAux = NULL, *pTopo = NULL;
    
    while(opc != 0){

//         system("clear");  
        printf("==============================================================\n");
        printf("PILHAS PAR OU IMPAR\n");
        printf("==============================================================\n");
    
        printf("\nEscolha o que deseja fazer\n\n");
        printf("1) Inicializar uma pilha\n");
        printf("2) Verificar se a pilha esta vazia\n");
        printf("3) Verificar se a pilha esta cheia\n");
        printf("4) Consultar o primeiro elemento da pilha\n");
        printf("5) Empilhar novo elemento\n");
        printf("6) Desempilhar elemento\n");
        printf("7) Listar pilhas\n");
        printf("0) Sair\n");
        
        printf("\nOpcao: ");
        scanf("%d", &opc);
        printf("\n\n");
        
        opcPilha = 0;

        while(opcPilha != 1 && opcPilha != 2){
            if(opc != 5 && opc != 7 && opc != 0){
                printf("Em qual pilha deseja utilizar? [1] Impar [2] Par\n");
                printf("Pilha: ");
                scanf("%d", &opcPilha);
            }
            else
                break;
        }
        
        if(opcPilha == 1){
            pAux = pilhaImpar;
            pTopo = &topoImpar;
        }
        else{
            pAux = pilhaPar;
            pTopo = &topoPar;
        }
        
        system("clear");
        printf("**** Mostrando a pilha %s", (opcPilha == 1) ? "IMPAR****\n\n" : "PAR****\n\n");
        
        switch(opc){
            case 0: //Sair.
                printf("Encerrando ... \n");
                break;
            case 1: //Inicializar uma pilha.
                *pTopo = inicializar_pilha(pAux,*pTopo);
                printf("Pilha inicializada! Podemos comecar...\n");
                break;
            case 2: //Verificar se a pilha esta vazia.
                if(pilha_vazia(*pTopo))
                printf("A pilha esta vazia!\n");
                else
                printf("A pilha nao esta vazia!\n");
                break;
            case 3: //Verificar se a pilha esta cheia.
                if(pilha_cheia(*pTopo))
                printf("A pilha esta cheia!\n");
                else
                printf("A pilha nao esta cheia!\n");
                break;
            case 4: //Consultar o primeiro elemento da pilha.
                consultar_pilha(pAux,*pTopo);
                break;
            case 5: //Empilha novo elemento.
                printf("Digite o elemento: ");
                scanf("%d",&elemento);
                if(elemento % 2)
                    topoImpar++;
                else
                    topoPar++;
                break;
            case 6: //Desempilha elemento.
                *pTopo = desempilhar_elemento(pAux,*pTopo);
                break;
            case 7: //Listar pilha.
                listar_pilha(pI,pP,topoImpar,topoPar);
                break;
            default:
                printf("Opcao invalida! Vamos tentar de novo?\n");
                break;
            opc = 0;
        }
        
  }
    
  return 0;
}

int inicializar_pilha(int *p, int topo){
  
  int i = 0;
  
  for(i = 0; i < T; i++)
    *(p + i) = 0; 
 
  return -1;
}
int pilha_vazia(int topo){
  return(topo == -1);
}
int pilha_cheia(int topo){
  return(topo == T - 1);
}
void consultar_pilha(int *p, int topo){
  
  if(pilha_vazia(topo))
    printf("A pilha esta vazia\n");
  else
    printf("O elemento do topo da pilha e: %d\n", *(p + topo));
}
int empilhar_elemento(int *p1, int *p2, int topo1, int topo2){
    printf("Entrei na funcao empilhar_elemento!!!\n\n");
    int elemento = 0;
        
        printf("Digite o elemento: ");
        scanf("%d",&elemento);
        
        if(elemento % 2){
            if(pilha_cheia(topo1))
                printf("A pilha IMPAR esta cheia!\n");
             else
                *(p1 + (++topo1)) = elemento;
        }
        else{
            if(pilha_cheia(topo2))
                printf("A pilha PAR esta cheia!\n");
            else
                *(p2 + (++topo2)) = elemento;
        }
        
    return elemento;
}
int desempilhar_elemento(int *p, int topo){

    if(pilha_vazia(topo)){
      printf("A pilha esta vazia!\n");
      return topo;
    }
    else{
      *(p + topo) = 0;
      printf("Elemento desempilhado!\n");
      return --topo;
    }
}
void listar_pilha(int *p1, int *p2, int topo1, int topo2){
  
    int i;

    for(i = T-1; i >= 0;i--){
        
        if(topo1 == -1){
            printf("Pilha não inicalizada :(\t");
        }
        else
            printf("Pilha Impar [%d] = %d%s \t\t\t", i, *(p1 + i), (i == topo1) ? " <-- TOPO" : "");
        
        if(topo2 == -1){
            printf("Pilha não inicalizada :(\n");
        }
        else
            printf("Pilha Par [%d] = %d%s ", i, *(p2 + i), (i == topo2) ? " <-- TOPO\n" : "\n");
    }
}