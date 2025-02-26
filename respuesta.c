/*
Cadenas Dispersas
Se debe implementar una estructura de datos en C que represente una cadena de texto utilizando una lista enlazada simple, donde cada nodo almacena una única palabra
Funcionalidad esperada:

Se debe implementar:

    Crear a partir de una cadena convencional y un separador indicado / destruir cadena.
    Imprimir, esta función debe mostrar por consola la cadena usando el separador.
    Obtener largo de la cadena, incluyendo el separador
    Obtener una palabra de una posición específica.
    Substituir una palabra en una posición por otra dada.
    Insertar palabra en una posición específica.
    Eliminar una palabra indicada por su posición.

Aspectos que serán evaluados

El código debe de estar documentado.

No es necesario desarrollar un main que haga uso de las funciones.

En su lugar, dejá un boceto de cómo probarías el código; qué argumentos recibiría, cómo sería lo que devuelve y contra qué lo compararías.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LARGO 100
#define TODO_OK 0
#define PUNTERO_NULO -1
#define SIN_TERMINADOR -2

typedef struct Nodo
{
	char palabra[MAX_LARGO];
	struct Nodo *Nodo;
} Nodo;

void imprimir_cadena_indices(char cadena[], int comienzo, int fin)
{
	int largo_palabra = fin - comienzo;
	char palabra[50];
	int i = 0;
	while (comienzo < fin && i < largo_palabra)
	{
		palabra[i] = cadena[comienzo];
		//printf("%c", cadena[comienzo]);
		printf("i: %d, comienzo %d\n", i, comienzo);
		i++;
		comienzo++;
	}
	//printf("i:%d\n", i);
	palabra[(i + 1)] = '\0';
	printf("%s\n", palabra);
	printf("Largo: %d\n", largo_palabra);
}

void imprimir_cadena_separador(char cadena[], int indice_separador)
{
	int i = 0;
	while (i <= indice_separador)
	{
		printf("%c", cadena[i]);
		i++;
	}
	printf("\n");
}

int largo_cadena_separador(char cadena[], int capacidad)
{
	int largo = 0;
	int contador = 0;
	while ((contador < capacidad) && (cadena[contador] != '/'))
	{
		largo++;
		contador++;
	}
	return largo;
}

int crear_elemento_lista(Nodo *raiz, char contenido[])
{
	Nodo *nuevo_nodo = malloc(sizeof(Nodo));
}

int separar_palabras(char cadena[], int capacidad)
{
	int codigo;
	int punto_de_partida = 0;
	if (cadena == NULL)
	{
		return PUNTERO_NULO; 
	}
	else if (cadena[(capacidad - 1)] != '\0')
	{
		return SIN_TERMINADOR;
	}
	else
	{
		//int primer_separador = 0;
		//int segundo_separador = primer_separador + 1;
		//meter la cadena de caracteres entre los dos indices que contienen los separadores?
		//crear una cadena temporal que guarde la palabra extraida para que sea guardada en la lista?
		for (int primer_separador = punto_de_partida; primer_separador < capacidad; primer_separador++)
		{
			//printf("PS:%d\n", primer_separador);
			printf("%c", cadena[primer_separador]);
			printf("Punto de partida actual: %d\n", punto_de_partida);
			printf("Primer separador actual: %d\n", primer_separador);
			if (cadena[primer_separador] == '_')
			{
				printf("\n");
				//printf("Encontrado primer separador\n");
				for (int segundo_separador = (primer_separador + 1); segundo_separador < capacidad; segundo_separador++)
				{
					//printf("SS:%d\n", segundo_separador);
					if (cadena[segundo_separador] == '_')
					{
						//printf("Segundo separador encontrado\n");
						//char palabra_extraida[50];
						//for (int x = 0; x <
						//printf("Palabra: %c %c\n", cadena[primer_separador + 1], cadena[segundo_separador - 1]);
						imprimir_cadena_indices(cadena, (primer_separador + 1), segundo_separador);
						punto_de_partida = (segundo_separador + 1);
						codigo = segundo_separador - (primer_separador + 1);
						//printf("Longitud palabra: %d\n", codigo);
					}
				}
			}
		}
	}
	return codigo;
}

//
int main()
{
	char prueba[] = "polapa/jamaica/boca/";
	printf("Cadena:\n");
	printf("%s\n", prueba);
	int longitud = sizeof(prueba) / sizeof(prueba[0]);
	int largo_hasta_separador = largo_cadena_separador(prueba, longitud);
	imprimir_cadena_separador(prueba, largo_hasta_separador);
	
	//printf("Largo: %d\n", longitud);
	/*int retorno = separar_palabras(prueba, longitud);
	if (retorno >= TODO_OK)
	{
		printf("Longitud: %d\n", retorno);
	}
	else if (retorno == PUNTERO_NULO)
	{
		printf("Error: el puntero pasado a la funcion es nulo\n");
	}
	else
	{
		printf("Error: la cadena no tiene un terminador en el indice esperado\n");
	}*/
	printf("%s\n", prueba);
	return 0;
}
