// Questão 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int i;

    array = (int *)malloc(5 * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Os numeros digitados sao:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}

// Questão 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int tamanho, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite %d valores inteiros:\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Os valores digitados sao:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}

// Questão 3

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    int tamanho, i;
    int pares = 0, impares = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(tamanho *sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro na alocacao de memoria\n");

        return 1;
    }

    printf("Digite %d valores inteiros: ", tamanho);
    for (i = 0; i < tamanho; i++){
        printf("Valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);

    free(vetor);

    return 0;
}

// Questão 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alocarString(int tamanho) {
    char *str = (char *)malloc(tamanho * sizeof(char));
    return str;
}

void removerVogais(char *str) {
    int i, j = 0;
    int len = strlen(str);
    char *novaStr = (char *)malloc((len + 1) * sizeof(char));

    for (i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            novaStr[j++] = str[i];
        }
    }
    novaStr[j] = '\0';
    strcpy(str, novaStr);
    free(novaStr);
}

int main() {
    int tamanho;
    char *str;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    str = alocarString(tamanho + 1);

    printf("Digite o conteúdo da string: ");
    scanf(" ");
    fgets(str, tamanho + 1, stdin);

    str[strcspn(str, "\n")] = '\0';

    removerVogais(str);

    printf("String sem vogais: %s\n", str);

    free(str);

    return 0;
}

// Questão 5
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, i, count = 0;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite %d valores inteiros:\n", N);
    for (i = 0; i < N; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor de X: ");
    scanf("%d", &X);

    printf("Multiplos de %d no vetor:\n", X);
    for (i = 0; i < N; i++) {
        if (vetor[i] % X == 0) {
            printf("%d ", vetor[i]);
            count++;
        }
    }
    printf("\nQuantidade de multiplos de %d: %d\n", X, count);

    free(vetor);

    return 0;
}

// Questão 6
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *memoria;
    int tamanhoMemoria, numeroInteiros;
    int opcao, posicao, valor;

    printf("Digite o tamanho da memoria a ser alocada (em bytes, multiplo de %zu): ", sizeof(int));
    scanf("%d", &tamanhoMemoria);

    if (tamanhoMemoria % sizeof(int) != 0) {
        printf("Erro: o tamanho da memoria deve ser um multiplo do tamanho do tipo inteiro (%zu bytes).\n", sizeof(int));
        return 1;
    }

    numeroInteiros = tamanhoMemoria / sizeof(int);

    memoria = (int *)malloc(tamanhoMemoria);
    if (memoria == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    for (int i = 0; i < numeroInteiros; i++) {
        memoria[i] = 0;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir um valor em uma determinada posicao\n");
        printf("2. Consultar o valor contido em uma determinada posicao\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 3) {
            break;
        }

        printf("Digite a posicao (0 a %d): ", numeroInteiros - 1);
        scanf("%d", &posicao);

        if (posicao < 0 || posicao >= numeroInteiros) {
            printf("Erro: posicao fora do intervalo valido.\n");
            continue;
        }

        if (opcao == 1) {
            printf("Digite o valor a ser inserido na posicao %d: ", posicao);
            scanf("%d", &valor);
            memoria[posicao] = valor;
        } else if (opcao == 2) {
            printf("Valor na posiçao %d: %d\n", posicao, memoria[posicao]);
        } else {
            printf("Opção invalida.\n");
        }
    }

    free(memoria);
    return 0;
}


// Questão 7
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int i, countZeros = 0;
    int tamanho = 1500;

    vetor = (int *)calloc(tamanho, sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == 0) {
            countZeros++;
        }
    }
    printf("Numero de valores inicializados com zero: %d\n", countZeros);

    for (i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }

    printf("Os 10 primeiros elementos do vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Os 10 ultimos elementos do vetor:\n");
    for (i = tamanho - 10; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}


// Questão 8
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int numero, i;

    while (1) {
        printf("Digite um numero (negativo para parar): ");
        scanf("%d", &numero);

        if (numero < 0) {
            break;
        }

        tamanho++;
        vetor = (int *)realloc(vetor, tamanho * sizeof(int));
        if (vetor == NULL) {
            fprintf(stderr, "Erro de realocacao de memoria\n");
            return 1;
        }

        vetor[tamanho - 1] = numero;
    }

    printf("Vetor lido:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}

// Questão 9
#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            return NULL;
        }
    }
    return matriz;
}

int buscarValor(int **matriz, int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int linhas, colunas;
    int **matriz;
    int valor, encontrado = 0;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    matriz = alocarMatriz(linhas, colunas);
    if (matriz == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor a ser buscado na matriz: ");
    scanf("%d", &valor);

    encontrado = buscarValor(matriz, linhas, colunas, valor);

    if (encontrado) {
        printf("O valor %d foi encontrado na matriz.\n", valor);
    } else {
        printf("O valor %d nao foi encontrado na matriz.\n", valor);
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}


// Questão 10
#include <stdio.h>
#include <stdlib.h>

float **alocarMatriz(int linhas, int colunas) {
    float **matriz = (float **)malloc(linhas * sizeof(float *));
    if (matriz == NULL) {
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
        if (matriz[i] == NULL) {
            return NULL;
        }
    }
    return matriz;
}

void liberarMatriz(float **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int linhas, colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    // Aloca espaço dinamicamente para a matriz
    float **matriz = alocarMatriz(linhas, colunas);
    if (matriz == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    liberarMatriz(matriz, linhas);

    return 0;
}



// Questão 11
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_INICIAL 10
#define TAMANHO_INCREMENTO 10

int main() {
    int *vetor = NULL;
    int tamanho_atual = TAMANHO_INICIAL;
    int numero, quantidade = 0;

    vetor = (int *)malloc(TAMANHO_INICIAL * sizeof(int));
    if (vetor == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite uma sequencia de numeros (Digite 0 para encerrar):\n");

    while (1) {
        scanf("%d", &numero);
        if (numero == 0) {
            break;
        }
        vetor[quantidade++] = numero;

        if (quantidade == tamanho_atual) {
            tamanho_atual += TAMANHO_INCREMENTO;
            int *novo_vetor = (int *)malloc(tamanho_atual * sizeof(int));
            if (novo_vetor == NULL) {
                fprintf(stderr, "Erro de alocacao de memoria\n");
                free(vetor);
                return 1;
            }
            for (int i = 0; i < quantidade; i++) {
                novo_vetor[i] = vetor[i];
            }
            free(vetor);
            vetor = novo_vetor;
        }
    }

    printf("Vetor lido:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}