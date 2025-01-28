#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CSV_FILE_PATH "/tmp/pokemon.csv"
#define IDNUBMERS_AND_MAXTAM_FILE 802
#define MAXTAM_LISTA 200
#define true 1
#define false 0
#define MAX_BUFFER_SIZE 1000

#define foreach(poke, collection, size) \
    pokemon *poke; \
    for (poke = collection; poke < collection + size; poke++)

typedef struct lista {
    char lista[MAXTAM_LISTA][500];
    int n;
} lista;

typedef struct pokemon {
    char id[4];
    char generation[200];
    char description[200];
    lista *types;
    lista *abilities;
    char weight[200];
    char height[200];
    char capture_rate[200];
    bool is_legendary;
    char capture_date[11];
    char name[200];
} pokemon;

char **str_split(char*, const char);
char *str_substring(const char*, size_t, size_t);
char *str_trim(char*);
void replace(char*, char, char);
int comparaElementos(pokemon a, pokemon b);
lista string_to_list(char[]);
void inserir_fim(lista*, char[]);
void mostrar_lista(lista*);
pokemon construtor(char id[], char generation[], char name[], char description[], lista *types, lista *abilities, char weight[], char height[], char capture_rate[], bool is_legendary, char capture_date[]);
pokemon construtor_vazio();
void preencherVetor(pokemon pokemons[]);
char *my_strsep(char **stringp, const char *delim);
int pesquisa_binaria(pokemon[], char*, int);
int comparar_pokemon(const void *a, const void *b);
void swap(pokemon *a, pokemon *b);
void selection_sort_rec(pokemon pokes[], int i, int n);
void shell_sort(pokemon arr[], int n);
float get_weight_as_float(char *weight);

char** str_split(char *_Str, const char _Delimiter) {
    char** _Sequence = NULL;
    size_t _Size = 0;
    if (_Str) {
        size_t _Len_Str = strlen(_Str);
        char *_Temp = _Str;
        while (*_Temp) {
            if (*_Temp == _Delimiter) {
                _Size = _Size + 1;
            }
            _Temp = _Temp + 1;
        }
        _Size = _Size + 1;
        _Sequence = (char**)malloc(_Size * sizeof(char*));
        if (_Sequence) {
            size_t _Var = 0;
            size_t _Start = 0;
            size_t _End = 0;
            while (_Var < _Size) {
                while (_End < _Len_Str && *(_Str + _End) != _Delimiter) {
                    _End++;
                }
                *(_Sequence + _Var) = str_substring(_Str, _Start, _End - 1);
                if (*(_Sequence + _Var) == NULL) {
                    *(_Sequence + _Var) = "";
                }
                _Start = _End + 1;
                _End = _Start;
                _Var++;
            }
            *(_Sequence + _Var) = NULL;
        }
    }
    return (_Sequence);
}

char* str_substring(const char *_Str, size_t _Start, size_t _End) {
    char *_Sub = NULL;
    size_t _Len_Str = strlen(_Str);
    if (_Start < _Len_Str && _End < _Len_Str && _Start <= _End) {
        size_t _Len = _End - _Start + 1;
        _Sub = (char*)malloc((_Len + 1) * sizeof(char));
        if (_Sub) {
            size_t j = 0;
            size_t i;
            for (i = _Start; i <= _End; i = i + 1, j = j + 1) {
                *(_Sub + j) = *(_Str + i);
            }
            *(_Sub + j) = '\0';
        }
    }
    return (_Sub);
}

char* str_trim(char *_Str) {
    char *_Dest = NULL;
    if (_Str) {
        size_t _Len = strlen(_Str);
        size_t _Start = 0;
        size_t _End = _Len - 1;
        while (_Start < _End && (*(_Str + _Start) == ' ' || *(_Str + _Start) == '\n' || *(_Str + _Start) == '\r' || *(_Str + _Start) == '\t')) {
            _Start = _Start + 1;
        }
        while (_End > _Start && (*(_Str + _End) == ' ' || *(_Str + _End) == '\n' || *(_Str + _End) == '\r' || *(_Str + _End) == '\t')) {
            _End = _End - 1;
        }
        _Dest = str_substring(_Str, _Start, _End);
    }
    return (_Dest);
}

void replace(char *string, char searchchar, char replacechar) {
    char *valueptr = strchr(string, searchchar);
    while (valueptr != NULL) {
        *valueptr = replacechar;
        valueptr = strchr(valueptr + 1, searchchar);
    }
}

int comparaElementos(pokemon a, pokemon b) {
    return strcmp(a.name, b.name);
}

lista string_to_list(char elementos[]) {
    lista novaLista;
    novaLista.n = 0;
    replace(elementos, '[', ' ');
    replace(elementos, ']', ' ');
    replace(elementos, '\'', ' ');
    char *token = strtok(elementos, ",");
    while (token != NULL) {
        char *trimmedToken = str_trim(token);
        inserir_fim(&novaLista, trimmedToken);
        token = strtok(NULL, ",");
    }
    return novaLista;
}

