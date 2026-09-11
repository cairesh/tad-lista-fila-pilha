#include <stdio.h>
#include "pilha.h"

Pilha criarPilha(void) {
    Pilha pilha;
    int i;
    pilha.topo = -1;
    for (i = 0; i < TAMANHO_PILHA; i++) {
        pilha.dados[i] = 0;
    }
    return pilha;
}

int pilhaVazia(Pilha pilha) {
    return pilha.topo == -1;
}

int pilhaCheia(Pilha pilha) {
    return pilha.topo == TAMANHO_PILHA - 1;
}

Pilha push(Pilha pilha, int valor) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia.\n");
        return pilha;
    }
    pilha.topo++;
    pilha.dados[pilha.topo] = valor;
    return pilha;
}

Pilha pop(Pilha pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return pilha;
    }
    pilha.dados[pilha.topo] = 0;
    pilha.topo--;
    return pilha;
}

int topoPilha(Pilha pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return -1;
    }
    return pilha.dados[pilha.topo];
}

void exibirPilha(Pilha pilha) {
    int i;
    printf("Pilha: ");
    if (pilhaVazia(pilha)) {
        printf("vazia");
    } else {
        for (i = pilha.topo; i >= 0; i--) {
            printf("%d ", pilha.dados[i]);
        }
    }
    printf("\n");
}
