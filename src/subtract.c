#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "from_roman.h"
#include "to_roman.h"

const char* roman_math_subtract(const char* a, const char* b)
{
  if (!is_valid_roman_numeral(a) || !is_valid_roman_numeral(b))
    return NULL;

  int lhs = roman_numeral_to_integer(a);
  int rhs = roman_numeral_to_integer(b);
  int result = lhs - rhs;

  return integer_to_roman_numeral(result);
}
