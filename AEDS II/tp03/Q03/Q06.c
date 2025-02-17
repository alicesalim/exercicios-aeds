#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define CSV_FILE_PATH "/tmp/pokemon.csv" 
#define IDNUBMERS_AND_MAXTAM_FILE 802
#define MAX_BUFFER_SIZE 1000
#define MAXTAM_LISTA 200
#define tamvet(vet) (sizeof(vet)/sizeof(vet[0]))
#define foreach(poke, collection, size) \
    for (pokemon *poke = collection; poke < collection + size; poke++)


typedef struct lista{
    char lista[MAXTAM_LISTA][500];      
    int n;                              
}lista;

typedef struct pokemon{
    char id[4];                        
    char generation[200];
    char name[200];                
    char description[200];          
    lista *types;                   
    lista *abilities;               
    char weight[200];                 
    char height[200];                 
    char capture_rate[200];              
    bool is_legendary;              
    char capture_date[11];         
}pokemon;

typedef struct poke_list{
    pokemon array[MAXTAM_LISTA];
    int n;
}poke_list;

void inserir_fim(lista *list, char x []);
char* str_substring(const char *_Str, size_t _Start, size_t _End);

//Str_split apresentou como resultado problemas de memory leak no passado, se possível, evite o seu uso!
char** str_split( char *_Str, const char _Delimiter )
{
    char** _Sequence = NULL;
    size_t _Size = 0;
    if( _Str )
    {
        size_t _Len_Str = strlen( _Str );
        // Contar a quantidade de delimitadores
        char *_tmp = _Str;
        while ( *_tmp )
        {
            if ( *_tmp == _Delimiter ) {
                _Size = _Size + 1;
            } // end if
            _tmp = _tmp + 1;
        } // end while
        _Size = _Size + 1; // Adicionar espaço NULL para terminação da Lista de Strings 

        _Sequence = (char**) malloc( _Size * sizeof(char*) );

        if ( _Sequence )
        {
            size_t _Var   = 0;
            size_t _Start = 0;
            size_t _End   = 0;
            while ( _Var < _Size )
            {
                while ( _End < _Len_Str && *(_Str+_End) != _Delimiter ) { _End++; }

                *(_Sequence+_Var) = str_substring( _Str, _Start, _End-1 );

                if ( *(_Sequence+_Var) == NULL ) {
                    *(_Sequence+_Var) = "";
                } // end if
                _Start = _End + 1; 
                _End = _Start;
                _Var++;
            } // end while
            *(_Sequence+_Var) = NULL;
        } // end if
    } // end if
    return ( _Sequence );
} // end str_split ( )

char* str_substring ( const char *_Str, size_t _Start, size_t _End )
{
    char *_Sub = NULL;
    size_t _Len_Str = strlen( _Str );
    if ( _Start < _Len_Str && _End < _Len_Str  && _Start <= _End )
    {
        size_t _Len = _End - _Start + 1;
        _Sub = (char*) malloc( (_Len+1) * sizeof(char) );
        if( _Sub )
        {
            size_t j = 0;
            size_t i;
            for (  i = _Start; i <= _End; i = i + 1, j = j + 1 ) {
                *(_Sub+j) = *(_Str+i);
            } // end for
            *(_Sub+j) = '\0';
        } // end if
    } // end if
    return ( _Sub );
} // end str_substring ( )

/*Função para remover espaços em branco à esquerda e à direita de uma string*/
char* str_trim ( char *_Str )
{
    char *_Dest = NULL;
    if ( _Str )
    {
        size_t _Len   = strlen(_Str);
        size_t _Start = 0;
        size_t _End   = _Len-1;
        while ( _Start < _End && ( *(_Str+_Start) == ' ' || *(_Str+_Start) == '\n' || *(_Str+_Start) == '\r' || *(_Str+_Start) == '\t' ) )
        { _Start = _Start + 1; }
        while ( _End > _Start && ( *(_Str+_End) == ' ' || *(_Str+_End) == '\n' || *(_Str+_End) == '\r' || *(_Str+_End) == '\t' ) )
        { _End = _End - 1; }
        _Dest = str_substring( _Str, _Start, _End );
    } // end if
    return ( _Dest );
} // end str_ trim( )

/*Função para substituir ocorrências de caracteres dentro de uma mesma String*/
void replace(char *string, char searchchar, char replacechar) {
    char *valueptr = strchr(string, searchchar);  // Encontra a primeira ocorrência de searchchar
    while (valueptr != NULL) {
        // Substitui o caractere encontrado por replacechar
        *valueptr = replacechar;
        // Procura a próxima ocorrência de searchchar
        valueptr = strchr(valueptr + 1, searchchar);
    }
}

lista string_to_list(char elementos []){
    lista novaLista;
    novaLista.n=0;

    replace(elementos,'[',' ');                  //remove colchetes
    replace(elementos,']',' ');
    replace(elementos,'\'',' ');                 //remove aspas simples

    char *token = strtok(elementos, ",");        //Divide os elementos pela vírgula e adiciona à Lista
    while(token!=NULL){
        char *trimmedToken = str_trim(token);        //Remove os espaçoes em branco ao redor do token
        inserir_fim(&novaLista,trimmedToken);    //Insere o token na lista

        token = strtok(NULL,",");                //Pega o próximo token
    }

    return novaLista;

}

