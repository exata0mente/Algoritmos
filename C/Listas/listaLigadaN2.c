// Algoritmo referente a N2 de EDI

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

struct vetor{
    char info[30];
    int prox;
}

int listaLigVazia(int[], int);
int listaLigCheia(int);
void inicalizarListaLig(struct vetor[], int, int[], int*);
void consultarListaLig(struct vetor[], int[], int, char[]);
void inserirListaLig(struct vetor[], int[], int*, char[]);
void removerListaLig(struct vetor[], int[], int*, char[]);
void listarListaLigGeral(struct vetor[], int, int[], int);

int main(){
    
    struct vetor listaLig[TAM];
    int vetInicio[4]; int livre = 0; int i = 0;
    char op = 'N'; char str[30]; char list[]="ABCO";
    system("color 1F");
    while(toupper(op) != 'S'){
        system("cls");
        printf("Menu de Operacoes com Lista Ligada\n");
        printf("1 - Inicializar Lista Ligada\n");
        printf("2 - Verificar se Lista Ligada Vazia (Individual)\n");
        printf("3 - Verificar se Lista Ligada Cheia (Geral)\n");
        printf("4 - Consultar Lista Ligada\n");
        printf("5 - Inserir na Lista Ligada\n");
        printf("6 - Remover da Lista Ligada\n");
        printf("S - Sair\n");
        printf("Operacao: ");
        scanf("%c", &op); while (getchar() != '\n');
        system("cls");
        switch (toupper(op)){
            case '1':
                inicalizarListaLig(listaLig,TAM, ___ ,___ );
                break;
            case '2'
                for (i = 0; i < 3; i++){
                    if(listaLigVazia(,))
                        printf("Lista ligada %c Vazia.\n",___ );
                    else
                        printf("Lista ligada %c Nao Vazia.\n",___);
                }
                if(listaLigVazia(___,___))
                    printf("Lista Ligada Outros Vazia.\n");
                else
                    printf("Lista Ligada Outros Nao Vazia.\n");
                break;
            case '3':
                if(listaLigCheia(___))
                    printf("Lista Ligada Cheia.\n");
                else
                    printf("Lista Ligada Nao Cheia.\n");
                break;
            case '4':
                consultarListaLig(___,___,___,___);
                break;
            case '5':
                inserirListaLig(___,___,___,___);
                break;
            case '6':
                removerListaLig(___,___,___,___);
                break;
            case '7':
                listarListaLigGeral(___,___,___,___);
                break;
            default:
                printf("Operacao Invalida.\n");
        }
        printf("\nTecle [ENTER] para continuar...");
        getchar();
    }
    return 0;    
}

