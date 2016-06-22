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
	srunner_set_log(sr, "log/test_allowedRepeatsFor.log");
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

