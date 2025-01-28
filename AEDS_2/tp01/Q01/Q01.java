
import java.util.Scanner; // fgets

public class Q01 { //mesmo nome do arquivo

    public static boolean palindromo(String linha) {
        linha = linha.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();//tratando a string
        int indice = 0;
        int fim = linha.length() - 1;

        while (indice < fim) {
            if (linha.charAt(indice) != linha.charAt(fim)) {//compara o indice e o fim
                return false; // Não é um palíndromo
            }
            indice++;
            fim--;
        }

        return true; // É um palíndromo
    }
        public static void main(String[] array) {
            
        Scanner scanner = new Scanner(System.in);
        String linha = scanner.nextLine();
        while (!linha.equals("FIM")) {
            if (palindromo(linha)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
            linha = scanner.nextLine();
        }
        scanner.close();
    }
}

