/**
 * @brief 
 *
 * @file set.h
 * @author Asier Tomé
 * @version 
 * @date 24/02/2022
 * @copyright GNU Public License
 */
#ifndef SET_H
#define SET_H
 #define MAX 20
#include "types.h"

typedef struct _Set Set;

/**
 * @brief It creates an array to colect the elements
 * 
 * @return It return a pointer to Set.
 */
Set *set_create();

/**
 * @brief It destroys the array created before
 * 
 * @param set 
 * @return OK or ERROR if it didnt work
 */
STATUS set_destroy(Set* set);

/**
 * @brief It adds a new object to the collection of Set
 * 
 * @param set 
 * @param id 
 * @return OK if the addition was succesfull or ERROR if it didn't work.
 */
STATUS set_add(Set* set, Id id);

/**
 * @brief It delete a id from the array
 * 
 * @param set 
 * @param id 
 * @return OK if it was succesfull or ERROR if it didn't work.
 */
STATUS set_delete(Set* set, Id id);

/**
 * @brief It tells the number of id's on the array.
 * 
 * @param set 
 * @return the number of Id's on the array, It returns -1 if its empty.
 */
int set_get_n_id(Set *set);

/**
 * @brief It gets de Id of a position on the array(set).
 * 
 * @param s a pointer to Set
 * @param pos, it marks the position you want to get.
 * @return Id of the array
 */
Id *set_get_id(Set *set);

/**
 * @brief It prints all the information of the array.
 *  
 * @param set 
 * @return OK if the information was printed or ERROR if something didn't work.
 */
STATUS set_print(Set* set);

/**
 * @brief Set the test 
 * 
 * @param set 
 * @return OK if it worked well, ERROR in case there is a mistake.
 */
STATUS set_test(Set* set);


/**
 * @brief Find if an id exists or not
 * 
 * @param set 
 * @param id 
 * @return TRUE if exists
 */
BOOL set_have_object(Set* set, Id id);

#endif 
