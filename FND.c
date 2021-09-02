#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char *strtok(char *str, const char *delim)

typedef struct snodo{ //snodo es el nombre de la estructura
    char* valor;
    struct snodo *sig; //El puntero siguiente para recorrer la lista enlazada
}tnodo; //tnodo es el tipo de dato para declarar la estructura
 
typedef tnodo *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros
 
void insertarEnLista (tpuntero *cabeza, char* e);
void imprimirLista (tpuntero cabeza);
void borrarLista (tpuntero *cabeza);
 
 
void insertarEnLista (tpuntero *cabeza, char* e){
    tpuntero nuevo; //Creamos un nuevo nodo
    nuevo = malloc(sizeof(tnodo)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->valor = e; //Le asignamos el valor ingresado por pantalla a ese nodo
    nuevo->sig = *cabeza; //Le asignamos al siguiente el valor de cabeza
    *cabeza = nuevo; //Cabeza pasa a ser el ultimo nodo agregado
}
 
void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("%s",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
}
 
void borrarLista(tpuntero *cabeza){ 
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
  
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}
/*
typedef struct nodo
{
  char* data;
  nodo *sig;
}nodo;

void insertar(char *contenido,nodo *raiz)
{
  struct nodo *nuevo = raiz;
  
  if(raiz == NULL)
  {
    raiz = malloc(sizeof(struct nodo));
    raiz->data = contenido;
  }
  else
  {
    while(nuevo->sig != NULL)
    {
    nuevo = nuevo->sig;
    }
    nuevo -> sig = malloc(sizeof(struct nodo));
    nuevo = nuevo -> sig;
    nuevo->data = contenido;
  }
}

void imprimir(nodo* raiz)
{
  struct nodo* aux = raiz;
    while (aux!=NULL)
    {
      printf("HOLAAA\n");
        printf("%s\n ",aux->data);
        aux=aux->sig;
    }
    printf("\n");
}
*/

int main(int argc, char *argv[])
{
    char cadenaPrincipal[80];
    tpuntero raiz = NULL;

    scanf("%s",cadenaPrincipal);
    char delimitador[] = "&";
  	char *token;
  	token = strtok(cadenaPrincipal, delimitador);
    while(token!= NULL) 
   	{
      insertarEnLista(&raiz,token);
      token = strtok(NULL, delimitador);
    }
    imprimirLista(raiz);



}