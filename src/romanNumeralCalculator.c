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
	//TODO: Complete this function
	return 0;

}



//=================================================================
// isRomanNum           : Function to check if the input string is a valid 
//                        roman numeral according to Roman Numeral Rules (refer README)
// Input                : Roman numeral string
// Output               : Returns true if input is valid roman numeral else false
//================================================================

bool isRomanNum(char * romanNumStr)
{

        bool isRoman            = true;
        bool isNotRoman         = false;
        int nextRomanValue      = 0;
        int repeatCount         = 0;
	
        int i = 0;
	//TODO: Create Function:
	//		int allowedrepeatsFor(int romanNumValue)
	//		int allowedValueBefore(int romanNumValue)
	
        for (i = strlen(romanNumStr)-1; i >=0; --i)
        {
                int currRomanValue = singleRomanToInt(romanNumStr[i]);

                if (currRomanValue == INVALID_INPUT) {return isNotRoman; }

                if (currRomanValue == nextRomanValue)
                {
                        ++repeatCount;
                        if (repeatCount > allowedRepeatsFor(currRomanValue))    {return isNotRoman;}
                }
                else    {repeatCount = 1;}

                if ((currRomanValue < nextRomanValue) \
                        && (currRomanValue != allowedValueBefore(nextRomanValue))) {return isNotRoman;}
                nextRomanValue = currRomanValue;
        }
        return isRoman;
}



