#ifndef FILA_H
#include <stdio.h>
#define FILA_H
#define TAMANHO_FILA 6
typedef struct {
    int inicio;
    int fim;
    int valores[TAMANHO_FILA];
    int tamanho;
    
} fila;
fila CriaFila();
int verifica(fila );
int enqueue(fila, int);
int dequeue(fila, int);
#endif
