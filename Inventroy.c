/**
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "object.h"
#include "set.h"

#define MAX 10
/**
 * 
 */

struct _Invetory{
  Set *objects;              /*!< Set de objetos del jugador */
  int max_objects;          /*!< Numero maximo de objetos que puede tener */
};

Inventory *inventory_create(){
    Inventory *new;

    new = (Inventory *)malloc(sizeof(Inventory));
    if(!new){
        return NULL;
    }

    new->max_objects = MAX;
    new->objects = set_create();
    if(new->objects == NULL){
        return NULL;
    }

    return new;
}
STATUS inventory_destroy(Inventory *i){
    if(!i){
        return ERROR;
    }

    if(set_destroy(i->objects) == ERROR){
        return ERROR;
    }

    free(i);
    return OK;
}
STATUS inventory_set(Inventory *i, Id id){

    if(!i || !id){
        return ERROR;
    }

    if(set_add(i->objects, id) == ERROR){
        return ERROR;
    }

    return OK;
}

Id *invenory_getObject(Inventory *i){
    if(!i ){
        return NULL;
    }

    return ;  // devolver un objeto del Set set_getObject

}