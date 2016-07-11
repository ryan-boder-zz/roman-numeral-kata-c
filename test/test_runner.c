#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <check.h>
#include "check_utility.h"
#include "check_add.h"


int main(void)
{
  SRunner* runner = srunner_create(check_utility_suite());
  srunner_add_suite(runner, check_add_suite());
  
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
