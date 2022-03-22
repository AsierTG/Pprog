/**
 * @file set.c
 * @author Asier Tomé Gaubeka
 * @brief
 * @version 0.1
 * @date 2022-02-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"



struct _Set
{
    int n_ids;
    Id array[MAX];
};

/**
 * @brief Crea un set de Id's inicializados a NO_ID
 * 
 * @return Set* 
 */
Set *set_create()
{
    int i;
    Set *set;

    set = (Set *)malloc(sizeof(Set));
    if (set == NULL)
    {
        return NULL;
    }

    for (i = 0; i < MAX; i++)
    {
        set->array[i] = NO_ID;
    }

    set->n_ids = 0;

    return set;
}

/**
 * @brief Elimina el Set creado anteriormente, liberando sus elementos
 *
 * @param set
 * @return OK o ERROR en caso de que no haya funcionado
 */
STATUS set_destroy(Set *set)
{
    int i;

    if (!set)
    {
        return ERROR;
    }

    for (i = 0; i < set->n_ids; i++)
    {
        set->array[i] = NO_ID;
    }
    free(set);
    return OK;
}

/**
 * @brief Añade un nuevo Id que recibe como argumento al array de Ids 
 *
 * @param set
 * @param id
 * @return OK si lo ha añadido, Error en cas de que no haya podido añadirlo
 */
STATUS set_add(Set *set, Id id)
{
    if (!set || !id)
    {
        return ERROR;
    }

    set->array[set->n_ids] = id;
    set->n_ids++;

    return OK;
}

/**
 * @brief Elimina una id del array
 *
 * @param set
 * @param id
 * @return OK si ha funcionado, ERROR en cualquier otro caso
 */
STATUS set_delete(Set *set, Id id)
{
    int i;

    if (!set || !id)
    {
        return ERROR;
    }
    // Al eliminar un Id del array debería coger el array de la ultima posicion y moverlo a la posicion borrada.
    for (i = 0; i < set->n_ids; i++)
    {
        if (id == set->array[i])
        {
            set->n_ids--;
            set->array[i] = set->array[set->n_ids];
            set->array[set->n_ids] = NO_ID;
        }
    }

    return OK;
}

/**
 * @brief Devuelve en numero de Ids que tiene almacenados
 *
 * @param set
 * @return int
 */
int set_get_n_id(Set *set)
{
    if (!set)
    {
        return -1;
    }
    return set->n_ids;
}

/**
 * @brief Devuelve un array con todos los Ids almacenados en set
 *
 * @param s
 * @param pos
 * @return Id
 */

BOOL set_have_object(Set* set, Id id){
  int i;

  if(!set||id==NO_ID){
    return FALSE;
  }

  for(i=0;i<MAX;i++){
    if(set->array[i]==id){
      return TRUE;
    }
  }
  return FALSE;
}

Id *set_get_id(Set *set)
{
    
    if (!set)
    {
        return NULL;
    }

    return set->array;
}

/**
 * @brief Imprime todos los datos del set 
 *
 * @param set
 * @return OK si se ha imprimido la informacion, ERROR en caso de fallo
 */
STATUS set_print(Set *set)
{
    int i;

    if (!set)
    {
        return ERROR;
    }

    fprintf(stdout, "Set has a total of %i Id's.\n", set->n_ids);

    for (i = 0; i < set->n_ids; i++)
    {
        fprintf(stdout, "Id nº%i: %ld\n", i + 1, set->array[i]);
    }

    return OK;
}

STATUS set_test(Set *set)
{
    if (!set)
    {
        return ERROR;
    }

    return OK;
}