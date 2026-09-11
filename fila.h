#ifndef FILA_H
#define FILA_H
#define TAMANHO_FILA 5

typedef struct {
    int dados[TAMANHO_FILA];
    int inicio;
    int fim; /* Proxima posicao de insercao. */
    int quantidade;
} Fila;

Fila criarFila(void);
Fila enqueue(Fila fila, int valor);
Fila dequeue(Fila fila);
int filaVazia(Fila fila);
int filaCheia(Fila fila);
/* Verifique filaVazia antes: -1 tambem pode ser um dado valido. */
int frenteFila(Fila fila);
void exibirFila(Fila fila);

#endif
