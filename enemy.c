/**
 * @brief Implementacion del modulo enemy
 *
 * @file enemy.c
 * @author Daniel Martinez Sanz
 * @date 03/03/2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "enemy.h"

/**
 * @brief Enemy
 *
 * Esta estructura almacena toda la informacion del enemigo
 */

struct _Enemy
{
    Id id;                    /*!< Id numero del enemigo, debe de ser unico */
    char name[WORD_SIZE + 1]; /*!< Nombre del enemigo */
    Id location;              /*!< Id de la localizacion del enemigo */
    float health;             /*!< Salud del enemigo */
};

/** Reserva memoria para un nuevo enemigo e inicializa todos su miembros */
Enemy *enemy_create(Id id)
{
    Enemy *newEnemy = NULL;

    if (id == NO_ID)
        return NULL;

    newEnemy = (Enemy *)malloc(sizeof(Enemy));
    if (newEnemy == NULL)
        return NULL;

    newEnemy->id = id;
    newEnemy->name[0] = '\0';
    newEnemy->location = NO_ID;
    newEnemy->health = HEALTH_ENEMY;

    return newEnemy;
}

/*Libera el puntero del enemigo */
STATUS enemy_destroy(Enemy *enemy)
{
    if (!enemy)
        return ERROR;

    free(enemy);

    enemy = NULL;

    return OK;
}

/** Obtiene la id del enemigo */
Id enemy_get_id(Enemy *enemy)
{
    if (!enemy)
        return NO_ID;

    return enemy->id;
}

/** Modifica la id del enemigo */
STATUS enemy_set_id(Enemy *enemy, Id id)
{
    if (!enemy || id == NO_ID)
        return ERROR;

    enemy->id = id;
    return OK;
}

/** Establece el nombre del enemigo */
STATUS enemy_set_name(Enemy *enemy, char *name)
{
    if (!enemy || !name)
        return ERROR;

    if (!strcpy(enemy->name, name))
        return ERROR;

    return OK;
}

/** Obtiene el nombre del jugador */
const char *enemy_get_name(Enemy *enemy)
{
    if (!enemy)
        return NULL;

    return enemy->name;
}

/** Obtiene la id de la localizacion del enemigo */
Id enemy_get_location(Enemy *enemy)
{
    if (!enemy)
        return NO_ID;

    return enemy->location;
}

/** Modifica la id de la localizacion del enemigo */
STATUS enemy_set_location(Enemy *enemy, Id id)
{
    if (!enemy || id == NO_ID)
        return ERROR;

    enemy->location = id;
    return OK;
}

/** Modifica la salud del enemigo */
STATUS enemy_set_health(Enemy *enemy, float health)
{
    if (!enemy || health < 0)
        return ERROR;

    enemy->health = health;

    return OK;
}

/** Obtiene la salud del enemigo */
float enemy_get_health(Enemy *enemy)
{
    if (!enemy)
        return -1;

    return enemy->health;
}

/** Imprime la informacin del enemigo */
STATUS enemy_print(Enemy *enemy)
{
    /* Control de Errores */
    if (!enemy)
        return ERROR;

    fprintf(stdout, "--->enemy (Id: %ld; Name: %s; Location: %ld)\n", enemy->id, enemy->name, enemy->location);

    return OK;
}
