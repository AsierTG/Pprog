/**
 * @brief Define el motor grafico textual
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "enemy.h"

#define ROWS 23
#define COLUMNS 80

struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, 13);
  ge->descript = screen_area_init(50, 1, 29, 13);
  ge->banner = screen_area_init(28, 15, 23, 1);
  ge->help = screen_area_init(1, 16, 78, 2);
  ge->feedback = screen_area_init(1, 19, 78, 3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID, ply_loc = NO_ID, ply_obj = NO_ID, ene_loc = NO_ID, *id_objetos=NULL;
  //id_objetos=(Id *) malloc (MAX*sizeof(Id));
  int i,j;
  float ply_health, ene_health;
  Space *space_act = NULL;
  //Player *player = player_create(ID_JUGADOR);
  //Enemy *enemy = enemy_create(ID_ENEMY);
  char obj = '\0';
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Imprime el area del mapa */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    
    if (id_back != NO_ID)
    {    
    id_objetos=space_get_object(game_get_space(game, id_back));
    for(i=0; i < MAX;i++){
      if (game_get_object_location(game,id_objetos[i]) == id_back)
        obj = '*';
      else
        obj = ' ';
  }
    


      sprintf(str, "  |         %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
  




  id_objetos=space_get_object(game_get_space(game, id_act));
    for(i=0; i < MAX ;i++){
    if (game_get_object_location(game, id_objetos[i]) == id_act)
      obj = '*';
    else
      obj = ' ';
    }
    if (id_act != NO_ID)
    {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      /*\\(\")/ CODIFICACION HORMIGA */
      sprintf(str, "  | gpp0^   %2d|", (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
    if (id_next != NO_ID)
    {
    id_objetos=space_get_object(game_get_space(game, id_next));
    for(i=0; i < MAX ;i++){
    if (game_get_object_location(game, id_objetos[i]) == id_next)
      obj = '*';
    else
      obj = ' ';
    }

      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Imprime la descripcion del area */
  screen_area_clear(ge->descript);
  sprintf(str, "  Object location:       ");
  screen_area_puts(ge->descript, str);
  for (i = 0; i < MAX_SPACES && game_get_space_no_id(game,i) != NULL; i++)
  {
    /*RECORRER SOLO EL NUMERO DE OBJETOS*/
    id_objetos=space_get_object(game_get_space_no_id(game,i));
    for(j = 0; j < 1/*NUM ID*/ ; j++){
    if ((obj_loc = game_get_object_location(game,id_objetos[j])) != NO_ID)
    {
      sprintf(str, "  %ld:%ld", space_get_id(game_get_space_no_id(game,i)), id_objetos[j]);
      //sprintf(str, "  %d:%ld", (int)obj_loc, space_get_id(game->spaces[i]));
      screen_area_puts(ge->descript, str);
      
    }
    }
  }

  if ((ply_loc = game_get_player_location(game)) != NO_ID)
  {
      sprintf(str, "  Player location:%d", (int)ply_loc);
      screen_area_puts(ge->descript, str);
  }
  
  if((ply_obj = player_get_object(game_get_player(game))) != NO_ID)
  {
      sprintf(str, "  Player object:%d", (int)ply_obj);
      screen_area_puts(ge->descript, str);
  }
  
  if((ply_health = player_get_health(game_get_player(game))) > 0)
  {
      sprintf(str, "  Player health:%.0f", (float)ply_health);
      screen_area_puts(ge->descript, str);
  }
  
  if((ene_loc = enemy_get_location(game_get_enemy(game))) != NO_ID && enemy_get_health(game_get_enemy(game)) > 0)
  {
      sprintf(str, "  Enemy location: %.0d", (int)ene_loc);
      screen_area_puts(ge->descript, str);
  }
                  
 if((ene_health = enemy_get_health(game_get_enemy(game))) > 0){
     sprintf(str, "  Enemy health: %.0f", (float)ene_health);
     screen_area_puts(ge->descript, str);
 }
  /* Imprime el area de la cabecera */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Imprime el area de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, " next or n, back or b, take or t, drop or d, lest or l, right or r, attack or  a exit or e");
  screen_area_puts(ge->help, str);

  /* Imprime el area de retroalimentacion */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Depura la terminal */
  screen_paint();
  printf("prompt:> ");
}
