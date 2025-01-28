import java.util.*;
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
       System.out.print(getName());
       System.out.println();
   }


}

/*----------------------------NO DA ARVORE BINARIA----------------------------*/

class No {
   Pokemon pokemon; // Conteudo do no.
   public No esq, dir;  // Filhos da esq e dir.

   //Construtor da classe.
   public No(Pokemon pokemon) {
    this.pokemon = pokemon;
    this.esq = this.dir = null;
}

   //Construtor da classe.
   public No(Pokemon pokemon, No esq, No dir) {
       this.pokemon = pokemon;
       this.esq = esq;
       this.dir = dir;
   }
}

/*----------------------------ARVORE BINARIA----------------------------*/

class ArvoreBinaria { 
	private No raiz; // Raiz da arvore.
	private int comparacoes = 0;

    public int getComparacoes() {
        return comparacoes;
    }
	//construtor
	public ArvoreBinaria() {
		raiz = null;
	}

	// Metodo publico iterativo para pesquisar elemento.
	public boolean pesquisar(String name) {
        System.out.print("=>raiz ");
		return pesquisar(name, raiz);
	}

	// Metodo privado recursivo para pesquisar elemento.
	private boolean pesquisar(String name, No i) {
      boolean resp;
		if (i == null) {
         resp = false;

      } else if (name.equals(i.pokemon.getName())) {
         comparacoes++;
         resp = true;

      } else if ((name.compareTo(i.pokemon.getName()) < 0)) {
        comparacoes++;
         System.out.print("esq ");
         resp = pesquisar(name, i.esq);

      } else {
        comparacoes++;
         System.out.print("dir ");
         resp = pesquisar(name, i.dir);
      }
      return resp;
	}

	//Metodo publico iterativo para inserir elemento.
	public void inserir(Pokemon pokemon) throws Exception {
		raiz = inserir(pokemon, raiz);
	}

	//Metodo privado recursivo para inserir elemento.
	private No inserir(Pokemon pokemon, No i) throws Exception {
		if (i == null) {
         i = new No(pokemon);

      } else if ((pokemon.getName().compareTo(i.pokemon.getName()) < 0)) {
         comparacoes++;
         i.esq = inserir(pokemon, i.esq);

      } else if ((pokemon.getName().compareTo(i.pokemon.getName()) > 0)) {
        comparacoes++;
         i.dir = inserir(pokemon, i.dir);

      } else {
         throw new Exception("Erro ao inserir!");
      }

		return i;
	}


}

/*----------------------------------Principal----------------------------------*/
public class Q01 {

    public static void main(String[] args) {
        long inicio = System.nanoTime(); 

      // Usando try-with-resources para garantir o fechamento do Scanner
      try (Scanner sc = new Scanner(System.in)) {
          String in = sc.nextLine();
          //int contaPokes = 0;
          ArrayList<Pokemon> pokemons = new ArrayList<>(); 
  
          while (!in.equals("FIM")) {
              String id = in.trim();
              Pokemon pokemon = new Pokemon();
              pokemon.read(id);
              pokemons.add(pokemon);
              //contaPokes++;
              in = sc.nextLine();
          }
  
          ArvoreBinaria arvore = new ArvoreBinaria();
  
          // Inserindo pokémons lidos
          for (Pokemon pokemon : pokemons) {
              try {
                  arvore.inserir(pokemon);
              } catch (Exception e) {
                  System.out.println("Falha ao inserir na lista:" + e.getMessage());
              }
          }
          boolean continuar = true;
          while (continuar) {
              // Leitura do nome a ser pesquisado
              String name = sc.nextLine().trim();
  
              if (name.equals("FIM")) {
                  continuar = false;  // Encerra o laço de pesquisa
              } else {
                  // Realiza a pesquisa do Pokémon
                  System.out.println(name);
                  boolean encontrado = arvore.pesquisar(name);
                  if (encontrado) {
                      System.out.println("SIM");
                  } else {
                      System.out.println("NAO");
                  }
              }
          }
      } catch (Exception e) {
          System.out.println("Erro: " + e.getMessage());
      }
      long fim = System.nanoTime();
        long tempoExecucao = fim - inicio;
        String matricula = "846006";
                // Criação do arquivo de log
                try (FileWriter fw = new FileWriter("846006_arvoreBinaria.txt", true); // O 'true' faz o arquivo abrir para adicionar conteúdo
                PrintWriter pw = new PrintWriter(fw)) {
   
               // Escreve a matrícula, tempo de execução e número de comparações no arquivo
               ArvoreBinaria arvore = new ArvoreBinaria();
               pw.println(matricula + "\t" + tempoExecucao + "\t" + arvore.getComparacoes());

           } catch (IOException e) {
               System.out.println("Erro ao criar o arquivo de log: " + e.getMessage());
           }
   }
}
