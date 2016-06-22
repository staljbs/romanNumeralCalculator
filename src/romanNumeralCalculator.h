#ifndef ROMAN_NUMERAL_CALC_H
#define ROMAN_NUMERAL_CALC_H

#include <stdbool.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000


extern const int INVALID_INPUT;

int singleRomanToInt(const char romanNumChar);
int allowedRepeatsFor(int romanNumValue);
int allowedValueBefore(int romanNumValue);
bool isRomanNum(char * romanNumStr);




#endif
                  
