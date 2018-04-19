/* Autor: Ricardo Bezerra
 * Ano: 2018
 * Descrição: Aplicar as funções implementadas de pilha em duas pilhas, par ou impar.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
#define T_MAX 20

int menu_opcoes(void);
int menu_define_pilha_uso(int, int);
int define_pilha_uso()

int main(void){
  
    int topoImpar = -1, topoPar = -1,opcMenu = -1, opcPilha = 0, elementoPilha = -1, statusInicializaImpar = 0, statusInicializaPar = 0;
    int tamanhoPilha = 1;
    int *pI, *pP, *pAux, *pTopo;
    
    printf("==============================================================\n");
    printf("PILHAS PAR OU IMPAR\n");
    printf("==============================================================\n");
    
    printf("Por gentileza, defina o tamanho da pilha, respeitando o limite de %d posições\n", T_MAX);
    printf("Tamanho: ");
    scanf("%d", &tamanhoPilha);

    pI = malloc(tamanhoPilha * sizeof(int));
    pP = malloc(tamanhoPilha * sizeof(int));
    pAux = malloc(tamanhoPilha * sizeof(int));
    pTopo = malloc(sizeof(int));
    
    while(opcMenu != 0){

        opcMenu = menu_opcoes();
        opcPilha = menu_define_pilha_uso(opcMenu,opcPilha);

        if(opcPilha == 1){
            pAux = pI;
            pTopo = &topoImpar;
        }
        else{
            pAux = pP;
            pTopo = &topoPar;
        }
        
        system("clear");
        
        switch(opcMenu){
            case 0: //Sair.
                printf("Encerrando ... \n");
                break;
            case 1: //Inicializar uma pilha.
                *pTopo = inicializar_pilha(pAux, tamanhoPilha);
                if(opcPilha == 1)
                    statusInicializaImpar = 1;
                else
                    statusInicializaPar = 1;
                printf("Pilha inicializada! Podemos comecar...\n");
                break;
            case 2: //Consultar o primeiro elemento da pilha.
                consultar_pilha(pAux,*pTopo);
                break;
            case 3: //Empilha novo elemento.
                /* Neste trecho precisamos validar se o elemento digitado (sendo par ou impar) vai
                 * ser alocado em uma pilha já inicializada.
                 */
                printf("Digite o elemento: ");
                scanf("%d%*c",&elementoPilha);
                if(elementoPilha % 2){
                    if(statusInicializaImpar > 0)
                        topoImpar = empilhar_elemento(pI,topoImpar,elementoPilha,tamanhoPilha);
                    else
                        printf("Ops! A pilha impar não foi inicializada :(\n");
                }
                else{
                    if(statusInicializaPar > 0)
                        topoPar = empilhar_elemento(pP,topoPar,elementoPilha,tamanhoPilha);
                    else
                        printf("Ops! A pilha par não foi inicializada :(\n");
                }
                break;
            case 4: //Desempilha elemento.
                *pTopo = desempilhar_elemento(pAux,*pTopo);
                break;
            case 5: //Listar pilha.
                system("clear");
                printf("****** PILHAS ******\n\n");
                if(statusInicializaImpar && statusInicializaPar)
                    listar_pilha(pI,pP,topoImpar,topoPar,tamanhoPilha);
                else
                    printf("Ops! Alguma pilha não foi inicializada...\n");
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

int menu_opcoes(void){
    
    int op;
    
        printf("\nEscolha o que deseja fazer\n\n");
        printf("1) Inicializar uma pilha\n");
        printf("2) Consultar o primeiro elemento da pilha\n");
        printf("3) Empilhar novo elemento\n");
        printf("4) Desempilhar elemento\n");
        printf("5) Listar pilhas\n");
        printf("6) Definir novo tamanho para a pilha\n");
        printf("0) Sair\n");
        
        printf("\nOpcao: ");
        scanf("%d%*c", &op);
        printf("\n\n");
        
        return op;
        
}
int menu_define_pilha_uso(int opMenu, int opPilha){
    
    opPilha = 0;
    while(opPilha != 1 && opPilha != 2){
        if(opMenu > 0 && opMenu < 5 && opMenu != 3){
            /* Algumas das opções do menu não necessitam a discriminação da pilha. 
                * Este trecho verifica se a opção solicitada se encaixa nesta condição. 
                */
            printf("Em qual pilha deseja utilizar? [1] Impar [2] Par\n");
            printf("Pilha: ");
            scanf("%d%*c", &opPilha);
        }
        else
            break;
    }
    return opPilha;
}