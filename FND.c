#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct nodo {
   char* info;
   int numero;
   struct nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

 
int ListaVacia(Lista lista) {
   return (lista == NULL);
}

void Insertar(Lista *lista, char* cadena,int numero) {
   pNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = malloc(sizeof(tipoNodo));
   nuevo->info = cadena;
   nuevo->numero = numero;

   /* Si la lista está vacía */
   if(ListaVacia(*lista)) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista;
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(anterior->siguiente)
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
}

void menu(){
  printf("Presiona 'a' para ejecutar el ejercicio 1\n");
  printf("Presiona 'b' para ejecutar el ejercicio 2\n");
  printf("Presiona 'esc' para salir\n");
  return;
}

void MostrarLista(Lista lista)
{
  pNodo nodo = lista;

  while (nodo)
  {
    printf("%s -> ", nodo->info);
    nodo = nodo->siguiente;
  }
  printf("\n");
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
	static int tt [6][7] = {
                          {1,2,6,6,3,2,6}, /* Tabla de Transiciones */
							            {6,2,6,6,6,2,6},
						            	{6,2,6,6,2,2,6},
						            	{6,4,6,5,4,6,6},
                          {6,4,6,6,4,6,6},
                          {6,5,5,6,5,5,6}
                          };
	int e=0; 
	unsigned int i; 
  printf("estados recorridos = [");
	for (i=0; s[i]!='\0' && e!=6; i++)
	{
		e = tt [e][Columna(s[i])];
    printf("%d, ",e);
	}	
	printf("]\n");
	return e; 
} 

void ejercicio1()
{
  char cadenaPrincipal[80];
  Lista  cadenas = NULL;

  scanf("%s", cadenaPrincipal);
  char delimitador[] = "&";
  char *token;
  token = strtok(cadenaPrincipal, delimitador);
  while (token != NULL)
  {
    Insertar(&cadenas, token,0);
    token = strtok(NULL, delimitador);
  }
  MostrarLista(cadenas);
  int estadoFinal;
  int cantDecimal = 0;
  int cantOctal = 0;
  int cantHexadecimal = 0;

  while (cadenas != NULL)
  {
    estadoFinal = EsPalabra2(cadenas->info);
    if (estadoFinal == 6)
    {
      printf("La cadena contiene una palabra (%s) que no pertenece al lenguaje - TERMINANDO EJECUCION\n", cadenas->info);
      printf("Presione cualquier tecla para continual...");
      getch();
      return;
    }

    switch (estadoFinal)
    {
    case 2:
    case 3:
      cantDecimal++;
      break;
    case 4:
      cantOctal++;
      break;
    case 5:
      cantHexadecimal++;
      break;
    }
    cadenas = cadenas->siguiente;
  }

  printf("Se encontraron:\n");
  printf("Decimales: %d\n", cantDecimal);
  printf("Octales: %d\n", cantOctal);
  printf("Hexadecimales: %d\n", cantHexadecimal);

  printf("Presione cualquier tecla para continual...");
  getch();
}

int Columna2(char c)
{
  switch (c)
  {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
      return 0;
    break;
  case '+':
  case '-':
  case '*':
      return 1;
    break;
  default:
    return 2;
  }
}

int esOperacion(char *s)
{
  static int tt [3][3] =  {
                          {1,3,3},
                          {1,0,3},
                          {3,3,3}
                          };
  
  int e=0; 
	unsigned int i; 
  printf("estados recorridos = [");
	for (i=0; s[i]!='\0' && e!=3; i++)
	{
		e = tt [e][Columna2(s[i])];
    printf("%d, ",e);
	}	
	printf("]\n");
	return e; 
}

int Valor(int c)
{
  return (c - '0');
}

int operarCaracteres(int resultado, int numero, char operacion)
{
  switch (operacion)
  {
  case '+':
    resultado = resultado + numero;
    break;
  case '-':
    resultado = resultado - numero;
    break;
  }
  return resultado;
}

void concatenarCharACadena(char *cadena, char c)
{
  char cadenaTemporal[2];
  cadenaTemporal[0] = c;
  cadenaTemporal[1] = '\0';
  strcat(cadena, cadenaTemporal);
}

int multiplicar(char *cadena, int resultado)
{
  char d;
  int i = 0;
  int j = 0;
  int n2 = 0;

  while (cadena[i] != 00)
  {
    for (j; cadena[j] != '*' && cadena[j] != 00; j++)
    {
      d = cadena[j];
      n2 = n2 * 10 + Valor(d);
      printf("Valor %d\n", n2);
    }
    resultado = resultado * n2;
    n2 = 0;
    if (cadena[j] != 00)
    {
      j++;
    }
    i = j;
  }
  printf("Resultado: %d\n", resultado);
  return resultado;
}

int realizarOperacion(char *cadenaDeOperaciones)
{
  int resultado = 0;
  int i = 0, j = 0, numero = 0, n2 = 0;
  char digito = ' ';
  char operacion = '+';

  while (cadenaDeOperaciones[i] != '\0')
  {
    for (j; (cadenaDeOperaciones[j] != '+') && (cadenaDeOperaciones[j] != '-') && (cadenaDeOperaciones[j] != '\0'); j++)
    {
      digito = cadenaDeOperaciones[j];
      if (digito == '*')
      {
        char c[] = "";
        j++;
        for (j; (cadenaDeOperaciones[j] != '+') && (cadenaDeOperaciones[j] != '-') && (cadenaDeOperaciones[j] != '\0'); j++)
        {
          concatenarCharACadena(c, cadenaDeOperaciones[j]);//Cadena de operaciones unicamente con multiplicaciones
        }
        numero = multiplicar(c, numero);
        j--;
      }
      else
      {
        numero = numero * 10 + Valor(digito);//Agrega el digito leido al numero que se esta formando 
      }
    }

    resultado = operarCaracteres(resultado, numero, operacion);//Se encarga de operar el numero obtenido en el termino con el resultado que se va a devolver
    
    char x = cadenaDeOperaciones[j];
    if (x == '+' || x == '-' || x == 00)
    {
      operacion = cadenaDeOperaciones[j];
    }
    if (x != 00)
    {
      j++;
    }
    numero = 0;
    i = j;
  }

  return resultado;
}

void ejercicio2(){
  char operacion[80];
  Lista  cadena = NULL;
  printf("Introduzca una operacion\n");
  scanf("%s",operacion);

  int estadoFinal;
  estadoFinal = esOperacion(operacion);
  if (estadoFinal == 3 || estadoFinal == 0)
  {
    printf("La cadena contiene una palabra (%s) que no pertenece al lenguaje - TERMINANDO EJECUCION\n", operacion);
    printf("Presione cualquier tecla para continual...");
    getch();
    return;
  }
  printf("La operacion es valida\n");
  int resultado = realizarOperacion(operacion);
  printf("%d\n",resultado);
  MostrarLista(cadena);
  getch();  
  return;   
}


int main(int argc, char *argv[])
{
  char opcion;
  menu();
  opcion = getch();
  while(opcion!=27)
  {
    switch (opcion)
    {
    case 'a':
    case 'A':
      printf("Escriba una cadena\n");
      ejercicio1();
      return 1;
      break;
    case 'b':
    case 'B':
      ejercicio2();
      return 1;
      break;
    }
    system("cls");
    menu();
    opcion = getch();
  }
  
  return 1;
}
