

public class Q12 {

    public static String ciframento(String linha, int i) {
        if (i >= linha.length()) {
            return ""; 
        }else{
            char c = linha.charAt(i);
            c = (char) (c+3);
            return c + ciframento(linha, i+1);
        }
        
    }

    public static void main(String[] args) {
        String linha = MyIO.readLine();

        while (!linha.equals("FIM")) {
            MyIO.println(ciframento(linha, 0));
            linha = MyIO.readLine();
        }

    }
}

    


