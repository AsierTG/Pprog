/**
 * @file inventory.h
 * @author Asier Tomé
 * @brief Modulo de inventario que contiene la estructura Inventory compuesta por el numero maximo de objetos que le puedes insertar
 * y un array con las Id's de los objetos.
 *
 * @version 0.1
 * @date 2022-03-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

#define NO_INIT 0

typedef struct _Invetory Inventory;

/**
 * @brief Reserva la memoria y crea una estructura Inventory.
 *
 * @return puntero a Inventory
 */
Inventory *inventory_create();

/**
 * @brief Libera toda la memoria anteriormente reservada de un inventario.
 *
 * @param i puntero a Inventory
 * @return devuelve ERROR en caso de fallo, en cualquier otro caso OK.
 */
STATUS inventory_destroy(Inventory *inv);

/**
 * @brief Almacena una id que recibe como argumento en el array de Inventory.
 *
 * @param i puntero a Inventory
 * @param max capacidad maxima del Inventario
 * @return devuelve ERROR en caso de fallo, en cualquier otro caso OK.
 */
STATUS inventory_setMAX(Inventory *inv, int max);

/**
 * @brief devuelve la capacidad maxima de elementos que puede almacenar el inventario.
 *
 * @param i puntero a Inventory.
 * @return numero maximo.
 */
int invenory_getMAX(Inventory *inv);

/**
 * @brief Almacena una id que recibe como argumento en el array de Inventory.
 *
 * @param i
 * @param obj
 * @return devuelve ERROR en caso de fallo, en cualquier otro caso OK.
 */
STATUS inventory_addObject(Inventory *inv, Id obj);

/**
 * @brief Elimina un objeto del array de Inventory.
 *
 * @param i puntero a Inventory
 * @param obj Id del objeto que deseas eliminar.
 * @return devuelve ERROR en caso de fallo, en cualquier otro caso OK.
 */
STATUS inventory_delObject(Inventory *inv, Id obj);

/**
 * @brief Imprime los datos del Inventario, la capacidad maxima y un array con los objetos.
 *
 * @param i puntero a Inventory
 * @return devuelve ERROR en caso de fallo, en cualquier otro caso OK.
 */
STATUS inventory_print(Inventory *inv);

#endif