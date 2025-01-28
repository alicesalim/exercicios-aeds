package lab;
import java.util.Scanner;

public class lab04 {

    public static void ordena(int array[], int modulo, int quantidade) {
        for (int i = quantidade - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                //módulo maior
                if ((array[j] % modulo) > (array[j + 1] % modulo)) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                } 
                //módulos iguais
                else if ((array[j] % modulo) == (array[j + 1] % modulo)) {
                    //dois ímpares
                    if ((array[j] % 2 != 0) && (array[j + 1] % 2 != 0) && array[j] < array[j + 1]) {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                    //dois pares
                    else if ((array[j] % 2 == 0) && (array[j + 1] % 2 == 0) && array[j] > array[j + 1]) {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                    //primeiro par, segundo ímpar
                    else if ((array[j] % 2 == 0) && (array[j + 1] % 2 != 0)) {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int quantidade = sc.nextInt();
        int modulo = sc.nextInt();
        while ((quantidade != 0) && (modulo != 0)) {
            int[] numeros = new int[quantidade];
            for (int i = 0; i < quantidade; i++) {
                numeros[i] = sc.nextInt();
            }
            System.out.printf("%d %d\n", quantidade, modulo);
            ordena(numeros, modulo, quantidade);
            for (int i = 0; i < quantidade; i++) {
                System.out.println(numeros[i]);
            }
            quantidade = sc.nextInt();
            modulo = sc.nextInt();
        }
        System.out.printf("%d %d\n", quantidade, modulo);
        sc.close();
    }
}

