#include <stdio.h>
#include "fila.h"

Fila criarFila(void) {
    Fila fila = {{0}, 0, 0, 0};
    return fila;
}

int filaVazia(Fila fila) {
    return fila.quantidade == 0;
}

int filaCheia(Fila fila) {
    return fila.quantidade == TAMANHO_FILA;
}

Fila enqueue(Fila fila, int valor) {
    if (filaCheia(fila)) {
        printf("Erro: fila cheia.\n");
        return fila;
    }
    fila.dados[fila.fim] = valor;
    fila.fim = (fila.fim + 1) % TAMANHO_FILA;
    fila.quantidade++;
    return fila;
}

Fila dequeue(Fila fila) {
    if (filaVazia(fila)) {
        printf("Erro: fila vazia.\n");
        return fila;
    }
    fila.dados[fila.inicio] = 0;
    fila.inicio = (fila.inicio + 1) % TAMANHO_FILA;
    fila.quantidade--;
    return fila;
}

int frenteFila(Fila fila) {
    if (filaVazia(fila)) {
        printf("Erro: fila vazia.\n");
        return -1;
    }
    return fila.dados[fila.inicio];
}

void exibirFila(Fila fila) {
    int i;
    printf("[");
    for (i = 0; i < fila.quantidade; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", fila.dados[(fila.inicio + i) % TAMANHO_FILA]);
    }
    printf("]\n");
}
