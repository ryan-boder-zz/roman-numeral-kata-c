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


START_TEST (should_return_VI_when_given_6)
{
  ck_assert_str_eq("VI", integer_to_roman_numeral(6));
}
END_TEST


START_TEST (should_return_VII_when_given_7)
{
  ck_assert_str_eq("VII", integer_to_roman_numeral(7));
}
END_TEST


START_TEST (should_return_IX_when_given_9)
{
  ck_assert_str_eq("IX", integer_to_roman_numeral(9));
}
END_TEST


START_TEST (should_return_X_when_given_10)
{
  ck_assert_str_eq("X", integer_to_roman_numeral(10));
}
END_TEST


START_TEST (should_return_XIV_when_given_14)
{
  ck_assert_str_eq("XIV", integer_to_roman_numeral(14));
}
END_TEST


START_TEST (should_return_XIX_when_given_19)
{
  ck_assert_str_eq("XIX", integer_to_roman_numeral(19));
}
END_TEST


START_TEST (should_return_XL_when_given_40)
{
  ck_assert_str_eq("XL", integer_to_roman_numeral(40));
}
END_TEST


START_TEST (should_return_XLI_when_given_41)
{
  ck_assert_str_eq("XLI", integer_to_roman_numeral(41));
}
END_TEST


START_TEST (should_return_L_when_given_50)
{
  ck_assert_str_eq("L", integer_to_roman_numeral(50));
}
END_TEST


START_TEST (should_return_XC_when_given_90)
{
  ck_assert_str_eq("XC", integer_to_roman_numeral(90));
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
  tcase_add_test(core, should_return_VI_when_given_6);
  tcase_add_test(core, should_return_VII_when_given_7);
  tcase_add_test(core, should_return_IX_when_given_9);
  tcase_add_test(core, should_return_X_when_given_10);
  tcase_add_test(core, should_return_XIV_when_given_14);
  tcase_add_test(core, should_return_XIX_when_given_19);
  tcase_add_test(core, should_return_XL_when_given_40);
  tcase_add_test(core, should_return_XLI_when_given_41);
  tcase_add_test(core, should_return_L_when_given_50);
  tcase_add_test(core, should_return_XC_when_given_90);
  suite_add_tcase(suite, core);
  return suite;
}
