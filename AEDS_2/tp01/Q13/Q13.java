import java.util.Scanner;

public class Q13 {

    // Método que substitui variáveis (A, B, C, etc.) pelos valores fornecidos e avalia a expressão booleana
    public static boolean algebra(String expressao, int[] valores) {
        for (int i = 0; i < valores.length; i++) {
            char var = (char) ('A' + i);  // Converte o índice para o caractere correspondente (A = 0, B = 1, etc.)
            expressao = expressao.replace(String.valueOf(var), String.valueOf(valores[i]));  // Substitui a variável pelo valor correspondente
        }

        // Substitui os operadores "and", "or" e "not" pelas suas versões equivalentes
        expressao = expressao.replace("and", "&&")
                             .replace("or", "||")
                             .replace("not", "!");
        
    
        return resultado(expressao);
    }

    // interpretador JavaScript (via ScriptEngine)
    public static boolean resultado(String expressao) {
        try {
            // Cria uma instância do ScriptEngine para executar a expressão como se fosse JavaScript
            javax.script.ScriptEngineManager manager = new javax.script.ScriptEngineManager();
            javax.script.ScriptEngine engine = manager.getEngineByName("JavaScript");
            // Avalia a expressão e retorna o resultado 
            return (boolean) engine.eval(expressao);
        } catch (Exception e) {
            return false;  // Retorna false se houver erro
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        String linha = sc.nextLine();
        while (!linha.equals("FIM")) {
            // Divide a linha de entrada em partes
            String[] partes = linha.split(" ");
            int n = Integer.parseInt(partes[0]);  
            int[] valores = new int[n];
            for (int i = 0; i < n; i++) {
                valores[i] = Integer.parseInt(partes[i + 1]);  // Preenche o array com os valores fornecidos
            }

            //expressão booleana
            String expressao = String.join(" ", partes).substring(linha.indexOf(partes[n + 1]));

            //1 (verdadeiro) ou 0 (falso)
            if (algebra(expressao, valores)) {
                System.out.println("1");
            } else {
                System.out.println("0");
            }
            linha = sc.nextLine(); 
        }
        sc.close();
    }
}

