public class ParImparSwitch {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Erro: informe um numero inteiro como parametro.");
            return;
        }

        try {
            int numero = Integer.parseInt(args[0]);

            switch (numero % 2) {
                case 0:
                    System.out.println("O numero " + numero + " e par.");
                    break;
                default:
                    System.out.println("O numero " + numero + " e impar.");
                    break;
            }
        } catch (NumberFormatException e) {
            System.out.println("Erro: o parametro informado nao e um numero inteiro.");
        }
    }
}
