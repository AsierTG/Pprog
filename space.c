/**
 * @brief Implementa el modulo space
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "set.h"

/**
 * @brief Space
 *
 * Esta estructura almacena la informacion del espacio
 */
struct _Space
{
  Id id;                    /*!< Numero de la id del espacio, debe ser unico */
  char name[WORD_SIZE + 1]; /*!< Nombre del espacio */
  Id north;                 /*!< Id del espacio en el norte */
  Id south;                 /*!< Id del espacio en el sur */
  Id east;                  /*!< Id del espacio en el este */
  Id west;                  /*!< Id del espacio en el oeste */
  Set *object;              /*!< Lista de objetos del espacio*/
  char gdesc[MAX_STRINGS][MAX_CARACTER]; /*!<Descripción gráfica*/
};

/** space_create asigna memoria para un nuevo espacio
 *  e inicializa sus miembros
 */
Space *space_create(Id id)
{
  Space *newSpace = NULL;
  int i;

  /* Control de Error */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Inicializacion del espacio vacio*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->object = set_create();

  for(i=0;i<MAX_STRINGS;i++){
      newSpace->gdesc[i][0]= '\0';
  }

  return newSpace;
}

/** space_destroy libera la reserva previa de memoria
 *  para un espacio
 */
STATUS space_destroy(Space *space)
{
  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->object);
  free(space);
  space = NULL;
  return OK;
}

/** Obtiene el id del espacio
 */
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/** Establece el nombre del espacio
 */
STATUS space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}
/** Obtiene el nombre del espacio
 */
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/** Establece el id del espacio ubicado en el norte
 */
STATUS space_set_north(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->north = id;
  return OK;
}
/** Obtiene el id del espacio localizado en el norte
 */
Id space_get_north(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->north;
}

/** Establece el id del espacio ubicado en el sur
 */
STATUS space_set_south(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->south = id;
  return OK;
}
/** Obtiene el id del espacio ubicado en el sur
 */
Id space_get_south(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->south;
}

/** Establece el id del espacio ubicado en el este
 */
STATUS space_set_east(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->east = id;
  return OK;
}
/** Obtiene el id del espacio ubicado en el este
 */
Id space_get_east(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->east;
}

/** Establece el id del espacio ubicado en el oeste
 */
STATUS space_set_west(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->west = id;
  return OK;
}
/** Obtiene el id del espacio ubicado en el oeste
 */
Id space_get_west(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->west;
}

/*Añade un objeto al espacio*/
STATUS space_set_object(Space *space, Id value)
{
  if (!space)
  {
    return ERROR;
  }
  if (set_add(space->object, value) == ERROR)
  {
    return ERROR;
  }

  return OK;
}
/** Obtiene si el espacio tiene un objeto o no
 */
Id *space_get_object(Space *space)
{
  if (!space)
  {
    return FALSE;
  }
  return set_get_id(space->object);
}

/** Imprime la informacion del espacio
 */
STATUS space_print(Space *space)
{
  Id idaux = NO_ID;
  long* objects=NULL;
  int i;

  /* Control de Error */
  if (!space)
  {
    return ERROR;
  }

  /* 1. Imprime el id y el nombre del espacio */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /* 2. Para cada direccion imprime su link */
  idaux = space_get_north(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Imprime si hay un objeto o no en el espacio */
objects=space_get_object(space);

  if(objects==NULL){
    fprintf(stdout, "---> No object in the space.\n");
  }

  for(i=0;i<MAX;i++){
    fprintf(stdout, "---> Object %ld in the space.\n",objects[i]);
  }


  return OK;
}


STATUS space_set_gdesc(Space* space, char* string, int pos){
  if(!space || !string || pos <0 || pos >5){
    return ERROR;
  }

  if(strlen(string)==MAX_CARACTER-1){
    strcpy(space->gdesc[pos],string);
    return OK;
  }

  return ERROR;
}

char* space_get_gdesc(Space* space,int pos){
  if(!space || pos <0 || pos >5){
    return NULL;
  }

  return space->gdesc[pos];
}

BOOL space_have_object(Space* space, Id id) {
  if (!space||id==NO_ID) {
    return FALSE;
  }

  if(set_have_id(space->object,id)==TRUE){
    return TRUE;
  }else
    return FALSE;
}

STATUS space_del_object(Space* space, Id id) {
  if (!space||id==NO_ID) {
    return ERROR;
  }

  set_delete(space->object,id);

  return OK;
}
