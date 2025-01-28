import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;

// Cria a classe Pokemon
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

    // Construtores
    public Pokemon() {
        this(0, 0, "", "", new ArrayList<>(), new ArrayList<>(), 0.0, 0.0, 0, false, null);
    }

    public Pokemon(int id, int generation, String name, String description, ArrayList<String> types, ArrayList<String> abilities, double weight, double height, int captureRate, boolean isLegendary, Date captureDate) {
        this.id = id;
        this.generation = generation;
        this.name = name;
        this.description = description;
        this.types = types;
        this.abilities = abilities;
        this.weight = weight;
        this.height = height;
        this.captureRate = captureRate;
        this.isLegendary = isLegendary;
        this.captureDate = captureDate;
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

    // Métodos Getters e Setters
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
}

public class Q09 {

    private static int compara(Pokemon a, Pokemon b) {
        if (a.getHeight() != b.getHeight()) {
            return Double.compare(a.getHeight(), b.getHeight());
        } else {
            return a.getName().compareTo(b.getName());
        }
    }

    private static void construir(Pokemon[] array, int tamanho) {
        for (int i = tamanho; i > 1 && compara(array[i - 1], array[i / 2 - 1]) > 0; i /= 2) {
            swap(array, i - 1, i / 2 - 1);
        }
    }

    public static void swap(Pokemon[] array, int i, int j) {
        Pokemon tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    private static int getMaiorFilho(Pokemon[] array, int i, int tamanho) {
        if (2 * i == tamanho || compara(array[2 * i - 1], array[2 * i]) > 0) {
            return 2 * i;
        } else {
            return 2 * i + 1;
        }
    }

    private static void reconstruir(Pokemon[] array, int tamanho) {
        int i = 1;
        while (i <= (tamanho / 2)) {
            int filho = getMaiorFilho(array, i, tamanho);
            if (compara(array[filho - 1], array[i - 1]) > 0) {
                swap(array, i - 1, filho - 1);
                i = filho;
            } else {
                i = tamanho;
            }
        }
    }

    public static void heapsort(Pokemon[] array, int tamanho) {
        // Constrói o heap
        for (int i = 2; i <= tamanho; i++) {
            construir(array, i);
        }

        // Ordena o array
        int tamHeap = tamanho;
        while (tamHeap > 1) {
            swap(array, 0, tamHeap - 1);
            tamHeap--;
            reconstruir(array, tamHeap);
        }
    }

    public static void main(String[] args) throws IOException {
        int matricula = 123456;
        FileWriter arq = new FileWriter(matricula + "_heapsort.txt");
        PrintWriter log = new PrintWriter(arq);

        // Vetor de Pokémons
        Pokemon[] pokemons = new Pokemon[3]; // Exemplo com 3 Pokémons, altere conforme necessário
        pokemons[0] = new Pokemon().read("1");
        pokemons[1] = new Pokemon().read("2");
        pokemons[2] = new Pokemon().read("3");

        // Ordena usando Heapsort
        heapsort(pokemons, pokemons.length);

        // Imprime os Pokémons ordenados
        for (Pokemon pokemon : pokemons) {
            log.println(pokemon.getId() + " " + pokemon.getName() + " " + pokemon.getHeight());
        }

        log.close();
    }
}

