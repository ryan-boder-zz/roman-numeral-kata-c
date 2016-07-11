#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "from_roman.h"


const char* arabic_to_roman(int arabic)
{
  switch (arabic) {
  case 1: return "I";
  case 4: return "IV";
  case 5: return "V";
  case 9: return "IX";
  case 10: return "X";
  case 40: return "XL";
  case 50: return "L";
  case 90: return "XC";
  case 100: return "C";
  case 400: return "CD";
  case 500: return "D";
  case 900: return "CM";
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
  
  const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  for (int i = 0; i < sizeof(values) / sizeof(*values); i++) {
    remaining = extract_roman_value(values[i], remaining, result);
  }
  
  return result;
}
