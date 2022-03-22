/** 
 * @brief It tests enemy module
 * 
 * @file enemy_test.c
 * @author Profesores Pprog
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "enemy.h"
#include "enemy_test.h"
#include "test.h"

#define MAX_TESTS 28

/** 
 * @brief Main function for Enemy unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Enemy:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_enemy_create();
  if (all || test == 2) test2_enemy_create();
  if (all || test == 3) test1_enemy_set_name();
  if (all || test == 4) test2_enemy_set_name();
  if (all || test == 5) test3_enemy_set_name();
  if (all || test == 6) test1_enemy_set_location();
  if (all || test == 7) test2_enemy_set_location();
  if (all || test == 14) test1_enemy_get_name();
  if (all || test == 15) test2_enemy_get_name();
  if (all || test == 19) test1_enemy_get_location();
  if (all || test == 20) test2_enemy_get_location();
  if (all || test == 27) test1_enemy_get_id();
  if (all || test == 28) test2_enemy_get_id();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_enemy_create() {
  int result;
  Enemy *s;
  s = enemy_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  enemy_destroy(s);
}

void test2_enemy_create() {
  Enemy *s;
  s = enemy_create(4);
  PRINT_TEST_RESULT(enemy_get_id(s) == 4);
  enemy_destroy(s);
}

void test1_enemy_set_name() {
  Enemy *s;
  s = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(s, "hola") == OK);
  enemy_destroy(s);
}

void test2_enemy_set_name() {
  Enemy *s = NULL;
  PRINT_TEST_RESULT(enemy_set_name(s, "hola") == ERROR);
}

void test3_enemy_set_name() {
  Enemy *s;
  s = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(s, NULL) == ERROR);
  enemy_destroy(s);
}

void test1_enemy_set_location() {
  Enemy *s;
  s = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_location(s, 4) == OK);
  enemy_destroy(s);
}

void test2_enemy_set_location() {
  Enemy *s = NULL;
  PRINT_TEST_RESULT(enemy_set_location(s, 4) == ERROR);
}

void test1_enemy_get_name() {
  Enemy *s;
  s = enemy_create(1);
  enemy_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(enemy_get_name(s), "adios") == 0);
  enemy_destroy(s);
}

void test2_enemy_get_name() {
  Enemy *s = NULL;
  PRINT_TEST_RESULT(enemy_get_name(s) == NULL);
}

void test1_enemy_get_location() {
  Enemy *s;
  s = enemy_create(5);
  enemy_set_location(s, 4);
  PRINT_TEST_RESULT(enemy_get_location(s) == 4);
  enemy_destroy(s);
}

void test2_enemy_get_location() {
  Enemy *s = NULL;
  PRINT_TEST_RESULT(enemy_get_location(s) == NO_ID);
}

void test1_enemy_get_id() {
  Enemy *s;
  s = enemy_create(25);
  PRINT_TEST_RESULT(enemy_get_id(s) == 25);
  enemy_destroy(s);
}

void test2_enemy_get_id() {
  Enemy *s = NULL;
  PRINT_TEST_RESULT(enemy_get_id(s) == NO_ID);
}
