#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "from_roman.h"


int digit_to_int(char digit)
{
  switch (digit)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}





int roman_numeral_to_integer(char* roman)
{
  int result = 0;
  for (int i = 0; i < strlen(roman); i++)
    {
      result += digit_to_int(roman[i]);
    }
  return result;
}
