
import java.util.*;
import java.util.concurrent.ExecutionException;
import java.io.*;
import java.text.SimpleDateFormat;


class Pokemon{ 
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

    public Pokemon (){
        this(0,0,"","", new ArrayList<>(), new ArrayList<>(),0.0,0.0,0,false,null);
   }

   public Pokemon(int id, int geracao, String nome, String descricao, ArrayList<String> tipos, ArrayList<String>habilidades, double peso, double altura, int taxaDeCaptura, boolean eLendario, Date dataDeCaptura){
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

   public Pokemon clone(Pokemon pokemon){

       Pokemon clone = new Pokemon(
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
           pokemon.getCaptureDate());

       return clone ;
   }

    public void setId(int id){
        this.id = id;
    }

    public void setGeneration(int generation){
        this.generation = generation;
    }

    public void setName (String name){
        this.name = name;
    }

    public void setDescription (String description){
        this.description = description;
    }

    public void setTypes (ArrayList<String> types){
        this.types = types;
    }

    public void setAbilities (ArrayList<String>abilities){
        this.abilities = abilities;
    }

    public void setWeight (double weight){
        this.weight = weight;
    }

    public void setHeight (double height){
        this.height = height;
    }

    public void setCaptureRate (int captureRate){
        this.captureRate = captureRate;
    }

    public void setIsLegendary (boolean isLegendary){
        this.isLegendary = isLegendary;
    }

    public void setCaptureDate (Date captureDate){
        this.captureDate = captureDate;
    }


    public int getId(){
        return this.id;
    }

    public int getGen(){
        return this.generation;
    }

    public String getName(){
        return this.name;
    }

    public String getDescription(){
        return this.description;
    }

    public ArrayList<String> getTypes(){
        return this.types;
    }

    public ArrayList<String> getAbilities(){
        return this.abilities;
    }

    public double getWeight(){
        return this.weight;
    }

    public double getHeight(){
        return this.height;
    }

    public int getCaptureRate(){
        return this.captureRate;
    }

    public boolean getIsLegendary(){
        return this.isLegendary;
    }

    public Date getCaptureDate(){
        return this.captureDate;
    }

    //Leitura-->
    public Pokemon read(String id) {
        try {
            File file = new File("/tmp/pokemon.csv");
            Scanner scanner = new Scanner(file);
            scanner.nextLine(); // Pula a linha de cabeçalho
    
            while (scanner.hasNextLine()) {
                SimpleDateFormat sdfInput = new SimpleDateFormat("dd/MM/yyyy");
    
                String linha = scanner.nextLine();
                String[] preParts = linha.split("\"");
    
                String novaLinha = preParts.length > 2 ? preParts[0] + preParts[2] : linha; // Verifica se há aspas
    
                String[] parts = novaLinha.split(",");
                if (parts.length >= 10 && parts[0].equals(id)) {
                    this.id = Integer.parseInt(parts[0]);
                    this.generation = Integer.parseInt(parts[1]);
                    this.name = parts[2];
                    this.description = parts[3];
    
                    // Adiciona tipos
                    this.types.add(parts[4].trim());
                    if (!parts[5].trim().isEmpty()) { // Verifica se o segundo tipo não está vazio
                        this.types.add(parts[5].trim());
                    }
    
                    // Adiciona habilidades
                    this.abilities = Lista(preParts[1]);
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
    
        return this;
    }
    
    //Método para transformar o trecho de dados abilities em lista
    public ArrayList<String> Lista(String elementos){
        ArrayList<String> novaLista = new ArrayList<>();
        // Remove colchetes, aspas simples e espaços
        elementos = elementos.replace("[", "").replace("]", "").replace("'", "").trim();
        // Divide os elementos pela vírgula e adiciona à lista
        for (String habilidade : elementos.split(",")) {
            novaLista.add(habilidade.trim());
        }
        return novaLista;
    }


    public void print() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        
        System.out.print("[" + "#" + getId() + " -> " + getName() + ": " + getDescription() + " - " + "[");

        if (getTypes() != null) {
            for (int i = 0; i < getTypes().size(); i++) {
                System.out.print("'" + getTypes().get(i) + "'");
                if (i + 1 < getTypes().size()) {
                    System.out.print(", ");
                }
            }
        }

        System.out.print("]" + " - " + "[");

         if (getAbilities() != null) {
            for (int i = 0; i < getAbilities().size(); i++) {
                System.out.print("'" + getAbilities().get(i) + "'");
                if (i + 1 < getAbilities().size()) {
                    System.out.print(", ");
                }
            }
        }

        System.out.print("]" + " - " + getWeight() + "kg" + " - " + getHeight() + "m" + " - " + getCaptureRate() + "%" + " - " + getIsLegendary() + " - " + getGen() + " gen" + "]");

        if (getCaptureDate() != null) {
            System.out.print( " - " + sdf.format(getCaptureDate()));
        } else {
            System.out.print("Data não disponível");
        }

        System.out.println();
    }


}
public class Q09{

    public static class pokeList{
        Pokemon [] lista;
        int n;

        public pokeList(){
            this(10);
        }

        public pokeList(int i){
            this.lista = new Pokemon [i];
            this.n = 0;
        }

        public void mostrar(){
            for(int i=0;i<this.n;i++){
                System.out.print("[" + i + "] ");
                lista[i].print();
            }
        }

        void inserirFim(Pokemon pokemon) throws Exception {
            if (this.n >= this.lista.length) {
                throw new Exception("Full List");
            }

            this.lista[n] = pokemon;
            n++;
        }

        Pokemon removerFim()throws Exception{
            if(this.n==0){
                throw new Exception("Lista Vazia");
            }

            return this.lista[--this.n];
        }

        public void operar(String operacao, Pokemon objeto,int pos){
            try {
                switch (operacao) {
                    case "I":
                        this.inserirFim(objeto);
                        break;
                    case "R":
                        System.out.println("(R) " + this.removerFim().getName());
                        break;
                    default:
                        System.out.println("Operação inválida: " + operacao);
                }
            } catch (Exception e) {
                System.out.println("Falha ao executar " + operacao + ": " + e.getMessage());
            }
            
        }
    }


    public static void main(String[] args) {
        // Usando try-with-resources para garantir o fechamento do Scanner
        try (Scanner sc = new Scanner(System.in)) {
            String in = sc.nextLine();
            int contaPokes = 0;
            ArrayList<Pokemon> pokemons = new ArrayList<>(); 
    
            while (!in.equals("FIM")) {
                String id = in.trim();
                Pokemon pokemon = new Pokemon();
                pokemon.read(id);
                pokemons.add(pokemon);
                contaPokes++;
                in = sc.nextLine();
            }
    
            in = sc.nextLine();
            int numOperacoes = Integer.parseInt(in);
            pokeList lista = new pokeList(contaPokes + numOperacoes);
    
            // Inserindo pokémons lidos
            for (Pokemon pokemon : pokemons) {
                try {
                    lista.inserirFim(pokemon);
                } catch (Exception e) {
                    System.out.println("Falha ao inserir na lista:" + e.getMessage());
                }
            }
    
            // Execução das operações
            for (int i = 0; i < numOperacoes; i++) {
                in = sc.nextLine();
                String[] parts = in.split(" ");
                String operacao = parts[0];
                Pokemon pokemon = new Pokemon();
                int value = -1;
    
                if (parts.length > 2 || parts[0].equals("R*")) {
                    value = Integer.parseInt(parts[1]);
                }
                
                if (parts.length > 1) {
                    pokemon.read(parts[parts.length - 1]);
                }
                
                lista.operar(operacao, pokemon, value);
            }
    
            lista.mostrar(); // Mova esta linha para fora do loop
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
    
}

