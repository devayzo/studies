public class Pesagem {

    public static String verificarSituacao(double imc) {
        if (imc < 18.5) {
            return "Abaixo do peso ideal";
        } else if (imc < 25.0) {
            return "Peso normal";
        } else if (imc < 30.0) {
            return "Acima do peso";
        } else if (imc < 35.0) {
            return "Obesidade grau I";
        } else if (imc < 40.0) {
            return "Obesidade grau II";
        } else {
            return "Obesidade grau III";
        }
    }

    public static void mostrarDados(Pessoas pessoa) {
        pessoa.mostrarNome();
        pessoa.mostrarIdade();
        pessoa.mostrarPeso();
        pessoa.mostrarAltura();

        double imc = pessoa.calcularIMC();
        System.out.printf("IMC: %.2f%n", imc);
        System.out.println("Situacao: " + verificarSituacao(imc));
        System.out.println();
    }

    public static void main(String[] args) {
        Pessoas pessoa1 = new Pessoas("Ana", 22, 58.0, 1.65);
        Pessoas pessoa2 = new Pessoas("Carlos", 35, 92.0, 1.78);

        System.out.println("--- PESSOA 1 ---");
        mostrarDados(pessoa1);

        System.out.println("--- PESSOA 2 ---");
        mostrarDados(pessoa2);
    }
}
