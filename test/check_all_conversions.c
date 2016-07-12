#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "from_roman.h"
#include "to_roman.h"


START_TEST (should_convert_roman_numerals_to_integers)
{
  FILE* fp = fopen("data/roman_numerals.txt", "r");
  if (NULL == fp)
    ck_abort_msg("Failed to open file");

  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, fp)) != -1) {
    char* integer = strtok(line, "=");
    char* roman = strtok(NULL, "\n");

    ck_assert_int_eq(atoi(integer), roman_numeral_to_integer(roman));

    free(line);
    line = NULL;
  }

  fclose(fp);
}
END_TEST


Suite* check_all_conversions_suite(void)
{
  Suite* suite = suite_create("Exaustive Conversions Test");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_convert_roman_numerals_to_integers);
  suite_add_tcase(suite, core);
  return suite;
}
