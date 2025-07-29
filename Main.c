#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

const char *cidades[] = {
    "Corrente", "Gilbués", "Bom Jesus", "Floriano", "Oeiras",
    "Teresina", "Campo Maior", "Piripiri", "Luís Correia", "Parnaíba"
};

// Estrutura para lista de adjacência
typedef struct Node {
    int destino;
    struct Node* prox;
} Node;

Node* grafo[MAX]; // Lista 

// Cria um novo nó
Node* novoNo(int destino) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->destino = destino;
    no->prox = NULL;
    return no;
}

// Adiciona uma aresta direcionada
void GRAPHinsertArc(int origem, int destino) {
    Node* no = novoNo(destino);
    no->prox = grafo[origem];
    grafo[origem] = no;
}
// Imprime o grafo
void imprimirGrafo() {
    printf("Mapa de conexões:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%s → ", cidades[i]);
        Node* temp = grafo[i];
        while (temp) {
            printf("%s ", cidades[temp->destino]);
            temp = temp->prox;
        }
        printf("\n");
    }
}

// Variáveis globais para caminhos
int caminhoAtual[MAX], melhorCaminho[MAX], piorCaminho[MAX];
int numCaminhos = 0, tamMin = MAX, tamMax = 0;

// DFS para encontrar todos os caminhos possíveis
void DFS(int atual, int destino, int visitado[], int nivel) {
    visitado[atual] = 1;
    caminhoAtual[nivel] = atual;

    if (atual == destino) {
        numCaminhos++;
        printf("Caminho %d: ", numCaminhos);
        for (int i = 0; i <= nivel; i++)
            printf("%s%s", cidades[caminhoAtual[i]], (i == nivel) ? "\n" : " → ");

        // Atualiza caminho mais curto
        if (nivel < tamMin) {
            tamMin = nivel;
            memcpy(melhorCaminho, caminhoAtual, sizeof(int) * (nivel + 1));
        }
        // Atualiza caminho mais longo
        if (nivel > tamMax) {
            tamMax = nivel;
            memcpy(piorCaminho, caminhoAtual, sizeof(int) * (nivel + 1));
        }
    } else {
        Node* temp = grafo[atual];
        while (temp) {
            if (!visitado[temp->destino])
                DFS(temp->destino, destino, visitado, nivel + 1);
            temp = temp->prox;
        }
    }
    visitado[atual] = 0; // backtracking
}

void mostrarResumo() {
    printf("\nResumo:\n");
    printf("Total de caminhos encontrados: %d\n", numCaminhos);
    printf("Caminho mais curto (%d conexões): ", tamMin);
    for (int i = 0; i <= tamMin; i++)
        printf("%s%s", cidades[melhorCaminho[i]], (i == tamMin) ? "\n" : " → ");
    printf("Caminho mais longo (%d conexões): ", tamMax);
    for (int i = 0; i <= tamMax; i++)
        printf("%s%s", cidades[piorCaminho[i]], (i == tamMax) ? "\n" : " → ");
}

int main() {
    // Inicia o grafo
    for (int i = 0; i < MAX; i++)
        grafo[i] = NULL;

    // Inserção das conexões
    GRAPHinsertArc(0, 1); // Corrente p/ Gilbués
    GRAPHinsertArc(1, 2); // Gilbués p/ Bom Jesus
    GRAPHinsertArc(2, 3); // Bom Jesus p/ Floriano
    GRAPHinsertArc(3, 4); // Floriano p/ Oeiras
    GRAPHinsertArc(4, 5); // Oeiras p/ Teresina
    GRAPHinsertArc(5, 6); // Teresina p/ Campo Maior
    GRAPHinsertArc(6, 7); // Campo Maior p/ Piripiri
    GRAPHinsertArc(7, 8); // Piripiri p/ Luís Correia
    GRAPHinsertArc(8, 9); // Luís Correia p/ Parnaíba
    GRAPHinsertArc(5, 9); // Teresina p/ Parnaíba (alternativa)
    GRAPHinsertArc(2, 5); // Bom Jesus p/ Teresina (alternativa)

    imprimirGrafo();

    int visitado[MAX] = {0};
    printf("\nTodos os caminhos de Corrente até Parnaíba:\n");
    DFS(0, 9, visitado, 0);

    mostrarResumo();

    return 0;
}
