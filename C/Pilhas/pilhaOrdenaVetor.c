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
    int i = 0;
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
    
    //Ordenação     
    for(i = 0; i < T; i++){
        topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + i), T);
        compara_pilhas();
        
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
// void percorre_vetor(int elemento, int *pt_1, int *pt_2, int *pv_1, int *pv_2){
// 
//     if(elemento < *(pv_1 + i)){
//         *pt_2 = empilhar_elemento(pv_2, *pt_2, *(pv_1 + i), T);
//         *pt_1 = desempilhar_elemento(pv_1, *pt_1);
//         *pt_1 = empilhar_elemento(pv_1, *pt_1, elemento, T);
//         *pt_1 = empilhar_elemento(pv_1, *pt_1, *(pv_2 + *pt_2), T);
//         *pt_2 = desempilhar_elemento(pv_2, *pt_2);
//     }
//     else{
//         *pt_1 = empilhar_elemento(pv_1, *pt_1, elemento, T);
//     }
// 
// }


// Referências:
// Números Aleatórios - https://www.ime.usp.br/~pf/algoritmos/aulas/random.html

