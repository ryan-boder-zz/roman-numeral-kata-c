#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "from_roman.h"
#include "to_roman.h"
#include "test_utility.h"


typedef void (*test_function)(const char*,const char*);


void test_from_roman(const char* integer, const char* roman)
{
  ck_assert_int_eq(atoi(integer), roman_numeral_to_integer(roman));
}


void test_to_roman(const char* integer, const char* roman)
{
  mem_free_assert_str_eq(roman, integer_to_roman_numeral(atoi(integer)));
}


void for_each_roman_numeral(test_function fn)
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

    fn(integer, roman);

    free(line);
    line = NULL;
  }

  fclose(fp);
}


START_TEST (should_convert_roman_numerals_to_integers)
{
  for_each_roman_numeral(test_from_roman);
}
END_TEST


START_TEST (should_convert_integers_to_roman_numerals)
{
  for_each_roman_numeral(test_to_roman);
}
END_TEST


Suite* check_all_conversions_suite(void)
{
  Suite* suite = suite_create("Exaustive Conversions Test");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_convert_roman_numerals_to_integers);
  tcase_add_test(core, should_convert_integers_to_roman_numerals);
  suite_add_tcase(suite, core);
  return suite;
}
