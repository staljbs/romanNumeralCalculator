#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeralCalculator.h"


START_TEST(test_basic)
{
	ck_assert_str_eq("X","X");
	ck_assert_int_eq( 0 , 0 ); 
	//ck_assert_int_eq( 0 , 1 ); //to check assertion failure log

}
END_TEST
START_TEST(test_romanNumConstants)
{
        ck_assert_int_eq(   I , 1);
        ck_assert_int_eq(   V , 5);
        ck_assert_int_eq(   X , 10);
        ck_assert_int_eq(   L , 50);
        ck_assert_int_eq(   C , 100);
        ck_assert_int_eq(   D , 500);
        ck_assert_int_eq(   M , 1000);
        ck_assert_int_eq(   INVALID_INPUT , 0);

}
END_TEST

START_TEST(test_singleRomanToInt)
{
        ck_assert_int_eq(   singleRomanToInt('I'), I);
        ck_assert_int_eq(   singleRomanToInt('V'), V);
        ck_assert_int_eq(   singleRomanToInt('X'), X);
        ck_assert_int_eq(   singleRomanToInt('L'), L);
        ck_assert_int_eq(   singleRomanToInt('C'), C);
        ck_assert_int_eq(   singleRomanToInt('D'), D);
        ck_assert_int_eq(   singleRomanToInt('M'), M);
        ck_assert_int_eq(   singleRomanToInt('A'), INVALID_INPUT);

}
END_TEST

START_TEST(test_allowedRepeatsFor)
{
        ck_assert_int_eq(   allowedRepeatsFor(I), 3);
        ck_assert_int_eq(   allowedRepeatsFor(V), 1);
        ck_assert_int_eq(   allowedRepeatsFor(X), 3);
        ck_assert_int_eq(   allowedRepeatsFor(L), 1);
        ck_assert_int_eq(   allowedRepeatsFor(C), 3);
        ck_assert_int_eq(   allowedRepeatsFor(D), 1);
        ck_assert_int_eq(   allowedRepeatsFor(M), 4);
        ck_assert_int_eq(   allowedRepeatsFor(123), INVALID_INPUT);
}
END_TEST

START_TEST(test_allowedValueBefore)
{
        ck_assert_int_eq(   allowedValueBefore(I), INVALID_INPUT);
        ck_assert_int_eq(   allowedValueBefore(V), I);
        ck_assert_int_eq(   allowedValueBefore(X), I);
        ck_assert_int_eq(   allowedValueBefore(L), X);
        ck_assert_int_eq(   allowedValueBefore(C), X);
        ck_assert_int_eq(   allowedValueBefore(D), C);
        ck_assert_int_eq(   allowedValueBefore(M), C);
        ck_assert_int_eq(   allowedValueBefore(123), INVALID_INPUT);
}
END_TEST


