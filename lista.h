#ifndef LISTA_H
#define LISTA_H
#define TAMANHO_LISTA 5
typedef struct {
    int dados[TAMANHO_LISTA];
    int quantidade;
} Lista;
Lista criarLista(void);
int buscarLista(Lista lista, int valor);
Lista inserirLista(Lista lista, int valor);
Lista removerLista(Lista lista, int valor);
int listaVazia(Lista lista);
int listaCheia(Lista lista);
void exibirLista(Lista lista);
#endif
