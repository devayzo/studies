public class ParImparIf {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Erro: informe um numero inteiro como parametro.");
            return;
        }

        try {
            int numero = Integer.parseInt(args[0]);

            if (numero % 2 == 0) {
                System.out.println("O numero " + numero + " e par.");
            } else {
                System.out.println("O numero " + numero + " e impar.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Erro: o parametro informado nao e um numero inteiro.");
        }
    }
}
