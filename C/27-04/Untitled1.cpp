#include <stdio.h>
#include <stdlib.h>

struct carteira {
	int cartaocred, cartaounimed, cartaosus, cnh;
	float dinheiro;
	char remedio[30];	
};struct carteira c;

void inserir() {
	printf("Cadastro de carteira");
	printf("\nEntre com o no. do cartao de credito: ");
	scanf("%d",&c.cartaocred);
	printf("Entre com o no. do cartao Unimed: ");
	scanf("%d",&c.cartaounimed);
	printf("Entre com o no. do cartao SUS: ");
	scanf("%d",&c.cartaosus);
	printf("Entre com o no. da CNH: ");
	scanf("%d",&c.cnh);
	printf("Entre com a quantidade de dinheiro da carteira: ");
	scanf("%f",&c.dinheiro);
	printf("Entre com o remedio: ");
	getchar();
	fgets(c.remedio,30,stdin);
}

void exibir(){
	printf("\nDados cadastrados");
	printf("\nNo. do cartao de credito: %d", c.cartaocred);
	printf("\nNo. do cartao da Unimed: %d", c.cartaounimed);
	printf("\nNo. do cartao SUS: %d", c.cartaosus);
	printf("\nNo. da CNH: %d", c.cnh);
	printf("\nQtd. de dinheiro: %.2f", c.dinheiro);
	printf("\nNome do remedio: %s", c.remedio);
}

int main() {
	inserir();
	exibir();
}