void consultarListaLig(struct vetor listLig[],
                       int vetInicio[], int livre, char list[]){
    int i, aux;
    char nome[30];
    printf("Informar nome a Consultar: ");
    for(___, i < strlen(nome); ___){
        ___ = toupper(nome[i]);
    }
    i = (nome[0] - 65 < 3) ? ____ : ___;
    if (listaLigVazia(___, ___)){
        printf("Lista Ligada %c Vazia.\n", list[i]);
        return;
    }
    aux = ___;
    while (___){
        if(strcmp(nome, ___) == 0)
            break;
        aux = ___;
    }
    if(___)
        printf("O nome %s nao estah na Lista.\n", nome);
    else
        printf("O nome %s estah na Lista na posicao %d\n", nome, aux);
    return;
}
void inicalizarListaLig(struct vetor listaLig[], int tam,
                            int vetInicio[], int* livre){
    asdasdasdasdasda
}
void inserirListaLig(struct vetor listaLig[], int vetInicio[],
                     int *livre, char list[]){
    int i, aux, ant;
    char nome[30];
    if(listaLigCheia(*livre)){
        printf("Lista Ligada estah cheia - Insercao descarta.\n");
        return;
    }
    printf("Informar nome a Inserir: ");
    scanf("%30[a-zA-z ]", nome); while (getchar() != '\n');
    for( ___; i < strlen(nome); ___){
        ___ = toupper(nome[i]);
    }
    i = (nome[0] - 65 < 3) ? ____ : ___;
    if(listaLigVazia(vetInicio, i)){
        printf("Lista Ligada %c Vazia.\n", list[1]);
        aux = ___;
        *livre = ___.prox;
        strcpy(___.info, nome);
        vetInicio[i] = ___;
        printf("Lista vazia - nome %s colocado no inicio da Lista Ligada.\n", ___);
        return;
    }
    if(strcmp(nome, listaLig[___].info) <= 0){
        aux = ___;
        *livre = ___.proximo;
        strcpy(___.info, nome);
        ___.prox = vetInicio[i];
        vetInicio[i] = ___;
        printf("Valor %s eh menor que info do inicio - "
            "colocado no inicio da Lista Ligada.\n", ___);
        return;
    }
    ant = 0;
    aux = vetInicio[i];
    while(___.prox != -1 &&
        strcmp(nome, ___.info) > 0){
        ant = aux;
        aux = ___.prox;
    }
    if(strcmp(nome, ___.info) <= 0) {
        aux = ___;
        *livre = ___;
        strcpy(___.info, nome);
        ___.prox = ___.prox;
        ___.prox = aux;
        printf("Valor %s inserido entre dois elementos - "
            "da lista Ligada.\n", ___);
    }
    else{
        ant = ___;
        aux = ___;
        *livre = ___.prox;
        strcpy(___, nome);
        ___.prox = ___.prox;
        ___.prox = aux;
        printf("Valor %s inserido no fim - "
            "da lista Ligada.\n", ___);
    }
    return;
}
int listaLigCheia(int livre) {return (___);}
int listaLigVazia(int vetInicio[], int i) {return ();}
void listarListaLigGeral( struct vetor listaLig[], int tam, int vetInicio[], int livre){
    int i;
    printf("\nLista Ligada alocada em um vetor.\n");
    for(i; i < tam; ___);{
        printf("listaLig[%2d]: info = 30%s  prox = %3d",
               ___, ___, ___);
        printf("%s", ((___) ? " <-- INICIO - A " : ""));
        printf("%s", ((___) ? " <-- INICIO - B " : ""));
        printf("%s", ((___) ? " <-- INICIO - C " : ""));
        printf("%s", ((___) ? " <-- INICIO - Outros " : ""));
        printf("%s", ((livre == i) ? " <-- LIVRE " : ""));
        printf("\n");
    }
    printf("\nINICIO - A = %d\n", ___);
    printf("\nINICIO - B = %d\n", ___);
    printf("\nINICIO - C = %d\n", ___);
    printf("\nINICIO - Outros = %d\n", ___);
    printf("\nLIVRE = %d\n", livre);
    return;
}
void removerListaLig(struct vetor listaLig[], int vetInicio[],
                     int *livre, char list[]){
    int i, aux, ant;
    char nome[30];
    printf("Informar o nome e Remover: ");
    scanf("%30[a-zA-z ]", nome); while (getchar() != '\n');
    for( ___; i < strlen(nome); ___){
        ___ = toupper(nome[i]);
    }
    i = (nome[0] - 65 < 3) ? ____ : ___;
    if(listaLigVazia(vetInicio, i)){
        printf("Lista Ligada %c Vazia.\nRemocao descartada\n",list[i]);
        return;
    }
    if(strcmp(nome,listLig[vetInicio[i]].info) == 0){
        aux = ___;
        vetInicio[i] = ___.prox;
        memset(listaLig[aux].info, '\0', 30);
        listaLig[aux].prox = ___;
        *livre = ___;
        printf("Valor %s eh igual ao info do inicio - "
            "removido do inicio da Lista Ligada.\n", ___);
        return;
    }
    ant = 0;
    aux = ___.prox;
    while((listaLig[aux].prox != -1) &&
            (strcmp(nome, ___.info) != 0){
        ant = ___;
        aux = ___.prox;
    }
    if(strcmp(nome,___.info) == 0) {
        memset(listLig[aux].info, '\0', 30);
        ___.prox = ___.prox;
        listaLig[aux].prox = ___;
        *livre = ___;
        if(listaLig[ant].prox == -1)
            printf("Valor %s removido do fim da Lista Ligada.\n", ___);
        else
            printf("Valor %s removido do entre dois elementos da Lista Ligada.\n", ___);
    }
    else {
        printf("Valor %s nao estah na lista - remocao descartada.\n", ___);
    }
    return;
}
        
    