START_TEST(test_isRomanNum)
{
//Valid Romans:
        ck_assert( isRomanNum("I"));
        ck_assert( isRomanNum("II"));
        ck_assert( isRomanNum("III"));
        ck_assert( isRomanNum("IV"));
        ck_assert( isRomanNum("V"));
        ck_assert( isRomanNum("VI"));
        ck_assert( isRomanNum("VII"));
        ck_assert( isRomanNum("VIII"));
        ck_assert( isRomanNum("IX"));
        ck_assert( isRomanNum("X"));
        ck_assert( isRomanNum("XI"));
        ck_assert( isRomanNum("XIII"));
        ck_assert( isRomanNum("XL"));
        ck_assert( isRomanNum("L"));
        ck_assert( isRomanNum("LX"));
        ck_assert( isRomanNum("LXXX"));
        ck_assert( isRomanNum("XC"));
        ck_assert( isRomanNum("C"));
        ck_assert( isRomanNum("CX"));
        ck_assert( isRomanNum("CXXX"));
        ck_assert( isRomanNum("CD"));
        ck_assert( isRomanNum("D"));
        ck_assert( isRomanNum("DC"));
        ck_assert( isRomanNum("DCCC"));
        ck_assert( isRomanNum("CM"));
        ck_assert( isRomanNum("M"));
        ck_assert( isRomanNum("MC"));
        ck_assert( isRomanNum("MCCC"));
        ck_assert( isRomanNum("MMMMD"));

//Invalid Romans:

        ck_assert( !isRomanNum("IIII"));
        ck_assert( !isRomanNum("XXXX"));
        ck_assert( !isRomanNum("CCCC"));
        ck_assert( !isRomanNum("VV"));
        ck_assert( !isRomanNum("LL"));
        ck_assert( !isRomanNum("DD"));
        ck_assert( !isRomanNum("IIV"));
        ck_assert( !isRomanNum("VIIII"));
        ck_assert( !isRomanNum("VX"));
        ck_assert( !isRomanNum("IIX"));
        ck_assert( !isRomanNum("XIIII"));
        ck_assert( !isRomanNum("XXL"));
        ck_assert( !isRomanNum("VL"));
        ck_assert( !isRomanNum("IL"));
        ck_assert( !isRomanNum("LXXXX"));
        ck_assert( !isRomanNum("XXC"));
        ck_assert( !isRomanNum("IC"));
        ck_assert( !isRomanNum("VC"));
        ck_assert( !isRomanNum("LC"));
        ck_assert( !isRomanNum("CXXXX"));
        ck_assert( !isRomanNum("CCD"));
        ck_assert( !isRomanNum("ID"));
        ck_assert( !isRomanNum("VD"));
        ck_assert( !isRomanNum("XD"));
        ck_assert( !isRomanNum("LD"));
        ck_assert( !isRomanNum("DCCCC"));
        ck_assert( !isRomanNum("CCM"));
        ck_assert( !isRomanNum("IM"));
        ck_assert( !isRomanNum("VM"));
        ck_assert( !isRomanNum("XM"));
        ck_assert( !isRomanNum("LM"));
        ck_assert( !isRomanNum("DM"));
        ck_assert( !isRomanNum("MCCCC"));
        ck_assert( !isRomanNum("MMMMM"));
        ck_assert( !isRomanNum(" "));
        ck_assert( !isRomanNum("_"));
        ck_assert( !isRomanNum("ABCD"));

}
END_TEST

