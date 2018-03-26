/* Alteraçṍes: Listando as duas pilhas [iss002]
 */

#include<stdio.h>

void listar_pilha(int *p1, int *p2, int topo1, int topo2){
  
    int i;

    for(i = T-1; i >= 0;i--){
        
        /*if(topo1 == -1){
            printf("Considere inicializar... :(\t");
        }
        else
        */    printf("Pilha Impar [%d] = %d%s \t\t\t", i, *(p1 + i), (i == topo1) ? " *" : "");
        
        /*if(topo2 == -1){
            printf("Considere inicializar... :(\n");
        }
        else
        */    printf("Pilha Par [%d] = %d%s ", i, *(p2 + i), (i == topo2) ? " *\n" : "\n");
    }
    printf("\nSendo * o topo da pilha\n");
}
