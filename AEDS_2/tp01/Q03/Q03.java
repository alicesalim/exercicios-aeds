
public class Q03 {

    public static String ciframento(String linha) {
        // Remove caracteres especiais e converte para minúsculas
        //linha = linha.replaceAll("[^a-zA-Z0-9]", "");
        char cripto[]= new char[linha.length()];

        for (int i = 0; i < linha.length(); i++) {
            char c = linha.charAt(i);
            cripto[i] = (char) (c + 3);


        }

        return new String(cripto);
    }

    public static void main(String[] args) {
        String linha = MyIO.readLine();

        while (!linha.equals("FIM")) {
            MyIO.println(ciframento(linha));
            linha = MyIO.readLine();
        }
    }
}

