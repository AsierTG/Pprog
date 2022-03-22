/**
 * @brief Deine el interfaz del objeto
 *
 * @file object.h
 * @author Alejandro Coloma
 * @date 10/02/2022
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

#define MAX_OBJECT 100
#define FIRST_OBJECT 1

/**
 * @brief Crea un nuevo objeto
 * @author Alejandro Coloma
 *
 * Asigna memoria para un nuevo objeto
 * @param id El número de identificación parael nuevo objeto
 * @return Un nuevo objeto inicializado
 */

Object *object_create(Id id);

/**
 * @brief Destruye un objeto
 * @author Alejandro Coloma
 *
 * space_destroy Libera la memoria reservada anteriormente para el objeto
 * @param object puntero al objeto que será borrado
 * @return OK, si todo ha ido bien o ERROR si hay algún error.
 */

STATUS object_destroy(Object *object);

/**
 * @brief Recoge el id de un objeto
 * @author Alejandro Coloma
 *
 * @param object es un puntero al objecto
 * @return la id del objeto
 */

Id object_get_id(Object *object);

/**
 * @brief Modifica el id de un objeto
 * @author Alejandro Coloma
 *
 * @param object es un puntero al objecto
 * @return la id del objeto
 */
STATUS object_set_id(Object *object, Id id);

/**
 * @brief Establece el nombre del objeto
 * @author Alejandro Coloma
 *
 * @param object es un puntero al objecto
 * @param name un string con el nuevo nombre
 * @return OK, si todo ha ido bien o ERROR si hay algún error.
 */
STATUS object_set_name(Object *object, char *name);

/**
 * @brief Recoge el nombre del objeto
 * @author Alejandro Coloma
 *
 * @param object es un puntero al objecto
 * @return  name un string con el nombre del objeto
 */

const char *object_get_name(Object *object);

/**
 * @brief Muestra la información del objeto
 * @author Alejandro Coloma
 *
 * Esta función muestra el nombre y la id del objeto
 * @param object es un puntero al objecto
 * @return OK, si todo ha ido bien o ERROR si hay algún error.
 */

STATUS object_print(Object *object);

#endif
