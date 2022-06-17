/*
 * Servicios.h
 *
 *  Created on: 15 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS B
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Mecanico.h"
#include "Especialidad.h"


#define EMPTY -1
typedef struct
{

	int dia;
	int mes;
	int anio;


}eFecha;
typedef struct
{
	int idServicio;
	char nombreCliente[51];
	int diagnostico;
	float cotizacion;
	int idMecanico; //Se relaciona mediante esta ID, cada servicio tiene un mecanico. Cada mecanico puede tener mas de 1 servicio
	int isEmpty;
	int isEmptyMecanico;


	eFecha fecha;

}eServicio;






/** \brief to indicate that all positions in the array are empty and the array don't have a mechanic
*
* \param servicio eServicio[]
* \param tamServicio int
* \return void
*
*/
void InicializarServicios(eServicio servicio[], int tamServicio);



void HarcodearServicios(eServicio servicio[], int tamServicio);



/** \brief esta funcion llama a la de BuscarLibre para buscar una posicion libre y poder llamar a la funcion para pedir los datos, le pasa la posicion de i
*
* \param servicio eServicio[]
* \param tamServicio int
* \param id int
* \return void
*
*/
void AgregarServicio(eServicio servicio[], int tamServicio, int id);

/** \brief to find a empty position to add a service
*
* \param servicio eServicio[]
* \param tamServicio int
* \return int (index position)
*
*/
int BuscarLibre(eServicio servicio[], int tamServicio);

/** \brief pide los datos del servicio y pregunta si los queres guardar llamando a una funcion para confirmar
*
* \param servicio eServicio[]
* \param tamServicio int
* \param i int
* \param id int
*
* \return void
*
*/
void PedirServicio(eServicio servicio[], int tamServicio, int i);

/** \brief para confirmar si queres guardar el servicio, si ingresas s (se valida que sea minuscula para preguntar en el if) se guarda
*
* \param message char*
* \return int ret (1 si ingresaste s)
*
*/
int ConfirmarProducto(char* message);




/** \brief to delete a service. The funcion change isEmpty to -1
*
* \param servicio eServicio[]
* \param tamServicio int
* \return void
*
*/
void EliminarServicio(eServicio servicio[], int tamServicio);


/** \brief muestra los servicios de la posicion i con la posicion isEmpty en 1
*
* \param servicio eServicio[]
* \param tamServicio int
* \return void
*
*/
void ListarServicios(eServicio servicio[], int tamServicio);

/** \brief muestra un servicio
*
* \param servicio eServicio
* \return void
*
*/
void ListarServicio(eServicio servicio);





/** \brief ordena por fecha los servicios. Primero compaar el año y si es igual compara el mes, despues compara el mes y si es igual hace lo mismo con el dia
*
* \param servicio eServicio[]
* \param tamServicio int
* \return void
*
*/
void OrdenarPorFecha(eServicio servicio[], int tamServicio);

/** \brief suma las cotizaciones de cambio de aceite para la fecha del 26/1/2023 y el diagnostico de "Cambio de aceite"
*
* \param servicio eServicio[]
* \param tamServicio int
* \return void
*
*/
void SumarCotizacionesCambioAceite(eServicio servicio[], int tamServicio);




/** \brief busca la posicion del producto, se le pasa el id para que busque y compare
*
* \param servicio eServicio[]
* \param tamServicio int
* \param id int
* \return void
*
*/
int BuscarProductoID(eServicio servicio[], int tamServicio, int id);

/** \brief Valida que haya un servicio. me fijo si hay un sercicio con el isEmpty en 1 (mayor a -1), en ese caso con que haya 1 servicio puede ingresar en algunas opciones
*
* \param servicio eServicio[]
* \param tamServicio int
* \return int ret
*
*/
int ValidarServicio(eServicio servicio[], int tamServicio);


/** \brief valida las fechas, que si ingresa el mes de febrero y el dia 29 vuelva a pedir los datos. No valido año bisiesto
*
* \param servicio eServicio[]
* \param i int
* \return void
*
*/
void PedirFechas(eServicio servicio[], int i);

/** \brief pregunta por las fechas con las funcion de getint
*
* \param dia int*
* \param mes int*
* \param anio int*
* \return void
*
*/
void PreguntarFechas(int* dia, int* mes, int* anio);


/////////////////////////////


#endif /* SERVICIOS_H_ */
