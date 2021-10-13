/*
 * informes.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Mati
 */

/*
.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"
#include "marca.h"
#include "viaje.h"
#include "aviones.h"


int menuInformes()
{
    int opcion;

    system("cls");
    printf("***---*** Informes ***---***\n\n");
    printf("1. Mostrar aviones Boeing\n2. Mostrar aviones de una marca \n3. Informar aviones que viajaron a Neuquen\n4. Informar kms totales de los aviones ATR\n5. Informar la cantidad total de asientos para un modelo de avion seleccionado\n"
           "6. Informar Promedio de kms para los aviones que viajaron en una fecha seleccionada \n7. Volver al menu principal\n\n");
    fflush(stdin);
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}


void mostrarAvionesBoeing(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje)
{


    int flag = 0;
    int auxTipo = 1000;

    system("cls");
    printf("*****Listado de Aviones Boeing*****\n\n");

    printf("       Id     Modelo              Viaje            Marca     Matricula     Cant/Asientos           Fecha       \n");

    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 && auxTipo == aviones[i].idMarca )
        {
        	 mostrarAvion (aviones [i], marcas, tamMarc,viajes, tamViaje);

            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay aviones que mostrar****\n\n");
    }
    system("pause");
}

void mostrarAvionXMarca(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje){


    int flag = 0;
    int auxMarca;

    system("cls");
    printf("*****Listado de aviones por Marca*****\n\n");

    listarMarcas(marcas, tamMarc);

    printf("Ingrese el id de la marca que quiera mostrar: ");
    scanf("%d", &auxMarca);
    if(auxMarca <1000 || auxMarca>1003)
    {
        printf("\nError selecciones un id de tipo valido: ");
        scanf("%d", &auxMarca);
    }
    printf("       Id     Modelo              Viaje            Marca     Matricula     Cant/Asientos           Fecha      \n");

    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 && auxMarca == aviones[i].idMarca )
        {
        	mostrarAvion (aviones [i], marcas, tamMarc,viajes, tamViaje);

            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay aviones que mostrar****\n\n");
    }

    system("pause");

}

void mostrarAvionANeuqen(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje)
{


    int flag = 0;
    int auxViaje = 102 ;

    system("cls");
    printf("*****Listado de aviones que viajan a Neuquen*****\n\n");

    printf("       Id     Modelo              Viaje            Marca     Matricula     Cant/Asientos           Fecha      \n");

    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 && auxViaje == aviones[i].idViaje )
        {
        	mostrarAvion (aviones [i], marcas, tamMarc,viajes, tamViaje);

            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay aviones que mostrar****\n\n");
    }

    system("pause");

}

void mostrarKmsTotalAtr(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje)
{


    int flag = 0;
    int auxAtr = 1002 ;
    float kmsTotal= 0;

    system("cls");
    printf("*****Kilometros totales de la aerolinea ATR*****\n\n");


    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 && auxAtr == aviones[i].idMarca )
        {
        	for(int j=0; j<tamViaje;j++){
        		if(aviones[i].idViaje == viajes[j].idViaje){
        			kmsTotal += viajes[j].kms;
        		}
        	}

            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay kilometros registrados por ATR****\n\n");
    }
printf("\n Los kilometros totales registrados por ATR son: %.2f\n\n", kmsTotal);

    system("pause");

}


void mostrarCantAsientosXTipo(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje){


    int flag = 0;
    int auxModelo;
    int auxAsientos= 0;
    system("cls");
    printf("*****Cantidad de asientos del modelo seleccionado*****\n\n");

    printf("ingrese el Modelo que quiere mostrar: ");
    		scanf("%d", &auxModelo);
    		while (auxModelo < 1950 || auxModelo > 2021) {
    					printf("error ingrese modelo valido (1950-2021)");
    					scanf("%d", &auxModelo);
    		}

    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 && auxModelo == aviones[i].modelo )
        {
        	auxAsientos += aviones[i].cantAsientos;

            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay aviones que mostrar****\n\n");
    }
    printf("La cantidad de asientos es: %d\n\n",auxAsientos);
    system("pause");

}


void mostrarPromKmsXFecha(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje)
{

    int flag = 0;
   int diaAux;
   int mesAux;
   int anioAux;
   int contador=0;
   float kmsTotal=0;
   float kmsPromedio=0;

        system("cls");
        printf("*****Promedio de kilometros por Fehca*****\n\n");
        printf("ingrese la fecha ( DIA ): ");
        		scanf("%d", &diaAux);
        		while (diaAux < 0 ||diaAux > 31) {
        			printf("error ingrese un dia valido");
        			scanf("%d", &diaAux);
        		}
        		printf("ingrese la fecha ( MES ): ");
        		scanf("%d", &mesAux);
        		while (mesAux < 0 || mesAux > 12) {
        			printf("error ingrese un mes valido");
        			scanf("%d", &mesAux);
        		}

        		printf("ingrese la fecha ( ANIO ): ");
        		scanf("%d", &anioAux);
        		while (anioAux < 2000 || anioAux > 2021) {
        			printf("error ingrese un anio valido (2000-2021)");
        			scanf("%d", &anioAux);
        		}

    system("cls");
    printf("*****Promedio de kilometros en la fecha seleccionada*****\n\n");


    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 && anioAux == aviones[i].fecha.anio && mesAux == aviones[i].fecha.mes && diaAux == aviones[i].fecha.dia)
        {
        	for(int j=0; j<tamViaje;j++){
        		if(aviones[i].idViaje == viajes[j].idViaje){
        			kmsTotal += viajes[j].kms;
        			contador++;
        		}
        	}

            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay viajes registrados****\n\n");
    }

   kmsPromedio= kmsTotal/contador;
printf("\n el promedio de kms registrados es: %.2f\n\n", kmsPromedio);

    system("pause");

}
