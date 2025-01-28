
 class No {
    public int elemento, quantidade; // Conteudo do no.
    public No esq, dir;  // Filhos da esq e dir.

    public No(int elemento) {
        this.elemento = elemento;
        this.esq = null;
        this.dir = null;
        this.quantidade = 0;
    }
}
