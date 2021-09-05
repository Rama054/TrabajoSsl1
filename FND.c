#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char *strtok(char *str, const char *delim)

typedef struct nodo
{
	char* info;
	struct nodo *sig;
} nodoL;

typedef nodoL* lista;

void insertarEnLista(lista *L, char* cadena);/* inserta el valor n al frente de la lista */
void mostrar(nodoL* L);/* muestra por pantalla los valores de L, en forma recursiva */
 
 
void insertarEnLista (lista *L, char* cadena){
	lista aux = malloc(sizeof(nodoL)); 
	aux -> info = cadena; 
	aux -> sig = *L; 
	*L=aux; 
	printf("Se agrego %s a la lista\n",cadena); 
}

void mostrar(nodoL* L){
	
	while (L!=NULL){
		printf(" |%s|->",L->info);
    L = L -> sig;
  }
	return;
}
 

int main(int argc, char *argv[])
{
    char cadenaPrincipal[80];
    lista raiz = NULL;

    scanf("%s",cadenaPrincipal);
    char delimitador[] = "&";
  	char *token;
  	token = strtok(cadenaPrincipal, delimitador);
    while(token!= NULL) 
   	{
      insertarEnLista(&raiz,token);
      token = strtok(NULL, delimitador);
    }
    mostrar(raiz);



}