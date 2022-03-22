#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

/**
 * @test Test enemy creation
 * @pre Enemy ID 
 * @post Non NULL pointer to enemy 
 */
void test1_enemy_create();

/**
 * @test Test enemy creation
 * @pre Enemy ID 
 * @post Enemy_ID == Supplied Enemy Id
 */
void test2_enemy_create();

/**
 * @test Test function for enemy_name setting
 * @pre String with enemy name
 * @post Ouput==OK 
 */
void test1_enemy_set_name();

/**
 * @test Test function for enemy_name setting
 * @pre pointer to enemy = NULL 
 * @post Output==ERROR
 */
void test2_enemy_set_name();

/**
 * @test Test function for enemy_name setting
 * @pre pointer to enemy_name = NULL (point to enemy = NON NULL) 
 * @post Output==ERROR
 */
void test3_enemy_set_name();
void test1_enemy_set_location();
void test2_enemy_set_location();
void test3_enemy_set_location();
void test4_enemy_set_location();
void test1_enemy_get_id();
void test2_enemy_get_id();
void test1_enemy_get_name();
void test2_enemy_get_name();
void test1_enemy_get_location();
void test2_enemy_get_location();

#endif
