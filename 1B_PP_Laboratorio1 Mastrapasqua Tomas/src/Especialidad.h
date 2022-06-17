/*
 * Especialidad.h
 *
 *  Created on: 23 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_


typedef struct
{

	char especialidad[21];
	int idEspecialidad;

	int cantidad;


}eEspecialidad;

void harcodeoEspecialidad(eEspecialidad especialidad[], int tamEspecialidad);

void ordenarPorCantidad(eEspecialidad especialidad[], int tamEspecialidad);


/** \brief Muestra el top 3 de especialidades mas estudiadas
*
* \param servicio eServicio[]
* \param tamEspecialidad int
* \return int acumulador (suma de cotización de * \un mecanico)
*
*/
void MostrarEspecialidadesMasEstudiadas(eEspecialidad especialidad[], int tamEspecialidad);

#endif /* ESPECIALIDAD_H_ */
