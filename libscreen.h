/**
 * @brief Define la interfaz de la pantalla
 *
 * @file libscreen.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __LIBSCREEN_H_
#define __LIBSCREEN_H_

typedef struct _Area Area;

/**
 * @brief Crea una nueva pantalla
 * @author Profesores PPROG
 *
 * Esta funcion debe ser llamada al principio del programa,
 *  por lo que se asigna la pantalla completa antes de comenzar a definir areas
 * @param rows numero de filas que tendra la pantalla completa
 * @param columns numero de columnas que tendra la pantalla completa
 */
void screen_init(int rows, int columns);

/**
 * @brief Destruye una nueva area de pantalla
 * @author Profesores PPROG
 *
 * Como libera la pantalla debe de ser llamada al final del programa,
 * cuando las areas creadas hayan sido liberadas.
 */
void screen_destroy();

/**
 * @brief Imprime en la terminal la composicion actual de la pantalla
 * @author Profesores PPROG
 *
 * Esta funcion debe ser llamada cuando se hagan actualizaciones
 * en la pantalla que se quiere mostrar
 */
void screen_paint();

/**
 * @brief Crea un nuevo area dentro de la pantalla
 * @author Profesores PPROG
 *
 * screen_area_init asigna memoria para una nueva area
 *  e inicializa sus miembros.
 * @param x coordenada x de la esquina superior izquierda del area
 * @param y coordenada y de la esquina superior izquierda del area
 * @param width el ancho del area
 * @param height la altura del area
 * @return una nueva area inicializada
 */
Area *screen_area_init(int x, int y, int width, int height);

/**
 * @brief Destruye un area de la pantalla
 * @author Profesores PPROG
 *
 * Esta funcion debe ser llamada cuando se deje de necesitar un area,
 *  antes de que termine el programa.
 * @param area area que sera liberada
 */
void screen_area_destroy(Area *area);

/**
 * @brief Limpia un area, borrando todo su contenido
 * @author Profesores PPROG
 *
 * Esta funcion debe ser llamada para borrar la informacion de un area,
 *  antes de introducir un nuevo estado en ella
 * @param area area que va a ser despejada
 */
void screen_area_clear(Area *area);

/**
 * @brief Resetea el cursor de un area
 * @author Profesores PPROG
 *
 * Esta funcion resetea el cursor a la esquina superior izquierda del area.
 * @param area el area involucrada
 */
void screen_area_reset_cursor(Area *area);

/**
 * @brief Introduce algo de informacion dentro del area
 * @author Profesores PPROG
 *
 * Esta funcion establece la cadena que sera mostrada en el area
 * Cada cadena introducida sera una linea en el area especifica.
 * @param area area que va a ser modificada
 * @param str cadena que contiene la informacion que va a ser introducida dentro del area
 */
void screen_area_puts(Area *area, char *str);

#endif
