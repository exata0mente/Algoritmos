/* Autor: Ricardo Bezerra
 * Ano: 2018
 * Descrição: Recebe um vetor de dados como entrada e ordena-o,
 * em modo crescente, utilizando duas pilhas, uma auxiliar e uma
 * definitiva.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhas.h"
#define T 5

void preenche_vetor_aleatorio(int*);
void preenche_vetor_manual(int*);
void mostra_vetor(int*);

int main(void){

    int vetEntrada[T];
    int vetDefinitivo[T], vetTroca[T];
    int topoDefinitivo = -1, topoTroca = -1;
    int i = 0, indiceVetor = 0;
    int *pEntrada = vetEntrada;
    int *pDefinitivo = vetDefinitivo;
    int *pTroca = vetTroca;
    int opcUsuario = -1;
    int seed = 0;

    //Inicialização das Pilhas
    topoTroca = inicializar_pilha(pTroca, T);
    topoDefinitivo = inicializar_pilha(pDefinitivo, T);
    
    //Preenchimento do vetor
    while(opcUsuario == -1){
        system("clear");
        printf("Escolha a forma que será preenchido o vetor: [1] Manual\t[2] Aleatório\n");
        printf("Opção: ");
        scanf("%d%*c", &opcUsuario);
        if(opcUsuario != 1 && opcUsuario != 2)
            opcUsuario = -1;
    }
    
    switch(opcUsuario){
        case 1:
            preenche_vetor_manual(pEntrada);
            break;
        case 2:
            opcUsuario = -1; //reutilização da variável
            while(opcUsuario == -1){
                printf("\nGostaria de Definir alguma seed? [1] Sim [2] Não (gera com time(NULL))\n");
                printf("Opção: ");
                scanf("%d%*c", &opcUsuario);
                switch(opcUsuario){
                    case 1:
                        printf("Seed: ");
                        scanf("%d%*c", &seed);
                        srand(seed);
                        preenche_vetor_aleatorio(pEntrada);
                        break;
                    case 2:
                        srand(time(NULL));
                        preenche_vetor_aleatorio(pEntrada);
                        printf("\n\n***** Preenchimento automático *****\n\n");
                        mostra_vetor(pEntrada);
                        break;
                    default:
                        opcUsuario = -1;
                }
            }
            break;
            
    }
    //Atribuição do primeiro valor do vetor
    topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *vetEntrada, T);
    indiceVetor++;

    //Ordenação     
    while(!(pilha_cheia(topoDefinitivo, T))){ 
        /* A pilha pDefinitivo conterá os elementos do vetor vetEntrada onrdenados. Como os seus tamanhos são 
         * iguais, a pilha terminará de ser ordenada quando ela estiver cheia.
         */
        if(*(pEntrada + indiceVetor) >= *(pDefinitivo + topoDefinitivo)){
            /* Caso o elemento do vetEntrada[i] for maior que o elemento da
             * pDefinitivo[topoDefinitivo], os elementos da pDefinitivo serão empilhados
             * na pTroca seguindo a validação relacional.
             */
            while(*(pEntrada + indiceVetor) > *(pDefinitivo + topoDefinitivo)){
                /* Sendo o elemento do vetEntrada[i] maior que pDefinitivo[topoDefinitivo],
                 * enviamos o pDefinitivo[topoDefinitivo] à pTroca validando cada elemento pDefinitivo
                 * até que a condição relacional seja atendida.
                 */
                topoTroca = empilhar_elemento(pTroca, topoTroca, *(pDefinitivo + topoDefinitivo), T); 
                topoDefinitivo = desempilhar_elemento(pDefinitivo, topoDefinitivo);
                if(pilha_vazia(topoDefinitivo)) break;
            }
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), T);
            while(!pilha_vazia(topoTroca)){
                /* Reempilha os elementos da pTroca em pDefinitivo, mantendo a pilha sempre na ordenação
                 * configurada.
                 */
                topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pTroca + topoTroca), T); 
                topoTroca = desempilhar_elemento(pTroca, topoTroca);
            }
        }
        else{
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), T);
        }
        
        indiceVetor++;
    }
    
    printf("\n\n***** Pilha ordenada *****\n\n");
    listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,T);
    
    return 0;

}

void preenche_vetor_aleatorio(int *p){
	int i = 0;

	for(i = 0; i < T; i++)
		*(p + i) = rand() % 100;
}
void preenche_vetor_manual(int *p){
	int i = 0;
        
        printf("\n\n***** Preenchimento manual *****\n\n");
        
        for(i = 0; i < T; i++){
            printf("Elemento[%d]: ", i+1);
            scanf("%d%*c", (p+i));
        }
}
void mostra_vetor(int *p){
    int i = 0;
    
    for(i = 0; i < T; i++)
        printf("%d. ", *(p + i));
}

// Referências:
// Números Aleatórios - https://www.ime.usp.br/~pf/algoritmos/aulas/random.html