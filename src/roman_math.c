#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "from_roman.h"
#include "to_roman.h"


typedef int (*operator)(int,int);


int operator_add(int a, int b) { return a + b; }
int operator_subtract(int a, int b) { return a - b; }


const char* roman_math_operation(const char* a, const char* b, operator op)
{
  if (!is_valid_roman_numeral(a) || !is_valid_roman_numeral(b))
    return NULL;

  int lhs = roman_numeral_to_integer(a);
  int rhs = roman_numeral_to_integer(b);
  int result = op(lhs, rhs);

  return integer_to_roman_numeral(result);
}



const char* roman_math_add(const char* a, const char* b)
{
  return roman_math_operation(a, b, operator_add);
}


const char* roman_math_subtract(const char* a, const char* b)
{
  return roman_math_operation(a, b, operator_subtract);
}
