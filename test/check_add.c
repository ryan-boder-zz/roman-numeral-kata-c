#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "roman_math.h"
#include "test_utility.h"


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
  mem_free_assert_str_eq("II", roman_math_add("I", "I"));
}
END_TEST


START_TEST (should_return_III_when_given_I_and_II)
{
  mem_free_assert_str_eq("III", roman_math_add("I", "II"));
  mem_free_assert_str_eq("III", roman_math_add("II", "I"));
}
END_TEST


START_TEST (should_return_IV_when_given_II_and_II)
{
  mem_free_assert_str_eq("IV", roman_math_add("II", "II"));
}
END_TEST


START_TEST (should_return_V_when_given_II_and_III)
{
  mem_free_assert_str_eq("V", roman_math_add("II", "III"));
  mem_free_assert_str_eq("V", roman_math_add("III", "II"));
}
END_TEST


START_TEST (should_return_XII_when_given_VII_and_V)
{
  mem_free_assert_str_eq("XII", roman_math_add("VII", "V"));
  mem_free_assert_str_eq("XII", roman_math_add("V", "VII"));
}
END_TEST


START_TEST (should_return_MDCCL_when_given_CMLXXXIV_and_DCCLXVI)
{
  mem_free_assert_str_eq("MDCCL", roman_math_add("CMLXXXIV", "DCCLXVI"));
  mem_free_assert_str_eq("MDCCL", roman_math_add("DCCLXVI", "CMLXXXIV"));
}
END_TEST


START_TEST (should_return_MMMCMXCIX_when_given_MMM_and_CMXCIX)
{
  mem_free_assert_str_eq("MMMCMXCIX", roman_math_add("MMM", "CMXCIX"));
  mem_free_assert_str_eq("MMMCMXCIX", roman_math_add("CMXCIX", "MMM"));
}
END_TEST


START_TEST (should_return_NULL_when_result_is_4000)
{
  ck_assert(NULL == roman_math_add("MMMCMXCIX", "I"));
  ck_assert(NULL == roman_math_add("I", "MMMCMXCIX"));
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
  tcase_add_test(core, should_return_IV_when_given_II_and_II);
  tcase_add_test(core, should_return_V_when_given_II_and_III);
  tcase_add_test(core, should_return_XII_when_given_VII_and_V);
  tcase_add_test(core, should_return_MDCCL_when_given_CMLXXXIV_and_DCCLXVI);
  tcase_add_test(core, should_return_MMMCMXCIX_when_given_MMM_and_CMXCIX);
  tcase_add_test(core, should_return_NULL_when_result_is_4000);
  suite_add_tcase(suite, core);  
  return suite;
}
