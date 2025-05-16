#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "arvore.h"

No* novo_no_valor(int valor) {
    No* no = malloc(sizeof(No));
    no->eh_operador = false;
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

No* novo_no_operador(char operador, No* esq, No* dir) {
    No* no = malloc(sizeof(No));
    no->eh_operador = true;
    no->operador = operador;
    no->esquerda = esq;
    no->direita = dir;
    return no;
}

int ler_numero(char** expr) {
    int num = 0;
    while (isdigit(**expr)) {
        num = num * 10 + (**expr - '0');
        (*expr)++;
    }
    return num;
}

No* construir_arvore(char** expr) {
    while (**expr == ' ') (*expr)++;

    if (isdigit(**expr)) {
        int num = ler_numero(expr);
        return novo_no_valor(num);
    }

    if (**expr == '(') {
        (*expr)++;  // pula '('
        No* esq = construir_arvore(expr);
        while (**expr == ' ') (*expr)++;
        char op = **expr;
        (*expr)++;  // pula operador
        No* dir = construir_arvore(expr);
        while (**expr != ')' && **expr != '\0') (*expr)++;
        if (**expr == ')') (*expr)++;
        return novo_no_operador(op, esq, dir);
    }

    return NULL;
}

void imprimir_pos_ordem(No* raiz) {
    if (raiz == NULL) return;

    imprimir_pos_ordem(raiz->esquerda);
    imprimir_pos_ordem(raiz->direita);
    if (raiz->eh_operador)
        printf("%c ", raiz->operador);
    else
        printf("%d ", raiz->valor);
}

int avaliar_arvore(No* raiz) {
    if (!raiz->eh_operador)
        return raiz->valor;

    int esq = avaliar_arvore(raiz->esquerda);
    int dir = avaliar_arvore(raiz->direita);

    switch (raiz->operador) {
        case '+': return esq + dir;
        case '-': return esq - dir;
        case '*': return esq * dir;
        case '/': return esq / dir;
    }

    return 0;
}

void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}
