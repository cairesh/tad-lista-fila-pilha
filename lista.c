#include <stdio.h>
#include "lista.h"

Lista criarLista(void) {
    Lista lista = {{0}, 0};
    return lista;
}

int buscarLista(Lista lista, int valor) {
    int i;
    for (i = 0; i < lista.quantidade; i++) {
        if (lista.dados[i] == valor) {
            return i;
        }
    }
    return -1;
}

int listaVazia(Lista lista) {
    return lista.quantidade == 0;
}

int listaCheia(Lista lista) {
    return lista.quantidade == TAMANHO_LISTA;
}

Lista inserirLista(Lista lista, int valor) {
    int indice = buscarLista(lista, valor);
    if (indice != -1) {
        printf("Elemento ja existe na lista.\n");
    } else if (listaCheia(lista)) {
        printf("Lista cheia.\n");
    } else {
        lista.dados[lista.quantidade] = valor;
        lista.quantidade++;
    }
    return lista;
}

Lista removerLista(Lista lista, int valor) {
    int indice = buscarLista(lista, valor);
    int i;
    if (indice == -1) {
        printf("Elemento nao existe na lista.\n");
    } else {
        for (i = indice; i < lista.quantidade - 1; i++) {
            lista.dados[i] = lista.dados[i + 1];
        }
        lista.quantidade--;
        lista.dados[lista.quantidade] = 0;
    }
    return lista;
}

void exibirLista(Lista lista) {
    int i;
    printf("[");
    for (i = 0; i < lista.quantidade; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", lista.dados[i]);
    }
    printf("]\n");
}
