#include <stdio.h>
#include <stdlib.h>

struct Aluno {
	char nome[50];
	int idade;
	float nota1, nota2;	
};

struct Aluno cadastraAluno(){
	struct Aluno aluno;
	printf("Digite o nome do aluno: ");
	fgets(aluno.nome, 50, stdin);
	printf("Digite a idade: ");
	scanf("%d", &aluno.idade);
	printf("Digite a nota 1: ");
	scanf("%f", &aluno.nota1);
	printf("Digite a nota 2: ");
	scanf("%f", &aluno.nota2);
	return aluno;
}

float calculaMedia(struct Aluno aluno) {
	return (aluno.nota1 + aluno.nota2)/2;
}

void mostraAluno(struct Aluno aluno) {
	float media = calculaMedia(aluno);
	printf("\nNome: %s", aluno.nome);
	printf("\nIdade: %d", aluno.idade);
	printf("\nNota 1: %.2f", aluno.nota1);
	printf("\nNota 1: %.2f", aluno.nota2);
	printf("\nMedia: %.2f", media);
}

int main() {
	struct Aluno aluno;
	aluno = cadastraAluno();
	mostraAluno(aluno);
}

