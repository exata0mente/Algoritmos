/* Alteraçṍes: Inserido a validação de se um elemento é par ou é impar
 */

#include<stdio.h>

int empilhar_elemento(int *p, int topo,int elemento){
  
    if(pilha_cheia(topo))
        printf("Atencao! Pilha cheia! Utilize a funcao Listar\n");
    else{
        *(p + (++topo)) = elemento;
        printf("Elemento %d empilhado!\n", *(p + topo));
    }

    return topo;
}