/**
 * 
 * 
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

typedef struct _Invetory Inventory;

Inventory *inventory_create();
STATUS inventory_destroy(Inventory *i);
STATUS inventory_set(Inventory *i, Id id);
Id *invenory_getObject(Inventory *i);
STATUS inventory_add();
STATUS inventory_del();

STATUS inventory_print();


#endif