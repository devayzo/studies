#include <stdio.h>

float calcularSalario(float horas, float valorHora, int dias) {
    return (horas * valorHora) * dias;
}

int main() {
    float horas, valorHora, salario;
    int dias;

    printf("Horas trabalhadas por dia: ");
    scanf("%f", &horas);

    printf("Valor da hora: ");
    scanf("%f", &valorHora);

    printf("Quantidade de dias trabalhados: ");
    scanf("%d", &dias);

    salario = calcularSalario(horas, valorHora, dias);

    printf("Salario = R$ %.2f\n", salario);

    return 0;
}
