#ifndef ROMAN_NUMERAL_CALC_H
#define ROMAN_NUMERAL_CALC_H

#include <stdbool.h>
#include <string.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000


extern const int INVALID_INPUT;

int singleRomanToInt(const char romanNumChar);
int romanToInt( const char* romanNumStr);




#endif
                  
