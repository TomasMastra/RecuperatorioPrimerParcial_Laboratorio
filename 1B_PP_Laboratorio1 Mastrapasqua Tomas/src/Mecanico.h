/*
 * Mecanico.h
 *
 *  Created on: 23 may. 2022
 *      Author: Tomas Mastra
 */

#ifndef MECANICO_H_
#define MECANICO_H_



typedef struct
{

	int id;
	char nombre[51];
	//char especialidad[21];
	int especialidad;
	int isEmpty;

}eMecanico;

void InicializarMecanicos(eMecanico mecanico[], int tamMecanico);//CAMBIAR

/** \brief harcodea los mecanicos. Primero se le asigna a unas variables y despues recorro un for y le asigno el valor a cada campo en la posicion de i
*
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void HarcodearMecanicos(eMecanico mecanico[], int tamMecanico);

/** \brief Valida que haya un mecanico. No la uso porque los mecanicos estan harcodeados
*
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return int ret (0 si encontro 1 mecanico)
*
*/
int ValidarMecanico(eMecanico mecanico[], int tamMecanico);


/** \brief
*
* \param mecanico eMecanico[]
* \param tamMecanico int
* \return void
*
*/
void OrdenarPorEspecialidad(eMecanico mecanico[], int tamMecanico);

/** \brief compara si el id que le pasas a la funcion es igual a el id de un mecanico, en caso de que sean iguales retorna 0, si son diferentes -1
*
* \param mecanico eMecanico[]
* \param tamMecanico int
* \param id
* \return void
*
*/
int ValidarMecanicoExiste(eMecanico mecanico[], int tamMecanico, int id);



#endif /* MECANICO_H_ */
