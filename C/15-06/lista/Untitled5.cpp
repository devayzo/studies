#include <stdio.h>

int main() {
    float salario,bonus=0,salarioFinal;
    int pontuacao;

    printf("Salario: ");
    scanf("%f",&salario);
    printf("Pontuacao: ");
    scanf("%d",&pontuacao);

    if(pontuacao>=1000)
        bonus=500;
    else if(pontuacao>=500)
        bonus=300;

    salarioFinal=salario+bonus;

    printf("Salario final: %.2f",salarioFinal);

}

