    /* Autor: Ricardo Bezerra
 * Ano: 2018
 * Descrição: Aplicar as funções implementadas de pilha em duas pilhas, par ou impar.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
#define T_MAX 20

struct pilha{
    int *ponteiro;
    int topo;
    int inicializada;
};

typedef struct pilha Pilha;

int menu_opcoes(void);
int obter_tamanho_pilha(void);
int menu_define_pilha_uso(int, int);

int main(void){
  
    //Definição de variáveis de controle.
    int opcMenu = -1,
        elementoPilha = 0,
        opcPilha = 0,
        tamanhoPilha = 0;
    
    //Definição das estruturas de pilhas.
    Pilha pilhaImpar;
    Pilha pilhaPar;
    Pilha *pAux;
    
    system("clear");
    
    printf("==============================================================\n");
    printf("PILHAS PAR OU IMPAR\n");
    printf("==============================================================\n");
    
    tamanhoPilha = obter_tamanho_pilha();

    pilhaImpar.ponteiro = malloc(tamanhoPilha * sizeof(int));
    pilhaPar.ponteiro = malloc(tamanhoPilha * sizeof(int));
    
    while(opcMenu != 0){

        opcMenu = menu_opcoes();
        opcPilha = menu_define_pilha_uso(opcMenu,opcPilha);
        //retorna 1 [pilha impar] ou 2 [pilha par]

        if(opcPilha == 1)
            pAux = &pilhaImpar;
        else
            pAux = &pilhaPar;
            
        
//         system("clear");
        
        switch(opcMenu){
            case 0: //Sair.
                break;
            case 1: //Inicializar uma pilha.
                pAux->topo = inicializar_pilha(pAux->ponteiro, tamanhoPilha);
                if(opcPilha == 1){
                    pilhaImpar.inicializada = 1;
                }
                else
                    pilhaPar.inicializada = 1;
                printf("\nPilha inicializada! Aperte para continuar...");getchar();
                break;
            case 2: //Consultar o primeiro elemento da pilha.
                consultar_pilha(pAux->ponteiro,pAux->topo);
                printf("Aperte para continuar ");getchar();
                break;
            case 3: //Empilha novo elemento.
                /* Neste trecho precisamos validar se o elemento digitado (sendo par ou impar) vai
                 * ser alocado em uma pilha já inicializada.
                 */
                printf("Digite o elemento: ");
                scanf("%d%*c",&elementoPilha);
                if(elementoPilha % 2){
                    if(pilhaImpar.inicializada > 0)
                        pilhaImpar.topo = empilhar_elemento(pilhaImpar.ponteiro,pilhaImpar.topo,elementoPilha,tamanhoPilha);
                    else
                        printf("Ops! A pilha impar não foi inicializada :(\n");
                }
                else{
                    if(pilhaPar.inicializada > 0)
                        pilhaPar.topo = empilhar_elemento(pilhaPar.ponteiro,pilhaPar.topo,elementoPilha,tamanhoPilha);
                    else
                        printf("Ops! A pilha par não foi inicializada :(\n");
                }
                printf("\nAperte para continuar ");getchar();
                break;
            case 4: //Desempilha elemento.
                if(pAux->inicializada > 0)
                    pAux->topo = desempilhar_elemento(pAux->ponteiro,pAux->topo);
                else
                    printf("Ops! A pilha par não foi inicializada :(\n");
                printf("\nAperte para continuar ");getchar();
                break;
            case 5: //Listar pilha.
//                 system("clear");
                if(pilhaImpar.inicializada && pilhaPar.inicializada)
                    listar_pilha(pilhaImpar.ponteiro,pilhaPar.ponteiro,pilhaImpar.topo,pilhaPar.topo,tamanhoPilha);
                else
                    printf("Ops! Alguma pilha não foi inicializada...\n");
                printf("\nAperte para continuar ");getchar();
                break;
            case 6: //realoca o tamanho da pilha
                tamanhoPilha = obter_tamanho_pilha();
                pilhaImpar.ponteiro = realloc(pilhaImpar.ponteiro, tamanhoPilha * sizeof(int));
                pilhaImpar.topo = tamanhoPilha - 1;
                pilhaPar.ponteiro = realloc(pilhaPar.ponteiro, tamanhoPilha * sizeof(int));
                pilhaPar.topo = tamanhoPilha - 1;
                break;
            default:
                printf("Opcao invalida! Vamos tentar de novo?\n");
                break;
            
            opcMenu = 0;
        }
        
  }
    
    
    //Libera o espaço de memória reservado aos ponteiros
    printf("Encerrando ... \n");
    printf("Liberando o ponteiro da pilha Impar");
    free(pilhaImpar.ponteiro);
    printf(" ----> OK!\n");
    printf("Liberando o ponteiro da pilha Par");
    free(pilhaPar.ponteiro);
    printf(" ----> OK!\n");
    pAux = NULL;
    
    return 0;
}
int obter_tamanho_pilha(void){
    
    int tamanhoVetor = 0;
    
    while(tamanhoVetor <= 0 || tamanhoVetor >= T_MAX){
        printf("\nPor gentileza, defina o tamanho da pilha, respeitando o limite de %d posições\n", T_MAX);
        printf("Tamanho: ");
        scanf("%d", &tamanhoVetor);
        if(tamanhoVetor <= 0 || tamanhoVetor >= T_MAX)
            printf("Valor não válido. Vamos tentar novamente ...\n");
    }
    
    system("clear");
    
    return tamanhoVetor;
}

int menu_opcoes(void){
    
    int op;

    system("clear");
    
    printf("==============================================================\n");
    printf("MENU\n");
    printf("==============================================================\n");

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
    printf("\n");

    return op;
    
}
int menu_define_pilha_uso(int opMenu, int opPilha){
    
    opPilha = 0;
    while(opPilha != 1 && opPilha != 2){
        if(opMenu > 0 && opMenu < 5 && opMenu != 3){
            /* Algumas das opções do menu não necessitam a discriminação da pilha. 
                * Este trecho verifica se a opção solicitada se encaixa nesta condição. 
                */
            printf("Em qual pilha deseja utilizar? [1] Impar [2] Par. Opção: ");
            scanf("%d%*c", &opPilha);
        }
        else
            break;
    }
    return opPilha;
}