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
STATUS inventory_destroy(Inventory *i)
{
    if (!i)
    {
        return ERROR;
    }

    if (set_destroy(i->objects) == ERROR)
    {
        return ERROR;
    }

    free(i);
    return OK;
}
STATUS inventory_setMAX(Inventory *i, int max)
{

    if (!i)
    {
        return ERROR;
    }

    i->max_objects = max;

    return OK;
}

int invenory_getMAX(Inventory *i)
{
    if (!i)
    {
        return NULL;
    }

    return i->max_objects;
}

STATUS inventory_addObject(Inventory *i, Id obj)
{

    if (!i || !obj)
    {
        return ERROR;
    }

    if (set_add(i->objects, obj) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

STATUS inventory_delObject(Inventory *i, Id obj)
{
    if (!i || !obj)
    {
        return ERROR;
    }

    if (set_delete(i->objects, obj) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

STATUS inventory_print(Inventory *i)
{
    if (!i)
    {
        return ERROR;
    }

    fprintf(stdout, "Elementos del inventario:\n Numero maximo de objetos: %i\nObjetos: \n", i->max_objects);
    if (set_print(i->objects) == ERROR)
    {
        return ERROR;
    }
    return OK;
}
