#include<stdio.h>

int desempilhar_elemento(int *p, int topo){

    if(pilha_vazia(topo)){
      printf("A pilha esta vazia!\n");
      return topo;
    }
    else{
      *(p + topo) = 0;
      printf("Elemento desempilhado!\n");
      return --topo;
    }
}