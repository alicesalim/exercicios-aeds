import java.util.Scanner;

// Classe para representar uma célula na matriz
class Node {
    public int valor;
    public Node esquerda, direita, acima, abaixo;

    Node() {
        this.valor = 0;
        this.esquerda = this.direita = this.acima = this.abaixo = null;
    }
}

// Classe para representar uma matriz flexível
class MatrizFlex {
    public Node topo;
    public int totalLinhas, totalColunas;

    MatrizFlex() {
        topo = criarLinha();
        Node linhaSeguinte = criarLinha();

        for (Node atual = topo, prox = linhaSeguinte; atual != null; atual = atual.direita) {
            atual.abaixo = prox;
            prox.acima = atual;
            prox = prox.direita;
        }

        totalLinhas = 2;
        totalColunas = 2;
    }

    Node criarLinha() {
        Node primeiro = new Node();
        Node segundo = new Node();

        primeiro.direita = segundo;
        segundo.esquerda = primeiro;

        return primeiro;
    }

    Node criarColuna(int altura) {
        Node inicial = new Node();
        Node tmp = inicial;

        for (int i = 0; i < altura - 1; i++) {
            Node novo = new Node();
            tmp.abaixo = novo;
            novo.acima = tmp;
            tmp = novo;
        }

        return inicial;
    }

    Node criarLinha(int largura) {
        Node inicial = new Node();
        Node tmp = inicial;

        for (int i = 0; i < largura - 1; i++) {
            Node novo = new Node();
            tmp.direita = novo;
            novo.esquerda = tmp;
            tmp = novo;
        }

        return inicial;
    }

    void adicionarLinha() {
        Node linhaAtual;
        for (linhaAtual = topo; linhaAtual.abaixo != null; linhaAtual = linhaAtual.abaixo);

        for (Node nova = criarLinha(totalColunas); nova != null; nova = nova.direita) {
            linhaAtual.abaixo = nova;
            nova.acima = linhaAtual;
            linhaAtual = linhaAtual.direita;
        }
        totalLinhas++;
    }

    void adicionarColuna() {
        Node colunaAtual;
        for (colunaAtual = topo; colunaAtual.direita != null; colunaAtual = colunaAtual.direita);

        for (Node nova = criarColuna(totalLinhas); nova != null; nova = nova.abaixo) {
            colunaAtual.direita = nova;
            nova.esquerda = colunaAtual;
            colunaAtual = colunaAtual.abaixo;
        }
        totalColunas++;
    }

    void definirValor(int valor, int linha, int coluna) {
        if (linha >= totalLinhas || coluna >= totalColunas || linha < 0 || coluna < 0) {
            throw new IllegalArgumentException("Posição inválida");
        }
        Node atual = topo;
        for (int i = 0; i < coluna; i++) {
            atual = atual.direita;
        }
        for (int i = 0; i < linha; i++) {
            atual = atual.abaixo;
        }
        atual.valor = valor;
    }

    void exibirDiagonalPrincipal() {
        if (totalLinhas != totalColunas) {
            throw new IllegalStateException("A matriz não possui diagonal principal.");
        }
        Node atual = topo;
        while (atual != null) {
            System.out.print(atual.valor + " ");
            atual = atual.direita;
            if (atual != null) {
                atual = atual.abaixo;
            }
        }
        System.out.println();
    }

    void exibirDiagonalSecundaria() {
        if (totalLinhas != totalColunas) {
            throw new IllegalStateException("A matriz não possui diagonal secundária.");
        }
        Node atual = topo;
        while (atual.direita != null) {
            atual = atual.direita;
        }

        while (atual != null) {
            System.out.print(atual.valor + " ");
            atual = atual.esquerda;
            if (atual != null) {
                atual = atual.abaixo;
            }
        }
        System.out.println();
    }
}

public class MatrizDinamica {
    public static void somarMatrizes(MatrizFlex m1, MatrizFlex m2) {
        for (Node linha1 = m1.topo, linha2 = m2.topo; linha1 != null && linha2 != null; linha1 = linha1.abaixo, linha2 = linha2.abaixo) {
            for (Node cel1 = linha1, cel2 = linha2; cel1 != null && cel2 != null; cel1 = cel1.direita, cel2 = cel2.direita) {
                System.out.print((cel1.valor + cel2.valor) + " ");
            }
            System.out.println();
        }
    }

    public static void multiplicarMatrizes(MatrizFlex m1, MatrizFlex m2) {
        if (m1.totalColunas != m2.totalLinhas) {
            throw new IllegalArgumentException("As matrizes não podem ser multiplicadas.");
        }
        for (Node linha1 = m1.topo; linha1 != null; linha1 = linha1.abaixo) {
            for (Node coluna2 = m2.topo; coluna2 != null; coluna2 = coluna2.direita) {
                int soma = 0;
                for (Node cel1 = linha1, cel2 = coluna2; cel1 != null && cel2 != null; cel1 = cel1.direita, cel2 = cel2.abaixo) {
                    soma += cel1.valor * cel2.valor;
                }
                System.out.print(soma + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numInstancias = scanner.nextInt();

        for (int i = 0; i < numInstancias; i++) {
            MatrizFlex mat1 = new MatrizFlex();
            MatrizFlex mat2 = new MatrizFlex();

            int linhas1 = scanner.nextInt();
            int colunas1 = scanner.nextInt();

            for (int l = 0; l < linhas1 - 2; l++) {
                mat1.adicionarLinha();
            }
            for (int c = 0; c < colunas1 - 2; c++) {
                mat1.adicionarColuna();
            }

            for (int l = 0; l < linhas1; l++) {
                for (int c = 0; c < colunas1; c++) {
                    mat1.definirValor(scanner.nextInt(), l, c);
                }
            }

            int linhas2 = scanner.nextInt();
            int colunas2 = scanner.nextInt();

            for (int l = 0; l < linhas2 - 2; l++) {
                mat2.adicionarLinha();
            }
            for (int c = 0; c < colunas2 - 2; c++) {
                mat2.adicionarColuna();
            }

            for (int l = 0; l < linhas2; l++) {
                for (int c = 0; c < colunas2; c++) {
                    mat2.definirValor(scanner.nextInt(), l, c);
                }
            }

            mat1.exibirDiagonalPrincipal();
            mat1.exibirDiagonalSecundaria();
            somarMatrizes(mat1, mat2);
            multiplicarMatrizes(mat1, mat2);
        }
        scanner.close();
    }
}
