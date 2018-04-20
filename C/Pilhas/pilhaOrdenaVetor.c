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
#define T_MAX 20

void preenche_vetor_aleatorio(int*,int);
void preenche_vetor_manual(int*,int);
void mostra_vetor(int*,int);
void menu_interacao_usuario(int*,int);
int obter_tamanho_vetor(void);

int main(void){

    int topoDefinitivo = -1, topoTroca = -1;
    int i = 0, indiceVetor = 0;
    int tamanhoVetor = 0;
    int *pEntrada;
    int *pDefinitivo;
    int *pTroca;

    //Obtenção do tamanho do vetor passado pelo usuário
    tamanhoVetor = obter_tamanho_vetor();
    
    //Definição do tamanho das pilhas
    pEntrada = malloc(tamanhoVetor * sizeof(int));
    pDefinitivo = malloc(tamanhoVetor * sizeof(int));
    pTroca = malloc(tamanhoVetor * sizeof(int));

    //Inicialização das Pilhas
    topoTroca = inicializar_pilha(pTroca, tamanhoVetor);
    topoDefinitivo = inicializar_pilha(pDefinitivo, tamanhoVetor);
    
    //Definição e preenchimento do vetor
    menu_interacao_usuario(pEntrada,tamanhoVetor);

    //Atribuição do primeiro valor do vetor
    topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *pEntrada, tamanhoVetor);
    indiceVetor++;

    //Ordenação     
    while(!(pilha_cheia(topoDefinitivo, tamanhoVetor))){ 
        /* A pilha pDefinitivo conterá os elementos do vetor pEntrada onrdenados. Como os seus tamanhos são 
         * iguais, a pilha terminará de ser ordenada quando ela estiver cheia.
         */
        if(*(pEntrada + indiceVetor) >= *(pDefinitivo + topoDefinitivo)){
            /* Caso o elemento do pEntrada[i] for maior que o elemento da
             * pDefinitivo[topoDefinitivo], os elementos da pDefinitivo serão empilhados
             * na pTroca seguindo a validação relacional.
             */
            while(*(pEntrada + indiceVetor) > *(pDefinitivo + topoDefinitivo)){
                /* Sendo o elemento do pEntrada[i] maior que pDefinitivo[topoDefinitivo],
                 * enviamos o pDefinitivo[topoDefinitivo] à pTroca validando cada elemento pDefinitivo
                 * até que a condição relacional seja atendida.
                 */
                topoTroca = empilhar_elemento(pTroca, topoTroca, *(pDefinitivo + topoDefinitivo), tamanhoVetor); 
                topoDefinitivo = desempilhar_elemento(pDefinitivo, topoDefinitivo);
                if(pilha_vazia(topoDefinitivo)) break;
            }
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), tamanhoVetor);
            while(!pilha_vazia(topoTroca)){
                /* Reempilha os elementos da pTroca em pDefinitivo, mantendo a pilha sempre na ordenação
                 * configurada.
                 */
                topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pTroca + topoTroca), tamanhoVetor); 
                topoTroca = desempilhar_elemento(pTroca, topoTroca);
            }
        }
        else{
            topoDefinitivo = empilhar_elemento(pDefinitivo, topoDefinitivo, *(pEntrada + indiceVetor), tamanhoVetor);
        }
        
        indiceVetor++;
    }
    
    printf("\n\n***** Pilha ordenada *****\n\n");
    listar_pilha(pDefinitivo,pTroca,topoDefinitivo,topoTroca,tamanhoVetor);

    //Libera o espaço de memória reservado para os ponteiros
    free(pDefinitivo);
    free(pEntrada);
    free(pTroca);
    
    return 0;

}
void menu_interacao_usuario(int *pDados, int tam_vet){
    /* Recebe um endereço de memória e solicita ao usário como será o método
     * de preenchimento de cada elemento: Manual, aleatório com seed definida
     * ou aleatório com seed indefinida.
     */
    
    int opcUsuario = -1;
    int seed;    
    
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
            preenche_vetor_manual(pDados,tam_vet);
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
                        preenche_vetor_aleatorio(pDados,tam_vet);
                        break;
                    case 2:
                        srand(time(NULL));
                        preenche_vetor_aleatorio(pDados,tam_vet);
                        printf("\n\n***** Preenchimento automático *****\n\n");
                        mostra_vetor(pDados,tam_vet);
                        break;
                    default:
                        opcUsuario = -1;
                }
            }
            default:
                break;
    }       
    
}

void preenche_vetor_aleatorio(int *p, int T){
	int i = 0;

	for(i = 0; i < T; i++)
		*(p + i) = rand() % 100;
}
void preenche_vetor_manual(int *p, int T){
	int i = 0;
        
        printf("\n\n***** Preenchimento manual *****\n\n");
        
        for(i = 0; i < T; i++){
            printf("Elemento[%d]: ", i+1);
            scanf("%d%*c", (p+i));
        }
}
void mostra_vetor(int *p, int T){
    int i = 0;
    
    for(i = 0; i < T; i++)
        printf("%d. ", *(p + i));
}

int obter_tamanho_vetor(void){
    
    int tamanhoVetor = 0;
    
    system("clear");
    while(tamanhoVetor <= 0 || tamanhoVetor >= T_MAX){
        printf("Qual será o tamanho do seu vetor? 'Com grandes poderes vem grandes responsabilidades'\n");
        printf("Tamanho: ");
        scanf("%d", &tamanhoVetor);
        if(tamanhoVetor <= 0 || tamanhoVetor >= T_MAX)
            printf("Valor não válido. Vamos tentar novamente ...\n");
    }
    
    return tamanhoVetor;
}
// Referências:
// Números Aleatórios - https://www.ime.usp.br/~pf/algoritmos/aulas/random.html