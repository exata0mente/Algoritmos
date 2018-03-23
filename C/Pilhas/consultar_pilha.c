#include<stdio.h>

void consultar_pilha(int *p, int topo){
  
  if(pilha_vazia(topo))
    printf("A pilha esta vazia");
  else
    printf("O elemento do topo da pilha e: %d\n", *(p + topo));
}