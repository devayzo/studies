#include <stdio.h>

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

int main() {
    float peso, altura, imc;

    printf("Digite o peso (kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (m): ");
    scanf("%f", &altura);

    imc = calcularIMC(peso, altura);

    printf("IMC = %.2f\n", imc);

    return 0;
}
