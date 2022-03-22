#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"
#include "space.h"
#include "object.h"

/**
   Lee un fichero con el mapa
*/
STATUS game_load_spaces(Game *game, char *filename)
{
  int i;
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      north = atol(toks);

      toks = strtok(NULL, "|");
      east = atol(toks);

      toks = strtok(NULL, "|");
      south = atol(toks);

      toks = strtok(NULL, "|");
      west = atol(toks);

      toks = strtok(NULL, "\n");
      strcpy(desc, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s\n", id, name, north, east, south, west, desc);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        for (i = 0; i < MAX_STRINGS; i++)
        {
          toks = strtok(NULL, "|");
          space_set_gdesc(space, toks, i); /* AÃ±ade la descripciÃ³n grÃ¡fica al juego */
        }
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id objId = NO_ID, spaceId;
  Space *s;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      objId = atol(toks); // Guarda ID Objeto

      toks = strtok(NULL, "|");
      strcpy(name, toks); // Guarda nombre de objeto

      toks = strtok(NULL, "|");
      spaceId = atol(toks); // Guarda Id del espacio

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", objId, name, spaceId);
#endif
      s = game_get_space(game, spaceId);
      if (!s)
      {
        return ERROR;
      }

      if (space_set_object(s, objId) == ERROR)
      {
        return ERROR;
      }
    }
  }

  fclose(file);
  return OK;
}

STATUS game_load_player(Game *game, char *filename){
        if(!game || !filename) return ERROR;
        
        FILE *file;
        Id player_id = NO_ID;
        float health;
        Id space_id;
        int inventory_size;
        char line[WORD_SIZE] = "";
        char name[WORD_SIZE] = "";
        char *toks = NULL;
        
        file = fopen(filename, "r");
        if(!file) return ERROR;
        
        while(fgets(line, WORD_SIZE, file)){
             
              if(strncmp("#p", line, 3) == 0)
              {
                 toks = strtok(line + 3, "|");
                 player_id = atol(toks);            // Guarda la ID del jugador.
                 
                 toks = strtok(NULL, "|");
                 strcpy(name,toks);                 // Guarda el nombre del jugador.
                 
                 toks = strtok(NULL, "|");
                 space_id = atol(toks);             // Guarda la id del espacio.
                 
                 toks = strtok(NULL, "|"),
                 
              }
              
              
        }
        
        
}