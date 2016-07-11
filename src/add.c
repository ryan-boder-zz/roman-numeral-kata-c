#include <stdlib.h>
#include <string.h>
#include "utility.h"


char* roman_math_add(char* a, char* b)
{
  if (!is_valid_roman_numeral(a) || !is_valid_roman_numeral(b))
    return NULL;
  return concatenate(a, b);
}
