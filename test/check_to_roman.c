#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "to_roman.h"


START_TEST (should_return_NULL_when_given_0)
{
  ck_assert(NULL == integer_to_roman_numeral(0));
}
END_TEST


START_TEST (should_return_NULL_when_given_negative)
{
  ck_assert(NULL == integer_to_roman_numeral(-1));
  ck_assert(NULL == integer_to_roman_numeral(-8));
  ck_assert(NULL == integer_to_roman_numeral(-10));
}
END_TEST


START_TEST (should_return_I_when_given_1)
{
  ck_assert_str_eq("I", integer_to_roman_numeral(1));
}
END_TEST


START_TEST (should_return_II_when_given_2)
{
  ck_assert_str_eq("II", integer_to_roman_numeral(2));
}
END_TEST


START_TEST (should_return_III_when_given_3)
{
  ck_assert_str_eq("III", integer_to_roman_numeral(3));
}
END_TEST


START_TEST (should_return_IV_when_given_4)
{
  ck_assert_str_eq("IV", integer_to_roman_numeral(4));
}
END_TEST


START_TEST (should_return_V_when_given_5)
{
  ck_assert_str_eq("V", integer_to_roman_numeral(5));
}
END_TEST


Suite* check_to_roman_suite(void)
{
  Suite* suite = suite_create("Convert Integers to Roman Numerals");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_return_NULL_when_given_0);
  tcase_add_test(core, should_return_NULL_when_given_negative);
  tcase_add_test(core, should_return_I_when_given_1);
  tcase_add_test(core, should_return_II_when_given_2);
  tcase_add_test(core, should_return_III_when_given_3);
  tcase_add_test(core, should_return_IV_when_given_4);
  tcase_add_test(core, should_return_V_when_given_5);
  suite_add_tcase(suite, core);
  return suite;
}
