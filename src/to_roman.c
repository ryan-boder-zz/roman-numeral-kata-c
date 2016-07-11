#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "from_roman.h"


const char* arabic_to_roman(int arabic)
{
  switch (arabic) {
  case 1: return "I";
  case 5: return "V";
  case 10: return "X";
  case 50: return "L";
  case 100: return "C";
  case 500: return "D";
  case 1000: return "M";
  default: return NULL;
  }
}


const char* integer_to_roman_numeral(int integer)
{
  if (0 >= integer)
    return NULL;
  
  char* result = calloc(64, sizeof(char));

  int remaining = integer;  
  
  while (remaining >= 5) {
    strcat(result, arabic_to_roman(5));
    remaining -= 5;
  }
  
  while (remaining >= 1) {
    strcat(result, arabic_to_roman(1));
    remaining -= 1;
  }
  
  return result;
}
