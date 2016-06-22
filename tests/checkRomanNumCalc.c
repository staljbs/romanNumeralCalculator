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
	srunner_set_log(sr, "log/test_isRomanNum.log");
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

