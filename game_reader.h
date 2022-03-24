
#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "space.h"

/*Módulo para la lectura del fichero o ficheros
con la configuración del programa, es decir, para inicializar el juego (crear el jugador, los
espacios, los objetos, etc.).*/

/**
 * @brief lee el fichero o ficheros con la configuración del programa
 * @author Profesores PPROG
 *
 * @param game puntero a la estructura Game
 * @param filename puntero con el nombre del fichero
 * @return OK, si todo ha ido bien o ERROR si hay algún error.
 */

STATUS game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief Lee el fichero o ficheros para crear los objetos del juego.
 *
 * @param game
 * @param filename
 * @return STATUS
 */
STATUS game_reader_load_objects(Game *game, char *filename);

/**
 * @brief Lee el fichero o ficheros para crear el jugador
 * @author Daniel Martinez Sanz
 * 
 * @param game puntero a la estructura Game
 * @param filename puntero con el nombre del fichero
 * @retun OK, si todo ha ido bien o ERROR si hay algún error.
 */
STATUS game_reader_load_player(Game *game, char *filename);

/**
 * @brief Lee el fichero o ficheros para crear el enemigo
 * @author Daniel Martinez Sanz
 * 
 * @param game puntero a la estructura Game
 * @param filename puntero con el nombre del fichero
 * @return OK, si todo ha ido bien o ERROR si hay algún error.
 */
STATUS game_reader_load_enemy(Game *game, char *filename);

#endif
