#ifndef _PILHAS_H
#define _PILHAS_H

#include<stdio.h>
#include<stdlib.h>

int pilha_vazia(int);
int pilha_cheia(int,int);
int inicializar_pilha(int*,int,int);
void consultar_pilha(int*,int);
int empilhar_elemento(int*, int,int,int);
int desempilhar_elemento(int*, int);
void listar_pilha(int*, int*, int, int, int);

int inicializar_pilha(int *p, int topo, int T){
  
  int i = 0;
  
  for(i = 0; i < T; i++)
    *(p + i) = 0; 
 
  return -1;
}
int pilha_vazia(int topo){
  return(topo == -1);
}
int pilha_cheia(int topo, int T){
  return(topo == T - 1);
}
void consultar_pilha(int *p, int topo){
  
  if(pilha_vazia(topo))
    printf("A pilha esta vazia\n");
  else
    printf("O elemento do topo da pilha e: %d\n", *(p + topo));
}
int empilhar_elemento(int *p, int topo,int elemento, int T){
  
    if(pilha_cheia(topo,T))
        printf("Atencao! Pilha cheia! Utilize a funcao Listar\n");
    else{
        *(p + (++topo)) = elemento;
        printf("Elemento %d empilhado!\n", *(p + topo));
    }

    return topo;
}
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
void listar_pilha(int *p1, int *p2, int topo1, int topo2, int T){
  
    int i;

    for(i = T-1; i >= 0;i--){
        
        printf("Pilha Impar [%d] = %d%s \t\t\t", i, *(p1 + i), (i == topo1) ? " *" : "");
        printf("Pilha Par [%d] = %d%s ", i, *(p2 + i), (i == topo2) ? " *\n" : "\n");
    }
    printf("\nSendo * o topo da pilha\n");
}


#endif

