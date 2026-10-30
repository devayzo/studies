#include "biblioteca.h"

#include <windows.h>
#include <stdio.h>

#define ARQUIVO_DADOS "livros.dat"

static void mostrar_menu(void) {
    SetConsoleOutputCP(CP_UTF8);

    printf("\n=== GERENCIAMENTO DE BIBLIOTECA ===\n"
           "1. Cadastrar livro\n"
           "2. Listar livros\n"
           "3. Buscar livro\n"
           "4. Editar livro\n"
           "5. Excluir livro\n"
           "6. Registrar empréstimo\n"
           "7. Registrar devolução\n"
           "0. Sair\n");
}

int main(void) {

    Biblioteca biblioteca;
    int opcao;
    int carregados;

    biblioteca_inicializar(&biblioteca);
    carregados = biblioteca_carregar(&biblioteca, ARQUIVO_DADOS);
    if (carregados < 0) {
        fprintf(stderr, "Erro ao carregar os dados.\n");
    } else if (carregados > 0) {
        printf("%d livro(s) carregado(s).\n", carregados);
    }

    do {
        mostrar_menu();
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            opcao = -1;
        } else {
            getchar();
        }

        switch (opcao) {
        case 1:
            cadastrar_livro(&biblioteca);
            break;
        case 2:
            listar_livros(&biblioteca);
            break;
        case 3:
            consultar_livro(&biblioteca);
            break;
        case 4:
            editar_livro(&biblioteca);
            break;
        case 5:
            excluir_livro(&biblioteca);
            break;
        case 6:
            registrar_emprestimo(&biblioteca);
            break;
        case 7:
            registrar_devolucao(&biblioteca);
            break;
        case 0:
            if (!biblioteca_salvar(&biblioteca, ARQUIVO_DADOS)) {
                fprintf(stderr, "Erro ao salvar os dados.\n");
            } else {
                printf("Dados salvos. Até logo!\n");
            }
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    biblioteca_liberar(&biblioteca);
    return 0;
}