void inserir_fim(lista *list, char x[]) {
    if (list->n >= MAXTAM_LISTA) {
        printf("!!! This code particular Exception!!! Exception 001: Erro ao inserir! Lista cheia!\n");
        exit(1);
    }
    strcpy(list->lista[list->n], x);
    list->n++;
}

void mostrar_lista(lista *list) {
    int i;
    printf("[");
    for (i = 0; i < list->n; i++) {
        printf("'%s'", list->lista[i]);
        if (i + 1 < list->n) {
            printf(", ");
        }
    }
    printf("]");
}

pokemon construtor(char id[], char generation[], char name[], char description[], lista *types, lista *abilities, char weight[], char height[], char capture_rate[], bool is_legendary, char capture_date[]) {
    pokemon p;
    strcpy(p.id, id);
    strcpy(p.generation, generation);
    strcpy(p.name, name);
    strcpy(p.description, description);
    p.types = types;
    p.abilities = abilities;
    strcpy(p.weight, weight);
    strcpy(p.height, height);
    strcpy(p.capture_rate, capture_rate);
    p.is_legendary = is_legendary;
    strcpy(p.capture_date, capture_date);
    return p;
}

pokemon construtor_vazio() {
    pokemon p;
    strcpy(p.id, "");
    strcpy(p.generation, "");
    strcpy(p.name, "");
    strcpy(p.description, "");
    p.types = malloc(sizeof(lista));
    p.types->n = 0;
    p.abilities = malloc(sizeof(lista));
    p.abilities->n = 0;
    strcpy(p.weight, "");
    strcpy(p.height, "");
    strcpy(p.capture_rate, "");
    p.is_legendary = false;
    strcpy(p.capture_date, "");
    return p;
}

char *my_strsep(char **stringp, const char *delim) {
    char *start = *stringp;
    char *end;
    if (start == NULL) {
        return NULL;
    }
    end = strpbrk(start, delim);
    if (end) {
        *end = '\0';
        *stringp = end + 1;
    } else {
        *stringp = NULL;
    }
    return start;
}

void preencherVetor(pokemon pokemons[]) {
    FILE *file = fopen(CSV_FILE_PATH, "r");
    if (!file) {
        printf("!!! This code particular Exception!!! Exception 002: Arquivo não encontrado\n");
        exit(1);
    }
    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, file);
    int i = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        char *preParts[3] = {NULL, NULL, NULL};
        int prePartsCount = 0;
        char *part = strtok(buffer, "\"");
        while (part && prePartsCount < 3) {
            preParts[prePartsCount++] = part;
            part = strtok(NULL, "\"");
        }
        char novaLinha[MAX_BUFFER_SIZE];
        if (prePartsCount > 2) {
            snprintf(novaLinha, MAX_BUFFER_SIZE, "%s%s", preParts[0], preParts[2]);
        } else {
            strncpy(novaLinha, buffer, MAX_BUFFER_SIZE);
        }
        char *parts[12] = {NULL};
        int partsCount = 0;
        char *tmp = novaLinha;
        while ((part = my_strsep(&tmp, ",")) != NULL && partsCount < 12) {
            parts[partsCount++] = part;
        }
        if (partsCount == 12) {
            pokemon novo = construtor(
                parts[0],
                parts[1],
                parts[2],
                parts[3],
                malloc(sizeof(lista)),
                malloc(sizeof(lista)),
                parts[4],
                parts[5],
                parts[6],
                strcmp(parts[7], "TRUE") == 0,
                parts[8]
            );
            novo.types = string_to_list(parts[9]);
            novo.abilities = string_to_list(parts[10]);
            pokemons[i++] = novo;
        }
    }
    fclose(file);
}

int pesquisa_binaria(pokemon *pokemons, char* name, int n) {
    int inicio, meio, fim;
    inicio = 0; 
    fim = n - 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        int comparacao = strcmp(pokemons[meio].name, name);
        if (comparacao == 0) {
            return meio;
        } 
        else if (comparacao > 0) {
            fim = meio - 1;
        } 
        else {
            inicio = meio + 1;
        }
    }
    return -1;
}

int comparar_pokemon(const void *a, const void *b) {
    pokemon *pokemonA = (pokemon *)a;
    pokemon *pokemonB = (pokemon *)b;
    return strcmp(pokemonA->name, pokemonB->name);
}

void swap(pokemon *a, pokemon *b) {
    pokemon temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort_rec(pokemon pokes[], int i, int n) {
    if (i >= n - 1) return;
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
        if (comparaElementos(pokes[j], pokes[minIdx]) < 0) {
            minIdx = j;
        }
    }
    swap(&pokes[i], &pokes[minIdx]);
    selection_sort_rec(pokes, i + 1, n);
}

void shell_sort(pokemon arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            pokemon temp = arr[i];
            int j;
            for (j = i; j >= gap && comparaElementos(arr[j - gap], temp) > 0; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

float get_weight_as_float(char *weight) {
    return atof(weight);
}
