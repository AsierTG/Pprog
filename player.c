/**
 * @brief Implementar el modulo de player
 *
 * @file player.c
 * @author Daniel Martinez Sanz
 * @date 17/02/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "object.h"
#include "set.h"
#include "inventory.h"

/**
 * @brief Player
 *
 * Esta estructura almacena toda la informacion del jugador
 */

struct _Player
{
  Id id;                    /*!< Id numero del jugador, debe de ser unico */
  char name[WORD_SIZE + 1]; /*!< Nombre del jugador */
  Id location;              /*!< Id de la localización del jugador */
  Inventory *object;        
  float health;
};

/** Reserva memoria para un nuevo jugador e inicializa todos sus miembros */
Player *player_create(Id id)
{
  Player *newPlayer = NULL;

  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *)malloc(sizeof(Player));
  if (newPlayer == NULL)
    return NULL;

  newPlayer->id = id;

  newPlayer->name[0] = '\0';

  newPlayer->location = NO_ID;

  newPlayer->object = inventory_create();
  newPlayer->health = HEALTH_PLAYER;

  return newPlayer;
}

/*Libera el puntero de player*/
STATUS player_destroy(Player *player)
{
  if (!player)
    return ERROR;

  if(inventory_destroy(player->object) == ERROR){
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

/** Obtiene la id del jugador */
Id player_get_id(Player *player)
{
  if (!player)
    return NO_ID;

  return player->id;
}

/** Modifica la id del jugador */
STATUS player_set_id(Player *player, Id id)
{
  if (!player || id == NO_ID)
    return ERROR;

  player->id = id;
  return OK;
}

/** Establece el nombre del jugador */
STATUS player_set_name(Player *player, char *name)
{
  if (!player || !name)
  {
    return ERROR;
  }

  if (!strcpy(player->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** Obtiene el nombre del jugador */
const char *player_get_name(Player *player)
{
  if (!player)
  {
    return NULL;
  }
  return player->name;
}

/** Obtiene la id del jugador */
Id player_get_location(Player *player)
{
  if (!player)
    return NO_ID;

  return player->location;
}

/** Modifica la id del jugador */
STATUS player_set_location(Player *player, Id id)
{
  if (!player || id == NO_ID)
    return ERROR;

  player->location = id;
  return OK;
}

/** Obtiene un array con los objetos del jugador, si es NO_ID, no tiene objetos */
/*Id player_get_object(Player *player)
{
  if(!player){
    return NO_ID;
  }

  return player->object;
}*/


 Id player_get_object(Player *player){

  if (!player)
  {
    return NO_ID;
  }

  return NO_ID; //Inventory get object.
}

/** Establece si el jugador tiene un objeto o no */
STATUS player_set_object(Player *player, Id id){
  if(!player){
    return ERROR;
  }

  return inventory_addObject(player->object, id);
}

/** Imprime la informacion del jugador */
STATUS player_print(Player *player)
{
    if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Objects:\n", player->id, player->name,player->location);
  if(inventory_print(player->object) == ERROR){
    return ERROR;
  }
  return OK;
}

/** Obtiene la vida del jugador */
float player_get_health(Player *player)
{
  if (!player)
  {
    return -1;
  }
  return player->health;
}

STATUS player_set_health(Player *player, float health)
{
  if (!player || health < 0)
    return ERROR;

  player->health = health;

  return OK;
}