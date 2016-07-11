#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "from_roman.h"


const char* arabic_to_roman(int arabic)
{
  switch (arabic) {
  case 1: return "I";
  case 4: return "IV";
  case 5: return "V";
  case 10: return "X";
  case 50: return "L";
  case 100: return "C";
  case 500: return "D";
  case 1000: return "M";
  default: return NULL;
  }
}


// Extracts the given value as many times as possible and returns the remainder
int extract_roman_value(int value, int remaining, char* result)
{
  while (remaining >= value) {
    strcat(result, arabic_to_roman(value));
    remaining -= value;
  }
  return remaining;
}


const char* integer_to_roman_numeral(int integer)
{
  if (0 >= integer)
    return NULL;
  
  char* result = calloc(64, sizeof(char));
  
  int remaining = integer;
  remaining = extract_roman_value(5, remaining, result);
  remaining = extract_roman_value(4, remaining, result);
  remaining = extract_roman_value(1, remaining, result);
  
  return result;
}
