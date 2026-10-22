#include<stdio.h>

int main() {
	int i;
	float notas[10], media = 0, maior, menor;
	
	for(i=0; i<10; i++) {
		printf("Entre com a nota: ");
		scanf("%f", &notas[i]);
		media = media + notas[i]; //acumulador
	}
	
	menor = notas[0];
	maior - notas[0];
	
	for(i=0; i<10; i++) {
		if (notas[i] < menor) {
			menor = notas[i];
		}
		if (notas[i] > maior) {
			maior = notas[i];
		}
	}
		
		printf("\nMenor nota: %.2f",menor);
		printf("\nMaior nota: %.2f",maior);
		printf("\nMedia das notas: %.2f",media/10);
}
