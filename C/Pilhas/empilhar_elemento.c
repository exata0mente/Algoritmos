/* Alteraçṍes: Inserido a validação de se um elemento é par ou é impar
 */

#include<stdio.h>

int empilhar_elemento(int *p1, int *p2, int topo1, int topo2){
    
    int elemento = 0;
        
        printf("Digite o elemento: ");
        scanf("%d",&elemento);
        
        if(elemento % 2){
            if(pilha_cheia(topo1))
                printf("A pilha IMPAR esta cheia!\n");
            *(p1 + (++topo1)) = elemento;
        }
        else{
            if(pilha_cheia(topo2))
                printf("A pilha PAR esta cheia!\n");
            *(p2 + (++topo2)) = elemento;
        }
        
    return elemento;
    
}