START_TEST(test_romanToInt)
{
//Valid Romans:
        ck_assert_int_eq( romanToInt("I"), 1);
        ck_assert_int_eq( romanToInt("II"), 2);
        ck_assert_int_eq( romanToInt("III"), 3);
        ck_assert_int_eq( romanToInt("IV"), 4);
        ck_assert_int_eq( romanToInt("V"), 5);
        ck_assert_int_eq( romanToInt("VI"), 6);
        ck_assert_int_eq( romanToInt("VII"), 7);
        ck_assert_int_eq( romanToInt("VIII"), 8);
        ck_assert_int_eq( romanToInt("IX"), 9);
        ck_assert_int_eq( romanToInt("X"), 10);
        ck_assert_int_eq( romanToInt("XI"), 11);
        ck_assert_int_eq( romanToInt("XIII"), 13);
        ck_assert_int_eq( romanToInt("XL"), 40);
        ck_assert_int_eq( romanToInt("L"), 50);
        ck_assert_int_eq( romanToInt("LX"), 60);
        ck_assert_int_eq( romanToInt("LXXX"), 80);
        ck_assert_int_eq( romanToInt("XC"), 90);
        ck_assert_int_eq( romanToInt("C"), 100);
        ck_assert_int_eq( romanToInt("CX"), 110);
        ck_assert_int_eq( romanToInt("CXXX"), 130);
        ck_assert_int_eq( romanToInt("CD"), 400);
        ck_assert_int_eq( romanToInt("D"), 500);
        ck_assert_int_eq( romanToInt("DC"), 600);
        ck_assert_int_eq( romanToInt("DCCC"), 800);
        ck_assert_int_eq( romanToInt("CM"), 900);
        ck_assert_int_eq( romanToInt("M"), 1000);
        ck_assert_int_eq( romanToInt("MC"), 1100);
        ck_assert_int_eq( romanToInt("MCCC"), 1300);
        ck_assert_int_eq( romanToInt("MMMMD"), 4500);

//Invalid Romans:
        ck_assert_int_eq( romanToInt("IIII"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("XXXX"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("CCCC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VV"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("LL"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("DD"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("IIV"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VIIII"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VX"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("IIX"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("XIIII"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("XXL"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VL"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("IL"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("LXXXX"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("XXC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("IC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("LC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("CXXXX"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("CCD"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("ID"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VD"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("XD"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("LD"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("DCCCC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("CCM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("IM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("VM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("XM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("LM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("DM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("MCCCC"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("MMMMM"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt(" "), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("_"), INVALID_INPUT);
        ck_assert_int_eq( romanToInt("ABCD"), INVALID_INPUT);

}
END_TEST


START_TEST(test_intToRoman)
{
        ck_assert_str_eq( intToRoman(1), "I");
        ck_assert_str_eq( intToRoman(2), "II");
        ck_assert_str_eq( intToRoman(3), "III");
        ck_assert_str_eq( intToRoman(4), "IV");
        ck_assert_str_eq( intToRoman(5), "V");
        ck_assert_str_eq( intToRoman(6), "VI");
        ck_assert_str_eq( intToRoman(7), "VII");
        ck_assert_str_eq( intToRoman(8), "VIII");
        ck_assert_str_eq( intToRoman(9), "IX");
        ck_assert_str_eq( intToRoman(10), "X");
        ck_assert_str_eq( intToRoman(11), "XI");
        ck_assert_str_eq( intToRoman(13), "XIII");
        ck_assert_str_eq( intToRoman(21), "XXI");
        ck_assert_str_eq( intToRoman(31), "XXXI");
        ck_assert_str_eq( intToRoman(41), "XLI");
        ck_assert_str_eq( intToRoman(49), "XLIX");
        ck_assert_str_eq( intToRoman(50), "L");
        ck_assert_str_eq( intToRoman(90), "XC");
        ck_assert_str_eq( intToRoman(99), "XCIX");
        ck_assert_str_eq( intToRoman(100), "C");
        ck_assert_str_eq( intToRoman(110), "CX");
        ck_assert_str_eq( intToRoman(400), "CD");
        ck_assert_str_eq( intToRoman(500), "D");
        ck_assert_str_eq( intToRoman(600), "DC");
        ck_assert_str_eq( intToRoman(900), "CM");
        ck_assert_str_eq( intToRoman(1000), "M");
        ck_assert_str_eq( intToRoman(1100), "MC");
        ck_assert_str_eq( intToRoman(3999), "MMMCMXCIX");
        ck_assert_str_eq( intToRoman(5000), "RESULT ABOVE 5000");

}
END_TEST


START_TEST(test_integerOperation)
{
        ck_assert_int_eq( integerOperation("I", "I", ADDITION_OPERATOR), 2);
	ck_assert_int_eq( integerOperation("I", "I", SUBTRACTION_OPERATOR), 0);
        ck_assert_int_eq( integerOperation("XI", "X", SUBTRACTION_OPERATOR), 1);
        ck_assert_int_eq( integerOperation("X", "XI", SUBTRACTION_OPERATOR), 0);
        ck_assert_int_eq( integerOperation("XX", "I", ADDITION_OPERATOR), 21);
	ck_assert_int_eq( integerOperation("MMMMCMXCIX", "I", ADDITION_OPERATOR), 5000);

}
END_TEST


START_TEST(test_romanAddition)
{

        ck_assert_str_eq( romanAddition("I", "I"), "II");
        ck_assert_str_eq( romanAddition("XV", "M"), "MXV");
        ck_assert_str_eq( romanAddition("MMMMCMXCIX", "I"), "RESULT ABOVE 5000");

}
END_TEST

START_TEST(test_romanSubtraction)
{
        ck_assert_str_eq( romanSubtraction("I", "I"), "INVALID NUMERAL OR OPERATION");
        ck_assert_str_eq( romanSubtraction("XI", "X"), "I");
        ck_assert_str_eq( romanSubtraction("X", "XI"), "INVALID NUMERAL OR OPERATION");
        ck_assert_str_eq( romanSubtraction("MXC", "M"), "XC");
        
}
END_TEST




Suite * romanNumCalculator_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("RomanNumeralCalculator");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_basic);
    tcase_add_test(tc_core, test_romanNumConstants);
    tcase_add_test(tc_core, test_singleRomanToInt);
    tcase_add_test(tc_core, test_allowedRepeatsFor);
    tcase_add_test(tc_core, test_allowedValueBefore);
    tcase_add_test(tc_core, test_isRomanNum);
    tcase_add_test(tc_core, test_romanToInt);
    tcase_add_test(tc_core, test_intToRoman);
    tcase_add_test(tc_core, test_integerOperation);
    tcase_add_test(tc_core, test_romanAddition);
    tcase_add_test(tc_core, test_romanSubtraction);
    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = romanNumCalculator_suite();
	sr = srunner_create(s);
	srunner_set_log(sr, "log/test_overall.log");
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

