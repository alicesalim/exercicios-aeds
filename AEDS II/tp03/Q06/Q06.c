#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Variáveis globais
#define MAX_STRING 1024
#define MAX_LIST 10
#define MAX_LIST_CLASS 100
#define MAX_CLASS 1000

// Estruturas de struct

// Date -> armazena a data do Pokemon
typedef struct
{
    int dia;
    int mes;
    int ano;
} Date;

typedef struct // "Classe" Lista
{
    int n;
    char *element[MAX_LIST];
} List;

typedef struct // "Classe" Pokemons
{
    int id;
    int generation;
    char name[MAX_STRING];
    char description[MAX_STRING];
    List types;     // Lista -> aponta para uma posição da lista
    List abilities; // Lista -> aponta para uma posição da lista
    double weight;
    double height;
    int captureRate;
    bool isLegendary;
    Date captureDate;
} Pokemons;

// Lista dinâmica
typedef struct Cel
{
    Pokemons el;
    struct Cel *prox;
} Cel;

Cel *newCel(Pokemons x) {
    Cel *novo = (Cel *)malloc(sizeof(Cel));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1); 
    }
    novo->el = x;
    novo->prox = NULL;
    return novo;
}


Cel *first;
Cel *last;


typedef struct // "Classe" Lista para Classe
{
    int n;
    Pokemons element[MAX_LIST_CLASS];
} ListPokemons;


void init(List *list)
{
    list->n = 0;
    for (int i = 0; i < MAX_LIST; i++)
    {
        list->element[i] = NULL; // Inicializa os els como NULL
    }
}

// Insere no início da lista
int insertList(List *list, char *el)
{
    if (list->n < MAX_LIST)
    {
        list->element[list->n] = (char *)malloc(strlen(el) + 1);
        if (list->element[list->n] != NULL)
        {
            strcpy(list->element[list->n], el);
            list->n++;
            return 1;
        }
    }
    return 0;
}

// Mostra els da lista
void show(List *list)
{
    for (int i = 0; i < list->n; i++)
    {
        printf("'%s'", list->element[i]);
        if (list->element[i + 1] != NULL)
        {
            printf(", ");
        }
    }
}

// ======= FUNÇÕES AUXILIARES =======
// Pega a posição do caracter procurado
int indexOf(const char *str, const char *find)
{
    char *pos = strstr(str, find);
    if ((pos != NULL))
    {
        return pos - str;
    }
    return -1;
}

// Retorna um recorte de uma string
char *substring(const char *str, int start, int lenght)
{
    // Se "não foi" colocado valor seta como o tamanho da string
    if (lenght == 0)
    {
        lenght = strlen(str);
    }

    // Cria uma String
    char *subStr = (char *)malloc(lenght + 1);
    if (subStr == NULL)
    {
        return NULL;
    }

    strncpy(subStr, str + start, lenght);
    subStr[lenght] = '\0';
    return subStr;
}

// String -> Date
Date insertDate(char *date)
{
    Date newDate;
    char *dia_str = substring(date, 0, indexOf(date, "/"));
    date = substring(date, indexOf(date, "/") + 1, 0);
    char *mes_str = substring(date, 0, indexOf(date, "/"));
    date = substring(date, indexOf(date, "/") + 1, 0);
    char *ano_str = malloc(5 * sizeof(char));
    strcpy(ano_str, date);

    int dia = atoi(dia_str);
    int mes = atoi(mes_str);
    int ano = atoi(ano_str);
    newDate.dia = dia;
    newDate.mes = mes;
    newDate.ano = ano;
    free(ano_str);
    return newDate;
}

