#include <stdio.h>

int main() {

    float salario, bonus, salarioFinal;
    int pontuacao;

    printf("Digite o salario: ");
    scanf("%f", &salario);

    printf("Digite a pontuacao: ");
    scanf("%d", &pontuacao);

    if (pontuacao >= 1000) {
        bonus = 500;
    } else if (pontuacao >= 500) {
        bonus = 300;
    } else {
        bonus = 0;
    }

    salarioFinal = salario + bonus;

    printf("\nBonus: R$ %.2f", bonus);
    printf("\nSalario final: R$ %.2f", salarioFinal);
}

