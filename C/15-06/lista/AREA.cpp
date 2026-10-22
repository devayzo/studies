#include <stdio.h>

int main() {
    float largura, comprimento, area;
    printf("Digite a largura: ");
    scanf("%f",&largura);
    printf("Digite o comprimento: ");
    scanf("%f",&comprimento);
    area = largura * comprimento;
    printf("Area: %.2f", area);
}
