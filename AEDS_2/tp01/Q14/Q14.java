public class Q14 {
    public static boolean x1(String linha, int i){//só vogais
        String linhaNova= linha.toLowerCase();
        if(i >= linhaNova.length()) {
            return true;
        }
        if("aeiou".indexOf(linhaNova.charAt(i)) == -1) {
            return false;
        } else {
            return x1(linhaNova, i + 1);
        }
    }

    public static boolean x2(String linha, int i){//só consoantes
        String linhaNova= linha.toLowerCase();
        char c = linhaNova.charAt(i);
        if(i >= linhaNova.length()) {
            return true;
        }
        if(("aeiou".indexOf(linhaNova.charAt(i))!= -1)||(!Character.isLetter(c))) {
            return false;
        } else {
            return x2(linhaNova, i + 1);
        }
    }
    
    public static boolean x3(String linha){//inteiro
        try {
            Integer.parseInt(linha);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    public static boolean x4(String linha){//real
        try {
            Double.parseDouble(linha);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static void main(String[] array){

        String linha = MyIO.readLine();

        while (!linha.equals("FIM")) {
            
            System.out.print(x1(linha, 0)?"SIM ": "NAO ");
            System.out.print(x2(linha, 0)?"SIM ": "NAO ");
            System.out.print(x3(linha)?"SIM ": "NAO ");
            System.out.print(x4(linha)?"SIM": "NAO");
            System.out.println("");

            linha = MyIO.readLine();
        }
    }
}