void inserir_fim(lista *list, char x []){
     if (list->n == 0) {//verifica se o n de lista já foi inicializado, senão, inicializa
        list->n = 0;
    }

    if(list->n>=MAXTAM_LISTA){
        printf("!!! This code particular Exception!!! Exception 001: Erro ao inserir! Lista cheia!\n");
        exit(1);
    }

    strcpy(list->lista[list->n], x);//copia a String recebida para a última posição da lista
    list->n++;
}

void mostrar_lista(lista *list){
    int i;
    printf("[");

    for(i=0;i<list->n;i++){
        printf("'%s'", list->lista[i]);
        if(i + 1 < list->n){
            printf(", ");
        }
    }
    printf("]");
}

pokemon construtor(char id[], char generation[], char name[], char description[], lista *types, lista *abilities, char weight[], char height[], char capture_rate[], bool is_legendary,char capture_date[]){
    pokemon p;

    strcpy(p.id, id);
    strcpy(p.generation, generation);
    strcpy(p.name,name);
    strcpy(p.description,description);

    p.types = types;
    p.abilities = abilities;

    strcpy(p.weight,weight);
    strcpy(p.height,height);
    strcpy(p.capture_rate,capture_rate);
    p.is_legendary = is_legendary;
    strcpy(p.capture_date,capture_date);

    return p;
}

pokemon construtor_vazio(){
    pokemon p;
    strcpy(p.id, "");
    strcpy(p.generation, "");
    strcpy(p.name,"");
    strcpy(p.description,"");

    p.types = malloc(sizeof(lista));
    p.types->n = 0;
    p.abilities = malloc(sizeof(lista));
    p.abilities->n = 0;


    strcpy(p.weight,"");
    strcpy(p.height,"");
    strcpy(p.capture_rate,"");
    p.is_legendary = false;
    strcpy(p.capture_date,"");

    return p;
}
//ok
char *my_strsep(char **stringp, const char *delim) {
    char *start = *stringp;  // Ponto de partida da string
    char *end;

    // Se a string for nula, retorna nulo
    if (start == NULL) {
        return NULL;
    }

    // Procura pelo próximo delimitador
    end = strpbrk(start, delim);
    
    if (end) {
        // Substitui o delimitador por um caractere nulo
        *end = '\0';
        *stringp = end + 1;  // Avança o ponteiro para o próximo token
    } else {
        // Se não houver mais delimitadores, aponta para NULL
        *stringp = NULL;
    }

    return start;  // Retorna o token encontrado
}
//ok
void preencherVetor(pokemon pokemons[]) {
    FILE *file = fopen(CSV_FILE_PATH, "r");
    if (!file) {
        printf("!!! This code particular Exception!!! Exception 002: Arquivo não encontrado\n");
        exit(1);
    }
    
    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, file);  // Ignora a linha de cabeçalho

    int i = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        // Dividir a linha por aspas
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

        // Agora, dividimos a nova linha por vírgula
        char *parts[12] = {NULL};  // Inicializa com NULL para lidar com campos vazios
        int partsCount = 0;
        char *tmp = novaLinha;

        while ((part = my_strsep(&tmp, ",")) != NULL && partsCount < 12) {
            parts[partsCount++] = part;
        }

        if (partsCount >= 10) {
            // Preenche o objeto pokemon com os dados lidos
            pokemon p = construtor_vazio();
            strcpy(p.id, parts[0]);
            strcpy(p.generation, parts[1]);
            strcpy(p.name, parts[2]);
            strcpy(p.description, parts[3]);

            // Tipos
            lista types = string_to_list(parts[4]);
            if (parts[5] && strlen(parts[5]) > 0) {
                inserir_fim(&types, parts[5]);
            }
            *p.types = types;

            // Habilidades
            lista abilities = string_to_list(preParts[1]);
            *p.abilities = abilities;

            // Peso, altura e taxa de captura
            if (parts[7] && strlen(parts[7]) > 0) {
                strcpy(p.weight, parts[7]);
            } else {
                strcpy(p.weight, "0.0");  // Define como 0.0 se vazio
            }

            if (parts[8] && strlen(parts[8]) > 0) {
                strcpy(p.height, parts[8]);
            } else {
                strcpy(p.height, "0.0");  // Define como 0.0 se vazio
            }

            strcpy(p.capture_rate, parts[9]);

            // Lendário
            p.is_legendary = strcmp(parts[10], "1") == 0 ? true : false;

            // Data de captura
            if (partsCount >= 12 && strlen(parts[11]) > 0) {
                strcpy(p.capture_date, parts[11]);
            }

            // Adiciona o pokémon ao array
            pokemons[i++] = p;

            if (i >= IDNUBMERS_AND_MAXTAM_FILE) {
                break;  // Evita exceder o limite do vetor
            }
        }
    }

    fclose(file);
}
//ok
void imprimir(pokemon pokemon) {
    // Começo do formato: [#ID -> Nome: Descrição - [Tipos] - [Habilidades] - Peso - Altura - CapturaRate - isLegendary - Geração - Data de Captura]

    // Imprime ID, Nome, e Descrição
    printf("[#%s -> %s: %s - ", pokemon.id, pokemon.name, pokemon.description);

    // Imprime a lista de tipos
    if (pokemon.types != NULL) {
        mostrar_lista(pokemon.types);  // Chama a função que já imprime os tipos formatados
    }

    printf(" - ");

    // Imprime a lista de habilidades
    if (pokemon.abilities != NULL) {
        mostrar_lista(pokemon.abilities);  // Chama a função que já imprime as habilidades formatadas
    }

    // Imprime peso, altura, taxa de captura e geração
    printf(" - %skg - %sm - %s%% - %s - %s gen]", pokemon.weight, pokemon.height, pokemon.capture_rate,
           pokemon.is_legendary ? "true" : "false", pokemon.generation);

    char *trimmed_capture_date = str_trim(pokemon.capture_date);
    // Imprime a data de captura, se disponível
    if (strlen(trimmed_capture_date) > 0) {
        printf(" - %s", trimmed_capture_date);
    } else {
        printf(" - Data não disponível");
    }

    // Finaliza a impressão com uma nova linha
    printf("\n");

    // Finaliza a impressão com uma nova linha
}
//ok
void poke_start(poke_list *lista){
    lista->n = 0;
}
char* poke_remover_fim(poke_list *lista){
    if(lista->n == 0){
        printf("Erro ao remover!");
        exit(1);
    }
    return lista->array[--lista->n].name;
}
void poke_mostrar(poke_list *lista){
    int i;

    for(i=0;i<lista->n;i++){
        printf("[%d] ",i);
        imprimir(lista->array[i]);
    }
}

