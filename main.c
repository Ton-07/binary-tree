#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main() {
    char expressao[256];
    printf("Digite a expressao:");
    fgets(expressao, sizeof(expressao), stdin);

    // Remover a quebra de linha ao final
    expressao[strcspn(expressao, "\n")] = '\0';

    char* ptr = expressao;
    No* raiz = construir_arvore(&ptr);

    printf("Expressao em pos-ordem: ");
    imprimir_pos_ordem(raiz);
    printf("\n");

    int resultado = avaliar_arvore(raiz);
    printf("Resultado da expressao: %d\n", resultado);

    liberar_arvore(raiz);
    return 0;
}
