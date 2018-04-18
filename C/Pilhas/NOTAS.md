# Introdução

Este arquivo serve para dar um breve resumo sobre o conteúdo desta pasta mas esta não será sua principal função. Aqui irei colocar notas de aula ou de pesquisas referente aos pontos necessários para o desenvolvimento dos projetos.

## Descrição dos arquivos

## Notas de Aula

### Alocação Dinâmica em C

Quando iniciamos o aprendizado em C, uma das estruturas de dados que causa certa dificuldade é o vetor. Entre pontos conceituais é muito comum ver e ouvir em sala de aula um colega de classe questionando: "posso solicitar ao usuário o tamanho do vetor, associar em uma variável e então declarar um vetor com o tamanho dado pelo cliente?". Prontamente a resposta de nossos professores é *não*.  

Acontece que a alocação do espaço de memória que uma variável vai necessitar do sistema, é separada em **tempo de compilação**, pois é nesse momento que o compilador irá "informar" ao sistema o quanto de memória aquele código irá necessitar.  

Definir o tamanho de um vetor estático no meio de um código é perigoso pois o usuário pode informar um número maior que disponível em memória, tendo resultados inesperados como consequência.  

Para tratar este tipo de situação, em que **o tamanho de determinada variável pode ser conhecida ou modificada no meio da execução do programa**, existe as funções `alloc`.

A função `malloc` recebe como argumento um tamanho (em bytes) e retorna o endereço de um espaço sequencial de memória disponível. Por exemplo:

    int *p;
    int tam;
    scanf("%d",&tam);
    p = malloc(tam * sizeof(int));
    
Neste código criamos um ponteiro, e uma variável para receber o tamanho do ponteiro. Aí então atribuímos ao ponteiro **um endereço de memória, sequência, que comporto `tam` vezes variáveis int**


## Referências

 - Alocação Dinâmica - [Site da USP](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
