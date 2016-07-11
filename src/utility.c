#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool is_valid_roman_numeral(const char* s)
{
  if (NULL == s)
    return false;
  
  size_t length = strlen(s);
  if (0 == length)
    return false;
  
  char* valid_digits = "IVXLCDM";
  for (int i = 0; i < length; i++) {
    if (NULL == strchr(valid_digits, s[i]))
      return false;
  }
  
  if (NULL != strstr(s, "IIII"))
    return false;
  if (NULL != strstr(s, "XXXX"))
    return false;
  if (NULL != strstr(s, "CCCC"))
    return false;
  if (NULL != strstr(s, "VV"))
    return false;
  if (NULL != strstr(s, "LL"))
    return false;
  if (NULL != strstr(s, "DD"))
    return false;

  return true;
}


const char* concatenate(const char* a, const char* b)
{
  char* result = malloc(strlen(a) + strlen(b) + 1);
  strcpy(result, a);
  strcat(result, b);
  return result;
}
