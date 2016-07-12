#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "roman_math.h"


START_TEST (should_return_NULL_when_given_NULL_input)
{
  ck_assert_ptr_eq(NULL, roman_math_subtract(NULL, NULL));
  ck_assert_ptr_eq(NULL, roman_math_subtract("", NULL));
  ck_assert_ptr_eq(NULL, roman_math_subtract(NULL, ""));
}
END_TEST


Suite* check_subtract_suite(void)
{
  Suite* suite = suite_create("Subtract Roman Numerals");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_return_NULL_when_given_NULL_input);
  suite_add_tcase(suite, core);  
  return suite;
}
