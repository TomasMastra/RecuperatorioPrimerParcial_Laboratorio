/*
 * Nexo.h
 *
 *  Created on: 23 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef NEXO_H_
#define NEXO_H_
#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Servicios.h"
#include "Input.h"
#include "Mecanico.h"
#include "Especialidad.h"
#define EMPTY -1


/** \brief Muestra un submenu con mas opciones. Para ingresar debe poner la opcion 5 en el menu anterior
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \param especialidad eEspecialidad[]
* \param tamEspecialidad int
* \return void
*
*/
void MostrarMenu(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief Muestra un menu con opciones. Para ingresar a la 2,3 y 4 debe ingresar un servicio
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \param especialidad eEspecialidad[]
* \param tamEspecialidad int
* \return void
*
*/
void MostrarSubMenu(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[],  int tamEspecialidad);

/** \brief to modify the service. The funcion allow you to change name, date abd mechanic
*
* \param servicio eServicio[]
* \param tamServicio int
* \return void
*
*/
void ModificarServicio(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief se le asigna un mecanico a un servicio. Primero pregunto por el mecanico, despues por el servicio en la funcion de AsignarIdMecanico y ahi al idMecanico del es igual al id del mecanico
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void Diagnosticar(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);


/** \brief muestra un mecanico
*
* \param servicio eServicio
* \return void
*
*/
void ListarMecanico(eMecanico mecanico, eEspecialidad especialidad);

/** \brief muestra los mecanicos de la posicion i
*
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void ListarMecanicos(eMecanico mecanico[], int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief muestro un servicio y un mecanico
*
* \param servicio eServicio
* \param mecanico eMecanico
* \return void
*
*/
void ListarServicioyMecanico(eServicio servicio, eMecanico mecanico, eEspecialidad especialidad);

/** \brief muestra los servicios junto con los mecanicos, para eso llamo a la funcion de ListarServicioyMecanico en la posicion de i para el mecanico y j para el servicio
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void ListarServiciosyMecanicos(eServicio servicio[], int tamServicio, eMecanico mecanico[], int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief // busca si el mecanico tiene un servicio o no, en caso de que no tenga lo muestra. Uso un contador
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void ListarMecanicosSinServicio(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief busca la cantidad de servicios que tiene cada mecanico y busca el mecanico con mas cantidad. Despues llama a la funcion de abajo y le pasa la cantidad de servicios de cada mecanico y el mecanico con mas cantidad
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void DeterminarMecanicosMasServicios(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief muestra los mecanicos con mas servicios. Compara si la cantidad de servicios de un mecanico es igual a la mayor cantidad que tiene un mecanico
*
* \param servicio eServicio[]
* \param tamServicio int
* \param cantidad int[]
* \param masCaro int
* \return void
*
*/
void MostrarMecanicosMasServicios(eMecanico mecanico[], int tamMecanico, int cantidad[], int masCaro, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void CalcularPromedioCotizacionesMecanico(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief muestra los servicios con una fecha entre marzo y mayo del 2020. Para la especialidad hago un strcmp y comparo la especialidad con "Suspencion" para ver si son iguales, en ese caso seria 0
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void ListarServiciosEntreMayoyMarzo2022(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief calcula el porcentaje de cada diagnostico 1, 2 o 3
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*
*/
void CalcularPorcentajeDiagnostico(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief calcula la cantidad de servicios diagnosticados. Lo que hago es comparar si idMecanico de servicio es igual a la id del mecanico, ahi el contador se suma 1 numero
*
* \param servicio eServicio[]
* \param tamServicio int
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return int contador (cantidad de servicios diagnosticados)
*
*/
int CalcularServiciosDiagnosticados(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico);

/** \brief Compara un mecanico que le pasamos con un los servicios hasta buscar que sean iguales. En ese caso retorna la posicion del servicio y si no se cumple retorna -1
*
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param tamServicio int
* \param index int
* \return int auxIndex (posicion del servicio)
*
*/
int CompararMecanicoServicio(eServicio servicio[],   eMecanico mecanico[], int tamServicio, int index);
/** \brief Compara la especialidad de un mecanico que le pasamos con un los los ids de las especialidades hasta buscar que sean iguales. En ese caso retorna la posicion del servicio y si no se cumple retorna -1
*
* \param especialidad eEspecialidad[]
* \param mecanico eMecanico[]
* \param tamEspecialidad int
* \param index int
* \return int auxIndex (posicion del servicio)
*
*/
int CompararMecanicoEspecialidad(eEspecialidad especialidad[], eMecanico mecanico[],  int tamEspecialidad,  int index);

/** \brief Compara un servicio que le pasamos con un los mecanicos hasta buscar que sean iguales. En ese caso retorna la posicion del servicio y si no se cumple retorna -1
*
* \param mecanico eMecanico[]
* \param servicio eServicio[]
* \param tamMecanico int
* \param index int
* \return int auxIndex (posicion del servicio)
*
*/
int CompararServicioMecanico(eMecanico mecanico[],   eServicio servicio[], int tamMecanico, int index);


/** \brief Muestra los mecanicos ordenados por especialidad. Para eso recorre el array de mecanicos. Previamente lo ordeno por especialidad del mecanico (int) y recorro el array de mecanicos
*
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param tamServicio int
* \param tamMecanico int
* \param especialidad eEspecialidad[]
* \param tamEspecialidad int
* \return void
*
*/
void ListarOrdenadoPorEspecialidad(eServicio servicio[], eMecanico mecanico[], int tamServicio, int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);

/** \brief Asigna el id del mecanico al servicio
*
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param tamServicio int
* \param tamMecanico int
* \param id int
* \return void
*
*/
void AsignarIdMeacnico(eServicio servicio[], eMecanico mecanico[],int tamServicio, int tamMecanico, int id);
/** \brief Valida que la estadia no tenga un id de un mecanico igual a la de otro mecanico
*
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param index int
* \param tamMecanico int
* \return int ret
*
*/
int validarMecanicoDiagnosticado(eServicio servicio[], eMecanico mecanico[], int index, int tamMecanico);


/** \brief busca cuantos servicios tiene un mecanico. Recorre los servicios y si el id del mecanico de la posición que le paso es igual al id mecanico de un servicio sumo el contador
*
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param index int
* \param tamServicio int
* \return int contador (cantidad de servicios   * \diagnosticados que tiene un mecanico)
*
*/
int BuscarCantidadServiciosPorMecanico(eServicio servicio[], eMecanico mecanico[],int tamServicio ,int index);

/** \brief Suma las cotizaciones de un mecanico en especifico, recorre un for con los servicios y busca si un id mecanico de un servicio es igual al id del mecanico de la posición index que le paso
*
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param index int
* \param tamServicio int
* \return int acumulador (suma de cotización de * \un mecanico)
*
*/
int SumarCotizacionesServiciosPorMecanico(eServicio servicio[], eMecanico mecanico[],int tamServicio ,int index);

/** \brief Busca la cantidad de mecanicos que estudiaron cada especialidad y las ordena de manera que la mas estudiada sea la primera y la menos estudiada la ultima
*
* \param mecanico eMecanico[]
* \param especialidad eEspecialidad[]
* \param tamMecanico int
* \param tamEspecialidad int
* \return int acumulador (suma de cotización de * \un mecanico)
*
*/
void CalcularEspecialidadesEstudiadas(eMecanico mecanico[], int tamMecanico, eEspecialidad especialidad[], int tamEspecialidad);



/** \brief Busca cuantos mecanicos estudiaron esa especialidad, le paso la especialidad, comparo y voy sumando un contador
* \param servicio eServicio[]
* \param mecanico eMecanico[]
* \param index int
* \param tamMecanico int
* \return int contador (cantidad de mecanicos que estudiaron esa especialidad)
*
*/
int BuscarCantidadEspecialidad(eMecanico mecanico[],int tamMecanico, eEspecialidad especialidad[],int index);


#endif /* NEXO_H_ */
