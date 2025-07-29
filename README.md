# Projeto de Rotas entre Cidades do Piauí com Grafos em C

Este projeto modela o percurso entre cidades do estado do **Piauí**, simulando uma jornada do viajante de **Corrente até Parnaíba** por meio de um **grafo direcionado**. Ele foi desenvolvido com foco **educacional**, para reforçar os conceitos de grafos, busca em profundidade (DFS), caminhos e estrutura de dados em C.

---

## Objetivos

O programa tem como objetivo:

- Representar as **cidades como vértices** de um grafo;
- Representar as **estradas como arestas direcionadas**;
- Imprimir a estrutura do grafo (conexões entre cidades);
- **Encontrar e exibir todos os caminhos possíveis** de Corrente a Parnaíba;
- Indicar o **caminho mais curto** (menor número de passos);
- Indicar o **caminho mais longo** (maior número de passos).

---

## Lógica por Trás do Código

### Representação do Grafo
O grafo é representado por uma **lista de adjacência**. Cada índice do vetor principal corresponde a uma cidade, e aponta para uma lista encadeada que contém os destinos acessíveis diretamente a partir dessa cidade (ou seja, suas conexões).

Isso foi escolhido porque:
- A lista de adjacência é eficiente para grafos esparsos (com poucas conexões em relação ao número total de vértices);
- Ela permite percorrer rapidamente todas as conexões de uma cidade;
- É simples de implementar em C com ponteiros e listas encadeadas.

###  Exploração de Caminhos: DFS + Backtracking

A lógica principal de exploração é feita com um algoritmo de **Busca em Profundidade (DFS)** recursiva, que visita todas as rotas possíveis partindo da cidade de origem (Corrente) até o destino (Parnaíba).

Durante o percurso, o algoritmo:

1. Marca o vértice atual como visitado;
2. Adiciona esse vértice ao caminho atual;
3. Se o vértice atual for o destino:
   - Imprime o caminho;
   - Verifica se ele é o mais curto ou mais longo encontrado até o momento e o armazena.
4. Se ainda não for o destino:
   - Chama a DFS recursivamente para cada vizinho não visitado;
5. Ao terminar de explorar todas as possibilidades a partir de um vértice:
   - Ele o **desmarca como visitado** para permitir que ele seja usado em outras rotas (técnica de **backtracking**).

Essa abordagem garante:
- Exploração de **todos os caminhos possíveis**, mesmo que envolvam desvios;
- Armazenamento do **menor e maior caminho** com base no número de passos (arestas);
- Evita ciclos ou repetições indevidas, respeitando a natureza direcionada do grafo.

### Armazenamento Temporário dos Caminhos
Durante a execução da DFS:

- Um vetor `caminhoAtual[]` guarda o caminho atual em construção;
- Variáveis `tamMin` e `tamMax` guardam os tamanhos dos caminhos extremos (curto e longo);
- Quando o destino é alcançado, `memcpy` copia o caminho para os vetores `melhorCaminho[]` ou `piorCaminho[]`, se necessário.

---

## Representação das Cidades

As cidades foram codificadas por índices de 0 a 9:

| Índice | Cidade         |
|--------|----------------|
| 0      | Corrente       |
| 1      | Gilbués        |
| 2      | Bom Jesus      |
| 3      | Floriano       |
| 4      | Oeiras         |
| 5      | Teresina       |
| 6      | Campo Maior    |
| 7      | Piripiri       |
| 8      | Luís Correia   |
| 9      | Parnaíba       |

---

##Conexões entre as Cidades (Arestas)

O grafo foi construído com as seguintes conexões direcionadas:

- Corrente → Gilbués  
- Gilbués → Bom Jesus  
- Bom Jesus → Floriano  
- Floriano → Oeiras  
- Oeiras → Teresina  
- Teresina → Campo Maior  
- Campo Maior → Piripiri  
- Piripiri → Luís Correia  
- Luís Correia → Parnaíba  
- **Teresina → Parnaíba** (rota alternativa)  
- **Bom Jesus → Teresina** (rota alternativa)

---

## Algoritmos Utilizados

### DFS Recursiva (Busca em Profundidade)

Usada para:
- Encontrar todos os caminhos possíveis entre Corrente e Parnaíba;
- Determinar o caminho mais curto (menor profundidade) e o mais longo (maior profundidade).

### Backtracking

Permite "voltar atrás" nas decisões e explorar todos os caminhos possíveis. Isso é feito desmarcando as cidades visitadas ao retornar de chamadas recursivas.

---

## Saída do Programa

1. Lista de conexões entre as cidades;
2. Todos os caminhos possíveis de Corrente até Parnaíba;
3. Resumo com:
   - Total de caminhos encontrados;
   - Caminho mais curto;
   - Caminho mais longo.

