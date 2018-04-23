# Introdução

Este arquivo serve para dar um breve resumo sobre o conteúdo desta pasta mas esta não será sua principal função. Aqui irei colocar notas de aula ou de pesquisas referente aos pontos necessários para o desenvolvimento dos projetos.

## Descrição dos arquivos

- [pilhaOrdenaVetor.c](https://raw.githubusercontent.com/exata0mente/Algoritmos/master/C/Pilhas/pilhaOrdenaVetor.c): Recebe um vetor de dados, preenchido manual ou aleatoriamente, e ordena, em ordem crescente, utilizando duas pilhas: uma definitiva e uma auxiliar.
- [pilhaParOuImpar.c](https://raw.githubusercontent.com/exata0mente/Algoritmos/master/C/Pilhas/pilhaParOuImpar.c): Implementa as funções-verbo utilizada na estrutura de dados pilha. Além das funções verbo. Além das funções-verbo, há uma implementação de empilhamento de elementos pares e impares em duas pilhas distintas.
- [pilhas.h](https://raw.githubusercontent.com/exata0mente/Algoritmos/master/C/Pilhas/pilhas.h): Arquivo fonte com as definições das funções-verbo utilizada em pilhas. 

## Notas de Aula

### Alocação Dinâmica em C

#### A função `malloc`
Quando iniciamos o aprendizado em C, uma das estruturas de dados que causa certa dificuldade é o vetor. Entre pontos conceituais é muito comum ver e ouvir em sala de aula um colega de classe questionando: "posso solicitar ao usuário o tamanho do vetor, associar em uma variável e então declarar um vetor com o tamanho dado pelo cliente?". Prontamente a resposta de nossos professores é *não*.  

Acontece que a alocação do espaço de memória que uma variável vai necessitar do sistema, é separada em **tempo de compilação**, pois é nesse momento que o compilador irá "informar" ao sistema o quanto de memória aquele código irá necessitar.  

Definir o tamanho de um vetor estático no meio de um código é perigoso pois o usuário pode informar um número maior que disponível em memória, tendo resultados inesperados como consequência.  

Para tratar este tipo de situação, em que **o tamanho de determinada variável pode ser conhecida ou modificada no meio da execução do programa**, existe as funções `alloc`.

A função `malloc` recebe como argumento um tamanho (em bytes) e retorna o endereço de um espaço sequencial de memória disponível. Por exemplo:

    int *p;
    int tam;
    scanf("%d",&tam);
    p = malloc(tam * sizeof(int));
    
Neste código criamos um ponteiro, e uma variável para receber um tamanho do ponteiro. Aí então atribuímos ao ponteiro **um endereço de memória, sequência, que comporto `tam` vezes variáveis int**.

Didaticamente, e apenas didaticamente, podemos ver como a maneira correta para

    int tam;
    scanf("%d",&tam);
    int vet[tam];
    
#### A função `free`

Ao término de uma função, o espaço de memória reservado para as variáveis declaradas em seu escopo (variáveis locais) é liberado para posterior uso. Porém, ao se utilizar as funções de alocação dinâmica, o espaço alocado não é liberado, permacendo travado para uso no sistema operacional.

Por exemplo:

    void teste(void){
        int i, j, k, l, m;
        
        i = 1; j = 25; l = 9;
        
    }
    
Quando esta função for chamada pelo programa, será alocado memória para as 5 variáveis e ao termino da função, será liberado o espaço utilizado (nossos professores costumam falar que a variável é "destruída").

Já no exemplo retirado deste [artigo](https://www.cprogressivo.net/2013/10/Funcao-free-Como-liberar-memoria-e-evitar-vazamento.html) ilustra como a alocação de memória dinâmica pode ser perigosa:

    #include <stdio.h>
    #include <stdlib.h>

    void aloca()
    {
        int *ptr;
        ptr = (int *) malloc(100);
    }

    int main(void)
    {
        while(1)
        aloca();

        return 0;
    }
        
Há um looping infinito que entra na função `aloca` e reserva 100 bytes de memória. Quando a função `aloca` acaba, o espaço reservado não é liberado, mantendo espaços de memória desnecessariamente bloqueados para uso.

Para evitar problemas como este utiliza-se a função `free` da biblioteca `stdlib.h`.

Esta função libera para uso o espaço de memória reservado para um ponteiro. Com isso, em um eventual `malloc` no mesmo código este espaço de memória pode ser reutilizado.

Recomenda-se então que, ao **final do uso de um ponteiro ele seja liberado**.

Há ainda observações sobre [atribuir valor NULL à um endereço de memória liberado](https://www.ime.usp.br/~pf/algoritmos/aulas/footnotes/null-after-free.html) e também um [exemplo](https://www.cprogressivo.net/2013/10/Funcao-free-Como-liberar-memoria-e-evitar-vazamento.html) de possível exploração do valor de "ponteiro solto".

#### A função realloc

Esta função, como sugere o nome, realoca o espaço de memória de um ponteiro de forma dinâmica. Seu retorno é o novo endereço de memória, que possui o tamanho solicitado.

Uso simples:

    int main(){
        int *ptr;
        int tam;
        ...
        printf("Digite o novo tamanho de seu ponteiro: \n");
        scanf("%d", &tam);
        
        ptr = realloc(ptr, tam * sizeof(int))
        ....
    }

#### Recomendações no uso de alocação dinâmica

Como se pode notar, as funções alloc não limitam o valor que pode ser passado como parâmetro, sendo assim, podemos ter casos em que a função receba algo como 9999999999 ou podemos nos deparar com a situação de não haver realmente espaço na memória. 
Quando isso ocorre, a função retorna o valor `NULL` para o ponteiro. Sugere-se então [o uso de um `if` para identificação destes casos](https://www.cprogressivo.net/2013/10/A-funcao-realloc-realocando-memoria-dinamicamente-e-a-calloc.html) ou o uso de uma [função-embalagem (**wrapper-function**)](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html).

### Struct

#### Definição de uma `struct`

Uma `struct` nada mais é do que uma estrutura que pode conter diferentes tipos de dados. A definição mais amplamente difundida é que uma `struct` é uma coleção de diferentes tipos de dados. Esta estrutura é muito utilizado para dar atributos a um objeto específico. Por exemplo, no cadastro hipotético de um aluno temos seu registro, nome e média de notas, ou seja, três tipos de dados diferentes, um `int`, um vetor de `char` e um `float`. 

Não seria possível montar esta estrutura de um vetor pois um vetor só pode ser preenchido com tipos de dados iguais. Já uma `struct` resolve este problema. Veja:

    struct Aluno{
        int registro;
        char nome[10];
        float media;
    };
    
Como citado, uma `struct` é um tipo de dado, logo, podemos declarar variáveis como este tipo de dado:

Declaração na definição da estrutura:

    struct Aluno{
        int registro;
        char nome[10];
        float media;
    } aluno1, aluno2, aluno3;
    
Declaração utilizando a etiqueta da estrutura:

    struct Aluno{
        int registro;
        char nome[10];
        float media;
    };
    
    struct Aluno aluno1;
    struct Aluno aluno2;
    struct Aluno aluno3;
    
Declaração utilizando um nome definido pela função [`typedef`](http://mtm.ufsc.br/~azeredo/cursoC/aulas/cb60.html)

    struct Aluno{
        int registro;
        char nome[10];
        float media;
    };
    
    typedef struct Aluno aluno;
    
    aluno aluno_A;
    aluno aluno_B;
    aluno aluno_C;
    
O "manuseio" das variáveis de tipo `aluno` são simples: para acessar um membro da estrutura utilizamos o operador ".":

    (...)
    aluno_A.registro = 123456;
    strcpy(aluno_A.nome, "Fulano");
    aluno_A.media = (n1 + n2)/2;
    
#### Struct como ponteiro

Uma `struct`, como qualquer outro tipo de dado, pode ser declarado como ponteiro. Seguindo o exemplo acima, podemos fazer:

    struct Aluno{
        int registro;
        char nome[10];
        float media;
    };
    
    typedef struct Aluno aluno;
    
    aluno a; //Cria o endereço de memória para a estrutura
    aluno *p; //Cria um ponteiro que apontará para um endereço de memória "aluno"
    
    p = &a // Atribui ao ponteiro p o endereço de memória da estrutura a.
    
    //Instruções que possuem mesmo significado
    p->registro = 12345;
    a.registro = 12345; 
    
    (*p).registro = 54321; 
    a.registro = 54321; 

Os conceitos de alocação de memória dinâmica também podem ser aplicadas em uma `struct`.
    
    
#### Struct como funções

Também podemos definir o retorno de uma função como `struct`.

    //protótipo
    aluno inicializa_dados(aluno);

    (...)
    
    aluno inicializa_dados(aluno j){
        j.registro = 9999;
        strcpy(j.nome, "xxxxx");
        j.media = 0.0;
    
    return aluno;
    }
    
O retorno desta função será **os valores** atribuidos internamente.
    
## Referências

 -- Alocação Dinâmica - [Site da USP](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)  
 -- Uso da função `free` = [CProgressivo](https://www.cprogressivo.net/2013/10/Funcao-free-Como-liberar-memoria-e-evitar-vazamento.html)  
 -- Função `realloc` = [CProgressivo](https://www.cprogressivo.net/2013/10/A-funcao-realloc-realocando-memoria-dinamicamente-e-a-calloc.html)  
 -- Exemplos e definições de `struct`s e ponteiros - [Site da USP](https://www.ime.usp.br/~mms/mac1222s2013/9%20-%20structs%20e%20ponteiros.pdf)  
 