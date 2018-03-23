#include<stdio.h>

void listar_pilha(int *p, int topo){
  
    int i;

    if(pilha_vazia(topo))
        printf("A pilha esta vazia!\n");
    else
        for(i = T-1; i >= 0;i--)
            printf("Elemento [%d] = %d%s", i, *(p + i), (i == topo) ? " <-- TOPO\n" : "\n");
        
}
