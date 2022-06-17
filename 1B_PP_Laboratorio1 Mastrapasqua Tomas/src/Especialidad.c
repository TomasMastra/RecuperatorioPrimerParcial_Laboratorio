/*
 * Especialidad.c
 *
 *  Created on: 23 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef ESPECIALIDAD_C_
#define ESPECIALIDAD_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Mecanico.h"
#include "Especialidad.h"

#define EMPTY -1

void harcodeoEspecialidad(eEspecialidad especialidad[], int tamEspecialidad)
{
	int i;
	int ids[] = {1,2,3};
	char especialidades[][21]={"Cambio de aceite","Reparacion de motor","Suspencion"};
	tamEspecialidad = 3;

	for(i=0;i<tamEspecialidad;i++)
		{
					especialidad[i].idEspecialidad = ids[i];
					strcpy(especialidad[i].especialidad, especialidades[i]);



		}



}


#endif /* ESPECIALIDAD_C_ */
