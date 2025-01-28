
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;
// cria classe pokemon
class Pokemon {
    private int id;
    private int generation;
    private String name;
    private String description;
    private ArrayList<String> types;
    private ArrayList<String> abilities;
    private double weight;
    private double height;
    private int captureRate;
    private boolean isLegendary;    
    private Date captureDate;

    // Método para ler os dados de um Pokémon a partir de um arquivo CSV
    public Pokemon read(String id) {
        try {
            File file = new File("/tmp/pokemon.csv");
            Scanner scanner = new Scanner(file);
            scanner.nextLine(); // Pula a linha de cabeçalho

            // Formato de data para conversão
            SimpleDateFormat sdfInput = new SimpleDateFormat("dd/MM/yyyy");

            while (scanner.hasNextLine()) {
                String linha = scanner.nextLine();
                String[] preParts = linha.split("\"");

                // Verifica e ajusta linhas que contêm aspas
                String novaLinha = preParts.length > 2 ? preParts[0] + preParts[2] : linha; 

                String[] parts = novaLinha.split(",");
                // Verifica se o ID corresponde ao Pokémon procurado
                if (parts.length >= 10 && parts[0].equals(id)) {
                    this.id = Integer.parseInt(parts[0]);
                    this.generation = Integer.parseInt(parts[1]);
                    this.name = parts[2];
                    this.description = parts[3];

                    // Adiciona tipos do Pokémon
                    this.types = new ArrayList<>();
                    this.types.add(parts[4].trim());
                    if (!parts[5].trim().isEmpty()) { // Verifica se o segundo tipo não está vazio
                        this.types.add(parts[5].trim());
                    }

                    // Adiciona habilidades
                    this.abilities = parseAbilities(preParts[1]);

                    // Atribui peso e altura, considerando possíveis entradas vazias
                    this.weight = parts[7].isEmpty() ? 0.0 : Double.parseDouble(parts[7]);
                    this.height = parts[8].isEmpty() ? 0.0 : Double.parseDouble(parts[8]);
                    this.captureRate = Integer.parseInt(parts[9]);
                    this.isLegendary = parts[10].equals("0") ? false : true;
                    if (!parts[11].isEmpty()) {
                        this.captureDate = sdfInput.parse(parts[11]);
                    }
                }
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Arquivo não encontrado: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }

        return this; // Retorna a instância atual do Pokémon
    }

    // Método para transformar o trecho de dados abilities em lista
    public ArrayList<String> parseAbilities(String elementos) {
        ArrayList<String> novaLista = new ArrayList<>();

        // Remove colchetes, aspas simples e espaços
        elementos = elementos.replace("[", "").replace("]", "").replace("'", "").trim();

        // Divide os elementos pela vírgula e adiciona à lista
        for (String habilidade : elementos.split(",")) {
            novaLista.add(habilidade.trim());
        }

        return novaLista; // Retorna a lista de habilidades
    }

    // Impressão dos dados do Pokémon
    public void print() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

        // Formata e exibe os dados do Pokémon
        System.out.print("[" + "#" + getId() + " -> " + getName() + ": " + getDescription() + " - " + "[");

        // Imprime os tipos do Pokémon
        if (getTypes() != null) {
            for (int i = 0; i < getTypes().size(); i++) {
                System.out.print("'" + getTypes().get(i) + "'");
                if (i + 1 < getTypes().size()) {
                    System.out.print(", ");
                }
            }
        }

        System.out.print("]" + " - " + "[");

        // Imprime as habilidades do Pokémon
        if (getAbilities() != null) {
            for (int i = 0; i < getAbilities().size(); i++) {
                System.out.print("'" + getAbilities().get(i) + "'");
                if (i + 1 < getAbilities().size()) {
                    System.out.print(", ");
                }
            }
        }

        // Exibe peso, altura, taxa de captura e status lendário
        System.out.print("]" + " - " + getWeight() + "kg" + " - " + getHeight() + "m" + " - " + getCaptureRate() + "%" + " - " + getIsLegendary() + " - " + getGen() + " gen" + "]");

        // Verifica se a data de captura está disponível
        if (getCaptureDate() != null) {
            System.out.print(" - " + sdf.format(getCaptureDate()));
        } else {
            System.out.print("Data não disponível");
        }

        System.out.println();
    }

