#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "check_utility.h"
#include "check_from_roman.h"
#include "check_to_roman.h"
#include "check_add.h"
#include "check_subtract.h"
#include "check_all_conversions.h"


int main(int argc, char** argv)
{
  SRunner* runner = srunner_create(check_utility_suite());
  srunner_add_suite(runner, check_from_roman_suite());
  srunner_add_suite(runner, check_to_roman_suite());
  srunner_add_suite(runner, check_add_suite());
  srunner_add_suite(runner, check_subtract_suite());
  srunner_add_suite(runner, check_all_conversions_suite());

  srunner_run_all(runner, (argc > 1) ? CK_VERBOSE : CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