// Date -> String
char *formatDate(Date date)
{
    char *dateStr = malloc(11 * sizeof(char));
    if (dateStr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    snprintf(dateStr, 11, "%02d/%02d/%04d", date.dia, date.mes, date.ano);

    return dateStr;
}

int tamanho()
{
    int tamanho = 0;
    Cel *i;
    for (i = first; i != last; i = i->prox, tamanho++)
        ;
    return tamanho;
}

// ========= Funções básicas para a manipulação da classe pokemons ========
// Construtor da classe Pokemons
void initPokemon(Pokemons *pokemon, int id, int generation, const char *name, const char *description,
                 double weight, double height, int captureRate, bool isLegendary, Date captureDate)
{
    pokemon->id = id;
    pokemon->generation = generation;
    strncpy(pokemon->name, name, MAX_STRING);
    strncpy(pokemon->description, description, MAX_STRING);
    pokemon->weight = weight;
    pokemon->height = height;
    pokemon->captureRate = captureRate;
    pokemon->isLegendary = isLegendary;
    pokemon->captureDate = captureDate;

    init(&pokemon->types);
    init(&pokemon->abilities);
}

// Printa a classe Pokemons
void print(Pokemons *pokemons)
{
    if (pokemons == NULL || pokemons->id == 0 || pokemons->name == NULL || pokemons->description == NULL)
    {
        return; // Sai da função se o Pokémon não for válido
    }

    printf("[#%d -> %s: ", pokemons->id, pokemons->name);
    printf("%s - ", pokemons->description);
    printf("[");
    show(&pokemons->types);
    printf("] - ");
    printf("[");
    show(&pokemons->abilities);
    printf("] - ");
    printf(
        "%.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n",
        pokemons->weight,
        pokemons->height,
        pokemons->captureRate,
        pokemons->isLegendary ? "true" : "false",
        pokemons->generation,
        formatDate(pokemons->captureDate));
}

void read(char *line, Pokemons *pokemons)
{
    int start = 0; // Inicio da linha
    int end = 0;   // Final da linha

    // ID
    // Pega os valores
    end = indexOf(line, ",");
    char *id_str = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    int id = atoi(id_str);
    pokemons->id = id;

    // Generation
    // Pega valores
    end = indexOf(line, ",");
    char *generation_str = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    int generation = atoi(generation_str);
    pokemons->generation = generation;

    // Name
    // Pega valores
    end = indexOf(line, ",");
    char *name = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    strcpy(pokemons->name, name);

    // Description
    // Pega valores
    end = indexOf(line, ",");
    char *description = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    strcpy(pokemons->description, description);

    //================
    init(&pokemons->types);
    // Type1
    // Pega valores
    end = indexOf(line, ",");
    char *type1 = substring(line, 0, end);
    line = substring(line, end + 1, 0);

    // Type2
    // Pega valores
    end = indexOf(line, ",");
    char *type2 = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    insertList(&pokemons->types, type1);
    if (end != 0)
    {
        insertList(&pokemons->types, type2);
    }
    free(type1);
    free(type2);

    // PEGANDO ABILITIES
    // =======================
    init(&pokemons->abilities);
    start = indexOf(line, "[") + 1;
    end = indexOf(line, "]");

    // === Redimensiona a linha ===
    char *expression = substring(line, start, end - start);
    line = substring(line, end + 3, 0);

    int n = 0;
    do
    {
        char *abilities = NULL;
        start = indexOf(expression, ",");
        if (start < 0)
        {
            abilities = substring(expression, 1, strlen(expression) - 2);
            if (abilities != NULL)
            {
                insertList(&pokemons->abilities, abilities);
            }
            break;
        }
        abilities = substring(expression, 1, start - 2);
        if (abilities != NULL)
        {
            insertList(&pokemons->abilities, abilities);
        }
        expression = substring(expression, start + 2, 0);
        n++;
    } while (n < MAX_LIST);
    free(expression);

    start = 0;

    // Weight
    // Pega valores
    end = indexOf(line, ",");
    char *weight_str = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    double weight = atof(weight_str);
    pokemons->weight = weight;
    free(weight_str);

    // Height
    // Pega valores
    end = indexOf(line, ",");
    char *height_str = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    double height = atof(height_str);
    pokemons->height = height;
    free(height_str);

    // CaptureRate
    // Pega valores
    end = indexOf(line, ",");
    char *captureRate_str = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    int captureRate = atoi(captureRate_str);
    pokemons->captureRate = captureRate;
    free(captureRate_str);

    // IsLegendary
    // Pega valores
    end = indexOf(line, ",");
    char *isLegendary_str = substring(line, 0, end);
    line = substring(line, end + 1, 0);
    int isLegendary_int = atoi(isLegendary_str);
    bool isLegendary = (isLegendary_int != 0);
    pokemons->isLegendary = isLegendary;
    free(isLegendary_str);

    // CaptureRate
    // Pega valores
    Date date = insertDate(line);
    pokemons->captureDate = date;
}

// ====== GERENCIAMENTO DA LISTA CLASSE ======void start(){
void start()
{
    Pokemons pokemonNew;
    Date pokemonNewCaptureDate = {20, 8, 2020}; // Exemplo de data
    initPokemon(&pokemonNew, 25, 1, "Pikachu", "O Pokémon elétrico.", 6.0, 0.4, 50, false, pokemonNewCaptureDate);
    first = newCel(pokemonNew);
    last = first;
}

// INSERIR
// Inserir Início
void inserirInicio(Pokemons x)
{

    Cel *tmp = newCel(x);
    tmp->prox = first->prox;
    first->prox = tmp;
    if (first == last)
    {
        last = tmp;
    }
    tmp = NULL;
}

// Inserir End
void inserirFim(Pokemons x)
{
    if (last == NULL)
    {
        Cel *tmp = newCel(x);
        first = tmp;
        last = first;
    }
    else
    {
        Cel *tmp = newCel(x);
        last->prox = tmp; 
        last = tmp;      
    }
}

// Inserir qualquer posição
void inserir(Pokemons x, int pos)
{
    int tam = tamanho();

    if (pos < 0 || pos > tam)
    {
        printf("Erro ao inserir posicao (%d/ tamanho = %d) invalida!", pos, tam);
    }
    else if (pos == 0)
    {
        inserirInicio(x);
    }
    else if (pos == tam)
    {
        inserirFim(x);
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        int j;
        Cel *i = first;
        for (j = 0; j < pos; j++, i = i->prox);

        Cel *tmp = newCel(x);
        tmp->prox = i->prox;
        i->prox = tmp;
        tmp = i = NULL;
    }
}

Pokemons removerInicio()
{
    if (first == last)
    {
        printf("Erro ao remover!");
    }

    Cel *tmp = first;
    first = first->prox;
    Pokemons resp = first->el;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

Pokemons removerFim()
{
    if (first == last)
    {
        printf("Erro ao remover!");
    }

    // Caminhar ate a penultima celula:
    Cel *i;
    for (i = first; i->prox != last; i = i->prox)
        ;

    Pokemons resp = last->el;
    last = i;
    free(last->prox);
    i = last->prox = NULL;

    return resp;
}

Pokemons remover(int pos)
{
    Pokemons resp;
    int tam = tamanho();

    if (first == last)
    {
        printf("Erro ao remover (vazia)!");
    }
    else if (pos < 0 || pos >= tam)
    {
        printf("Erro ao remover posicao (%d/ tamanho = %d) invalida!", pos, tam);
    }
    else if (pos == 0)
    {
        resp = removerInicio();
    }
    else if (pos == tam - 1)
    {
        resp = removerFim();
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        Cel *i = first;
        int j;
        for (j = 0; j < pos; j++, i = i->prox);

        Cel *tmp = i->prox;
        resp = tmp->el;
        i->prox = tmp->prox;
        tmp->prox = NULL;
        free(tmp);
        i = tmp = NULL;
    }
    return resp;
}

void mostrar()
{
    Cel *i;
    int cont = 0;
    for (i = first->prox; i != NULL; i = i->prox)
    {
        printf("[%d] ", cont);
        print(&i->el);
        cont++;
    }
}

// Variáveis globais
static Pokemons listPokemons[MAX_CLASS];
static char PATH[] = "/tmp/pokemon.csv";
/*
 * ======================================================
 * MÉTODOS DE INTERAÇÃO DOS DADOS
 * =========================================================
 */

void setListPokemons()
{
    FILE *file = fopen(PATH, "r");
    if (file == NULL) // Verificação
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // Pular a primeira linha
    char line[MAX_STRING];
    if (fgets(line, sizeof(line), file) == NULL) // Verificação
    {
        printf("Erro ao ler a primeira linha ou arquivo vazio.\n");
        fclose(file);
        return; // Retorna em caso de erro na leitura
    }

    int i = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (i >= MAX_CLASS)
        {
            printf("Limite de pokémons alcançado.\n");
            break;
        }

        Pokemons pokemon;
        read(line, &pokemon);
        listPokemons[i] = pokemon;
        i++;
    }

    fclose(file);
}

Pokemons *findID(int id)
{
    for (int i = 0; i < MAX_CLASS; i++)
    {
        if (listPokemons[i].id == id)
        {
            return &listPokemons[i];
        }
    }

    return NULL;
}

int main()
{
    start();
    setListPokemons();
    char ln[MAX_STRING];

    while (fgets(ln, sizeof(MAX_STRING), stdin))
    {
        ln[strcspn(ln, "\n")] = 0;
        if (strcmp(ln, "FIM") == 0)
        {
            break;
        }

        int id = atoi(ln);
        Pokemons *pokemon = findID(id);
        if (id != 0)
        {
            if (pokemon != NULL)
            {
                inserirFim(*pokemon);
            }
            else
            {
                printf("Pokemon não encontrado!\n");
            }
        }
    }

    int qtd = 0;
    scanf("%d", &qtd);
    char str_cmd[MAX_STRING];

    for (int i = 0; i <= qtd; i++)
    {
        char *parts[3];
        Pokemons *pk_find = NULL;
        char *cmd = NULL;
        int id = 0, pos = 0;

        fgets(str_cmd, MAX_STRING, stdin);
        str_cmd[strcspn(str_cmd, "\n")] = 0;

        parts[0] = strtok(str_cmd, " ");
        parts[1] = strtok(NULL, " ");
        parts[2] = strtok(NULL, " ");

        if (parts[0] != NULL)
        {
            cmd = parts[0];
        }

        if (parts[2] != NULL)
        {
            pos = atoi(parts[1]);
            id = atoi(parts[2]);
            pk_find = findID(id);
        }
        else if (parts[1] != NULL)
        {

            if (strcmp(cmd, "R*") == 0)
            {
                pos = atoi(parts[1]);
            }
            else
            {
                id = atoi(parts[1]);
                pk_find = findID(id);
            }
        }

        // Switch Case (IF)
        if (cmd != NULL)
        {
            if (strcmp(cmd, "I") == 0)
            {
                inserirFim(*pk_find);
            }
            else if (strcmp(cmd, "R") == 0)
            {
                Pokemons pkRF = removerFim();
                printf("(R) %s\n", pkRF.name);
            }
            else
            {
                printf("Comando não reconhecido.\n");
            }

        }
    }

    mostrar();
    return 0;
}