    // Construtores ???
    public Pokemon() {
        this(0, 0, "", "", new ArrayList<>(), new ArrayList<>(), 0.0, 0.0, 0, false, null);
    }
//construtor 
    public Pokemon(int id, int geracao, String nome, String descricao, ArrayList<String> tipos, ArrayList<String> habilidades, double peso, double altura, int taxaDeCaptura, boolean eLendario, Date dataDeCaptura) {
        this.id = id;
        this.generation = geracao;
        this.name = nome;
        this.description = descricao;
        this.types = tipos;
        this.abilities = habilidades;
        this.weight = peso;
        this.height = altura;
        this.captureRate = taxaDeCaptura;
        this.isLegendary = eLendario;
        this.captureDate = dataDeCaptura;
    }

    // Método de clonagem
    public Pokemon clone(Pokemon pokemon) {
        return new Pokemon(
            pokemon.getId(),
            pokemon.getGen(),
            pokemon.getName(),
            pokemon.getDescription(),
            pokemon.getTypes(),
            pokemon.getAbilities(),
            pokemon.getWeight(),
            pokemon.getHeight(),
            pokemon.getCaptureRate(),
            pokemon.getIsLegendary(),
            pokemon.getCaptureDate()
        );
    }

    // Métodos Setters
    public void setId(int id) {
        this.id = id;
    }

    public void setGeneration(int generation) {
        this.generation = generation;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setTypes(ArrayList<String> types) {
        this.types = types;
    }

    public void setAbilities(ArrayList<String> abilities) {
        this.abilities = abilities;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public void setCaptureRate(int captureRate) {
        this.captureRate = captureRate;
    }

    public void setIsLegendary(boolean isLegendary) {
        this.isLegendary = isLegendary;
    }

    public void setCaptureDate(Date captureDate) {
        this.captureDate = captureDate;
    }

    // Métodos Getters O que são: Getters são métodos que retornam o valor de um atributo privado da classe.
//Função: Permitem o acesso a atributos privados fora da classe sem modificar seu valor, garantindo o princípio de encapsulamento.


    public int getId() {
        return this.id;
    }

    public int getGen() {
        return this.generation;
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public ArrayList<String> getTypes() {
        return this.types;
    }

    public ArrayList<String> getAbilities() {
        return this.abilities;
    }

    public double getWeight() {
        return this.weight;
    }

    public double getHeight() {
        return this.height;
    }

    public int getCaptureRate() {
        return this.captureRate;
    }

    public boolean getIsLegendary() {
        return this.isLegendary;
    }

    public Date getCaptureDate() {
        return this.captureDate;
    }
}
public class Q03 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Pokemon> pokemonList = new ArrayList<>();
        String input = scanner.nextLine();
        int comparacoes = 0;

        long startTime = System.nanoTime();  // Início da contagem de tempo

        // Leitura dos IDs e criação dos Pokémons
        while (!input.equals("FIM")) {
            String id = input.trim();
            
            Pokemon pokemon = new Pokemon();
            pokemon.read(id);
            pokemonList.add(pokemon);
            
            input = scanner.nextLine();
        }

        input = scanner.nextLine();

        // Verificação de nomes de Pokémons
        while (!input.equals("FIM")) {
            boolean found = false;
            String name = input.trim();

            for (Pokemon pokemon : pokemonList) {
                comparacoes++;
                if (name.equals(pokemon.getName())) {
                    System.out.println("SIM");
                    found = true;
                    break; // Interrompe o loop se o Pokémon foi encontrado
                }
            }

            if (!found) {
                System.out.println("NAO");
            }

            input = scanner.nextLine();
        }

        long endTime = System.nanoTime();  // Fim da contagem de tempo
        long executionTime = endTime - startTime;  // Tempo de execução

        // Criação do arquivo de log
        try {
            FileWriter logFile = new FileWriter("matricula_sequencial.txt");
            logFile.write("846006\t" + executionTime + "\t" + comparacoes);  // Exemplo de matrícula: 846006
            logFile.close();
        } catch (IOException e) {
            System.out.println("Erro ao escrever no arquivo de log: " + e.getMessage());
        }

        scanner.close();
    }
}

