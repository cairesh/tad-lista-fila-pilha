#include <stdio.h>
#include "TADs.h"

/* Confere conteudo, quantidade, indices e estados apos cada operacao. */
int conferirLista(Lista lista, int quantidade, int a, int b, int c, int d, int e) {
    int esperado[TAMANHO_LISTA] = {a, b, c, d, e};
    int i;
    exibirLista(lista);
    if (lista.quantidade != quantidade || lista.quantidade < 0 ||
        lista.quantidade > TAMANHO_LISTA) {
        printf("FALHA: quantidade incorreta.\n");
        return 1;
    }
    if (listaVazia(lista) != (quantidade == 0) ||
        listaCheia(lista) != (quantidade == TAMANHO_LISTA)) {
        printf("FALHA: estado vazia/cheia incorreto.\n");
        return 1;
    }
    for (i = 0; i < quantidade; i++) {
        if (lista.dados[i] != esperado[i] || buscarLista(lista, esperado[i]) != i) {
            printf("FALHA: valor ou indice incorreto na posicao %d.\n", i);
            return 1;
        }
    }
    return 0;
}

int conferirBusca(Lista lista, int valor, int esperado) {
    int indice = buscarLista(lista, valor);
    printf("Busca de %d: indice %d (esperado %d).\n", valor, indice, esperado);
    return indice != esperado;
}

