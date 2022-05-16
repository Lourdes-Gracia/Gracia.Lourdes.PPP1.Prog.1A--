/*
 ============================================================================
 a) Crear una función llamada aplicarAumento que reciba como parámetro el precio
 de un producto y devuelva el valor del producto con un aumento del 5%.
 Realizar la llamada desde el main.


 b)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMV 5
//A
float calcularAumento(float precioOriginal);

//B
typedef struct
{
	int id;
	char nombre[];
	char tipo;
	int isEmpty;
	float efectividad;
}eVacuna;
int creciente(eVacuna vacunas[], int tam);
int listar(eVacuna vec[], int tam);
int mostrar(eVacuna vec, int tam);
int main()
{
	setbuf(stdout, NULL);
	float precio;

printf("Ingrese precio a aumentar : ");
scanf("%f", &precio);
while(precio < 0)
{
	printf("Error reingrese precio a aumentar  ");
	scanf("%f", &precio);
}

calcularAumento(precio);


eVacuna vacunas[TAMV] =
    {
        {7000, "Vacuna 1","a", 500},
        {7001, "Vacuna 2","b", 600},
        {7002, "Vacuna 3","c", 450},
        {7003, "Vacuna 4","a", 650},
        {7004, "Vacuna 5","c", 550}
    };

creciente(vacunas, TAMV);

return 0;
}


float calcularAumento(float precioOriginal)
{
    int todoOk = 0;
    float aumento ;
    float precioConAumento;

      	 aumento = precioOriginal * 0.05;

      	 precioConAumento = precioOriginal + aumento;

      	printf("Precio con aumento: %0.2f", precioConAumento);

return todoOk;
}
int creciente(eVacuna vacunas[], int tam)
{
	int todoOk = 0;

	eVacuna auxV;
	    if(vacunas != NULL && tam > 0)
	    {
	        for(int i=0; i < tam -1; i++)
	        {
	            for(int j= i + 1; j < tam; j++)
	            {
	                if(vacunas[i].tipo > vacunas[j].tipo && (vacunas[i].efectividad > vacunas[j].efectividad))
	                {
	                	auxV = vacunas[i];
	                	vacunas[i] = vacunas[j];
	                	vacunas[j] = auxV;
	                }
	            }
	        }
	        todoOk = 1;
	    }
	return todoOk;
}
int listar(eVacuna vec[], int tam)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("          *** Listado ***\n\n");
        printf(" id          Nombre     Tipo    Efectividad  \n");
        printf("-----------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrar(vec[i]);
                flag++;
            }
        }

        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrar(eVacuna vec, int tam)
{
	int todoOk = 0;

	    if(vec != NULL && tam > 0)
	    {

	        printf("    %4d       %15s       %c      %9.2f   \n",
	               vec.id,
	               vec.nombre,
	               vec.tipo,
				   vec.efectividad
	              );
	        todoOk = 1;
	    }
}
