/**
 * Principal para Arvore Binaria de Pesquisa
 * @author Max do Val Machado
 */
public class Principal {
    public static void main(String[] args) throws Exception {
        ArvoreBinaria arvoreBinaria = new ArvoreBinaria();
        for(int i=1; i<10; i++){
            arvoreBinaria.inserir(i);
            No no = arvoreBinaria.pesquisar(i);
            System.out.println("Nuemro inserido " + i);
            System.out.println("quantidade: " + no.quantidade);
        }
        for(int i=1; i<10; i++){
            arvoreBinaria.inserir(i);
            No no = arvoreBinaria.pesquisar(i);
            System.out.println("Numero inserido " + i);
            System.out.println("quantidade: " + no.quantidade);
    
        }
    }
}
