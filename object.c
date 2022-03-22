#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/**
 * @brief Object
 *
 * Esta estructura guarda toda la información de object
 */

struct _Object
{
  Id id;                    /*!< El número id del objeto, debe ser único */
  char name[WORD_SIZE + 1]; /*!< Nombre del objeto */
};

/** object_create asigna memoria para el nuevo objeto e inicializa los parámetros
 */
Object *object_create(Id id)
{
  Object *newObject = NULL;

  /* Control de errores */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *)malloc(sizeof(Object));
  if (newObject == NULL)
    return NULL;

  /* Inicialización de un objeto vacío*/
  newObject->id = id;
  newObject->name[0] = '\0';
  return newObject;
}

/** object_destroy libera la asignación de memoria anterior para un espacio
 */
STATUS object_destroy(Object *object)
{
  if (!object)
  {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

/** Coge la id del objeto
 */
Id object_get_id(Object *object)
{
  if (!object)
  {
    return NO_ID;
  }
  return object->id;
}

/** Establece el id del objeto
 */
STATUS object_set_id(Object *object, Id id)
{
  if (!object || id == NO_ID)
    return ERROR;

  object->id = id;
  return OK;
}

/** Establece el nuevo nombre del objeto
 */
STATUS object_set_name(Object *object, char *name)
{
  if (!object || !name)
  {
    return ERROR;
  }

  if (!strcpy(object->name, name))
  {
    return ERROR;
  }
  return OK;
}
/** Coge el nombre del objeto
 */
const char *object_get_name(Object *object)
{
  if (!object)
  {
    return NULL;
  }
  return object->name;
}

/** Muestra la información del objeto
 */
STATUS object_print(Object *object)
{

  /* Control de errores */
  if (!object)
  {
    return ERROR;
  }

  /* 1. Muestra la id y el nombre del objeto */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}
