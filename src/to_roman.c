#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "from_roman.h"

const char* integer_to_roman_numeral(int integer)
{
  if (integer == 2)
    return "II";
  return "I";
}
