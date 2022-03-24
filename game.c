/**
 * @brief Implementa la interfaz de juego y todas las llamadas requeridas
 * para cada comando
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"
#include "set.h"
#include "enemy.h"
#include "player.h"


#include <time.h> //Para los comandas rand


#define MAX_RAND 9

struct _Game
{
  Player *player;
  Enemy *enemy;
  Object* object[MAX];
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
};

/**
   Funciones privadas
*/

Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
STATUS game_set_enemy_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id);

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);
void game_command_left(Game *game);
void game_command_right(Game *game);
void game_command_attack(Game *game);


/*Funciones para obtener elementos de la estructura Game*/
/* Player *player;
  Enemy *enemy;
  Object* object[MAX];
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;*/


Player *game_get_player(Game *game){

  return game->player;
}

Enemy *game_get_enemy(Game *game){

  return game->enemy;

}


T_Command game_get_command(Game *game){

  return game->last_cmd;

}

Space *game_get_space_no_id(Game *game,int i){

  return game->spaces[i];

}




/**
   Implementacion de la interfaz de juego
*/

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  game->player = player_create(ID_JUGADOR);
  for(i=0;i<MAX;i++){
    game->object[i] = NULL;
  }
  game->enemy = enemy_create(ID_ENEMY);
  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_create_from_file(Game *game, char *filename)
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_player(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_enemy(game, filename) == ERROR)
    return ERROR;

  //game_set_player_location(game, game_get_space_id_at(game, 0));
  //game_set_enemy_location(game, game_get_space_id_at(game, 0));
  //player_print(game->player);
  //enemy_print(game->enemy);

  
  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}

STATUS game_set_enemy_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  enemy_set_location(game->enemy, id);

  return OK;
}


STATUS game_set_object_location(Game *game, Id id)
{
  int i;

  if (!game || id == NO_ID)
  {
    return ERROR;
  }

  for (i = 0; game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == id)
    {
      space_set_object(game->spaces[i], id);
      /*if(space_get_object(game->spaces[i])!=NO_ID){
          space_set_object(game->spaces[i],NO_ID);
          player_set_object(game->player,object_get_id(game->object));
          return OK;
        }

      if(space_get_object(game->spaces[i])==NO_ID){
          space_set_object(game->spaces[i],object_get_id(game->object));
          player_set_object(game->player,NO_ID);
          return OK;
        }*/
    }
  }

  return ERROR;
}

Id game_get_player_location(Game *game)
{
  if (!game)
    return NO_ID;
  return player_get_location(game->player);
}

/*Id game_get_object_location(Game *game)
{
  int i;
  Id id = NO_ID;

  if (!game)
    return NO_ID;

  for (i = 0; game->spaces[i] != NULL; i++)
  {
    if (space_get_object(game->spaces[i]) == NULL)
    {
      return NO_ID;
    }
    else
    {
      id = space_get_id(game->spaces[i]);
      return id;
    }
  }

  return id;
}*/



Id game_get_object_location(Game *game, Id id)
{
  int i,j;
  Id aux_id = NO_ID;

  if (!game)
    return NO_ID;

  for(i=0;i<MAX;i++){
    if(object_get_id(game->object[i])==id){
      break;
    }
  }

  for(j=0;j<MAX;j++){
    if(space_have_object(game->spaces[j],object_get_id(game->object[i]))==TRUE){
      aux_id=space_get_id(game->spaces[j]);
      return aux_id;
    }
  }

  return id;
}

STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  switch (cmd)
  {
  case UNKNOWN:
    game_command_unknown(game);
    break;

  case EXIT:
    game_command_exit(game);
    break;

  case NEXT:
    game_command_next(game);
    break;

  case BACK:
    game_command_back(game);
    break;

  case TAKE:
    game_command_take(game);
    break;

  case DROP:
    game_command_drop(game);
    break;

  case LEFT:
    game_command_left(game);
    break;

  case RIGHT:
    game_command_right(game);
    break;

  case ATTACK:
    game_command_attack(game);
    break;

  default:
    break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }
//printf("=> Object location: %d\n", (int)game_get_object_location(game));
for(i=0; i < MAX ;i++){
    printf("=> Object %d location: %ld\n",i+1, game_get_object_location(game,object_get_id(game->object[i])));
  }

  printf("=> Player location: %ld\n", game_get_player_location(game));
  printf("prompt:> ");
}

BOOL game_is_over(Game *game)
{
  /*if (player_get_health(game->player) == 0)
    return TRUE;
  else*/
    return FALSE;
}

/**
   Implementacion de llamadas para cada accion
*/
void game_command_unknown(Game *game)
{
}

void game_command_exit(Game *game)
{
}

void game_command_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_command_take(Game *game)
{
  int i; // j;
  Id id = NO_ID;
  // Id *lista_id;
  char aux;
  if (!game)
  {
    return;
  }
  scanf(" %c", &aux);

  if (aux != 'O')
  {
    return;
  }

  scanf(" %ld", &id);

  for (i = 0; game->spaces[i] != NULL; i++)
  {
    if (game_get_player_location(game) == space_get_id(game->spaces[i]))
    {
      if (player_get_object(game->player) == NO_ID && space_have_object(game->spaces[i], id) != FALSE)
      {
        player_set_object(game->player, id);
        space_del_object(game->spaces[i], id);
        return;
      }
    }
  }
}

void game_command_drop(Game *game)
{
  int i;

  if (!game)
    return;

  for (i = 0; game->spaces[i] != NULL; i++)
  {
    if (game_get_player_location(game) == space_get_id(game->spaces[i]))
    {
      if (player_get_object(game->player) != NO_ID)
      {
        space_set_object(game->spaces[i], player_get_object(game->player));
        player_set_object(game->player, NO_ID);
        return;
      }
    }
  }

  return;
}

void game_command_left(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_command_right(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_command_attack(Game *game)
{
  int x;

  if (!game)
  {
    return;
  }

  // Comprobar que este en el mismo espacio:
  if (player_get_location(game->player) != enemy_get_location(game->enemy)) // Como conseguir la localizacion del Enemigo?
  {
    return;
  }

  if (enemy_get_health(game->enemy) < 0) // Si el enemigo no tiene vida no ataca.
  {
    return;
  }

  // Genera un numero al azar entre 0 y MAX_RAND(9)
  x = rand() % MAX_RAND;

  // Si el numero esta entre 0 y 4, gana el enemigo y por tanto el jugador pierde un punto de vida
  if (x < 5)
  {
    if (player_set_health(game->player, player_get_health(game->player) - 1) == ERROR)
    {
      return;
    }
  }
  // Si el numero es mayor que 5, gana el jugador y por tanto el enemigo pierde un punto de vida.
  else
  {
    if (enemy_set_health(game->enemy, enemy_get_health(game->enemy) - 1) == ERROR)
    {
      return;
    }
  }
}
