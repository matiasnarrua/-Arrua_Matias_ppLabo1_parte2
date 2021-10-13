/*
 ============================================================================
 Name        : Arrua_Matias_ppLabo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "viaje.h"
#include "aviones.h"
#include "hardcodear.h"
#include "informes.h"
#define TAM_VIAJE 5
#define TAM_M 4
#define TAM 12
#define TAM_HARDCODE 10

int main(void) {

setbuf(stdout, NULL);
int flagSeguir = 1;
char seguir2 = 's';
char confirma2;
int flag = 1;
		char continuar;
		int idAvi = 1;
		eViaje viajes[TAM_VIAJE] = { { 100, "Salta" ,1462.5},{ 101, "Tucuman",1247.6 },{ 102, "Neuquen",1139.4 },{ 103, "Corrientes",670 },{ 104, "Chubut",1735.8 } };
	   eMarca marcas[TAM_M]= { { 1000, "Boeing" },{ 1001, "Airbus" },{ 1002, "ATR" },{ 1003, "Bombardier"} };
		eAviones aviones[TAM];
         inicializarAviones(aviones, TAM);

         hardcodearAvion(aviones, TAM_HARDCODE);


do {
			switch (menu()) {

			case 1:
				system("cls");
				printf("\n ----- Alta ------\n");
				if(altaAvion(aviones, TAM,idAvi,viajes, TAM_VIAJE,marcas,TAM_M)==1){
					idAvi++;
					 flag = 1;
				}

				break;

			case 2:
				system("cls");
				if(flag == 1)
				            {
				                modificarAvion(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				            }
				            else
				            {
				                printf("Error.... Primero debe realizar el alta de un avion");
				            }

				break;

			case 3:
				system("cls");
				if(flag == 1)
				            {
				                bajaAvion(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				            }
				            else
				            {
				                printf("Error.... Primero debe realizar el alta de un avion");
				            }



				printf("\n");
				break;

			case 4:
				system("cls");
				if(flag == 1)
				            { ordenarAviones(aviones, TAM);
				                listarAviones(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				            }
				            else
				            {
				                printf("Error.... Primero debe realizar el alta de un avion");
				            }


				break;

			case 5:
				system("cls");

				                listarViaje(viajes, TAM_VIAJE);
				break;
			case 6:
			 system("cls");
			 listarMarcas(marcas, TAM_M);

			 break;

			case 7:
				 system("cls");
				 if(flag ==1){
				            do
				            {
				                switch (menuInformes())
				                {
				                case 1:
				                	mostrarAvionesBoeing(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				                    break;

				                case 2:
				                	mostrarAvionXMarca(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				                    break;

				                case 3:
                                    mostrarAvionANeuqen(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				                    break;

				                case 4:
				                	mostrarKmsTotalAtr(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				                    break;
				                case 5:
				                   mostrarCantAsientosXTipo(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);

				                    break;

				                case 6:
				                	mostrarPromKmsXFecha(aviones, TAM, marcas, TAM_M, viajes, TAM_VIAJE);
				                    break;

				                case 7:
				                    printf("Confirma salir ?");
				                    fflush(stdin);
				                    scanf("%c", &confirma2);
				                    if (confirma2 == 's')
				                    {
				                        seguir2 = 'n';
				                    }
				                    break;
				                default:
				                				printf("Elija una opcion correcta del menu\n\n");
				                				break;
				                }
				            }
				            while(seguir2 == 's');
				            break;
				 }
				 else
								            {
								                printf("Error.... Primero debe realizar el alta de un avion");
								            }



			break;
			case 8:
				printf("Confirma que quiere salir? (s/n):  ");
				fflush(stdin);
				scanf("%c", &continuar);
				if (continuar == 'n') {
					flagSeguir = 1;
				} else if (continuar == 's') {
					flagSeguir = 0;
				} else {
					printf("ingrese una opcion correcta");
				}
				system("cls");
				break;

			default:
				printf("Elija una opcion correcta del menu\n\n");
				break;

			}
		} while (flagSeguir == 1);




	return EXIT_SUCCESS;
}
