#include <stdio.h>

int main() {
    float peso,altura,imc;
    printf("Peso: ");
    scanf("%f",&peso);
    printf("Altura: ");
    scanf("%f",&altura);

    imc = peso/(altura*altura);

    if(imc>=18.5 && imc<=30)
        printf("Peso ideal");
    else if(imc>30)
        printf("Obeso");
    else
        printf("Abaixo do peso ideal");
}
