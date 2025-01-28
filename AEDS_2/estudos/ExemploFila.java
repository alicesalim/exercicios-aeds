import java.util.ArrayList;

class Fila {
    private ArrayList<Integer> arrayList; // Atributo para armazenar elementos da fila

    // Construtor que inicializa o ArrayList
    public Fila() {
        arrayList = new ArrayList<>();
    }

    // Método para inserir um elemento no final da fila
    public void inserir(int valor) {
        arrayList.add(valor);
    }

    // Método para remover o primeiro elemento da fila
    public int remover() {
        if (arrayList.isEmpty()) {
            throw new RuntimeException("A fila está vazia!");
        }
        int removido = arrayList.get(0);
        arrayList.remove(0);
        return removido;
    }

    // Método para mostrar todos os elementos da fila
    public void mostrar() {
        System.out.println("Elementos na fila:");
        for (int elemento : arrayList) {
            System.out.println(elemento);
        }
    }
}

public class ExemploFila {
    public static void main(String[] args) {
        Fila fila = new Fila();

        // Inserindo elementos na fila
        for (int i = 0; i < 10; i++) {
            fila.inserir(i);
        }

        // Removendo e exibindo alguns elementos
        System.out.println("Removido: " + fila.remover());
        fila.inserir(10);
        System.out.println("Removido: " + fila.remover());
        fila.inserir(11);
        System.out.println("Removido: " + fila.remover());
        fila.inserir(12);

        // Mostrando todos os elementos restantes na fila
        System.out.println("======== Mostrar ========");
        fila.mostrar();
    }
}
