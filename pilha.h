#ifndef PILHA_H
#define PILHA_H
#define TAMANHO_PILHA 5

typedef struct {
    int dados[TAMANHO_PILHA];
    int topo;
} Pilha;

Pilha criarPilha(void);
Pilha push(Pilha pilha, int valor);
Pilha pop(Pilha pilha);
int pilhaVazia(Pilha pilha);
int pilhaCheia(Pilha pilha);
void exibirPilha(Pilha pilha);

#endif
