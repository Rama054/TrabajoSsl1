#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
	static int tt [10][7] = {
                          {1,2,9,9,3,2,9}, /* Tabla de Transiciones */
							            {9,2,9,9,9,2,9},
						            	{9,2,9,9,2,2,9},
						            	{9,4,9,5,7,9,9},
                          {9,4,9,9,4,9,9},
                          {9,6,6,9,8,6,9},
                          {9,6,6,9,6,6,9},
                          {9,9,9,9,9,9,9},
                          {9,9,9,9,9,9,9},
                          {9,9,9,9,9,9,9}
                          };
	int e=0; 
	unsigned int i; 
  printf("estados recorridos = [");
	for (i=0; s[i]!='\0' && e!=9; i++)
	{
		e = tt [e][Columna(s[i])];
    printf("%d, ",e);
	}	
	printf("]\n");
	return e; 
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

    int estadoFinal;
    int cantDecimal = 0;
    int cantOctal = 0;
    int cantHexadecimal = 0;

    while(cadenas !=NULL)
    {
      estadoFinal = EsPalabra2( cadenas ->info);
      if (estadoFinal == 9)
      {
        printf("La cadena contiene una palabra (%s) que no pertenece al lenguaje - TERMINANDO EJECUCION\n",cadenas->info);
        printf("Presione cualquier tecla para continual...");
        getch();
        return 1;
      }

      switch (estadoFinal)
      {
      case 2:
      case 3:
        cantDecimal++;
        break;
      case 4:
      case 7:
        cantOctal++;
        break;       
      case 6:
      case 8:
        cantHexadecimal++;
        break;
      }
      cadenas = cadenas -> sig;
    }

    printf("Se encontraron:\n");
    printf("Decimales: %d\n",cantDecimal);
    printf("Octales: %d\n",cantOctal);
    printf("Hexadecimales: %d\n",cantHexadecimal);

    
    printf("Presione cualquier tecla para continual...");
    getch();
    return 1;
}



