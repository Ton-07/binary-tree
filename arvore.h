#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

typedef struct No {
    bool eh_operador;
    union {
        int valor;
        char operador;
    };
    struct No* esquerda;
    struct No* direita;
} No;

No* novo_no_valor(int valor);
No* novo_no_operador(char operador, No* esq, No* dir);
No* construir_arvore(char** expr);
void imprimir_pos_ordem(No* raiz);
int avaliar_arvore(No* raiz);
void liberar_arvore(No* raiz);

#endif
