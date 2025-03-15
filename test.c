#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/TestDB.h>

#include <string.h>
#include "fizzbuzz.c"
#include "fizzbuzz.h"
#include "main.c"

void fizzbuzz_test_1(void);
void fizzbuzz_test_3(void);
void fizzbuzz_test_5(void);
void fizzbuzz_test_15(void);
void fizzbuzz_test_30(void);
void get_str_test(void);

#undef main

int main(void) {
    int ret;
    CU_pSuite suite;
    CU_initialize_registry();

    suite = CU_add_suite("FizzBuzz Test", NULL, NULL);
    CU_add_test(suite, "FizzBuzz_Test_1", fizzbuzz_test_1);
    //CU_add_test(suite, "FizzBuzz_Test_3", fizzbuzz_test_3);
    //CU_add_test(suite, "FizzBuzz_Test_5", fizzbuzz_test_5);
    //CU_add_test(suite, "FizzBuzz_Test_15", fizzbuzz_test_15);
    //CU_add_test(suite, "FizzBuzz_Test_30", fizzbuzz_test_30);

    // テストを追加
    //suite = CU_add_suite("FizzBuzz String Test", NULL, NULL);
    CU_add_test(suite, "get_str_test", get_str_test);

    // CU_console_run_tests();
    CU_basic_run_tests();

    ret = CU_get_number_of_failures();
    CU_cleanup_registry();
    return ret;
}

void fizzbuzz_test_1(void) {
    char result[256];
    memset(result, '\0', sizeof(result));

    fizzbuzz(1, result);

    CU_ASSERT_STRING_EQUAL("1", result);
    return;
}

void fizzbuzz_test_3(void) {
    char result[256];
    memset(result, '\0', sizeof(result));

    fizzbuzz(3, result);

    CU_ASSERT_STRING_EQUAL("Fizz", result);
    return;
}

void fizzbuzz_test_5(void) {
    char result[256];
    memset(result, '\0', sizeof(result));

    fizzbuzz(5, result);

    CU_ASSERT_STRING_EQUAL("Buzz", result);
    return;
}

void fizzbuzz_test_15(void) {
    char result[256];
    memset(result, '\0', sizeof(result));

    fizzbuzz(15, result);

    CU_ASSERT_STRING_EQUAL("FizzBuzz", result);
    return;
}

void fizzbuzz_test_30(void) {
    char result[256];
    memset(result, '\0', sizeof(result));

    CU_ASSERT_NOT_EQUAL_FATAL(fizzbuzz(30, result), 0);
    return;
}

void get_str_test(void) {
    CU_ASSERT_STRING_EQUAL("Fizz", get_str_Fizz());
    CU_ASSERT_STRING_EQUAL("Buzz", get_str_Buzz());
    CU_ASSERT_STRING_EQUAL("FizzBuzz", get_str_FizzBuzz());
    return;
}
