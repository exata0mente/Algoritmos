/* Autor: Ricardo Bezerra
 * Ano: 2018
 * Descrição: Ordenar uma entrada de vetor utilizando uma pilha
 * Pendências: Efetuar o algoritmo de comparação ENTRE PILHAS.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhas.h"
#define T 5

void preenche_vetor(int*);
void mostra_vetor(int*);
// void percorre_vetor(int, int*, int*, int*, int*);

int main(void){

    int vetEntrada[T];
    int vetDefinitivo[T], vetTroca[T];
    int topoDefinitivo = -1, topoTroca = -1;
    int i = 0, indiceVetor = 0;
    int *pEntrada = vetEntrada;
    int *pDefinitivo = vetDefinitivo;
    int *pTroca = vetTroca;

    srand(time(NULL));

    
    //Inicialização das Pilhas
    topoTroca = inicializar_pilha(pTroca, T);
    topoDefinitivo = inicializar_pilha(pDefinitivo, T);
    
    //Preenchimento do vetor com dados aleatórios
    preenche_vetor(pEntrada);
    mostra_vetor(pEntrada);
    
    //Atribuição do primeiro valor do vetor
    topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *vetEntrada, T);
    indiceVetor++;

//     printf("\nPasso \n"); //log 
//     printf("\nTopo1 = %d\tTopo2 = %d\n ", topoDefinitivo, topoTroca);//log
//     listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);//log
    
    //Ordenação     
    while(!(pilha_cheia(topoDefinitivo, T))){ // Enquanto a pilha não estiver cheia
//         printf("Entrei no while 1\n");
        if(*(pEntrada + indiceVetor) >= *(pDefinitivo + topoDefinitivo)){
//             printf("Entrei no if 1\n");
            while(*(pEntrada + indiceVetor) > *(pDefinitivo + topoDefinitivo)){
//                 printf("Entrei no while 2\n");
                //Empilha a_i em b
                topoTroca = empilhar_elemento(pTroca, topoTroca, *(pDefinitivo + topoDefinitivo), T); 
//                 printf("EMPILHEI! Topo1 = %d\tTopo2 = %d\n ", topoDefinitivo, topoTroca);
                //Desempilha a_i
                topoDefinitivo = desempilhar_elemento(pDefinitivo, topoDefinitivo);
//                 printf("DESEMPILHEI! Topo1 = %d\tTopo2 = %d\n ", topoDefinitivo, topoTroca);
//                 printf("\nTopo1 = %d\tTopo2 = %d\n ", topoDefinitivo, topoTroca);//log
//                 listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);//log
                if(pilha_vazia(topoDefinitivo)) break;
            }
            //Empilha elemento em a
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), T);
            while(!pilha_vazia(topoTroca)){
//                 printf("Entrei no while 3\n");
                //Empilha b_i em a
                topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pTroca + topoTroca), T); 
                //Desempilha b_i
                topoTroca = desempilhar_elemento(pTroca, topoTroca);
//                 printf("\nPasso \n"); //log
//                 printf("\nTopo1 = %d\tTopo2 = %d\n ", topoDefinitivo, topoTroca);//log
//                 listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);//log
            }
            
//             printf("Passo \n"); //log
//             printf("Topo1 = %d\tTopo2 = %d\n", topoDefinitivo, topoTroca);//log
//             listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);//log
        }
        else{
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), T);
        }
        
        indiceVetor++;
    }
    
//     printf("\n\n ");
    listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);
    
//         mostra_vetor(pDefinitivo);
    return 0;

}

void preenche_vetor(int *p){
	int i = 0;

	for(i = 0; i < T; i++)
		*(p + i) = rand() % 100;
}
void mostra_vetor(int *p){
    int i = 0;
    
    for(i = 0; i < T; i++)
        printf("%d. ", *(p + i));
    printf("\n\n ");
}

// Referências:
// Números Aleatórios - https://www.ime.usp.br/~pf/algoritmos/aulas/random.html