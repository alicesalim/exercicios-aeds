
import java.util.Scanner; // fgets

public class Q10 {

    public static boolean palindromo(String linha, int i, int fim) {

        if (i>=fim) {
            return true;
        }
        if (linha.charAt(i) != linha.charAt(fim)){
            return false;
        }
        return palindromo(linha, i+1, fim-1); // É um palíndromo
    }
        public static void main(String[] array) {
            
        Scanner scanner = new Scanner(System.in);
        String linha = scanner.nextLine();
        while (!linha.equals("FIM")) {
            if (palindromo(linha, 0, linha.length()-1)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
            linha = scanner.nextLine();
        }
        scanner.close();
    }
}

