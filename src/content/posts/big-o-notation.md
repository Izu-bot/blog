---
title: Big O Notation
tag: Algoritmo
pubDate: 2026-03-10T10:00:00
description: O que é e como usar a notação Big O para analisar a eficiência de algoritmos
author: IzuBot
---

## Índice

- [O que é eficiência de algoritmos?](#o-que-é-eficiência-de-algoritmos)
  - [Medir o tempo importa?](#medir-o-tempo-importa)
- [Definição formal e simplificada sobre o que é Big O](#definição-formal-e-simplificada-sobre-o-que-é-big-o)
  - [Conceito de comportamento assintótico](#conceito-de-comportamento-assintótico)
- [Complexidades mais comuns](#complexidades-mais-comuns)
- [Como calcular o Big O de um algoritmo?](#como-calcular-o-big-o-de-um-algoritmo)
  - [Regras básicas de cálculo](#regras-básicas-de-cálculo)
  - [Ignorando constantes e termos menores](#ignorando-constantes-e-termos-menores)
  - [Exemplos práticos passo a passo](#exemplos-práticos-passo-a-passo)
- [Complexidade de Tempo vs. Complexidade de Espaço](#complexidade-de-tempo-vs-complexidade-de-espaço)
- [Como usar esse conhecimento no dia a dia](#como-usar-esse-conhecimento-no-dia-a-dia)

---

## O que é eficiência de algoritmos?

A eficiência de um algoritmo pode ser avaliada sob diferentes aspectos. Aqui, abordaremos dois: **precisão** e **velocidade**.

A **precisão** diz respeito à qualidade da resposta fornecida. Um algoritmo de ordenação pode ser rápido, mas se não ordenar os elementos corretamente, sua precisão é baixa — e um resultado errado entregue rápido não tem valor.

A **velocidade** mede quanto tempo um algoritmo leva para produzir uma resposta. Esse tempo precisa ser viável para o contexto: um algoritmo que leva 10 anos para responder pode ser matematicamente correto, mas é completamente inútil na prática.

### Medir o tempo importa?

Importa e muito. Saber quanto tempo seu algoritmo leva para executar é fundamental para determinar se ele é eficiente. Porém, medir o tempo de execução em segundos é pouco confiável, pois depende de fatores externos como hardware, linguagem de programação e tamanho da entrada.

Por isso, usamos a **notação Big O**: uma forma abstrata de analisar eficiência, focando em como o tempo de execução cresce à medida que o tamanho da entrada aumenta. Isso nos permite comparar algoritmos de forma independente do ambiente e escolher o mais adequado para cada problema.

---

## Definição formal e simplificada sobre o que é Big O

> "A notação Big O é uma notação matemática que descreve o comportamento limitante de uma função quando o argumento tende a um valor específico ou ao infinito." — [Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)

Em termos práticos, Big O descreve a **complexidade** do seu algoritmo usando expressões algébricas.

Imagine um algoritmo cujo tempo de execução pode ser descrito por `f(n) = 3n² + 2n + 1`. À medida que `n` cresce, o termo `3n²` passa a dominar completamente os demais. A notação Big O nos permite simplificar essa expressão para `O(n²)`, ignorando constantes e termos de menor ordem.

Outro exemplo: um algoritmo que percorre todos os elementos de uma lista tem complexidade `O(n)`, pois o tempo cresce linearmente com o número de elementos.

### Conceito de comportamento assintótico

O comportamento assintótico descreve como um algoritmo se comporta à medida que o tamanho da entrada (`n`) tende ao infinito. O foco está no termo de maior crescimento — constantes e termos menores são descartados, pois se tornam irrelevantes para entradas muito grandes.

---

## Complexidades mais comuns

1. **O(1)** — Tempo constante
2. **O(log n)** — Tempo logarítmico
3. **O(n)** — Tempo linear
4. **O(n log n)** — Tempo linear-logarítmico
5. **O(n²)** — Tempo quadrático
6. **O(2ⁿ) e O(n!)** — Os casos a evitar

---

## Como calcular o Big O de um algoritmo?

Para determinar a complexidade de um algoritmo, siga estes passos:

1. **Identifique as operações básicas**: Foque nas operações mais custosas em termos de tempo, como loops, chamadas recursivas e buscas.
2. **Expresse o tempo como função de `n`**: Escreva uma função matemática que represente o tempo de execução em relação ao tamanho da entrada.
3. **Simplifique usando as regras do Big O**: Elimine constantes e termos de menor ordem.

### Regras básicas de cálculo

- **Ignore constantes**: `O(3n)` → `O(n)`
- **Ignore termos menores**: `O(n² + n)` → `O(n²)`
- **Loops aninhados multiplicam**: um loop dentro de outro resulta em `O(n²)`
- **Loops sequenciais somam**: dois loops um após o outro resultam em `O(n + n)` → `O(n)`

### Ignorando constantes e termos menores

O motivo para ignorar constantes é que, para entradas muito grandes, elas pouco influenciam o comportamento geral. O que importa é a **taxa de crescimento**: `O(n²)` sempre superará `O(n)` para valores suficientemente grandes de `n`, independentemente das constantes envolvidas.

### Exemplos práticos passo a passo

**Exemplo 1 — Soma de elementos de uma lista:**

```python
def sum_list(lst):
    total = 0
    for num in lst:
        total += num
    return total
```

1. A operação principal é o loop `for`, que executa uma vez para cada elemento.
2. Tempo de execução: `f(n) = c * n`, onde `c` é o custo de cada iteração.
3. Eliminando a constante: **O(n)**.

**Exemplo 2 — Busca em matriz quadrada:**

```python
def search_matrix(matrix, target):
    for row in matrix:
        for cell in row:
            if cell == target:
                return True
    return False
```

1. Há dois loops aninhados, cada um percorrendo `n` elementos.
2. Tempo de execução: `f(n) = n * n = n²`.
3. Resultado: **O(n²)**.

---

## Complexidade de Tempo vs. Complexidade de Espaço

A **complexidade de tempo** descreve como o número de operações cresce em função do tamanho da entrada. O tempo não é medido em segundos, mas em taxa de crescimento de operações.

A **complexidade de espaço** mede a quantidade de memória que o algoritmo consome em relação à entrada. Isso inclui variáveis temporárias, estruturas de dados auxiliares e a pilha de chamadas em casos de recursão.

Na prática, existe um trade-off frequente entre as duas: algoritmos mais rápidos tendem a consumir mais memória, enquanto algoritmos com baixo uso de memória costumam ser mais lentos. A complexidade de tempo geralmente recebe mais atenção, mas a de espaço é crítica em sistemas embarcados ou no processamento de grandes volumes de dados.

---

## Como usar esse conhecimento no dia a dia

Conhecer Big O não é apenas teoria — é uma habilidade prática que melhora a qualidade das suas decisões de desenvolvimento:

- **Antes de escolher uma estrutura de dados**, pergunte-se qual operação será mais frequente (inserção, busca, remoção) e escolha a estrutura com menor complexidade para essa operação. Um `set` tem busca `O(1)`, enquanto uma lista tem `O(n)`.

- **Ao revisar código em pull requests**, identifique loops aninhados desnecessários ou operações caras dentro de laços. Um `.find()` dentro de um `for` transforma um algoritmo `O(n)` em `O(n²)` sem que o autor perceba.

- **Ao lidar com grande volume de dados**, teste seu algoritmo com entradas de tamanhos diferentes (100, 10.000, 1.000.000) e observe se o tempo de resposta cresce de forma aceitável. Isso revela gargalos antes de chegarem à produção.

- **Em entrevistas técnicas**, articule a complexidade da sua solução explicitamente. Isso demonstra maturidade técnica e capacidade de raciocínio sobre escalabilidade.

- **Ao otimizar**, priorize reduzir a complexidade assintótica antes de micro-otimizações. Trocar um `O(n²)` por `O(n log n)` tem impacto muito maior do que qualquer ajuste de constantes.

---
