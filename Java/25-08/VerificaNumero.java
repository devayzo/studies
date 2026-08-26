public class VerificaNumero {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Erro: informe um parametro pela linha de comandos.");
            return;
        }

        try {
            double numero = Double.parseDouble(args[0]);

            System.out.println("O parametro informado e um numero.");

            if (numero < 0) {
                System.out.println("Negativo.");
            } else if (numero > 0) {
                System.out.println("Positivo.");
            } else {
                System.out.println("O numero e zero.");
            }
        } catch (NumberFormatException e) {
            System.out.println("O parametro informado nao e um numero.");
        }
    }
}