int main(void) {
    Lista lista = criarLista();
    int falhas = 0;

    printf("===== TESTES DA LISTA =====\nLista inicial:\n");
    falhas += conferirLista(lista, 0, 0, 0, 0, 0, 0);
    falhas += conferirBusca(lista, 10, -1);
    falhas += conferirBusca(lista, 0, -1);

    printf("Inserindo primeiro elemento: 10...\n");
    lista = inserirLista(lista, 10);
    falhas += conferirLista(lista, 1, 10, 0, 0, 0, 0);

    printf("Inserindo 20: 20...\n");
    lista = inserirLista(lista, 20);
    falhas += conferirLista(lista, 2, 10, 20, 0, 0, 0);
    falhas += conferirBusca(lista, 20, 1);
    falhas += conferirBusca(lista, 99, -1);

    printf("Tentando repetir 20: 20...\n");
    lista = inserirLista(lista, 20);
    falhas += conferirLista(lista, 2, 10, 20, 0, 0, 0);
    falhas += conferirBusca(lista, 20, 1);
    falhas += conferirBusca(lista, 99, -1);

    printf("Inserindo 30: 30...\n");
    lista = inserirLista(lista, 30);
    falhas += conferirLista(lista, 3, 10, 20, 30, 0, 0);

    printf("Removendo do meio: 20...\n");
    lista = removerLista(lista, 20);
    falhas += conferirLista(lista, 2, 10, 30, 0, 0, 0);
    falhas += conferirBusca(lista, 20, -1);

    printf("Inserindo depois de remover: 40...\n");
    lista = inserirLista(lista, 40);
    falhas += conferirLista(lista, 3, 10, 30, 40, 0, 0);

    printf("Inserindo 50: 50...\n");
    lista = inserirLista(lista, 50);
    falhas += conferirLista(lista, 4, 10, 30, 40, 50, 0);

    printf("Preenchendo capacidade 5: 60...\n");
    lista = inserirLista(lista, 60);
    falhas += conferirLista(lista, 5, 10, 30, 40, 50, 60);

    printf("Tentando sexto elemento: 70...\n");
    lista = inserirLista(lista, 70);
    falhas += conferirLista(lista, 5, 10, 30, 40, 50, 60);
    falhas += conferirBusca(lista, 70, -1);

    printf("Tentando repetido na lista cheia: 10...\n");
    lista = inserirLista(lista, 10);
    falhas += conferirLista(lista, 5, 10, 30, 40, 50, 60);

    printf("Removendo do inicio: 10...\n");
    lista = removerLista(lista, 10);
    falhas += conferirLista(lista, 4, 30, 40, 50, 60, 0);
    falhas += conferirBusca(lista, 10, -1);

    printf("Removendo do meio: 40...\n");
    lista = removerLista(lista, 40);
    falhas += conferirLista(lista, 3, 30, 50, 60, 0, 0);
    falhas += conferirBusca(lista, 40, -1);

    printf("Removendo do final: 60...\n");
    lista = removerLista(lista, 60);
    falhas += conferirLista(lista, 2, 30, 50, 0, 0, 0);
    falhas += conferirBusca(lista, 60, -1);

    printf("Inserindo zero como dado valido: 0...\n");
    lista = inserirLista(lista, 0);
    falhas += conferirLista(lista, 3, 30, 50, 0, 0, 0);

    printf("Tentando remover inexistente: 999...\n");
    lista = removerLista(lista, 999);
    falhas += conferirLista(lista, 3, 30, 50, 0, 0, 0);
    falhas += conferirBusca(lista, 999, -1);

    printf("Removendo 30: 30...\n");
    lista = removerLista(lista, 30);
    falhas += conferirLista(lista, 2, 50, 0, 0, 0, 0);
    falhas += conferirBusca(lista, 30, -1);

    printf("Removendo 50: 50...\n");
    lista = removerLista(lista, 50);
    falhas += conferirLista(lista, 1, 0, 0, 0, 0, 0);
    falhas += conferirBusca(lista, 50, -1);

    printf("Removendo ultimo elemento: 0...\n");
    lista = removerLista(lista, 0);
    falhas += conferirLista(lista, 0, 0, 0, 0, 0, 0);
    falhas += conferirBusca(lista, 0, -1);

    printf("Tentando remover da lista vazia: 0...\n");
    lista = removerLista(lista, 0);
    falhas += conferirLista(lista, 0, 0, 0, 0, 0, 0);
    falhas += conferirBusca(lista, 0, -1);

    printf("\n===== TESTES DA FILA =====\n");
    /* TODO: integrante responsavel: pelo menos 6 enqueue e 6 dequeue
       intercalados; conferir FIFO, circularidade, overflow e underflow. */
    printf("TODO: integrante responsavel.\n");
    
    printf("\n===== TESTES DA PILHA =====\n");

    Pilha pilha = criarPilha();

    printf("Pilha inicial:\n");
    exibirPilha(pilha);

    printf("Vazia? %d\n", pilhaVazia(pilha));
    printf("Cheia? %d\n", pilhaCheia(pilha));

    printf("\nPush 10...\n");
    pilha = push(pilha, 10);
    exibirPilha(pilha);

    printf("\nPush 20...\n");
    pilha = push(pilha, 20);
    exibirPilha(pilha);

    printf("\nPush 30...\n");
    pilha = push(pilha, 30);
    exibirPilha(pilha);

    printf("\nTopo esperado: 30\n");
    printf("Topo encontrado: %d\n", topoPilha(pilha));

    printf("\nPop...\n");
    pilha = pop(pilha);
    exibirPilha(pilha);

    printf("Topo esperado: 20\n");
    printf("Topo encontrado: %d\n", topoPilha(pilha));

    printf("\nPush 40...\n");
    pilha = push(pilha, 40);

    printf("Push 50...\n");
    pilha = push(pilha, 50);

    printf("Push 60...\n");
    pilha = push(pilha, 60);

    printf("Push 70 para preencher...\n");
    pilha = push(pilha, 70);

    exibirPilha(pilha);

    printf("\nTentando overflow com 80...\n");
    pilha = push(pilha, 80);
    exibirPilha(pilha);

    printf("\nRemovendo elementos:\n");

    pilha = pop(pilha);
    exibirPilha(pilha);

    pilha = pop(pilha);
    exibirPilha(pilha);

    pilha = pop(pilha);
    exibirPilha(pilha);

    pilha = pop(pilha);
    exibirPilha(pilha);

    pilha = pop(pilha);
    exibirPilha(pilha);

    printf("\nTentando underflow:\n");
    pilha = pop(pilha);

    printf("Vazia? %d\n", pilhaVazia(pilha));

    printf("\nResultado da Lista: %d falha(s).\n", falhas);
    return falhas == 0 ? 0 : 1;
}
