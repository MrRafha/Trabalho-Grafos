# 🗺️ Projeto de Rotas entre Cidades do Piauí com Grafos em C

Este projeto modela o percurso entre cidades do estado do **Piauí**, simulando uma jornada do viajante de **Corrente até Parnaíba** por meio de um **grafo direcionado**. Ele foi desenvolvido com foco **educacional**, para reforçar os conceitos de grafos, busca em profundidade (DFS), caminhos e estrutura de dados em C.

## 📌 Objetivos

O programa tem como objetivo:

- Representar as **cidades como vértices** de um grafo;
- Representar as **estradas como arestas direcionadas**;
- Imprimir a estrutura do grafo (conexões entre cidades);
- **Encontrar e exibir todos os caminhos possíveis** de Corrente a Parnaíba;
- Indicar o **caminho mais curto** (menor número de passos);
- Indicar o **caminho mais longo** (maior número de passos).

---

## 🏙️ Representação das Cidades

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

## 🔗 Conexões entre as Cidades (Arestas)

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

## ⚙️ Estrutura de Dados Utilizada

Foi utilizada uma **lista de adjacência**, onde cada vértice possui uma lista ligada apontando para seus vizinhos. Esta estrutura é ideal para grafos esparsos e permite inserções e percursos eficientes.

```
