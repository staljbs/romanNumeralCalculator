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




//=================================================================
// allowedRepeatsFor    : Function to get the allowed value of repetition for 
//                        a roman numeral value
// Input                : Roman numeral value (integer)
// Output               : Returns allowed repetitions for the input according 
//                        Roman Numeral Rules (refer README)
//================================================================
int allowedRepeatsFor(int romanNumValue)
{
        switch(romanNumValue)
        {
                case I  :       return 3;
                case V  :       return 1;
                case X  :       return 3;
                case L  :       return 1;
                case C  :       return 3;
                case D  :       return 1;
                case M  :       return 4;
                default :       return INVALID_INPUT;
        }

}


//=================================================================
// allowedValuesBefore  : Function to get the allowed smaller roman numeral
//                        before the input roman numeral value
// Input                : Roman numeral value (integer)
// Output               : Returns allowed smaller roman numeral value before 
//                        the input roman numeral value according to 
//                        Roman Numeral Rules (refer README)
//================================================================

int allowedValueBefore(int romanNumValue)
{
        switch(romanNumValue)
        {
                case I  :       return INVALID_INPUT;
                case V  :       return I;
                case X  :       return I;
                case L  :       return X;
                case C  :       return X;
                case D  :       return C;
                case M  :       return C;
                default :       return INVALID_INPUT;
        }

}



//=================================================================
// isRomanNum           : Function to check if the input string is a valid 
//                        roman numeral according to Roman Numeral Rules (refer README)
// Input                : Roman numeral string
// Output               : Returns true if input is valid roman numeral else false
//================================================================
bool isRomanNum(const char * romanNumStr)
{

        bool isRoman            = true;
        bool isNotRoman         = false;
        int nextRomanValue      = 0;
        int currRomanValue      =0;
        int repeatCount         = 0;
        bool isSmallerThanNext = false;

        int i = 0;
        for (i = strlen(romanNumStr)-1; i >=0; --i)
        {
                currRomanValue = singleRomanToInt(romanNumStr[i]);

                if (currRomanValue == INVALID_INPUT) {return isNotRoman; }

                if (currRomanValue == nextRomanValue)
                {
                        if (isSmallerThanNext)  {return isNotRoman;}
                        ++repeatCount;
                        if (repeatCount > allowedRepeatsFor(currRomanValue))    {return isNotRoman;}

                }
                else    {repeatCount = 1;}

                if (currRomanValue < nextRomanValue)
                {
                        isSmallerThanNext = true;
                        if (currRomanValue != allowedValueBefore(nextRomanValue)) {return isNotRoman;}
                }
                else
                {
                        isSmallerThanNext = false;
                }

                nextRomanValue = currRomanValue;
        }
        return isRoman;
}


//=================================================================
// romanToInt           : Function to convert the input roman numeral string
//                        to integer value according to Roman Numeral Rules (refer README)
// Input                : Roman numeral string
// Output               : Returns integer conversion of the input roman numeral
//================================================================

int romanToInt( const char* romanNumStr)
{

        int romanIntValue = 0;
        int nextRomanValue = 0;
        int currRomanValue = 0;
        if (!isRomanNum(romanNumStr))   {return INVALID_INPUT;}

        int i = 0;
        for (i = strlen(romanNumStr)-1; i >=0; --i)
        {
                currRomanValue = singleRomanToInt(romanNumStr[i]);

                if (currRomanValue<nextRomanValue)
                {
                        romanIntValue -= currRomanValue;
                }
                else
                {
                        romanIntValue += currRomanValue;
                }

                nextRomanValue = currRomanValue;
        }
        return romanIntValue;
}

                     
