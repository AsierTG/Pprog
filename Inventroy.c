/**
 * @file Inventroy.c
 * @author Asier Tomé
 * @brief Contiene las funciones y la estructura de datso de Inventory
 * @version 0.1
 * @date 2022-03-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "object.h"
#include "set.h"

struct _Invetory
{
    Set *objects;    /*!< Set de objetos del jugador */
    int max_objects; /*!< Numero maximo de objetos que puede tener */
};

Inventory *inventory_create()
{
    Inventory *new;

    new = (Inventory *)malloc(sizeof(Inventory));
    if (!new)
    {
        return NULL;
    }

    new->max_objects = NO_INIT;
    new->objects = set_create();
    if (new->objects == NULL)
    {
        return NULL;
    }

    return new;
}
STATUS inventory_destroy(Inventory *inv)
{
    if (!inv)
    {
        return ERROR;
    }

    if (set_destroy(inv->objects) == ERROR)
    {
        return ERROR;
    }

    free(inv);
    return OK;
}
STATUS inventory_setMAX(Inventory *inv, int max)
{

    if (!inv)
    {
        return ERROR;
    }

    inv->max_objects = max;

    return OK;
}

int invenory_getMAX(Inventory *inv)
{
    if (!inv)
    {
        return NULL;
    }

    return inv->max_objects;
}

STATUS inventory_addObject(Inventory *inv, Id obj)
{

    if (!inv || !obj)
    {
        return ERROR;
    }

    if (set_add(inv->objects, obj) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

STATUS inventory_delObject(Inventory *inv, Id obj)
{
    if (!inv || !obj)
    {
        return ERROR;
    }

    if (set_delete(inv->objects, obj) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

STATUS inventory_print(Inventory *inv)
{
    if (!inv)
    {
        return ERROR;
    }

    fprintf(stdout, "Elementos del inventario:\n Numero maximo de objetos: %i\nObjetos: \n", inv->max_objects);
    if (set_print(inv->objects) == ERROR)
    {
        return ERROR;
    }
    return OK;
}
