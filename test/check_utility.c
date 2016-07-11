#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "utility.h"


START_TEST (validate_roman_numeral_should_return_false_when_given_NULL_input)
{
  ck_assert(!is_valid_roman_numeral(NULL));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_given_empty_input)
{
  ck_assert(!is_valid_roman_numeral(""));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_input_with_invalid_digit)
{
  ck_assert(!is_valid_roman_numeral("A"));
  ck_assert(!is_valid_roman_numeral("B"));
  ck_assert(!is_valid_roman_numeral("XXI3I"));
  ck_assert(!is_valid_roman_numeral("VVPV"));
  ck_assert(!is_valid_roman_numeral("V-LV"));
  ck_assert(!is_valid_roman_numeral("X X"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_true_when_input_with_all_valid_digits)
{
  ck_assert(is_valid_roman_numeral("I"));
  ck_assert(is_valid_roman_numeral("V"));
  ck_assert(is_valid_roman_numeral("X"));
  ck_assert(is_valid_roman_numeral("L"));
  ck_assert(is_valid_roman_numeral("C"));
  ck_assert(is_valid_roman_numeral("D"));
  ck_assert(is_valid_roman_numeral("M"));
  ck_assert(is_valid_roman_numeral("II"));
  ck_assert(is_valid_roman_numeral("IVXLCD"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_I_repeats_more_than_thrice)
{
  ck_assert(!is_valid_roman_numeral("IIII"));
  ck_assert(!is_valid_roman_numeral("IIIXIIII"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_X_repeats_more_than_thrice)
{
  ck_assert(!is_valid_roman_numeral("XXXX"));
  ck_assert(!is_valid_roman_numeral("XXXIXXXX"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_C_repeats_more_than_thrice)
{
  ck_assert(!is_valid_roman_numeral("CCCC"));
  ck_assert(!is_valid_roman_numeral("CCCICCCC"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_V_repeats_more_than_once)
{
  ck_assert(!is_valid_roman_numeral("VV"));
  ck_assert(!is_valid_roman_numeral("VIVV"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_L_repeats_more_than_once)
{
  ck_assert(!is_valid_roman_numeral("LL"));
  ck_assert(!is_valid_roman_numeral("LILL"));
}
END_TEST


START_TEST (validate_roman_numeral_should_return_false_when_D_repeats_more_than_once)
{
  ck_assert(!is_valid_roman_numeral("DD"));
  ck_assert(!is_valid_roman_numeral("DIDD"));
}
END_TEST


Suite* check_utility_suite(void)
{
  Suite* suite = suite_create("Roman Numeral Utilities");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_given_NULL_input);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_given_empty_input);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_input_with_invalid_digit);
  tcase_add_test(core, validate_roman_numeral_should_return_true_when_input_with_all_valid_digits);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_I_repeats_more_than_thrice);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_X_repeats_more_than_thrice);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_C_repeats_more_than_thrice);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_V_repeats_more_than_once);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_L_repeats_more_than_once);
  tcase_add_test(core, validate_roman_numeral_should_return_false_when_D_repeats_more_than_once);
  suite_add_tcase(suite, core);  
  return suite;
}
