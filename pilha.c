#include <stdio.h>
#include "pilha.h"

void inicializar_pilha(Pilha* p) {
    p->topo = -1;
}

void empilhar(Pilha* p, No* valor) {
    if (p->topo < TAM_MAX - 1) {
        p->itens[++(p->topo)] = valor;
    }
}

No* desempilhar(Pilha* p) {
    if (p->topo >= 0) {
        return p->itens[(p->topo)--];
    }
    return NULL;
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}
