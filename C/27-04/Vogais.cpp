#include <stdio.h>

int main() {
	char frase[1000]; 
	int i, vogais = 0;
	
	printf("Digite uma frase: ");
	fgets(frase, sizeof(frase), stdin);
	
	for(i=0; frase[i] != '\0'; i++) {
		char c = frase[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			vogais++;
		}
	}
	
	printf("Total de vogais: %d", vogais);
}
