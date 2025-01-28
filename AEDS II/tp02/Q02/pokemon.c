#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER_SIZE 1500
#define MAXTAM_LISTA 250
#define IDNUBMERS_AND_MAXTAM_FILE 802
#define true 1
#define false 0
#define CSV_FILE_PATH "/tmp/pokemon.csv"



typedef struct lista{
    char lista[MAXTAM_LISTA][500];  
    int n;                             
}lista;

typedef struct pokemon{
    char id[4];                        
    char generation[200];
    char nome[200];                 
    char description[200];         
    lista *types;                   
    lista *abilities;               
    char peso[200];                
    char altura[200];                 
    char rate[200];              
    bool is_legendary;              
    char capture_date[11];          

}pokemon;


char **str_split(char*, const char);
char *str_substring(const char *, size_t, size_t );
char *str_trim(char *);
void replace(char *,char,char);
lista string_to_list(char[]);
void inserir_fim(lista*, char[]);
void mostrar(lista*);
pokemon construtor(char id[], char generation[], char nome[], char description[], lista *types, lista *abilities, char peso[], char altura[], char rate[], bool is_legendary,char capture_date[]);
pokemon vazio();
void preencher(pokemon pokemons[]);
char *my_strsep(char **stringp, const char *delim);

char** str_split( char *_Str, const char _Delimiter )
{
    char** _Sequence = NULL;
    size_t _Size = 0;
    if( _Str )
    {
        size_t _Len_Str = strlen( _Str );
        // Contar a quantidade de delimitadores
        char *_Temp = _Str;
        while ( *_Temp )
        {
            if ( *_Temp == _Delimiter ) {
                _Size = _Size + 1;
            } // end if
            _Temp = _Temp + 1;
        } // end while
        _Size = _Size + 1; // Adicionar espaço NULL para terminação da Lista de Strings 

        _Sequence = (char*) malloc( _Size * sizeof(char) );

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

char* str_trim ( char *_Str ){
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

void replace(char *string, char searchchar, char replacechar) {

    char *valueptr = strchr(string, searchchar);  // Encontra a primeira ocorrência de searchchar

    while (valueptr != NULL) {
        
        // Substitui o caractere encontrado por replacechar
        *valueptr = replacechar;
        // Procura a próxima ocorrência de searchchar
        valueptr = strchr(valueptr + 1, searchchar);
    }
}


void inserir_fim(lista *list, char x []){

     if (list->n == 0) {//já foi inicializado? 
        list->n = 0;
    }

    if(list->n>=MAXTAM_LISTA){
        printf("!!! This code particular Exception!!! Exception 001: Erro ao inserir! Lista cheia!\n");
        exit(1);
    }
    \
    strcpy(list->lista[list->n], x);
    list->n++;
}



lista string_to_list(char elementos []){
    lista novaLista;
    novaLista.n=0;
    replace(elementos,']',' ');
    replace(elementos,'\'',' '); 
    replace(elementos,'[',' ');                 
    char *token = strtok(elementos, ",");        //Divide os elemento
    while(token!=NULL){
        char *trimmedToken = str_trim(token);        //Remove os espaços
        inserir_fim(&novaLista,trimmedToken);    //Insere na lista
        token = strtok(NULL,",");                
    }

    return novaLista;

}

void mostrar(lista *list){
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

//<--Funções relacionados à Lista


//Funções relacionadas aos pokemon-->
pokemon construtor(char id[], char generation[], char nome[], char description[], lista *types, lista *abilities, char peso[], char altura[], char rate[], bool is_legendary,char capture_date[]){
    pokemon p;

    strcpy(p.id, id);
    strcpy(p.generation, generation);
    strcpy(p.nome,nome);
    strcpy(p.description,description);

    p.types = types;
    p.abilities = abilities;

    strcpy(p.peso,peso);
    strcpy(p.altura,altura);
    strcpy(p.rate,rate);
    p.is_legendary = is_legendary;
    strcpy(p.capture_date,capture_date);

    return p;
}

pokemon vazio(){
    pokemon p;
    strcpy(p.id, "");
    strcpy(p.generation, "");
    strcpy(p.nome,"");
    strcpy(p.description,"");

    p.types = malloc(sizeof(lista));
    p.types->n = 0;
    p.abilities = malloc(sizeof(lista));
    p.abilities->n = 0;


    strcpy(p.peso,"");
    strcpy(p.altura,"");
    strcpy(p.rate,"");
    p.is_legendary = false;
    strcpy(p.capture_date,"");

    return p;
}

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


// não encontrado
void preencher(pokemon pokemons[]) {
    FILE *file = fopen(CSV_FILE_PATH, "r");
    if (!file) {
        printf("!!! This code particular Exception!!! Exception 002: Arquivo não encontrado\n");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, file);  

    int i = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        // Dividir
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
       
            pokemon p = vazio();
            strcpy(p.id, parts[0]);
            strcpy(p.generation, parts[1]);
            strcpy(p.nome, parts[2]);
            strcpy(p.description, parts[3]);
            lista types = string_to_list(parts[4]);
            if (parts[5] && strlen(parts[5]) > 0) {
                inserir_fim(&types, parts[5]);
            }
            *p.types = types;

            lista abilities = string_to_list(preParts[1]);
            *p.abilities = abilities;

            if (parts[7] && strlen(parts[7]) > 0) {
                strcpy(p.peso, parts[7]);
            } else {
                strcpy(p.peso, "0.0");  
            }

            if (parts[8] && strlen(parts[8]) > 0) {
                strcpy(p.altura, parts[8]);
            } else {
                strcpy(p.altura, "0.0");  
            }

            strcpy(p.rate, parts[9]);
            p.is_legendary = strcmp(parts[10], "1") == 0 ? true : false;


            if (partsCount >= 12 && strlen(parts[11]) > 0) {
                strcpy(p.capture_date, parts[11]);//data
            }

            pokemons[i++] = p; // Adiciona 

            if (i >= IDNUBMERS_AND_MAXTAM_FILE) {
                break;  
            }
        }
    }

    fclose(file);
}



void imprimir(pokemon pokemon) {

    printf("[#%s -> %s: %s - ", pokemon.id, pokemon.nome, pokemon.description);

    if (pokemon.types != NULL) {

        mostrar(pokemon.types);  
    }

    printf(" - ");

    if (pokemon.abilities != NULL) {

        mostrar(pokemon.abilities);  
    }

    printf(" - %skg - %sm - %s%% - %s - %s gen]", pokemon.peso, pokemon.altura, pokemon.rate, pokemon.is_legendary ? "true" : "false", pokemon.generation);

    char *trimmed_capture_date = str_trim(pokemon.capture_date);
   
    if (strlen(trimmed_capture_date) > 0) {

        printf(" - %s", trimmed_capture_date);
    } else {

        printf(" - Data não disponível");
    }


    printf("\n");
}


int main() {

   char id[200];
   int result;
   int i;

    pokemon pokemons[IDNUBMERS_AND_MAXTAM_FILE];
    preencher(pokemons);

    scanf("%s" , id);

    while(strcmp(id,"FIM")!=0){

        for(i=0; i< IDNUBMERS_AND_MAXTAM_FILE;i++){
            result = strcmp(pokemons[i].id,id);
            if(result == 0){
                imprimir(pokemons[i]);
                break;
            }
        }
        scanf("%s",id);
    }

    return 0;
}