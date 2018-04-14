/* Autor: Ricardo Bezerra
 * Ano: 2018
 * Descrição: Ordenar uma entrada de vetor utilizando uma pilha
 * Pendências: Efetuar o algoritmo de comparação ENTRE PILHAS.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhas.h"
#define T 3

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
    
    printf("Vou entrar no primeiro while\n"); //log
    printf("topoDefinitivo = %d\n", topoDefinitivo);
    //Ordenação     
    while(topoDefinitivo >= 0){
        if(*(pEntrada + indiceVetor) > *(pDefinitivo + topoDefinitivo)){
            topoTroca = empilhar_elemento(pTroca, topoTroca, *(pDefinitivo + topoDefinitivo), T);
            topoDefinitivo = desempilhar_elemento(pDefinitivo, topoDefinitivo);
            printf("Passo \n"); //log
            printf("Topo1 = %d\tTopo2 = %d\n", topoDefinitivo, topoTroca);//log
            listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);//log
        }
        else{
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), T);
            while(topoTroca >= 0){
                topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pTroca + topoTroca), T);
                topoTroca = desempilhar_elemento(pTroca, topoTroca);
                printf("Passo \n"); //log
                printf("Topo1 = %d\tTopo2 = %d\n", topoDefinitivo, topoTroca);//log
                listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);//log
            }
        }
        indiceVetor++;
    }
    
    listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);
    printf("\n");
    
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
        printf("%d, ", *(p + i));
    printf("\n");
}

// ENQUANTO topo_a > 0 FAÇA:
//     SE elementoj < ai:
//         EMPILHA ai EM b;
//         topo_b++;
//         DESEMPILHA a;
//         topo_a--;
//     SENAO:
//         EMPILHA elemento EM a;
//         topo_a++;
//         ENQUANTO topo_b > 0:
//             EMPILHA bi EM a;
//             topo_a++;
//             DESEMPILHA b;
//             topo_b-;
//         FIM_ENQUANTO;
//     j++;
// FIM_ENQUANTO;

// Referências:
// Números Aleatórios - https://www.ime.usp.br/~pf/algoritmos/aulas/random.html