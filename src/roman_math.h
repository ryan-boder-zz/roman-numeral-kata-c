#ifndef ROMAN_MATH_H
#define ROMAN_MATH_H

/**
 * Adds 2 Roman Numerals.
 *
 * Returns the result of a + b or NULL on error.
 *
 * The returned string is dynamically allocated and must be freed by the caller.
 */
const char* roman_math_add(const char* a, const char* b);

/**
 * Subtracts one Roman Numeral from another.
 *
 * Returns the result of a - b or NULL on error.
 *
 * The returned string is dynamically allocated and must be freed by the caller.
 */
const char* roman_math_subtract(const char* a, const char* b);

#endif
