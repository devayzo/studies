#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista {
    int ra;
    char nome[30], curso[50], email[50];
    struct Lista *prox;
}; struct Lista *aux, *inicio=NULL, *final=NULL;
// função para criar a lista

struct Lista *cria(void) {
    return NULL;
}

struct Lista *insere() {
    aux*(struct Lista*)malloc(sizeof(struct Lista));
    printf("\nEntre com o RA do aluno: ");
    scanf("%d", &aux->ra);
    printf("\nEntre com o nome do aluno: ");
    getchar();
    fgets(aux->nome,50,stdin);
    printf("\nEntre com o curso do aluno: ");
    getchar();
    fgets(aux->curso,50,stdin);
    printf("\nEntre com o e-mail do aluno: ");
    getchar();
    fgets(aux->email,50,stdin);
    aux->prox = (struct Lista *)NULL;
    if (inicio == NULL) {
        inicio = final = aux;
    }

    else {
        final->prox = aux;
        final = aux;
    }
    
    return inicio;

    int lista_vazia(struct Lista *lista) {
        if (lista == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }

    void visualiza_lista(struct Lista *lista) {
        if (!lista_vazia(lista)) {
            aux = lista;
            while (aux != (struct Lista *)NULL) {
                printf("\nRA: %d", aux->ra);
                printf("\nNome: %s", aux->nome);
                printf("\nCurso: %s", aux->curso);
                printf("\nE-mail: %s", aux->email);
                aux = aux->prox;
            }
        }
        else {
            printf("\nLista vazia!!!");
        }
    }
}

struct Lista *busca(struct Lista *lista, int busca) {
    int achou = 0;
    if (!lista_vazia(lista)) {
        for (aux = lista; aux != NULL; aux->prox) {
            if (aux->ra == busca) {
                printf("\nAluno encontrado:");
                printf("\nRA: %d", aux->ra);
                printf("\nNome: %s", aux->nome);
                printf("\nCurso: %s", aux->curso);
                printf("\nE-mail: %s", aux->email);
                achou = 1;
            }
        }
        if (!achou) {
            printf("\nAluno não encontrado.");
        }
        
        else {
            printf("\nTentou buscar de uma lista vazia.");
        }
    }
}