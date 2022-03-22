/**
 * @brief Define la interfaz de juego
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "enemy.h"
#include "object.h"
#include "set.h"

#define ID_JUGADOR 1
#define ID_OBJETO 2
#define ID_ENEMY 3

typedef struct _Game Game;

STATUS game_add_space(Game *game, Space *space);

STATUS game_create(Game *game);

STATUS game_create_from_file(Game *game, char *filename);

STATUS game_update(Game *game, T_Command cmd);

STATUS game_destroy(Game *game);

BOOL game_is_over(Game *game);

void game_print_data(Game *game);

Space *game_get_space(Game *game, Id id);

Id game_get_player_location(Game *game);

Id game_get_enemy_location(Game *game);

//Id game_get_object_location(Game *game);
Id game_get_object_location(Game *game, Id id);

T_Command game_get_last_command(Game *game);


/*FUNCIONES NUEVAS CON GAME OPACO*/
Player *game_get_player(Game *game);

Enemy *game_get_enemy(Game *game);


T_Command game_get_command(Game *game);

Space *game_get_space_no_id(Game *game,int i);

#endif
