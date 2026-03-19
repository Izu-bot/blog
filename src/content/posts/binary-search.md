---
title: Binary Search
tag: Algoritmo
pubDate: 2026-03-15T11:45:00
description: O que é Binary Search e como implementá-lo?
author: IzuBot
---

## Índice

- [Binary Search](#binary-search)
- [Implementando Binary Search](#implementando-binary-search)
- [Conclusão](#conclusão)

## Binary Search

A **pesquisa binária**, ou Binary search é um **algoritmo de busca** - o mais simples. Ela recebe uma **lista** ou um **array** de valores **ordenados** - é extremamente importante que itens estejam ordenados e que existe um valor específico a ser encontrado. Se o elemento buiscado estiver presente na lista, o algoritmo retorna a posição do elemento. Caso contrário, ele retorna um valor indicando que o elemento não foi encontrado - geralmente -1 ou null.

Ao contrario da pesquisa simples que elimina um elemento por vez, a pesquisa binária divide a lista na metada e verifica se o elemento buscado é **menor**, **maior** ou **igual** ao elemento do **meio**, eliminando metade dos elementos restantes a cada iteração. Isso possiblita acharmos o que procuramos em um tempo muito mais rápido, especialmente para listas grandes.

---

### Exemplo de pesquisa simples com C

```C

#include <stdio.h>

int main(int argc, char *argv[]) {
    
    // Pesquisa simples

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t arr_length = sizeof(arr) / sizeof(arr[0]);

    int target = 5;

    for (int i = 0; i < arr_length; i++)
    {
        if (arr[i] == target) printf("Valor: %i\nIndice: %i\n", arr[i], i);
    }
    
    return 0;

}

```

---

Este é um é um exemplo simplório da pesquisa simples ou linear search, onde o algoritmo percorre cada elemento da lista até encontrar o valor buscado ou chegar ao final da lista. A complexidade desse algoritmo é O(n), onde n é o número de elementos na lista, pois no pior caso ele precisa verificar cada elemento uma vez. Ou seja, nesse exemplo o algoritmo pode precisar verificar até 10 elementos para encontrar o valor 5, porém e se, por exemplo, aumentarmos a lista para 1 milhão de elementos? O algoritmo precisaria verificar - no pior dos casos 1 milhão de elementos, o que pode ser muito ineficiente.

---

## Implementando Binary Search

Ok, agora que entendemos o que é a pesquisa binária e quais são as vantagens dela sobre a pesquisa simples, vamos implementar a pesquisa binária em C.

Mas antes vamos entender o algoritmo passo a passo:

1. **Definir os limites**: Inicialmente, definimos dois ponteiros ou índices, um para o início da lista (left) e outro para o final da lista (right).
2. **Calcular o meio**: Em cada iteração, calculamos o índice do elemento do meio usando a fórmula: `mid = left + (right - left) / 2`. Isso evita problemas de overflow que podem ocorrer com a fórmula tradicional `(left + right) / 2`.
3. **Comparar o elemento do meio**: Comparamos o elemento do meio com o valor buscado (target):
   - Se o elemento do meio for igual ao target, retornamos o índice do meio.
   - Se o elemento do meio for maior que o target, significa que o target está na metade esquerda da lista, então movemos o ponteiro direito para `mid - 1`.
   - Se o elemento do meio for menor que o target, significa que o target está na metade direita da lista, então movemos o ponteiro esquerdo para `mid + 1`.
4. **Repetir**: Repetimos os passos 2 e 3 até que o ponteiro esquerdo seja maior que o ponteiro direito, o que indica que o elemento não foi encontrado na lista.

---

### Implementação em C

```C

#include <stdio.h>

int binary_search(int arr[], size_t arr_length, int target);

int main(int argc, char *argv[]) {
    
    // Pesquisa binária

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t arr_length = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int item = binary_search(arr, arr_length, target);

    printf("Valor: %i\nIndice: %i\n", target, item);
}

int binary_search(int arr[], size_t arr_length, int target) {
    int left = 0;
    int right = arr_length - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1; 
        }
    }

    return -1;
}


```

---

Neste exemplo, a função `binary_search` implementa o algoritmo de pesquisa binária. Ela recebe um array de inteiros, o tamanho do array e o valor alvo a ser buscado. A função retorna o índice do elemento encontrado ou -1 se o elemento não estiver presente na lista. A complexidade desse algoritmo é **O(log n)**, onde n é o número de elementos na lista, o que significa que ele é muito mais eficiente do que a pesquisa simples, especialmente para listas grandes.

Como vimos, algoritmos que tem o tempo de execução O(log n) são muito eficientes, pois a cada iteração eles eliminam metade dos elementos restantes, o que resulta em um número de operações muito menor do que algoritmos com tempo de execução O(n), como a pesquisa simples. Portanto, a pesquisa binária é uma escolha excelente para encontrar elementos em listas ordenadas, especialmente quando lidamos com grandes conjuntos de dados.

Caso queira recaptular sobre a complexidade de tempo e espaço, recomendo ler meu post sobre [Estrutura de Dados e Algoritmos](./big-o-notation.md) onde explico brevemente  esses conceitos.

---

## Conclusão

Em resumo, a pesquisa binária é um algoritmo eficiente para encontrar elementos em listas ordenadas. Ele divide a lista em metades e elimina metade dos elementos restantes a cada iteração, o que resulta em uma complexidade de O(log n). É importante lembrar que a lista deve estar ordenada para que a pesquisa binária funcione corretamente.

A implementação em C que forneci é um exemplo simples de como a pesquisa binária pode ser implementada, mas o algoritmo pode ser adaptado para outras linguagens de programação e tipos de dados. Se você estiver lidando com grandes conjuntos de dados ou precisar realizar buscas frequentes, a pesquisa binária é uma escolha excelente para melhorar a eficiência do seu código.
