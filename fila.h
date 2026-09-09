#ifndef FILA_H
#define FILA_H
#define TAMANHO_FILA 5
typedef struct {
    int inicio;
    int fim;
    int tamanho;
    int itens[TAMANHO_FILA];
} fila;
fila CriaFila(void);
/* A lista que será criada será uma lista circular, deverá ser tratado erros tipo underflow 
e underflow, também irá indicar se está vazia ou cheia, caso desejar adicionar outro elemento após 
estar cheia perguntar se gostaria de substituir o primeiro elemento e tornar o segundo elemento o primeiro
(fez sentido isso?)*/
#endif
