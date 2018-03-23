#include<stdio.h>

int empilhar_elemento(int *p, int topo){
  
    if(pilha_cheia(topo))
        printf("A pilha esta cheia!\n");
    else{
        printf("Digite o elemento: ");
        scanf("%d",(p + (++topo)));
        printf("Elemento %d empilhado!\n", *(p + topo));
    }

    return topo;
}