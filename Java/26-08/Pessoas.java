public class Pessoas {
    private String nome;
    private int idade;
    private double peso;
    private double altura;

    public Pessoas(String nome, int idade, double peso, double altura) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;
    }

    public void mostrarNome() {
        System.out.println("Nome: " + nome);
    }

    public void mostrarIdade() {
        System.out.println("Idade: " + idade + " anos");
    }

    public void mostrarPeso() {
        System.out.printf("Peso: %.2f kg%n", peso);
    }

    public void mostrarAltura() {
        System.out.printf("Altura: %.2f m%n", altura);
    }

    public double calcularIMC() {
        return peso / (altura * altura);
    }
}