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


START_TEST (should_return_NULL_when_given_empty_input)
{
  ck_assert_ptr_eq(NULL, roman_math_subtract("", ""));
  ck_assert_ptr_eq(NULL, roman_math_subtract("I", ""));
  ck_assert_ptr_eq(NULL, roman_math_subtract("", "I"));
}
END_TEST


START_TEST (should_return_NULL_when_given_input_with_invalid_digit)
{
  ck_assert_ptr_eq(NULL, roman_math_subtract("A", "I"));
  ck_assert_ptr_eq(NULL, roman_math_subtract("I", "A"));
}
END_TEST


START_TEST (should_return_I_when_given_II_and_I)
{
  ck_assert_str_eq("I", roman_math_subtract("II", "I"));
}
END_TEST


START_TEST (should_return_II_when_given_IX_and_VII)
{
  ck_assert_str_eq("II", roman_math_subtract("IX", "VII"));
}
END_TEST


START_TEST (should_return_MMLXVII_when_given_MMMCCLVI_and_MCLXXXIX)
{
  ck_assert_str_eq("MMLXVII", roman_math_subtract("MMMCCLVI", "MCLXXXIX"));
}
END_TEST


START_TEST (should_return_NULL_when_result_is_0)
{
  ck_assert(NULL == roman_math_subtract("I", "I"));
  ck_assert(NULL == roman_math_subtract("V", "V"));
  ck_assert(NULL == roman_math_subtract("XX", "XX"));
}
END_TEST


START_TEST (should_return_NULL_when_result_is_negative)
{
  ck_assert(NULL == roman_math_subtract("I", "II"));
  ck_assert(NULL == roman_math_subtract("V", "X"));
  ck_assert(NULL == roman_math_subtract("XX", "M"));
}
END_TEST


Suite* check_subtract_suite(void)
{
  Suite* suite = suite_create("Subtract Roman Numerals");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, should_return_NULL_when_given_NULL_input);
  tcase_add_test(core, should_return_NULL_when_given_empty_input);
  tcase_add_test(core, should_return_NULL_when_given_input_with_invalid_digit);
  tcase_add_test(core, should_return_I_when_given_II_and_I);
  tcase_add_test(core, should_return_II_when_given_IX_and_VII);
  tcase_add_test(core, should_return_MMLXVII_when_given_MMMCCLVI_and_MCLXXXIX);
  tcase_add_test(core, should_return_NULL_when_result_is_0);
  tcase_add_test(core, should_return_NULL_when_result_is_negative);
  suite_add_tcase(suite, core);  
  return suite;
}
