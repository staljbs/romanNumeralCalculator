#include "romanNumeralCalculator.h"

const int INVALID_INPUT = 0;

//=================================================================
// singleRomanToInt     : Function to convert a single roman numeral to its 
//                        integer value
// Input                : Roman numeral character
// Output               : Returns integer value corresponding to the input
//================================================================
int singleRomanToInt( const char romanNumChar )
{
        switch (romanNumChar)
        {
                case 'I':       return I;
                case 'V':       return V;
                case 'X':       return X;
                case 'L':       return L;
                case 'C':       return C;
                case 'D':       return D;
                case 'M':       return M;
                default :       return INVALID_INPUT;
        };
}


