#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "from_roman.h"


START_TEST (should_return_1_when_given_I)
{
  ck_assert_int_eq(1, roman_numeral_to_integer("I"));
}
END_TEST


Suite* check_from_roman_suite(void)
{
  Suite* suite = suite_create("Convert Roman Numerals to Integers");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_return_1_when_given_I);
  suite_add_tcase(suite, core);  
  return suite;
}
