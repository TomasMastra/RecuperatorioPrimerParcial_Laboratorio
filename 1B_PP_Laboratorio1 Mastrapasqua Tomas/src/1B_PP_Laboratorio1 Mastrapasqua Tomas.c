/*
 ============================================================================
 Name        : 1B_PP_Laboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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

#define T 100
int main(void) {

	setbuf(stdout, NULL);
	eServicio servicio[T];
	eMecanico mecanico[17];
	eEspecialidad especialidad[3];

	int tamServicio = T;
	int tamMecanico = 16;
	int tamEspecialidad = 4;




	InicializarServicios(servicio, tamServicio);
	InicializarMecanicos(mecanico, tamMecanico);

	HarcodearMecanicos(mecanico,  tamMecanico);
	harcodeoEspecialidad(especialidad,  tamEspecialidad);


	 MostrarMenu(servicio,  mecanico,  tamServicio,  tamMecanico,  especialidad,  tamEspecialidad);

	printf("Se ejecuto con exitos\n");



	return EXIT_SUCCESS;
}
