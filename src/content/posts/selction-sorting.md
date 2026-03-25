---
title: Selection Sort
tag: Algoritmo
pubDate: 2026-03-25T11:19:00
description: Explicando o algoritmo de ordenação por seleção
author: IzuBot
---

## Índice

- [Selection Sort](#selection-sort)
  - [Exemplo de ordenação por seleção](#exemplo-de-ordenação-por-seleção)
- [Implementação em C](#implementação-em-c)
- [Conclusão](#conclusão)

## Selection Sort

O algoritmo de ordenação por seleção, ou Selection Sort, é um algoritmo de ordenação simples e intuitivo. Ele funciona dividindo a lista em duas partes: a parte ordenada e a parte não ordenada. O algoritmo repetidamente seleciona o menor (ou maior, dependendo da ordem desejada) elemento da parte não ordenada e o troca com o primeiro elemento da parte não ordenada, movendo assim a fronteira entre as partes ordenada e não ordenada.

O processo é repetido em todo o array até que a parte não ordenada esteja vazia, resultando em um array todo ordenado. A complexidade do Selection Sort é O(n²) no pior e melhor caso, isso porque ele precisa percorrer o array para encontrar o menor elemento em cada iteração, independentemente de a lista já estar ordenada ou não.

### Exemplo de ordenação por seleção

Vamos ao exemplo de como isso funciona, sem implementar ainda o código, apenas para entender o processo:

Suponha que temos a seguinte lista de número:

```bash
[64, 25, 12, 22, 11]
```

Então, dado esse array desordenado precisamos ordená-lo usando o Selection Sort. O processo seria o seguinte:

1. Quando começamos a iteração no vetor, deixamos um **ponteiro** para o primeiro elemento, esse **ponteiro** é importante pois ele indica onde a parte ordenada termina e onde a parte não ordenada começa. Então no primeiro loop, o ponteiro começa no índice 0, e o algoritmo procura o menor elemento na parte não ordenada (ponteiro + 1) até o final do array. O menor elemento encontrado é **11**, que está no índice **4**. Então, o algoritmo troca o elemento no índice **0** (64) com o elemento no índice **4** (11). Agora a lista fica assim:

    ```bash
    [11, 25, 12, 22, 64]
    ```

2. Na segunda iteração a parte ordenada é o elemento no índice 0, e o **ponteiro** se move para o índice 1. O algoritmo procura o menor elemento na parte não ordenada (índices 2 a 4) e encontra o **12** no índice **2**. Então, ele troca o elemento no índice **1** (25) com o elemento no índice **2** (12). Agora a lista fica assim:

    ```bash
    [11, 12, 25, 22, 64]
    ```

3. Na terceira iteração, o **ponteiro** se move para o índice 2, e o algoritmo procura o menor elemento na parte não ordenada (índices 3 a 4) e encontra o **22** no índice **3**. Então, ele troca o elemento no índice **2** (25) com o elemento no índice **3** (22). Agora a lista fica assim:

    ```bash
    [11, 12, 22, 25, 64]
    ```

4. Na quarta iteração, o **ponteiro** se move para o índice 3, e o algoritmo procura o menor elemento na parte não ordenada (índice 4) e encontra o **64** no índice **4**. Então, ele troca o elemento no índice **3** (25) com o elemento no índice **4** (64). Agora a lista fica assim:

    ```bash
    [11, 12, 22, 25, 64]
    ```

5. Na última iteração, o **ponteiro** se move para o índice 4, e o algoritmo procura o menor elemento na parte não ordenada (que está vazia) e não encontra nenhum elemento. Então, a lista permanece a mesma:

    ```bash
    [11, 12, 22, 25, 64]
    ```

E assim, a lista foi ordenada usando o algoritmo de ordenação por seleção. O processo é repetido até que toda a lista esteja ordenada, e o resultado final é:

```bash
[11, 12, 22, 25, 64]
```

O algoritmo que descrevi é o selection sort in-place, ou seja, ele ordena a lista sem usar espaço adicional significativo, apenas algumas variáveis temporárias para realizar as trocas. Ele é um algoritmo de ordenação estável, o que significa que ele mantém a ordem relativa dos elementos iguais. No entanto, devido à sua complexidade O(n²), ele não é recomendado para listas grandes, mas pode ser útil para listas pequenas ou como parte de algoritmos mais complexos.

Além do in-place, existe uma variação do selection sort out of-place, onde o algoritmo cria uma nova lista para armazenar os elementos ordenados, mas isso não é tão comum e geralmente não é recomendado devido ao uso adicional de memória.

Existe inúmeras formas de se aplicar o selection sort, como um selection sort recursivo, ou um selection sort otimizado que para de iterar quando a lista já está ordenada, mas isso é assunto para outro post. O importante é entender o conceito básico do algoritmo e como ele funciona.

## implementação em C

```C

#include <stdio.h>

void print_array(int arr[], int n);

int main(int argc, char *argv[])
{
    int arr[] = {64, 25, 12, 22, 11};

    size_t tamanho_arr = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tamanho_arr - 1; i++)
    {
        int indice_menor = i;

        for (int j = i + 1; j < tamanho_arr; j++)
        {
            if (arr[j] < arr[indice_menor])
                indice_menor = j;
        }

        int aux = arr[i]; // aux é apenas uma variável temporária para realizar a troca dos elementos (swap)
        arr[i] = arr[indice_menor]; // aqui o elemento no índice i (valor 64) é substituído pelo elemento no índice indice_menor (valor 11)
        arr[indice_menor] = aux; // aqui o elemento no índice indice_menor (valor 11) é substituído pelo valor armazenado em aux (valor 64), completando a troca dos elementos.
        // Resultado, o valor 11 que estava em arr[indice_menor] (índice 4) é armazenado no arr[i] (índice 0), e o valor 64 que estava em arr[i] (índice 0) é armazenado no arr[indice_menor] (índice 4).
        
    }

    print_array(arr, tamanho_arr);

    return 0;

}

// Essa função é apenas para imprimir o array, não faz parte do algoritmo de ordenação por seleção, mas é útil para verificar o resultado final da ordenação.
void print_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

```

> Esses comentarios no final do código explicam apenas o primeiro loop, mas o processo é o mesmo para os outros loops, deve facilitar o entendimento da parte do swap, que é a parte mais confusa do algoritmo, - pelo menos pra mim foi.

## Conclusão

No começo pode ser confuso entender como o algoritmo funciona, principalmente na hora de realizar a troca dos elementos, mas com prática e visualização do processo, fica mais fácil de entender. O importante é lembrar que o selection sort é um algoritmo de ordenação simples e intuitivo, mas não é recomendado para listas grandes devido à sua complexidade O(n²). Ele pode ser útil para listas pequenas ou como parte de algoritmos mais complexos. Além disso, existem variações do selection sort, como o selection sort recursivo ou otimizado, mas o conceito básico do algoritmo é o mesmo. Espero que este post tenha ajudado a entender.
