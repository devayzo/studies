#include "biblioteca.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    char codigo[TAM_CODIGO];
    char editora[TAM_EDITORA];
    int ano;
    int emprestado;
} LivroArquivo;

static void ler_texto(const char *mensagem, char *destino, size_t tamanho) {
    int caractere;

    printf("%s", mensagem);
    if (fgets(destino, (int)tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    if (strchr(destino, '\n') == NULL) {
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
    }
    destino[strcspn(destino, "\n")] = '\0';
}

static int ler_inteiro(const char *mensagem) {
    char entrada[32];
    char *fim;
    long valor;

    for (;;) {
        ler_texto(mensagem, entrada, sizeof entrada);
        valor = strtol(entrada, &fim, 10);
        while (isspace((unsigned char)*fim)) {
            fim++;
        }
        if (entrada[0] != '\0' && *fim == '\0') {
            return (int)valor;
        }
        printf("Digite um número válido.\n");
    }
}

static int contem_ignore_case(const char *texto, const char *busca) {
    size_t i;
    size_t j;

    if (busca[0] == '\0') {
        return 1;
    }
    for (i = 0; texto[i] != '\0'; i++) {
        for (j = 0; busca[j] != '\0' && texto[i + j] != '\0'; j++) {
            if (tolower((unsigned char)texto[i + j]) !=
                tolower((unsigned char)busca[j])) {
                break;
            }
        }
        if (busca[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

static Livro *buscar_por_codigo(const Biblioteca *biblioteca, const char *codigo) {
    Livro *atual = biblioteca->inicio;

    while (atual != NULL) {
        if (strcmp(atual->codigo, codigo) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

static void mostrar_livro(const Livro *livro) {
    printf("\nCódigo: %s\nTítulo: %s\nAutor: %s\nEditora: %s\nAno: %d\nStatus: %s\n",
           livro->codigo, livro->titulo, livro->autor, livro->editora,
           livro->ano, livro->emprestado ? "Emprestado" : "Disponível");
}

static void preencher_livro(Livro *livro) {
    ler_texto("Título: ", livro->titulo, sizeof livro->titulo);
    ler_texto("Autor: ", livro->autor, sizeof livro->autor);
    ler_texto("Código/ISBN: ", livro->codigo, sizeof livro->codigo);
    ler_texto("Editora: ", livro->editora, sizeof livro->editora);
    livro->ano = ler_inteiro("Ano de publicação: ");
}

void biblioteca_inicializar(Biblioteca *biblioteca) {
    biblioteca->inicio = NULL;
}

int biblioteca_carregar(Biblioteca *biblioteca, const char *arquivo) {
    FILE *fp = fopen(arquivo, "rb");
    LivroArquivo salvo;
    Livro *novo;
    Livro **fim = &biblioteca->inicio;
    int quantidade = 0;

    if (fp == NULL) {
        return 0;
    }
    while (fread(&salvo, sizeof salvo, 1, fp) == 1) {
        novo = malloc(sizeof *novo);
        if (novo == NULL) {
            fclose(fp);
            return -1;
        }
        memcpy(novo->titulo, salvo.titulo, sizeof novo->titulo);
        memcpy(novo->autor, salvo.autor, sizeof novo->autor);
        memcpy(novo->codigo, salvo.codigo, sizeof novo->codigo);
        memcpy(novo->editora, salvo.editora, sizeof novo->editora);
        novo->ano = salvo.ano;
        novo->emprestado = salvo.emprestado;
        novo->prox = NULL;
        *fim = novo;
        fim = &novo->prox;
        quantidade++;
    }
    if (ferror(fp)) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return quantidade;
}

int biblioteca_salvar(const Biblioteca *biblioteca, const char *arquivo) {
    FILE *fp = fopen(arquivo, "wb");
    const Livro *atual = biblioteca->inicio;
    LivroArquivo salvo;

    if (fp == NULL) {
        return 0;
    }
    while (atual != NULL) {
        memcpy(salvo.titulo, atual->titulo, sizeof salvo.titulo);
        memcpy(salvo.autor, atual->autor, sizeof salvo.autor);
        memcpy(salvo.codigo, atual->codigo, sizeof salvo.codigo);
        memcpy(salvo.editora, atual->editora, sizeof salvo.editora);
        salvo.ano = atual->ano;
        salvo.emprestado = atual->emprestado;
        if (fwrite(&salvo, sizeof salvo, 1, fp) != 1) {
            fclose(fp);
            return 0;
        }
        atual = atual->prox;
    }
    if (fclose(fp) != 0) {
        return 0;
    }
    return 1;
}

void biblioteca_liberar(Biblioteca *biblioteca) {
    Livro *atual = biblioteca->inicio;

    while (atual != NULL) {
        Livro *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    biblioteca->inicio = NULL;
}

void cadastrar_livro(Biblioteca *biblioteca) {
    Livro *novo = malloc(sizeof *novo);

    if (novo == NULL) {
        printf("Não foi possível alocar memória.\n");
        return;
    }
    preencher_livro(novo);
    if (novo->codigo[0] == '\0' || buscar_por_codigo(biblioteca, novo->codigo) != NULL) {
        printf("Código vazio ou já cadastrado. Livro não incluído.\n");
        free(novo);
        return;
    }
    novo->emprestado = 0;
    novo->prox = biblioteca->inicio;
    biblioteca->inicio = novo;
    printf("Livro cadastrado com sucesso.\n");
}

void listar_livros(const Biblioteca *biblioteca) {
    const Livro *atual = biblioteca->inicio;

    if (atual == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    while (atual != NULL) {
        mostrar_livro(atual);
        atual = atual->prox;
    }
}

void consultar_livro(const Biblioteca *biblioteca) {
    char busca[100];
    const Livro *atual = biblioteca->inicio;
    int encontrados = 0;

    ler_texto("Buscar por título, autor ou código: ", busca, sizeof busca);
    while (atual != NULL) {
        if (contem_ignore_case(atual->titulo, busca) ||
            contem_ignore_case(atual->autor, busca) ||
            contem_ignore_case(atual->codigo, busca)) {
            mostrar_livro(atual);
            encontrados = 1;
        }
        atual = atual->prox;
    }
    if (!encontrados) {
        printf("Nenhum livro encontrado.\n");
    }
}

void editar_livro(Biblioteca *biblioteca) {
    char codigo[TAM_CODIGO];
    Livro *livro;
    char codigo_antigo[TAM_CODIGO];

    ler_texto("Código do livro a editar: ", codigo, sizeof codigo);
    livro = buscar_por_codigo(biblioteca, codigo);
    if (livro == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }
    strcpy(codigo_antigo, livro->codigo);
    preencher_livro(livro);
    if (livro->codigo[0] == '\0' ||
        (strcmp(codigo_antigo, livro->codigo) != 0 &&
         buscar_por_codigo(biblioteca, livro->codigo) != NULL)) {
        strcpy(livro->codigo, codigo_antigo);
        printf("Código vazio ou já cadastrado. Edição cancelada.\n");
        return;
    }
    printf("Livro editado com sucesso.\n");
}

void excluir_livro(Biblioteca *biblioteca) {
    char codigo[TAM_CODIGO];
    Livro **atual = &biblioteca->inicio;
    Livro *removido;

    ler_texto("Código do livro a excluir: ", codigo, sizeof codigo);
    while (*atual != NULL && strcmp((*atual)->codigo, codigo) != 0) {
        atual = &(*atual)->prox;
    }
    if (*atual == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }
    if ((*atual)->emprestado) {
        printf("Não é possível excluir um livro emprestado.\n");
        return;
    }
    removido = *atual;
    *atual = removido->prox;
    free(removido);
    printf("Livro excluído com sucesso.\n");
}

void registrar_emprestimo(Biblioteca *biblioteca) {
    char codigo[TAM_CODIGO];
    Livro *livro;

    ler_texto("Código do livro para empréstimo: ", codigo, sizeof codigo);
    livro = buscar_por_codigo(biblioteca, codigo);
    if (livro == NULL) {
        printf("Livro não encontrado.\n");
    } else if (livro->emprestado) {
        printf("Esse livro já está emprestado.\n");
    } else {
        livro->emprestado = 1;
        printf("Empréstimo registrado.\n");
    }
}

void registrar_devolucao(Biblioteca *biblioteca) {
    char codigo[TAM_CODIGO];
    Livro *livro;

    ler_texto("Código do livro para devolução: ", codigo, sizeof codigo);
    livro = buscar_por_codigo(biblioteca, codigo);
    if (livro == NULL) {
        printf("Livro não encontrado.\n");
    } else if (!livro->emprestado) {
        printf("Esse livro já está disponível.\n");
    } else {
        livro->emprestado = 0;
        printf("Devolução registrada.\n");
    }
}
