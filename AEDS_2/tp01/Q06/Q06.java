public class Q06 {
    
    public static boolean x1(String linha){//só vogais
        String linhaNova= linha.toLowerCase();
        for(int i=0;i<linhaNova.length(); i++){
            if ("aeiou".indexOf(linhaNova.charAt(i))==-1) {//compara o indice e o fim
                return false; // tem consoante
            }
        }
        return true;
    }

    public static boolean x2(String linha){//só consoantes
        String linhaNova= linha.toLowerCase();
        
        for(int i=0;i<linhaNova.length(); i++){
            char c = linhaNova.charAt(i);
            if (("aeiou".indexOf(linhaNova.charAt(i))!=-1)||(!Character.isLetter(c))) {//compara o indice e o fim
                return false; // tem consoante
            }
        }
        return true;
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
            
            System.out.print(x1(linha)?"SIM ": "NAO ");
            System.out.print(x2(linha)?"SIM ": "NAO ");
            System.out.print(x3(linha)?"SIM ": "NAO ");
            System.out.print(x4(linha)?"SIM": "NAO");
            System.out.println("");

            linha = MyIO.readLine();
        }
    }   
}
