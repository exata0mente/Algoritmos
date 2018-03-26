#include<stdio.h>
#include<stdlib.h>
#include "pilhas.h"
#define T 5

int main(void){
  
    int topoImpar = -1, topoPar = -1,opcMenu = -1, opcPilha = 0, elementoPilha = -1, statusInicializaImpar = 0, statusInicializaPar = 0;
    int pilhaImpar[T], pilhaPar[T];
    int *pI = pilhaImpar, *pP = pilhaPar, *pAux = NULL, *pTopo = NULL;
    
    printf("==============================================================\n");
    printf("PILHAS PAR OU IMPAR\n");
    printf("==============================================================\n");

    
    while(opcMenu != 0){

//         system("clear");  
        
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
        scanf("%d%*c", &opcMenu);
        printf("\n\n");
        
        opcPilha = 0;

        while(opcPilha != 1 && opcPilha != 2){
            if(opcMenu != 5 && opcMenu != 7 && opcMenu != 0){
                printf("Em qual pilha deseja utilizar? [1] Impar [2] Par\n");
                printf("Pilha: ");
                scanf("%d%*c", &opcPilha);
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
        
        switch(opcMenu){
            case 0: //Sair.
                printf("Encerrando ... \n");
                break;
            case 1: //Inicializar uma pilha.
                *pTopo = inicializar_pilha(pAux,*pTopo,T);
                if(opcPilha == 1)
                    statusInicializaImpar = 1;
                else
                    statusInicializaPar = 1;
                printf("Pilha inicializada! Podemos comecar...\n");
                break;
            case 2: //Verificar se a pilha esta vazia.
                if(pilha_vazia(*pTopo))
                printf("A pilha esta vazia!\n");
                else
                printf("A pilha nao esta vazia!\n");
                break;
            case 3: //Verificar se a pilha esta cheia.
                if(pilha_cheia(*pTopo,T))
                printf("A pilha esta cheia!\n");
                else
                printf("A pilha nao esta cheia!\n");
                break;
            case 4: //Consultar o primeiro elemento da pilha.
                consultar_pilha(pAux,*pTopo);
                break;
            case 5: //Empilha novo elemento.
                printf("Digite o elemento: ");
                scanf("%d%*c",&elementoPilha);
                if(elementoPilha % 2){
                    if(statusInicializaImpar > 0)
                        topoImpar = empilhar_elemento(pilhaImpar,topoImpar,elementoPilha,T);
                    else
                        printf("Ops! A pilha impar não foi inicializada :(\n");
                }
                else{
                    if(statusInicializaPar > 0)
                        topoPar = empilhar_elemento(pilhaPar,topoPar,elementoPilha,T);
                    else
                        printf("Ops! A pilha par não foi inicializada :(\n");
                }
                break;
            case 6: //Desempilha elemento.
                *pTopo = desempilhar_elemento(pAux,*pTopo);
                break;
            case 7: //Listar pilha.
                system("clear");
                printf("****** PILHAS ******\n\n");
                if(statusInicializaImpar && statusInicializaPar)
                    listar_pilha(pI,pP,topoImpar,topoPar,T);
                else{
                    printf("Ops! Alguma pilha não foi inicializada...\n");
//                     printf("Pilha Impar = %d\tPilha Par = %d\n", statusInicializaImpar,statusInicializaPar);
                }
                printf("Aperte para continuar ");getchar();
                break;
            default:
                printf("Opcao invalida! Vamos tentar de novo?\n");
                break;
            opcMenu = 0;
        }
        
  }
    
  return 0;
}
