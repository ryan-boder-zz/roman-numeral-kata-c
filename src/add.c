#include <stdlib.h>
#include <string.h>


char* roman_math_add(char* a, char* b)
{
  if (NULL == a || NULL == b)
    return NULL;
  size_t a_length = strlen(a);
  size_t b_length = strlen(b);
  if (0 == a_length || 0 == b_length)
    return NULL;
  char* result = malloc(a_length + b_length + 1);
  strcpy(result, a);
  strcat(result, b);
  return result;
}
