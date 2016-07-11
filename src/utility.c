#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool is_valid_roman_numeral(char* s)
{
  if (NULL == s)
    return false;
  
  size_t length = strlen(s);
  if (0 == length)
    return false;
  
  char* valid_digits = "IVXLCD";
  for (int i = 0; i < length; i++) {
    if (NULL == strchr(valid_digits, s[i]))
      return false;
  }
  
  return true;
}
