/*
 * Servicios.c
 *
 *  Created on: 15 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef SERVICIOS_C_
#define SERVICIOS_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Mecanico.h"//no lo reconoce
#include "Especialidad.h"

#define EMPTY -1

void InicializarServicios(eServicio servicio[], int tamServicio)
{
	int i;

	for(i=0;i<tamServicio;i++)
		{

			servicio[i].isEmpty = EMPTY;
			servicio[i].isEmptyMecanico = EMPTY;


		}


}




void AgregarServicio(eServicio servicio[], int tamServicio, int id)
{
	int i;
	i = BuscarLibre(servicio, tamServicio);

	if(i!= EMPTY)
		{
			PedirServicio(servicio, tamServicio, i);
			servicio[i].idServicio = id;

		}else
		{
			printf("No hay espacio...\n");
		}



}
int BuscarLibre(eServicio servicio[], int tamServicio)
{
	int i;
	int index = -1;

	for(i=0;i<tamServicio;i++)
	{
		if(servicio[i].isEmpty == EMPTY)
		{
			index = i;
			break;
		}
	}



	return index;

}
void PedirServicio(eServicio servicio[], int tamServicio, int i)
{


	char nombreCliente[51];
	int diagnostico;


	int confirm;

	getName(nombreCliente, "Ingrese el nombre: ", "ERROR, ingrese el nombre: ", 51);
	getInt(&diagnostico, "Ingrese el diagnostico (1. cambio aceite, 2.Cambio motor 3.Suspencion): ", "ERROR, ingrese el diagnostico(1. cambio aceite, 2.Cambio motor 3.Suspencion): ", 1, 3);

	PedirFechas(servicio,i);

	 confirm = ConfirmarProducto("Ingrese S para guardar el servicio");


	 if(confirm == 1)
	 {
		 	strcpy(servicio[i].nombreCliente,nombreCliente);
		 	servicio[i].diagnostico = diagnostico;
		 	servicio[i].cotizacion = 0;


		 	servicio[i].isEmpty = 1;


	 }






}

void PedirFechas(eServicio servicio[], int i)
{

	int ret;
	int dia;
	int mes;
	int anio;

	PreguntarFechas(&dia,  &mes,  &anio);


	while (ret == 0)
		    {
				printf("\n\n");
		        switch (mes)
		        {
		            case  1 :
		            case  3 :
		            case  5 :
		            case  7 :
		            case  8 :
		            case 10 :
		            case 12 :
		            	if (dia >= 1 && dia <= 31)
		            	{
		                          ret = 1;
		            	}
		                      break;

		            case  4 :
		            case  6 :
		            case  9 :
		            case 11 :
		            	if (dia >= 1 && dia <= 30)
		            		{
		                         ret = 1;
		            		}
		                      break;

		            case  2 :
		                          if ( dia >= 1 && dia <= 28 )
		                          {
		                              ret = 1;
		                          }


		        }

		        if(ret == 1)
		        {

		        	servicio[i].fecha.dia = dia;
		        	servicio[i].fecha.mes = mes;
		        	servicio[i].fecha.anio = anio;




		        }else
		        {
		        	printf("Hubo un ERROR con las fechas\n");
		        	PreguntarFechas(&dia,  &mes,  &anio);

		        }
		    }










}

void PreguntarFechas(int* dia, int* mes, int* anio)
{
	getInt(anio, "Ingrese el anio: ", "ERROR, ingrese el anio: ", 2022, 2030);
	getInt(mes, "Ingrese el mes: ", "ERROR, ingrese el mes: ", 1, 12);
	getInt(dia, "Ingrese el dia: ", "ERROR, ingrese el dia: ", 1, 31);

}




int ConfirmarProducto(char* message)
{
	int ret;
	char confirm;

	ret = -1;

	getChar(&confirm, "Ingrese S para guardar el servicio: ");
	confirm = tolower(confirm);

		if(confirm == 's' )
		{

			ret = 1;

		}

		return ret;

}



int BuscarProductoID(eServicio servicio[], int tamServicio, int id)
{
	int ret = EMPTY;
	int i;

	for(i=0;i<tamServicio;i++)
	{
		if(servicio[i].idServicio == id)
		{
			ret = i;
			break;
		}
	}

	return ret;
}




void EliminarServicio(eServicio servicio[], int tamServicio)
{
		int id;
		int confirm;
		int index;


		ListarServicios(servicio, tamServicio);
		getInt(&id, "Ingrese el ID a eliminar\n", "ERROR, ingrese el ID a eliminar\n", 5000, 6000);
		index = BuscarProductoID(servicio, tamServicio, id);


		if(index > EMPTY)
		{
			getInt(&confirm, "Estas seguro? (1.si / 2.no)\n", "Estas seguro? (1.si / 2.no)\n", 1, 2);
				if(confirm == 1)
				{
					servicio[index].isEmpty = EMPTY;
					servicio[index].isEmptyMecanico = EMPTY;

				}

		}else
		{
			printf("Ese servicio no existe!!!\n");
		}
}



void ListarServicio(eServicio servicio)//SE QUEDA, ESTA BIEN
{
	printf("%-20d  %-20d  %-20s  %-20.2f  %d/%d/%d \n", servicio.idServicio, servicio.diagnostico, servicio.nombreCliente, servicio.cotizacion, servicio.fecha.dia, servicio.fecha.mes, servicio.fecha.anio);


}
void ListarServicios(eServicio servicio[], int tamServicio)
{
	int i;

	printf("\nLista de servicios...\n\n"
							   "%-20s %-20s %-20s %-20s %-20s\n", "ID", "Diagnostico", "Nombre del cliente", "Cotizacion", "Fecha");
	for(i=0;i<tamServicio;i++)
	{
		if(servicio[i].isEmpty!=-1)
		{
			ListarServicio(servicio[i]);
		}
	}


}




void OrdenarPorFecha(eServicio servicio[], int tamServicio)
{



		int i;
		int j;


		eServicio auxServicio;

		printf("Funciona...\n");

		for(i=0; i<tamServicio-1; i++)
				{
					for(j=i+1; j<tamServicio; j++)
					{
						if(servicio[i].isEmpty != EMPTY && servicio[j].isEmpty != EMPTY)
						{
							if(servicio[i].fecha.anio < servicio[j].fecha.anio)//BIEN  <
							{
								auxServicio = servicio[i];
								servicio[i] = servicio[j];
								servicio[j] = auxServicio;
							}else
							{

								if(servicio[i].fecha.anio == servicio[j].fecha.anio)
								{
									if(servicio[i].fecha.mes < servicio[j].fecha.mes)//<
									{
										auxServicio = servicio[i];
										servicio[i] = servicio[j];
										servicio[j] = auxServicio;

									}else
									{

										if(servicio[i].fecha.mes == servicio[j].fecha.mes)
										{

											if(servicio[i].fecha.dia < servicio[j].fecha.dia)//<
											{

												auxServicio = servicio[i];
												servicio[i] = servicio[j];
												servicio[j] = auxServicio;



											}else
											{
												if(servicio[i].fecha.dia == servicio[j].fecha.dia)
												{

													auxServicio = servicio[i];
													servicio[i] = servicio[j];
													servicio[j] = auxServicio;


												}

											}


										}


									}


								}
							}
						}
					}
				}

}

void SumarCotizacionesCambioAceite(eServicio servicio[], int tamServicio)
{
	int i;
	int acumulador;
	acumulador = 0;

	for(i=0;i<tamServicio;i++)
	{
			if(servicio[i].idServicio != EMPTY)
			{
				if(servicio[i].fecha.anio == 2023 && servicio[i].fecha.mes == 1 && servicio[i].fecha.dia == 26 && servicio[i].diagnostico == 1)
				{
						acumulador = acumulador + servicio[i].cotizacion;
				}
			}

	}

	printf("Suma de cotizaciones para cambio de aceite del 26/1/2023 - %d\n", acumulador);


}


int ValidarServicio(eServicio servicio[], int tamServicio)
{
	int ret;
	int i;
	ret = -1;



	for(i=0;i<tamServicio;i++)
	{
		if(servicio[i].isEmpty > -1)
		{
			ret = 0;
			break;
		}
	}


	return ret;
}













#endif /* SERVICIOS_C_ */
