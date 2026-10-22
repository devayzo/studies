#include <stdio.h>

int main() {
	int vetor[10], i;
	
	for(i=0; i<10; i++) {
		printf("Entre com um valor: ");
		scanf("%i", &vetor[i]);
	}
	
	for(i=0; i<10; i++) {
		printf("\nValor[%i]: %i",i,vetor[i]);
	}
}
