/**
 * @brief Define la interfaz de jugador
 *
 * @file player.h
 * @author Daniel Martinez Sanz
 * @date 17-02-2022
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#define HEALTH_PLAYER 20;
typedef struct _Player Player;

/**
 * @brief Crea un nuevo jugador
 * @author Daniel Martinez Sanz
 *
 * player_create reserva memoria para un nuevo jugador
 * e inicializa sus miembros
 * @param id el identificador del numero para el nuevo jugador
 * @return un nuevo jugador inicializado
 */
Player *player_create(Id id);

/**
 * @brief Destruye un jugador
 * @author Daniel Martinez Sanz
 *
 * player_destroy libera la reserva previa de memoria
 * para un jugador
 * @param player un puntero al jugador que tiene que ser destruido
 * @return Ok, si todo funciona correctamente o ERROR si ha habido algun fallo
 */
STATUS player_destroy(Player *player);

/**
 * @brief Obtiene la id de un jugador
 * @author Daniel Martinez Sanz
 *
 * @param player un puntero al jugador
 * @return la id del jugador
 */
Id player_get_id(Player *player);

/**
 * @brief Modifica la id de un jugador
 * @author Alejandro Coloma
 *
 * @param player un puntero al jugador
 * @return la id del jugador
 */
STATUS player_set_id(Player *player, Id id);

/**
 * @brief Establece el nombre de un jugador
 * @author Daniel Martinez Sanz
 *
 * @param player un puntero a un jugador
 * @param name una cadena con el nombre a asignar
 * @return OK si todo esta bien o ERROR si hay algun fallo
 */

STATUS player_set_name(Player *player, char *name);

/**
 * @brief Obtiene el nombre de un jugador
 * @author Daniel Martinez Sanz
 *
 * @param player un puntero al jugador
 * @return una cadena con el nombre del jugador
 */
const char *player_get_name(Player *player);

/**
 * @brief Obtiene la localización del jugador
 * @author Alejandro Coloma
 *
 * @param player un puntero al jugador
 * @return id de la localización del jugador
 */
Id player_get_location(Player *player);

/**
 * @brief Cambia la localización del jugador
 * @author Alejandro Coloma
 *
 * @param player un puntero al jugador
 * @return Id del jugador
 */
STATUS player_set_location(Player *player, Id id);

/**
 * @brief Obtiene la id del objeto del jugador
 * @author Alejandro Coloma
 *
 * @param player un puntero al jugador
 * @return Id del objeto
 */
Id player_get_object(Player *player);

/**
 * @brief Obtiene si el jugador tiene un objeto o no
 * @author Daniel Martinez Sanz
 *
 * @param player un puntero al jugador
 * @param id el identificador del objeto
 * @return OK si todo esta bien o ERROR si ha habido algun error
 */
STATUS player_set_object(Player *player, Id id);

/**
 * @brief Imprime la informacion del jugador
 * @author Daniel Martinez Sanz
 *
 * Esta funcion muestr la id y el nombre del jugador, los espacios que le rodean y si tiene algun
 * objeto
 * @param player un puntero al jugador
 * @return OK si todo esta bien o ERROR si ha habido algun error
 */
STATUS player_print(Player *player);

/**
 * @brief Obtiene la salud del jugador
 * @author Alejandro Coloma
 *
 * @param player un puntero al jugador
 * @return Float de la vida del jugador
 */
float player_get_health(Player *player);

/**
 * @brief Modifica la salud del jugador
 * @author Alejandro Coloma
 *
 * @param player un puntero al jugador
 * @return OK si todo esta bien o ERROR si ha habido algun error
 */
STATUS player_set_health(Player *player, float health);

#endif
