/**
 * @brief Define la interfaz del espacio
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define MAX_ID 30
#define MAX_STRINGS 5
#define MAX_CARACTER 10

/**
  * @brief Crea un nuevo espacio
  * @author Profesores PPROG
  *
  * space_create asigna memoria para un nuevo espacio
  * e inicializa sus miembros
  * @param id el numero de identificacion para el nuevo espacio
  * @return un nuevo espacio inicializado
  */
Space* space_create(Id id);

/**
  * @brief Destruye un espacio
  * @author Profesores PPROG
  *
  * space_destroy libera la reserva previa de memoria
  * para un espacio
  * @param space un puntero al espacio que tiene que ser destruido 
  * @return OK si todo esta bien o ERROR si hay algun fallo
  */
STATUS space_destroy(Space* space);

/**
  * @brief Obtiene la id de un espacio
  * @author Profesores PPROG
  * 
  * @param space un puntero al espacio 
  * @return la id del espacio
  */
Id space_get_id(Space* space);

/**
  * @brief Establece el nombre del espacio
  * @author Profesores PPROG
  * 
  * @param space un puntero al espacio
  * @param name la cadena con el nombre a almacenar
  * @return OK si todo esta bien o ERROR si hay algun fallo
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief Obtiene el nombre del espacio
  * @author Profesores PPROG
  * 
  * @param space un puntero al espacio
  * @return una cadena con el nombre del espacio
  */
const char* space_get_name(Space* space);

/**
  * @brief Establece el id del espacio ubicado en el norte
  * @author Profesores PPROG
  * 
  * @param space un puntero al espacio
  * @param id el numero del id del espacio ubicado al norte
  * @return OK si todo esta bien o ERROR si hay algun fallo
  */
STATUS space_set_north(Space* space, Id id);
/**
  * @brief Obtiene el id del espacio ubicado en el norte
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @return el numero del id del espacio ubicado al norte
  */
Id space_get_north(Space* space);

/**
  * @brief Establece el id del espacio ubicado en el sur
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @param id el numero de la id del espacio ubicado al sur
  * @return OK si todo esta bien o ERROR si ha habido algun fallo 
  */
STATUS space_set_south(Space* space, Id id);
/**
  * @brief Obtiene la id del espacio ubicado en el sur
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @return el numero de la id del espacio ubicado al sur
  */
Id space_get_south(Space* space);

/**
  * @brief Establece el id del esspacio ubicado en el este
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @param id el numero del id del espacio ubicado al este
  * @return OK si esta todo bien o ERROR si ha habido algun fallo
  */
STATUS space_set_east(Space* space, Id id);
/**
  * @brief Obtiene el id del espacio ubicado en el este
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @return el numero del id del espacio ubicado al este
  */
Id space_get_east(Space* space);

/**
  * @brief Establece el id del espacio ubicado en el oeste
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @param id el numero del id del espacio ubicado al oeste
  * @return OK si todo esta bien o ERROR si ha habido algun fallo
  */
STATUS space_set_west(Space* space, Id id);

/**
  * @brief Obtiene el id del espacio ubicado en el oeste
  * @author Profesores PPROG
  *
  * @param space un puntero al espacio
  * @return el numero del id del espacio ubicado en el oeste
  */
Id space_get_west(Space* space);

/**
  * @brief Añade un objeto al espacio
  * @author Alejandro Coloma
  *
  * @param space un puntero al espacio
  * @param value La id del objeto
  * @return OK si todo esta bien o ERROR si ha habido algun fallo
  */
STATUS space_set_object(Space* space, Id value);

/**
  * @brief Obtiene la lista de objetos en el espacio
  * @author Alejandro Coloma
  *
  * @param space un puntero al espacio
  * @return Un ountero que las id del espacio
  */
Id *space_get_object(Space* space);

/**
  * @brief Imprime la informacion de un espacio
  * @author Alejandro Coloma
  *
  * 
  * @param space un puntero al espacio
  * @return OK si todo esta bien o ERROR si ha habido algun fallo
  */
STATUS space_print(Space* space);

/**
  * @brief Busca si existe un objeto en el espacio
  * @author Alejandro Coloma
  *
  * 
  * @param space un puntero al espacio
  * @param id La id del objeto
  * @return True si el objeto está en el espacio y False si no.
  */
BOOL space_have_object(Space* space, Id id);

/**
  * @brief Borra un objeto en el espacio
  * @author Alejandro Coloma
  *
  * 
  * @param space un puntero al espacio
  * @param id La id del objeto
  * @return OK si todo esta bien o ERROR si ha habido algun fallo
  */
STATUS space_del_object(Space* space, Id id);

/**
  * @brief Modifica la descripción gráfica de un espacio y una posición
  * @author Alejandro Coloma
  *
  * 
  * @param space un puntero al espacio
  * @param string La descripción gráfica
  * @param pos posición dentro del espacio
  * @return OK si todo esta bien o ERROR si ha habido algun fallo
  */
STATUS space_set_gdesc(Space* space, char* string, int pos);

/**
  * @brief Obtiene la descripción gráfica de un espacio y una posición
  * @author Alejandro Coloma
  *
  * 
  * @param space un puntero al espacio
  * @param pos posición dentro del espacio
  * @return string de la descripción gráfica
  */
char* space_get_gdesc(Space* space,int pos);
#endif
