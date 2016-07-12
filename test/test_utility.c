#include <stdlib.h>
#include <math.h>
#include <check.h>
#include "test_utility.h"


// Asserts then frees the malloced memory
void mem_free_assert_str_eq(const char* expected, const char* actual)
{
  ck_assert_str_eq(expected, actual);
  free((void*) actual);
}
