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
extern const char ADDITION_OPERATOR;
extern const char SUBTRACTION_OPERATOR;

int singleRomanToInt( const char romanNumChar );
int romanToInt( const char* romanNumStr);
char* romanAddition(const char* romanNum1, const char* romanNum2);
char* romanSubtraction(const char* romanNum1, const char* romanNum2);
char* intToRoman(int romanIntValue);



#endif
                  