void poke_inserir_fim(pokemon pokemon, poke_list *lista){
    if(lista->n >= MAXTAM_LISTA){
        printf("Erro ao inserir!");
        exit(1);
    }
    lista->array[lista->n] = pokemon;
    lista->n+=1;
}
//ok
void poke_operar(char* operacao, pokemon objeto, int pos, poke_list* lista){
    if(strcmp(operacao,"I")==0){
        poke_inserir_fim(objeto,lista);
    }else if(strcmp(operacao,"R")==0){
        printf("(R) %s\n",poke_remover_fim(lista));
    }
    //poke_mostrar(lista);
}
int main(){


   char entrada[200];
   int result;          
   int i,j=0, count=0;
    pokemon pokemons[IDNUBMERS_AND_MAXTAM_FILE];
    preencherVetor(pokemons);
    pokemon *tmp = malloc(IDNUBMERS_AND_MAXTAM_FILE*sizeof(pokemon));
    scanf("%s" , entrada);

    while(strcmp(entrada,"FIM")!=0){

        for(i=0; i< IDNUBMERS_AND_MAXTAM_FILE;i++){
            result = strcmp(pokemons[i].id,entrada);
            if(result == 0){
                tmp[j] =  pokemons[i];
                count++;
                j++;
            }
        }
        scanf("%s",entrada);
    }
    
    pokemon pokemons_salvos[count];
    poke_list lista;
    poke_start(&lista);     

    for(i=0; i < count; i++){
    pokemons_salvos[i] = tmp[i];
    }
    free(tmp);


    foreach(poke , pokemons_salvos, count){
        poke_inserir_fim(*poke,&lista);
    }

    int num_operacoes;
    scanf("%d",&num_operacoes);

   for(i = 0; i < num_operacoes; i++) {
    scanf(" %[^\n]", entrada);  // Lê a linha inteira de entrada
    char *token[3];
    token[0] = strtok(entrada, " ");
    token[1] = strtok(NULL, " ");
    token[2] = strtok(NULL, " ");

    char *operacao = token[0];
    int pos = -1;
    pokemon pokemon;

    // Verifique se `token[1]` existe e atribua `pos` se necessário
    if (token[1] != NULL) {
        pos = atoi(token[1]);
    }

    // Verifique se `token[2]` existe apenas para operações que precisam de um ID adicional (como "I*")
    if (strcmp(operacao, "I*") == 0 && token[2] != NULL) {
        int id = atoi(token[2]);
        id--;
        if (id >= 0 && id < IDNUBMERS_AND_MAXTAM_FILE) {  
            pokemon = pokemons[id];
        } else {
            printf("Erro: ID de Pokémon inválido.\n");
            continue;
        }
    } else if (token[1] != NULL) { // Para operações como "II" ou "IF"
        int id = atoi(token[1]);
        id--;
        if (id >= 0 && id < IDNUBMERS_AND_MAXTAM_FILE) {
            pokemon = pokemons[id];
            //printf("Pokemon a ser operado:%s\n\n",pokemon.name);
        } else {
            printf("Erro: ID de Pokémon inválido.\n");
            continue;
        }
    }

    // Executa a operação
    poke_operar(operacao, pokemon, pos, &lista);
}

   poke_mostrar(&lista);


    return 0;
}