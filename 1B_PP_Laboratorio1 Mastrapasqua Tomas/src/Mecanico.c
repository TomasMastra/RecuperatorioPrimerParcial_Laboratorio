/*
 * Mecanico.c
 *
 *  Created on: 23 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef MECANICO_C_
#define MECANICO_C_
#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Mecanico.h"
#include "Especialidad.h"
#define EMPTY -1


void InicializarMecanicos(eMecanico mecanico[], int tamMecanico)
{
	int i;

	for(i=0;i<tamMecanico;i++)
	{

		mecanico[i].isEmpty = EMPTY;

	}


}

void HarcodearMecanicos(eMecanico mecanico[], int tamMecanico)
{

	int i;
	int id[] = {EMPTY, 10001, 10002, 10003, 10004, 10005, 10006, 10007, 10008, 10009, 10010, 10011, 10012, 10013, 10014, 10015};
	char nombre[][51] = {"No tiene", "Jose", "Maria", "Tomas", "German", "Matias", "Carolina", "Ezequiel", "Valentina", "Santiago", "Lucas", "Jonathan", "Zahir", "Daniela", "Raul", "Ricardo"};
	int especialidad[] = {-1, 1, 2, 3, 1, 3, 2, 2, 2, 3, 1, 2, 3, 2, 1, 3};


	for(i=0;i<tamMecanico;i++)
	{
		mecanico[i].id = id[i];
		strcpy(mecanico[i].nombre, nombre[i]);
		mecanico[i].especialidad = especialidad[i];

		mecanico[i+1].isEmpty = 1;


	}



}


int ValidarMecanicoExiste(eMecanico mecanico[], int tamMecanico, int id)
{

	int ret;
	int i;

	ret = EMPTY;

	for(i=0;i<tamMecanico;i++)
	{
		if(mecanico[i].id == id)
		{
			ret = 0;
		}
	}

	return ret;

}

int ValidarMecanico(eMecanico mecanico[], int tamMecanico)
{
	int i;
	int ret;
	ret = -1;

	for(i=0;i<tamMecanico;i++)
	{
		if(mecanico[i].isEmpty > EMPTY)
		{
			ret = 0;
			break;
		}
	}


	return ret;
}


void OrdenarPorEspecialidad(eMecanico mecanico[], int tamMecanico)
{
	int i;
	int j;
	eMecanico auxMecanico;

	for(i=0;i<tamMecanico-1;i++)
	{
		for(j=i+1;j<tamMecanico;j++)
		{
			if(mecanico[i].especialidad > mecanico[j].especialidad && mecanico[i].isEmpty!=-1  && mecanico[j].isEmpty!=-1)
			{
				auxMecanico = mecanico[i];
				mecanico[i] = mecanico[j];
				mecanico[j] = auxMecanico;
			}
		}

	}

}



#endif /* MECANICO_C_ */
