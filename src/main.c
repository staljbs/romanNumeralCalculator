#include "romanNumeralCalculator.h"
#include <stdio.h>
#include <stdlib.h>
/* only main should be in this file, to make all other functions in
   the program testable by Check.  in order to test main(), use a
   whole program testing framework like Autotest.
*/

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("\nNOT ENOUGH ARGUMENTS \nExpected Arguments: romanNumeral1 operator romanNumeral2 \n\n");    
		return 1;
	}
	else
	{
		char* result = 0;
		if (strcmp(argv[2], "+") == 0 )
                {
                        result = romanAddition(argv[1], argv[3]);
                }
                else if (strcmp(argv[2], "-") == 0)
                {
                        result = romanSubtraction(argv[1], argv[3]);
                }
                else
                {
                        printf("\nUNSUPPORTED OPERATION \n\n");
			return 2;
                }

                if (result)
                {
                        printf("\nResult: %s\n\n", result);
                }
                

	}
	return 0;
}
