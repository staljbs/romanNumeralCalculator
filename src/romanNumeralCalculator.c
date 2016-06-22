#include "romanNumeralCalculator.h"

const int INVALID_INPUT = 0;
const char ADDITION_OPERATOR = '+';
const char SUBTRACTION_OPERATOR = '-';

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

//=================================================================
// integerOperation     : Function to perform various operations -currently supports ADDITION & SUBTRACTION-
//                        on input roman numerals
// Input1               : Roman numeral string
// Input2               : Roman numeral string
// Input3               : operator character
// Output               : Returns result of integer operation on the two input roman numerals
//================================================================


int integerOperation(const char* romanNum1, const char* romanNum2, const char operator)
{
        int num1 = romanToInt(romanNum1);
        int num2 = romanToInt(romanNum2);
        if ((num1 == INVALID_INPUT) \
	|| (num2 == INVALID_INPUT) \
	|| ((operator == SUBTRACTION_OPERATOR) \
		&& (num2>num1)))
        {
                return INVALID_INPUT;
        }
	
	if (operator == SUBTRACTION_OPERATOR)
	{
		return num1 - num2;
	}
	else if (operator == ADDITION_OPERATOR)
	{
		return num1 + num2;
        }
	
	return INVALID_INPUT;

}



//=================================================================
// romanAddition        : Function to perform addition on the input roman numeral strings
// Input1               : Roman numeral string
// Input2               : Roman numeral string
// Output               : Returns roman numeral string which is the result of addition of the inputs
//================================================================

char* romanAddition(const char* romanNum1, const char* romanNum2)
{
        int sum = integerOperation(romanNum1, romanNum2, ADDITION_OPERATOR);
        if (sum == INVALID_INPUT) {return "INVALID NUMERAL OR OPERATION";}

        return intToRoman(sum);
}


//=================================================================
// romanSubtraction     : Function to perform subtraction on the input roman numeral strings
// Input1               : Roman numeral string
// Input2               : Roman numeral string
// Output               : Returns roman numeral string which is the result of subtraction of the inputs
//================================================================

char* romanSubtraction(const char* romanNum1, const char* romanNum2)
{
        int difference = integerOperation(romanNum1, romanNum2, SUBTRACTION_OPERATOR);
        if (difference == INVALID_INPUT) {return "INVALID NUMERAL OR OPERATION";}

        return intToRoman(difference);
}



//=================================================================
// intToRoman	     	: Function to convert integer to roman numeral string
// Input                : Integer value
// Output               : Returns roman numeral string corresponding to the input 
//			  according Roman Numeral Rules(refer README)
//================================================================

char* intToRoman(int romanIntValue)
{
	//Roman numerals equal to or above 5000 cannot be converted. Heavy bar representation needed.
	//TODO: Implement heavy bar representation for roman numerals to have integers upto 5,000,000
        if (romanIntValue >= 5000)
        {
                return "RESULT ABOVE 5000";
        }

        char romanNumStr[100];
        memset(romanNumStr, 0, 100);

        int intValues[] 		= {1000, 900,  500, 400,  100, 90,   50,  40,   10,   9,    5,   4,    1};
        const char* romanValues[] 	= {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int count = sizeof(intValues)/sizeof(intValues[0]);

        int i = 0;
        for (i = 0; i < count; ++i)
        {
                for (;romanIntValue >= intValues[i]; romanIntValue -= intValues[i])
                {
                        strcat(romanNumStr, romanValues[i]);
                }
        }

        return strdup(romanNumStr);
}
                
