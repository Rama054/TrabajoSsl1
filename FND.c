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

int Columna (char c) {
	switch (c) {
		case '+': 
    case '-':
      return 0;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      return 1;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
      return 2;
    case 'x':
      return 3;
    case '0':
      return 4;
    case '8':
    case '9':
      return 5;
    default:
      return 6;
	}
}

int EsPalabra2 (const char *s) { 
	static int tt [7][7] = {{1,2,6,6,3,2,6}, /* Tabla de Transiciones */
							            {6,2,6,6,6,2,6},
						            	{6,2,6,6,2,2,6},
						            	{6,4,6,5,6,6,6},
                          {6,4,6,6,4,6,6},
                          {6,5,5,6,5,5,6},
                          {6,6,6,6,6,6,6},
                          };
	int e=0; 
	unsigned int i; 
	for (i=0; s[i]!='\0' && e!=6; i++)
	{
		e = tt [e][Columna(s[i])];
    printf("%d\n",e);
	}	
		
	return e!=6; /* estado final? retorna 1 */
} 


int main(int argc, char *argv[])
{
    char cadenaPrincipal[80];
    lista cadenas = NULL;

    scanf("%s",cadenaPrincipal);
    char delimitador[] = "&";
  	char *token;
  	token = strtok(cadenaPrincipal, delimitador);
    while(token!= NULL) 
   	{
      insertarEnLista(&cadenas,token);
      token = strtok(NULL, delimitador);
    }

    if(EsPalabra2(cadenaPrincipal))
      printf("La palabra pertenece al lenguaje\n");
      else
      printf("La palabra no pertenece al lenguaje\n");









    //mostrar(cadenas);



}



