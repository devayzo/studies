import java.util.Scanner;

public class EstatisticasNumeros {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int soma = 0;
        int quantidade = 0;
        int maior = 0;
        int menor = 0;
        int somaPares = 0;
        int quantidadePares = 0;
        int quantidadeImpares = 0;

        System.out.println("Digite numeros inteiros positivos.");
        System.out.println("Digite 0 para encerrar.");

        while (true) {
            System.out.print("Numero: ");

            if (!scanner.hasNextInt()) {
                System.out.println("Valor invalido. Digite apenas numeros inteiros.");
                scanner.next();
                continue;
            }

            int numero = scanner.nextInt();

            if (numero == 0) {
                break;
            }

            if (numero < 0) {
                System.out.println("Digite apenas numeros positivos.");
                continue;
            }

            soma += numero;
            quantidade++;

            if (quantidade == 1) {
                maior = numero;
                menor = numero;
            } else {
                if (numero > maior) {
                    maior = numero;
                }

                if (numero < menor) {
                    menor = numero;
                }
            }

            if (numero % 2 == 0) {
                somaPares += numero;
                quantidadePares++;
            } else {
                quantidadeImpares++;
            }
        }

        if (quantidade == 0) {
            System.out.println("\nNenhum numero positivo foi digitado.");
        } else {
            double media = (double) soma / quantidade;
            double porcentagemImpares = (double) quantidadeImpares * 100 / quantidade;

            System.out.println("\n--- RESULTADOS ---");
            System.out.println("Soma dos numeros: " + soma);
            System.out.println("Quantidade de numeros: " + quantidade);
            System.out.printf("Media dos numeros: %.2f%n", media);
            System.out.println("Maior numero: " + maior);
            System.out.println("Menor numero: " + menor);

            if (quantidadePares > 0) {
                double mediaPares = (double) somaPares / quantidadePares;
                System.out.printf("Media dos numeros pares: %.2f%n", mediaPares);
            } else {
                System.out.println("Media dos numeros pares: nao ha numeros pares.");
            }

            System.out.printf("Porcentagem de numeros impares: %.2f%%%n", porcentagemImpares);
        }

        scanner.close();
    }
}
