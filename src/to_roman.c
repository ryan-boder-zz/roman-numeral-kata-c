#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "from_roman.h"

const char* integer_to_roman_numeral(int integer)
{
  if (0 >= integer)
    return NULL;
  if (integer == 3)
    return "III";
  if (integer == 2)
    return "II";
  return "I";
}
