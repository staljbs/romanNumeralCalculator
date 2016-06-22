#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeralCalculator.h"


START_TEST(test_basic)
{
	ck_assert_str_eq("X","X");
	ck_assert_int_eq( 0 , 0 ); 
	ck_assert_int_eq( 0 , 1 ); //to check assertion failure log

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

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

