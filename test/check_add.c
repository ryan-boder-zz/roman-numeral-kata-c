#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "roman_math.h"


START_TEST (should_return_NULL_when_given_NULL_input)
{
  ck_assert_ptr_eq(NULL, roman_math_add(NULL, NULL));
  ck_assert_ptr_eq(NULL, roman_math_add("", NULL));
  ck_assert_ptr_eq(NULL, roman_math_add(NULL, ""));
}
END_TEST


START_TEST (should_return_NULL_when_given_empty_input)
{
  ck_assert_ptr_eq(NULL, roman_math_add("", ""));
  ck_assert_ptr_eq(NULL, roman_math_add("I", ""));
  ck_assert_ptr_eq(NULL, roman_math_add("", "I"));
}
END_TEST


START_TEST (should_return_NULL_when_given_input_with_invalid_digit)
{
  ck_assert_ptr_eq(NULL, roman_math_add("A", "I"));
  ck_assert_ptr_eq(NULL, roman_math_add("I", "A"));
}
END_TEST


START_TEST (should_return_II_when_given_I_and_I)
{
  ck_assert_str_eq("II", roman_math_add("I", "I"));
}
END_TEST


START_TEST (should_return_III_when_given_I_and_II)
{
  ck_assert_str_eq("III", roman_math_add("I", "II"));
  ck_assert_str_eq("III", roman_math_add("II", "I"));
}
END_TEST


Suite* check_add_suite(void)
{
  Suite* suite = suite_create("Add Roman Numerals");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_return_NULL_when_given_NULL_input);
  tcase_add_test(core, should_return_NULL_when_given_empty_input);
  tcase_add_test(core, should_return_NULL_when_given_input_with_invalid_digit);
  tcase_add_test(core, should_return_II_when_given_I_and_I);
  tcase_add_test(core, should_return_III_when_given_I_and_II);
  suite_add_tcase(suite, core);  
  return suite;
}
