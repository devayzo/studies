#include <stdio.h>

void ordena(int vetor[]) {
    int i, j, temp;

    for(i = 0; i < 10; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 9; i++) {
        for(j = i + 1; j < 10; j++) {
            if(vetor[i] > vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main() {
    int vetor[10];
    int i;

    ordena(vetor);

    printf("\nVetor Ordenado:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
