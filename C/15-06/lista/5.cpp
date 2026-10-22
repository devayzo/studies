#include <stdio.h>

struct DVD {
    char artista[50];
    char nomeAlbum[50];
    char estiloMusical[30];
    char gravadora[50];
    int ano;
    float preco;
};

int main() {
    struct DVD dvd;

    printf("Artista: ");
    fgets(dvd.artista, 50, stdin);

    printf("Nome do Album: ");
    fgets(dvd.nomeAlbum, 50, stdin);

    printf("Estilo Musical: ");
    fgets(dvd.estiloMusical, 30, stdin);

    printf("Gravadora: ");
    fgets(dvd.gravadora, 50, stdin);

    printf("Ano: ");
    scanf("%d", &dvd.ano);

    printf("Preco: ");
    scanf("%f", &dvd.preco);

    printf("\n=== DADOS DO DVD ===\n");
    printf("Artista: %s", dvd.artista);
    printf("Album: %s", dvd.nomeAlbum);
    printf("Estilo Musical: %s", dvd.estiloMusical);
    printf("Gravadora: %s", dvd.gravadora);
    printf("Ano: %d\n", dvd.ano);
    printf("Preco: R$ %.2f\n", dvd.preco);

    return 0;
}
