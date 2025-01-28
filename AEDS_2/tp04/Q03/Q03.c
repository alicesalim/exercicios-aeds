#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define MAX_DESC_LEN 200
#define MAX_TYPES 2
#define MAX_ABILITIES 5

// Definindo a estrutura do Pokémon
typedef struct
{
    int id;
    int generation;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    char types[MAX_TYPES][MAX_NAME_LEN];
    char abilities[MAX_ABILITIES][MAX_NAME_LEN];
    double weight;
    double height;
    int captureRate;
    bool isLegendary;
    struct tm captureDate;
} Pokemon;

// Estrutura do nó da árvore binária
typedef struct No
{
    Pokemon pokemon;
    struct No *esq;
    struct No *dir;
} No;

// Função para inicializar um Pokémon
Pokemon *initPokemon(int id, int generation, const char *name, const char *description,
                     const char types[MAX_TYPES][MAX_NAME_LEN], const char abilities[MAX_ABILITIES][MAX_NAME_LEN],
                     double weight, double height, int captureRate, bool isLegendary, struct tm captureDate)
{
    Pokemon *pokemon = (Pokemon *)malloc(sizeof(Pokemon));
    pokemon->id = id;
    pokemon->generation = generation;
    strncpy(pokemon->name, name, MAX_NAME_LEN);
    strncpy(pokemon->description, description, MAX_DESC_LEN);

    for (int i = 0; i < MAX_TYPES; i++)
    {
        strncpy(pokemon->types[i], types[i], MAX_NAME_LEN);
    }

    for (int i = 0; i < MAX_ABILITIES; i++)
    {
        strncpy(pokemon->abilities[i], abilities[i], MAX_NAME_LEN);
    }

    pokemon->weight = weight;
    pokemon->height = height;
    pokemon->captureRate = captureRate;
    pokemon->isLegendary = isLegendary;
    pokemon->captureDate = captureDate;

    return pokemon;
}

// Função para criar um nó na árvore binária
No *initNo(Pokemon *pokemon)
{
    No *newNode = (No *)malloc(sizeof(No));
    newNode->pokemon = *pokemon;
    newNode->esq = newNode->dir = NULL;
    return newNode;
}

// Função para inserir um Pokémon na árvore binária
No *inserir(No *root, Pokemon *pokemon)
{
    if (root == NULL)
    {
        return initNo(pokemon);
    }

    if (strcmp(pokemon->name, root->pokemon.name) < 0)
    {
        root->esq = inserir(root->esq, pokemon);
    }
    else if (strcmp(pokemon->name, root->pokemon.name) > 0)
    {
        root->dir = inserir(root->dir, pokemon);
    }

    return root;
}

// Função para pesquisar um Pokémon na árvore binária
bool pesquisar(No *root, const char *name)
{
    if (root == NULL)
    {
        return false;
    }

    if (strcmp(name, root->pokemon.name) == 0)
    {
        return true;
    }

    if (strcmp(name, root->pokemon.name) < 0)
    {
        printf(" esq");
        return pesquisar(root->esq, name);
    }
    else
    {
        printf(" dir");
        return pesquisar(root->dir, name);
    }
}

// Função para ler a data de captura no formato dd/MM/yyyy
struct tm readDate(const char *dateStr)
{
    struct tm date = {0};
    sscanf(dateStr, "%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);
    date.tm_year -= 1900; // Ajusta o ano para o formato correto
    date.tm_mon -= 1;     // Ajusta o mês
    return date;
}

// Função para ler os dados de um Pokémon de um arquivo CSV
Pokemon *readPokemonFromCSV(FILE *file, const char *id)
{
    char line[1024];
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    char types[MAX_TYPES][MAX_NAME_LEN];
    char abilities[MAX_ABILITIES][MAX_NAME_LEN];
    double weight, height;
    int captureRate;
    bool isLegendary;
    struct tm captureDate;

    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, ",");
        if (token != NULL && strcmp(token, id) == 0)
        {
            // Leitura dos dados
            token = strtok(NULL, ","); // ID
            int generation = atoi(token);
            token = strtok(NULL, ","); // Name
            strncpy(name, token, MAX_NAME_LEN);
            token = strtok(NULL, ","); // Description
            strncpy(description, token, MAX_DESC_LEN);
            token = strtok(NULL, ","); // Type 1
            strncpy(types[0], token, MAX_NAME_LEN);
            token = strtok(NULL, ","); // Type 2 (se houver)
            if (token != NULL)
            {
                strncpy(types[1], token, MAX_NAME_LEN);
            }
            token = strtok(NULL, ","); // Abilities
            strncpy(abilities[0], token, MAX_NAME_LEN);
            token = strtok(NULL, ","); // Weight
            weight = atof(token);
            token = strtok(NULL, ","); // Height
            height = atof(token);
            token = strtok(NULL, ","); // Capture Rate
            captureRate = atoi(token);
            token = strtok(NULL, ","); // Is Legendary
            isLegendary = (strcmp(token, "0") != 0);
            token = strtok(NULL, ","); // Capture Date
            captureDate = readDate(token);

            // Criar e retornar o Pokémon
            return initPokemon(atoi(id), generation, name, description, types, abilities, weight, height, captureRate, isLegendary, captureDate);
        }
    }

    return NULL;
}

int main()
{
    // Inicia o contador de tempo
    clock_t start = clock();

    FILE *file = fopen("tmp/pokemon.csv", "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char id[10];
    No *root = NULL;

    // Ler os Pokémons e inseri-los na árvore binária
    while (scanf("%s", id) && strcmp(id, "FIM") != 0)
    {
        Pokemon *pokemon = readPokemonFromCSV(file, id);
        if (pokemon != NULL)
        {
            root = inserir(root, pokemon);
        }
    }

    // Pesquisar Pokémons
    while (scanf("%s", id) && strcmp(id, "FIM") != 0)
    {
        printf("%s\nraiz", id);
        bool found = pesquisar(root, id);
        if (found)
        {
            printf(" SIM\n");
        }
        else
        {
            printf(" NAO\n");
        }
    }

    fclose(file);

    // Calcula o tempo de execução
    clock_t end = clock();
    double execTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", execTime);

    return 0;
}
