/*
 ============================================================================
 Name        : PP1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 4


typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	float precio;
}eNotebook;

int subibaja(char string[]);
int ordenarNotebooks(eNotebook vec[], int tam);

int main(void) {
	setbuf(stdout,NULL);

	char nombre[]="JOAquin";

	eNotebook notebook[TAM]={
				{100, "ADB", "Ryzen", 100000},
				{101, "ABC", "Intel", 300000},
				{102, "BAB", "Intel", 200000},
				{103, "BAA", "Ryzen", 200000}
		};

	ordenarNotebooks(notebook, TAM);

	subibaja(nombre);

	for(int i = 0; i<8; i++)
	{
		printf("%c", nombre[i]);
	}
	for(int i = 0; i<TAM; i++)
	{
		printf("%d     %-4s      %-6s     %f \n",
				notebook[i].id,
				notebook[i].procesador,
				notebook[i].marca,
				notebook[i].precio);
	}


	return 0;
}


/*
 * 1. Crear una función llamada calcularIVA que reciba como primer parámetro el precio bruto de un producto
 * y como segundo parámetro la dirección de memoria de una variable donde debe escribir el valor del impuesto(el IVA es 21%).
 *  La función retorna 1 si salió todo bien o 0 si hubo algún error. Realizar la llamada desde main.
 */
/*int calcularIVA(float precio, float* impuesto)
{

}*/

/*
 * 2. Crear una función que se llame subibaja que reciba una cadena de caracteres y que los caracteres
 * en minúscula los pase a mayúscula y los que están en mayúscula los pase a minúscula retorna 1 si esta todo bien o 0 si hubo algún error.
 */
int subibaja(char string[])
{
	int retorno=0;
	int tam;
	tam = strlen(string);


	for(int i=0; i<tam; i++)
	{
		if(string[i]>= 'A'  && string[i]<= 'Z')
		{
			string[i]=tolower(string[i]);
		}
		else
		{
			string[i]=toupper(string[i]);
		}
	}

	return retorno;
}
/*
 * 3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar
 *  un array de dicha estructura por marca ascendente Ante igualdad de marca deberá ordenarse por precio descendente.
 *   Hardcodear datos y mostrarlos desde el main.
 */


int ordenarNotebooks(eNotebook vec[], int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;


    if(vec != NULL && tam > 0)
    {
    	for(int i = 0; i<tam-1; i++)
		{
			for(int j= i+1; j < tam; j++)
			{
                 if((strcmp(vec[i].marca, vec[j].marca) > 0) || (strcmp(vec[i].marca, vec[j].marca) == 0 && vec[i].precio > vec[j].precio))
                 {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                 }
             }
        }
    }

    return todoOk;
}




