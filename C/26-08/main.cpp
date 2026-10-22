#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Pedido
{
    int codigo, quantidade;
    char cliente[50], produto[50];
};
struct Pedido fila[MAX];

int inicio = 0, fim = 0, total = 0;

void inserirPedido()
{
    if (total == MAX)
    {
        printf("\nFila cheia!");
    }

    else
    {
        printf("Codigo do pedido: ");
        scanf("%d", &fila[fim].codigo);
        printf("Nome do Cliente: ");
        getchar();
        fgets(fila[fim].cliente, 50, stdin);
        printf("Produto: ");
        fgets(fila[fim].produto, 50, stdin);
        printf("Quantidade: ");
        scanf("%d", &fila[fim].quantidade);
        fim++;
        total++;
        printf("\nPedido inserido com sucesso!");
    }
}

void removerPedido()
{
    if (total == 0)
    {
        printf("\nA fila esta vazia!!");
    }

    else
    {
        printf("\nPedido removido:");
        printf("\nCodigo: %d", fila[inicio].codigo);
        printf("\nCliente: %s", fila[inicio].cliente);
        printf("\nProduto: %s", fila[inicio].produto);
        printf("\nQuantidade: %d", fila[inicio].quantidade);
        for (int i = 0; i < total - 1; i++)
        {
            fila[i] = fila[i + 1];
        }
        fim--;
        total--;
        printf("\nPedido removido com sucesso.");
    }
}

void imprimirFila()
{
    int i;
    if (total == 0)
    {
        printf("\nFila vazia!!!");
    }

    else
    {
        printf("\nPedidos na fila:");
        printf("\nTotal de pedidos: %d", total);
    }

    for (i = 0; i < total; i++)
    {
        printf("\nPosicao na fila: %d", i + 1);
        printf("\nCodigo: %d", fila[i].codigo);
        printf("\nCliente: %s", fila[i].cliente);
        printf("\nProduto: %s", fila[i].produto);
        printf("\nQuantiade: %d", fila[i].quantidade);
    }
}

void buscarPedido()
{
    int codigobusca, i, encontrado = 0;
    if (total == 0)
    {
        printf("\nFila vazia!");
    }

    else
    {
        printf("\nDigite o codigo do pedido: ");
            scanf("%d", &codigobusca);
        for (i = 0; i < total; i++)
        {
            if (fila[i].codigo == codigobusca)
            {
                printf("\nPedido encontrado");
                printf("\nPosicao da fila: %d", i + 1);
                printf("\nCodigo: %d", fila[i].codigo);
                printf("\nCliente: %s", fila[i].cliente);
                printf("\nProduto: %s", fila[i].produto);
                printf("\nQuantidade: %d", fila[i].quantidade);
            }
        }

        if (encontrado == 0)
        {
            printf("\nPedido não encontrado!");
        }
    }
}

int main()
{
    int op;
    do
    {
        printf("\nFila de pedidos");
            printf("\n1 - Inserir pedido");
                printf("\n2 - Remover pedido");
                    printf("\n3 - Imprimir fila");
                        printf("\n4 - Buscar pedido");
                            printf("\n5 - Encerrar programa");
                                printf("\nEntre com a opcao:");
                                    scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserirPedido();
            break;
        case 2:
            removerPedido();
            break;
        case 3:
            imprimirFila();
            break;
        case 4:
            buscarPedido();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nOpcao invalida!!!");
        }
    } while (op != 5);
} 

