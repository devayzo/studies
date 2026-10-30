#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define TAM_TITULO 100
#define TAM_AUTOR 100
#define TAM_CODIGO 30
#define TAM_EDITORA 100

typedef struct Livro {
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    char codigo[TAM_CODIGO];
    char editora[TAM_EDITORA];
    int ano;
    int emprestado;
    struct Livro *prox;
} Livro;

typedef struct {
    Livro *inicio;
} Biblioteca;

void biblioteca_inicializar(Biblioteca *biblioteca);
int biblioteca_carregar(Biblioteca *biblioteca, const char *arquivo);
int biblioteca_salvar(const Biblioteca *biblioteca, const char *arquivo);
void biblioteca_liberar(Biblioteca *biblioteca);
void cadastrar_livro(Biblioteca *biblioteca);
void listar_livros(const Biblioteca *biblioteca);
void consultar_livro(const Biblioteca *biblioteca);
void editar_livro(Biblioteca *biblioteca);
void excluir_livro(Biblioteca *biblioteca);
void registrar_emprestimo(Biblioteca *biblioteca);
void registrar_devolucao(Biblioteca *biblioteca);

#endif
