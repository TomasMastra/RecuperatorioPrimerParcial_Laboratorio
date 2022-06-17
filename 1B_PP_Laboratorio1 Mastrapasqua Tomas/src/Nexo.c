/*
 * Nexo.c
 *
 *  Created on: 23 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef NEXO_C_
#define NEXO_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Mecanico.h"
#include "Especialidad.h"
#include "Nexo.h"
#define EMPTY -1

void MostrarMenu(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//BIEN, PONERLA EN EL NEXO
{
	int option;
	int id;
	int validar;





		id = 5000;

		do{
				getInt(&option, "-------------------------------------\n"
					 	    								 "1. ALTA\n"
					 	    								 "2. BAJA\n"
					 	    								 "3. MODIFICAR SERVICIO\n"
					 	    								 "4. DIAGNOSTICAR\n"
															 "5. SUB MENU\n"
					 	    								 "6. SALIR\n"
					 	    								 "-------------------------------------\n",
					 	    								 "Ingrese una opcion: "
					 	    								 "-------------------------------------\n"
															 "1. ALTA\n"
															 "2. BAJA\n"
															 "3. MODIFICAR SERVICIO\n"
															 "4. DIAGNOSTICAR\n"
															 "5. SUB MENU\n"
															 "6. SALIR\n"
					 	    								 "-------------------------------------\n"
					 	    								 "ERROR, Ingrese una opcion: ", 1, 6);

				validar =  ValidarServicio(servicio,  tamServicio);



					switch(option)
					{
					case 1:

						 AgregarServicio(servicio, tamServicio, id);
						 id++;


					break;

					case 2:

						if(validar == 0)
						{
						EliminarServicio(servicio, tamServicio);
						}else
						{
							printf("No hay servicios\n");
						}

						break;

					case 3:
						if(validar == 0)
						{
						 ModificarServicio(servicio,  mecanico,  tamServicio,  tamMecanico, especialidad,  tamEspecialidad);
						}else
						{
							printf("No hay servicios\n");
						}


						break;
					case 4:
						if(validar == 0)
						{
						Diagnosticar(servicio, mecanico, tamServicio, tamMecanico,  especialidad,  tamEspecialidad);
						}else
						{
							printf("No hay servicios\n");
						}
						break;


					case 5:

						MostrarSubMenu(servicio, mecanico,  tamServicio,  tamMecanico, especialidad, tamEspecialidad);

						break;



					}

				}while(option!=6);


}

void MostrarSubMenu(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[],  int tamEspecialidad)
{

	int option;
	int validar;



	do{

		getInt(&option, "-------------------------------------\nLISTAR:\n"
							 	    								 "1. MECANICOS\n"
							 	    								 "2. SERVICIOS\n"
							 	    								 "3. TODOS LOS MECANICOS SIN SERVICIO ASIGNADO\n"
							 	    								 "4. SERVICIOS ORDENADOS POR FECHA\n"
																	 "5. SUMA DE COTIZACION DE 26/1/2023 EN CAMBIO DE ACEITE\n"
							 	    								 "6. COTIZACION PROMEDIO DE CADA UNO DE LOS MECANICOS\n"
																	 "7. MECANICOS CON MAS SERVICIOS ASIGNADOS\n"
											 	    				 "8. SERVICIOS ORDENADOS POR ESPECIALIDAD DEL MECANICO\n"
																	 "9. LISTADO DE SERVICIOS ENTRE MARZO Y MAYO DEL 2022 PARA ESPECIALIDAD DE SUSPENCION\n"//ESPECIALIDAD DEL MECANICO, NO DIAGNOSTICO
											 	    				 "10. PORCENTAJE DE SERVICIOS DIAGNOSTICADOS QUE ATIENDE CADA MECANICO\n"
																	 "11. ESPECIALIDADES MAS ESTUDIADAS\n"
				 	 	 	 	 	 	 	 	 	 	 	 	 	 "12. VOLVER AL MENU PRINCIPAL\n"

							 	    								 "-------------------------------------\n",
							 	    								 "Ingrese una opcion: "
							 	    								 "-------------------------------------\n"
																	 "1. MECANICOS\n"
																	 "2. SERVICIOS\n"
																     "3. TODOS LOS MECANICOS SIN SERVICIO ASIGNADO\n"
																	 "4. SERVICIOS ORDENADOS POR FECHA\n"
																	 "5. SUMA DE COTIZACION DE 26/1/2023 EN CAMBIO DE ACEITE\n"
																	 "6. COTIZACION PROMEDIO DE CADA UNO DE LOS MECANICOS\n"
																	 "7. MECANICOS CON MAS SERVICIOS ASIGNADOS\n"
																	 "8. SERVICIOS ORDENADOS POR ESPECIALIDAD DEL MECANICO\n"
																	 "9. LISTADO DE SERVICIOS ENTRE MARZO Y MAYO DEL 2022 PARA ESPECIALIDAD DE SUSPENCION\n"
																	 "10. PORCENTAJE DE SERVICIOS DIAGNOSTICADOS QUE ATIENDE CADA MECANICO\n"
																	 "11. ESPECIALIDADES MAS ESTUDIADAS\n"
																	 "12. VOLVER AL MENU PRINCIPAL\n"

							 	    								 "-------------------------------------\n"
							 	    								 "ERROR, Ingrese una opcion: ", 1, 12);

		validar =  ValidarServicio(servicio,  tamServicio);



		switch(option)
		{

		case 1:
			//OrdenarPorEspecialidad(mecanico,  tamMecanico);
			ListarMecanicos(mecanico, tamMecanico,  especialidad,  tamEspecialidad);
					break;

		case 2:
			if(validar == 0)
			{
			ListarServicios(servicio, tamServicio);
			}else
			{
				printf("No hay servicios\n");
			}

					break;
		case 3:
			 ListarMecanicosSinServicio(servicio, mecanico, tamServicio, tamMecanico, especialidad, tamEspecialidad);


					break;
		case 4:
			if(validar == 0)
			{
			 OrdenarPorFecha(servicio,  tamServicio);
			 ListarServicios(servicio, tamServicio);
			}else
			{
				printf("No hay servicios\n");
			}



					break;
		case 5:
			if(validar == 0)
			{
			SumarCotizacionesCambioAceite(servicio,  tamServicio);
			}else
			{
				printf("No hay servicios\n");
			}

					break;
		case 6:
			if(validar == 0)
			{
			CalcularPromedioCotizacionesMecanico(servicio, mecanico, tamServicio, tamMecanico, especialidad, tamEspecialidad);
			}else
			{
				printf("No hay servicios\n");
			}

					break;
		case 7:
			if(validar == 0)
			{
			 DeterminarMecanicosMasServicios(servicio,  mecanico,  tamServicio,  tamMecanico,  especialidad,  tamEspecialidad);
			}else
			{
				printf("No hay servicios\n");
			}


					break;
		case 8:
			if(validar == 0)
			{
			OrdenarPorEspecialidad(mecanico,  tamMecanico);
			ListarOrdenadoPorEspecialidad(servicio, mecanico, tamServicio, tamMecanico,  especialidad,  tamEspecialidad);
			}else
			{
				printf("No hay servicios\n");
			}

					break;
		case 9:
			if(validar == 0)
			{
			ListarServiciosEntreMayoyMarzo2022(servicio,  mecanico,  tamServicio, tamMecanico,  especialidad,  tamEspecialidad);
			}else
			{
				printf("No hay servicios\n");
			}
					break;
			case 10:
			if(validar == 0)
			{
				CalcularPorcentajeDiagnostico(servicio, mecanico, tamServicio,  tamMecanico, especialidad, tamEspecialidad);
			}else
			{
				printf("No hay servicios\n");
			}

						break;

		case 11:

			CalcularEspecialidadesEstudiadas(mecanico,  tamMecanico, especialidad,  tamEspecialidad);

			break;
		}


		}while(option!=12);

}


void ModificarServicio(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//ponerla en el nexo// VERLA Y CORREGIR
{

	int id;
	int opcion;
	int auxInt;
	char auxChar[51];
	int confirm;
	int index;
	int validar;


	opcion = 0;


	ListarServicios(servicio, tamServicio);
	getInt(&id, "Ingrese el ID a modificar\n", "ERROR, ingrese el ID a modificar\n", 5000, 7000);
	index = BuscarProductoID(servicio,  tamServicio,  id);



	if(index > -1)
	{
		getInt(&opcion, "Ingrese la opcion (1.Nombre 2.Fecha 3. Mecanico)\n", "ERROR, ingrese la opcion (1.Nombre 2.Fecha 3. Mecanico)\n", 1, 3);

		switch(opcion)
		{
		case 1:
			getName(auxChar, "Ingrese el nuevo nombre\n", "ERROR, ingrese el nuevo nombre\n", 51);
			getInt(&confirm, "Estas seguro? (1.si / 2.no)\n", "Estas seguro? (1.si / 2.no)\n", 1, 2);
			if(confirm == 1)
			{
				strcpy(servicio[index].nombreCliente, auxChar);
			}
			break;
		case 2:
			PedirFechas(servicio,index);

			break;
		case 3:
			if(servicio[index].isEmptyMecanico != -1)
			{


				ListarMecanicos(mecanico, tamMecanico, especialidad, tamEspecialidad);
				getInt(&auxInt, "Ingrese el mecanico: \n", "ERROR, ingrese el mecanico: \n", 10001, 20000);
				validar = ValidarMecanicoExiste(mecanico,  tamMecanico, auxInt);
				if(validar == 0)
				{
				getInt(&confirm, "Estas seguro? (1.si / 2.no)\n", "Estas seguro? (1.si / 2.no)\n", 1, 2);

				if(confirm == 1)
				{
					servicio[index].idMecanico = auxInt;
				}
				}else
					{
						printf("Este mecanico no existe\n");
					}
			}else
				{
				printf("Este servicio no tiene ningun mecanico, primero agregale uno\n");


				}
		break;

		}
	}else
	{
		printf("No existe ese ID\n");
	}


}

void Diagnosticar(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//pasar al nexo (esta bien)
{
	int idMecanico;
	int validarMecanico;

	ListarMecanicos(mecanico, tamMecanico, especialidad, tamEspecialidad);
	getInt(&idMecanico, "Ingrese una ID de un mecanico: ", "ERROR, Ingrese una ID de un mecanico: ", 10001, 20000);
	validarMecanico  = ValidarMecanicoExiste(mecanico, tamMecanico, idMecanico);


	printf("\n");

	if(validarMecanico == 0)
	{
			ListarServicios(servicio, tamServicio);
			AsignarIdMeacnico(servicio,  mecanico, tamServicio, tamMecanico, idMecanico);

	}else
	{
		printf("No existe ese mecanico\n");
	}





}

void AsignarIdMeacnico(eServicio servicio[], eMecanico mecanico[],int tamServicio, int tamMecanico, int id)
{

	int servicioIngresado;
	int i;
	int index;

	getInt(&servicioIngresado, "Ingrese una ID de un servicio para asignarle un mecanico: ", "Ingrese una ID de un servicio para asignarle un mecanico: ", 5000, 6000);

		for(i=0;i<tamServicio;i++)
		{
			//printf("%d - %d\n",servicioIngresado, servicio[i].idServicio);
			if(servicioIngresado == servicio[i].idServicio)
			{
				index = i;
				if(validarMecanicoDiagnosticado(servicio,  mecanico,  index,  tamMecanico)==-1)
				{
					getFloat(&servicio[i].cotizacion, "Ingrese la cotizacion: ", "ERROR, ingrese la cotizacion: ", 10000, 20000);

					servicio[i].idMecanico = id;
					servicio[i].isEmptyMecanico = 1;
					break;
				}else
				{
					printf("Ese servicio ya esta diagnosticado!!!\n");
					break;
				}

			}else
				if(i==tamServicio-1)
				{
					printf("Ese servicio no existe!!!\n");
				}
		}

}

void ListarMecanico(eMecanico mecanico, eEspecialidad especialidad)//LLEVAR A MECANICO.C, ESTA BIEN
{

	printf("%-20d - %-20s - %-20s\n", mecanico.id, mecanico.nombre, especialidad.especialidad);

}

void ListarMecanicos(eMecanico mecanico[], int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//LLEVAR A MECANICO.C, ESTA BIEN
{

	int i;
	int j;

	printf("\nLista de mecanicos...\n\n"
							   "%-20s %-20s %-20s\n", "ID", "Nombre", "Especialidad");
	for(i=0;i<tamMecanico;i++)
	{
		j = CompararMecanicoEspecialidad(especialidad, mecanico, tamEspecialidad,  i);

			if(j!= -1)
			{
					ListarMecanico(mecanico[i], especialidad[j]);
			}

	}



}


void ListarMecanicosSinServicio(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//VER Y PONER EN EL NEXO
{

	int i;
	int j;
	int k;

	tamEspecialidad = 3;


	printf("Mecanicos sin servicio asignado:\n");
	for(i=0; i<tamMecanico; i++)
			{

				j = CompararMecanicoEspecialidad(especialidad, mecanico, tamEspecialidad, i);
				k = CompararMecanicoServicio(servicio, mecanico, tamServicio, i);

				if(k == -1 && j != -1)
				{
					ListarMecanico(mecanico[i], especialidad[j]);

				}


			}

}


void CalcularPromedioCotizacionesMecanico(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//VER
{

	int i;
	int j;
	int k;
	int acumulador;
	int contador;
	float promedio;
	int auxK = -1;



	printf("\nPromedio cotizacion por mecanico...\n\n"
						   "%-20s %-20s %-20s %-20s\n", "Promedio", "ID", "Nombre", "Especialidad");
	for(i=0;i<tamMecanico;i++)
	{
		acumulador = 0;
		contador = 0;

		j=CompararMecanicoServicio(servicio, mecanico, tamServicio, i);
		k=CompararMecanicoEspecialidad(especialidad, mecanico, tamEspecialidad, i);

		contador = BuscarCantidadServiciosPorMecanico(servicio, mecanico, tamServicio , i);
		acumulador = SumarCotizacionesServiciosPorMecanico(servicio, mecanico, tamServicio , i);

		if(j!=-1 && k!=-1)
		{

				auxK = k;
		}





		if(contador>0)
		{
		promedio = acumulador/contador;
		printf("%-20.2f", promedio);
		ListarMecanico(mecanico[i], especialidad[auxK]);
		}


	}



}

void DeterminarMecanicosMasServicios(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//VER
{
	int i;
	int j;
	int contador[tamMecanico];
	int flag;
	int masCaro;

	masCaro = 0;
	flag = 0;

		for(i=0; i<tamMecanico; i++)
			{
				contador[i] = 0;
				j=CompararMecanicoServicio(servicio, mecanico, tamServicio, i);

					if(j!=-1 && servicio[j].isEmptyMecanico!=-1)
					{


						contador[i] = BuscarCantidadServiciosPorMecanico( servicio,  mecanico, tamServicio , i);


						if(flag == 0)
						{
							masCaro = contador[i];
							flag = 1;
						}else
						if(contador[i]>masCaro)
						{
							masCaro = contador[i];
						}

					}



			}
		 MostrarMecanicosMasServicios(mecanico,  tamMecanico,  contador,  masCaro, especialidad, tamEspecialidad);
}

void MostrarMecanicosMasServicios(eMecanico mecanico[], int tamMecanico, int cantidad[], int masCaro, eEspecialidad especialidad[], int tamEspecialidad)//VER
{
	int i;
	int j;

		if(masCaro >0)
		{
			printf("Mecanicos con mas servicios con una cantidad de %d:\n", masCaro);
			for(j=0;j<tamMecanico;j++)
			{
				i = CompararMecanicoEspecialidad(especialidad, mecanico, tamEspecialidad, j);
				if(i!=-1 && cantidad[j] == masCaro)
				{

						ListarMecanico(mecanico[j], especialidad[i]);
				}

			}
		}else
		{
			printf("No hay mecanicos con servicios asignados\n");
		}

}

int BuscarCantidadServiciosPorMecanico(eServicio servicio[], eMecanico mecanico[],int tamServicio , int index)
{
	int i;
	int contador;

	contador = 0;
	for(i=0;i<tamServicio;i++)
	{
		if( mecanico[index].id == servicio[i].idMecanico && servicio[i].isEmptyMecanico!=EMPTY && mecanico[index].isEmpty!=EMPTY)
		{
			contador++;
		}
	}


	return contador;
}

int SumarCotizacionesServiciosPorMecanico(eServicio servicio[], eMecanico mecanico[],int tamServicio ,int index)
{
	int i;
	int acumulador;

	acumulador = 0;
		for(i=0;i<tamServicio;i++)
		{
			if( mecanico[index].id == servicio[i].idMecanico && mecanico[index].isEmpty!=EMPTY && servicio[i].isEmptyMecanico!=EMPTY)
			{
				acumulador=acumulador+servicio[i].cotizacion;
			}
		}


		return acumulador;
}

void ListarServicioyMecanico(eServicio servicio, eMecanico mecanico, eEspecialidad especialidad)
{
	printf("%-20s %-20s %-20d %-20d  %-20d  %-20s  %-20.2f  %d/%d/%d \n", mecanico.nombre, especialidad.especialidad, servicio.idMecanico, servicio.idServicio, servicio.diagnostico, servicio.nombreCliente, servicio.cotizacion, servicio.fecha.dia, servicio.fecha.mes, servicio.fecha.anio);

}

void ListarServiciosyMecanicos(eServicio servicio[], int tamServicio, eMecanico mecanico[], int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//VER LOS FOR
{
	int i;
	int j;
	int k;

		printf("\nLista de servicios...\n\n"
								   "%-20s %-20s %-20s  %-20s %-20s %-20s %-20s %-20s\n", "Nombre del mecanico", "Especialidad", "ID MECANICO", "ID SERVICIO", "Diagnostico", "Nombre del cliente", "Cotizacion", "Fecha");
		for(i=0;i<tamServicio;i++)
		{

			j=CompararServicioMecanico(mecanico, servicio, tamMecanico, i);
			k=CompararMecanicoEspecialidad(especialidad, mecanico, tamEspecialidad, j);

			if(j!=-1 && k!=-1)
			{
				ListarServicioyMecanico(servicio[i], mecanico[j], especialidad[k]);
			}

		}


}

void ListarServiciosEntreMayoyMarzo2022(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)
{
	int i;
	int j;
	int k;

			printf("\nLista de servicios entre marzo y mayo del 2022...\n\n"
									   "%-20s %-20s %-20s  %-20s %-20s %-20s %-20s %-20s\n", "Nombre del mecanico", "Especialidad", "ID MECANICO", "ID SERVICIO", "Diagnostico", "Nombre del cliente", "Cotizacion", "Fecha");
			for(i=0;i<tamServicio;i++)
			{

				j=CompararServicioMecanico(mecanico, servicio, tamMecanico, i);
				k=CompararMecanicoEspecialidad(especialidad, mecanico, tamEspecialidad, j);


				if(j!=-1 && k!=-1)
				{
					if(servicio[i].fecha.mes>2 && servicio[i].fecha.mes <6 && servicio[i].fecha.anio == 2022 && especialidad[k].idEspecialidad == 3)
					{

						ListarServicioyMecanico(servicio[i], mecanico[j], especialidad[k]);

					}
				}

			}


}

int CalcularServiciosDiagnosticados(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico)
{
	int i;
	int j;
	int contador;
	int acumulador;

	contador = 0;
	acumulador = 0;


	for(i=0; i<tamMecanico; i++)
	{
		j=CompararMecanicoServicio(servicio, mecanico, tamServicio, i);

			if(j!= EMPTY )
			{
				 contador = BuscarCantidadServiciosPorMecanico(servicio, mecanico, tamServicio , i);
				 acumulador = contador + acumulador;

			}
	}

	return acumulador;
}

void CalcularPorcentajeDiagnostico(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)//VER
{

	int totalDiagnosticados;
	int i;
	int j;
	int k;
	int contador;
	float porcentaje;
	int indexK;
	contador = 0;

	tamEspecialidad = 3;

	totalDiagnosticados = CalcularServiciosDiagnosticados(servicio,  mecanico,  tamServicio,  tamMecanico);
	printf("%d - Cantidad diagnosticados\n", totalDiagnosticados);


	if(totalDiagnosticados>0)
	{
		printf("\nPromedio cotizacion por mecanico...\n\n"
								   "%-20s %-20s %-20s %-20s\n", "Porcentaje", "ID", "Nombre", "Especialidad");


			for(i=0;i<tamMecanico;i++)
					{
						contador=0;
						j=CompararMecanicoServicio(servicio,mecanico,tamServicio, i);
						k=CompararMecanicoEspecialidad(especialidad,mecanico,tamEspecialidad,i);
						//printf("j %d - k %d\n",j,k);

						if(j!=EMPTY && k!=EMPTY)
						{
							indexK=k;
							contador = BuscarCantidadServiciosPorMecanico(servicio, mecanico, tamServicio , i);
						}







			if(contador>0 && mecanico[i].isEmpty!=EMPTY)
			{

				porcentaje = (contador*100)/totalDiagnosticados;

				printf("%.2f  - ", porcentaje);
				ListarMecanico(mecanico[i], especialidad[indexK]);


			}


		}
	}else
	{
		printf("No hay servicios diagnosticados\n");
	}


}

int CompararMecanicoServicio(eServicio servicio[], eMecanico mecanico[], int tamServicio, int index)
{
	int i;
	int auxIndex;
	auxIndex = EMPTY;


	for(i=0;i<tamServicio;i++)
	{

		if(mecanico[index].id == servicio[i].idMecanico && mecanico[index].isEmpty != EMPTY && servicio[i].isEmptyMecanico!=EMPTY)
		{
			auxIndex = i;
			break;
		}
	}


	return auxIndex;
}
int CompararMecanicoEspecialidad(eEspecialidad especialidad[], eMecanico mecanico[] , int tamEspecialidad, int index)
{
	int i;
	int auxIndex = EMPTY;


	for(i=0;i<tamEspecialidad;i++)
	{
		if(mecanico[index].especialidad == especialidad[i].idEspecialidad && mecanico[index].isEmpty!=EMPTY)
		{

			auxIndex = i;
			break;
		}

	}


	return auxIndex;
}

int CompararServicioMecanico(eMecanico mecanico[], eServicio servicio[], int tamMecanico, int index)
{
	int i;
	int auxIndex;
	auxIndex = EMPTY;


		for(i=0;i<tamMecanico;i++)
		{

			if(servicio[index].idMecanico == mecanico[i].id && servicio[index].isEmptyMecanico!=EMPTY)
			{
				auxIndex = i;
				break;
			}
		}


	return auxIndex;
}




void ListarOrdenadoPorEspecialidad(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)
{
	int i;
	int j;
	int k;

	printf("\nLista de servicios...\n\n"
									   "%-20s %-20s %-20s  %-20s %-20s %-20s %-20s %-20s\n", "Nombre del mecanico", "Especialidad", "ID MECANICO", "ID SERVICIO", "Diagnostico", "Nombre del cliente", "Cotizacion", "Fecha");
	for(i=0;i<tamMecanico;i++)
	{
		j=CompararMecanicoServicio(servicio,mecanico,tamServicio, i);
		k=CompararMecanicoEspecialidad(especialidad,mecanico,tamEspecialidad,i);

		if(j!=EMPTY && k!=EMPTY)
		{
		ListarServicioyMecanico(servicio[j], mecanico[i], especialidad[k]);
		}


	}


}

int validarMecanicoDiagnosticado(eServicio servicio[], eMecanico mecanico[], int index, int tamMecanico)
{
	int i;
	int ret = EMPTY;



	for(i=0;i<tamMecanico;i++)
	{
		if(servicio[index].idMecanico == mecanico[i].id && servicio[index].isEmptyMecanico!=-1)
		{
			ret = 1;
			break;
		}
	}



	return ret;
}

void CalcularEspecialidadesEstudiadas(eMecanico mecanico[], int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad)
{
	int i;

	for(i=0;i<tamEspecialidad;i++)
	{
		especialidad[i].cantidad=BuscarCantidadEspecialidad(mecanico,tamMecanico,especialidad,i);


	}

	ordenarPorCantidad(especialidad,  tamEspecialidad);
	MostrarEspecialidadesMasEstudiadas(especialidad,  tamEspecialidad);

}

int BuscarCantidadEspecialidad(eMecanico mecanico[],int tamMecanico, eEspecialidad especialidad[], int index)
{
	int i;
	int contador;

	contador=0;
	for(i=0;i<tamMecanico;i++)
	{
		if(mecanico[i].especialidad == especialidad[index].idEspecialidad)
		{
			contador++;
		}
	}

	return contador;

}

void MostrarEspecialidadesMasEstudiadas(eEspecialidad especialidad[], int tamEspecialidad)
{

	int i;

	printf("Especialidades mas estudiadas: \n");
	for(i=0;i<tamEspecialidad;i++)
	{
		if(especialidad[i].idEspecialidad>0)
		{
			printf("%d. %s\n",i+1,especialidad[i].especialidad);
		}
	}

}


#endif /* NEXO_C_ */
