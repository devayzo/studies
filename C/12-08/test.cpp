#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor[5], tamanho, inicio;
}; struct lista lista;

void inserefinal() {
    int x;
    if (lista.tamanho == 5) {
        printf("\nLista cheia!");
    }
    else {
        printf("Digite um valor: ");
        scanf("%d", &x);
        lista.valor[lista.tamanho] = x;
        lista.tamanho++;
        printf("Elemento %d inserido na lista.", x);
    }
}

void removefinal() {
    int removido;
    if (lista.tamanho == 0) {
        printf("\nNão dá para remover de uma lista vazia!");
    }

    else {
        lista.tamanho--;
        removido = lista.valor[lista.tamanho];
        printf("\nElemento %d removido.", removido);
    }
}

void imprime() {
    int v, i;
    i = lista.inicio;
    while (i != lista.tamanho) {
        v = lista.valor[i];
        printf("\nElemento %d da lista: %d", i, v);
        i++;
    }
}

void busca() {
	int vbusca, i;
	printf("Entre com o valor que deseja buscar: ");
	scanf("%i", &vbusca);
	if (vbusca == lista.valor[i]) {
		printf("Valor %d encontrado na posição %d", vbusca, i);
		i++;
	}
}

int main() {
    int op;
    while (op != 4) {
        printf("\nLista estatica!\n");
        printf("Digite 1 para inserir final\n");
        printf("Digite 2 para remover final\n");
        printf("Digite 3 para imprimir lista\n");
        printf("Digite 4 para buscar\n");
        printf("Digite 5 para encerrar programa\n");
        printf("Entre com a opcao: ");
        scanf("%i", &op);
        switch(op) {
            case 1: inserefinal(); break;
            case 2: removefinal(); break;
            case 3: imprime(); break;
            case 4: busca(); break;
            case 5: exit(1);
            default: printf("\nOpcao invalida!!!");
        }
    }
}
