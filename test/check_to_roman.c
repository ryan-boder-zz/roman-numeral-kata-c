#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "to_roman.h"


START_TEST (should_return_I_when_given_1)
{
  ck_assert_str_eq("I", integer_to_roman_numeral(1));
}
END_TEST


Suite* check_to_roman_suite(void)
{
  Suite* suite = suite_create("Convert Integers to Roman Numerals");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_return_I_when_given_1);
  suite_add_tcase(suite, core);
  return suite;
}
