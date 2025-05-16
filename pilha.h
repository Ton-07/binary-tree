#ifndef PILHA_H
#define PILHA_H

#include "arvore.h"

#define TAM_MAX 100

typedef struct {
    No* itens[TAM_MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha* p);
void empilhar(Pilha* p, No* valor);
No* desempilhar(Pilha* p);
int pilha_vazia(Pilha* p);

#endif