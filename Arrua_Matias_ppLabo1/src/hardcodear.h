/*
 * hardcodear.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Mati
 */


#ifndef HARDCODEAR_H_INCLUDED
#define HARDCODEAR_H_INCLUDED

int idsHard[]= {1,2,3,4,5,6,7,8,9,10};
int idsMarcaHard[] = {1003,1000,1001,1002,1003,1002,1001,1002,1003,1000};
int idsViajeHard [] = { 100, 101, 103,100,104,101, 102, 100, 102,103};
int cantAsientosHard []= {2000,2900,2000,2700,2600,2000,2900,2700,2000,2600};
int matriculaHard[ ]={500,380,484,584,945,1204,6587,54821,359,1478};
int modeloHard[ ]= {1952,2000,2003,2020,2019,2020,2008,2007,2010,2014};
int diaHard[]={19,20,23,20,19,20,28,03,10,14};
int mesHard[]={12,02,03,02,11,10,07,04,10,12};
int anioHard[]={2012,2002,2003,2002,2011,2010,2007,2004,2010,2012};

#endif // HARDCODEAR_H_INCLUDED

void hardcodearAvion(eAviones vec[],int cant);






void hardcodearAvion(eAviones vec[],int cant){
    for(int i =0; i< cant; i++)
    {

        vec[i].idAvion =idsHard[i];
         vec[i].idMarca= idsMarcaHard [i];
        vec[i].idViaje = idsViajeHard[i];
        vec[i].cantAsientos = cantAsientosHard[i];
        vec[i].matricula = matriculaHard[i];
        vec[i].modelo = modeloHard[i];
        vec[i].fecha.dia =diaHard[i];
        vec[i].fecha.mes =mesHard[i];
        vec[i].fecha.anio =anioHard[i];
        vec[i].isEmpty = 0;
    }
}
