/**
 * @brief Define la interfaz del enemigo
 *
 * @file enemy.h
 * @author Daniel Martinez Sanz
 * @date 01-03-2022
 */

#ifndef ENEMY_H
#define PLAYER_H

#include "types.h"
#define HEALTH_ENEMY 10;
typedef struct _Enemy Enemy;

/**
 * @brief Crea un nuevo enemigo
 * @author Daniel Martinez Sanz
 *
 * enemy_create reserva memoria para un nuevo enemigo
 * e inicializa sus miembros
 * @param id el identificador para el nuevo enemigo
 * @return un nuevo enemigo inicializado
 */
Enemy *enemy_create(Id id);

/**
 * @brief Destruye un enemigo
 * @author Daniel Martinez Sanz
 *
 * enemy_destroy libera la reserva previa de memoria
 * para un enemigo
 * @param enemy un puntero al enemigo que sera destruido
 * @return OK, si ha funcionado correctamente o ERROR si ha fallado en algun momento
 */
STATUS enemy_destroy(Enemy *enemy);

/**
 * @brief Obtiene la id de un enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy un puntero al enemigo
 * @return la id del enemigo
 */
Id enemy_get_id(Enemy *enemy);

/**
 * @brief Modifica la id de un enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy un puntero al enemigo
 * @param id id que se establecera en el enemigo
 * @return Ok, si ha funcionado correctamente o ERROR si ha fallado en algun momento
 */
STATUS enemy_set_id(Enemy *enemy, Id id);

/**
 * @brief Establece el nombre de un enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy un puntero a un enemigo
 * @param name una cadena con el nombre a asignar
 * @return OK si ha funcionado correctamente o ERROR si ha fallado en algun momento
 */
STATUS enemy_set_name(Enemy *enemy, char *name);

/**
 * @brief Obtiene el nombre del enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy un puntero al enemigo
 * @return una cadena con el nombre del enemigo
 */
const char *enemy_get_name(Enemy *enemy);

/**
 * @brief Obtiene la id de la localizacion del enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy un puntero al enemigo
 * @return id de la posicion del enemigo o NO_ID si hay algun error*/
Id enemy_get_location(Enemy *enemy);

/**
 * @brief Cambia la localizacion del enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy puntero al enemigo
 * @param id identificador de la localizacion
 * @return OK si ha funcionado correctamente o ERROR si ha fallado en algun momento
 */
STATUS enemy_set_location(Enemy *enemy, Id id);

/**
 * @brief Establece la salud de un enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy puntero al enemigo
 * @param health salud que sera asignada
 * @return OK si ha funcionado correctamente o ERROR si ha fallado en algun momento
 */
STATUS enemy_set_health(Enemy *enemy, float health);

/**
 * @brief Obtiene la salud de un enemigo
 * @author Daniel Martinez Sanz
 *
 * @param enemy puntero al enemigo
 * @return salud del enemigo
 */
float enemy_get_health(Enemy *enemy);

/**
 * @brief Imprime la informacion del enemigo
 * @author Daniel Martinez Sanz
 *
 * Esta funcion muestra la id y el nombre del enemigo
 * @param enemy un puntero al enemigo
 * @return OK si ha funcionado correctamente o ERROR si ha fallado en algun momento*/
STATUS enemy_print(Enemy *enemy);

#endif