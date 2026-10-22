#include <stdio.h>

float Celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    float fahrenheit, celsius;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = Celsius(fahrenheit);

    printf("Temperatura em Celsius: %.2f°C\n", celsius);

    return 0;
}
