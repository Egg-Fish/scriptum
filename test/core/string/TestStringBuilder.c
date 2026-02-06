#include "core/string/StringBuilder.h"

#include "core/string/String.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test__StringBuilder_appendStringLiteral__oneLiteral(void) {
    StringBuilder sb = StringBuilder_create();

    StringBuilder_appendStringLiteral(sb, "67");

    String expected = String_create("67");
    String actual = StringBuilder_toString(sb);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    StringBuilder_destroy(sb);
    String_destroy(expected);
    String_destroy(actual);
}

void test__StringBuilder_appendStringLiteral__twoLiterals(void) {
    StringBuilder sb = StringBuilder_create();

    StringBuilder_appendStringLiteral(sb, "Hello ");
    StringBuilder_appendStringLiteral(sb, "world!");

    String expected = String_create("Hello world!");
    String actual = StringBuilder_toString(sb);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    StringBuilder_destroy(sb);
    String_destroy(expected);
    String_destroy(actual);
}

void test__StringBuilder_appendString__emptyString(void) {
    StringBuilder sb = StringBuilder_create();

    String s = String_create("");
    StringBuilder_appendString(sb, s);

    String expected = String_create("");
    String actual = StringBuilder_toString(sb);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    StringBuilder_destroy(sb);
    String_destroy(s);
    String_destroy(expected);
    String_destroy(actual);
}

void test__StringBuilder_appendString__oneString(void) {
    StringBuilder sb = StringBuilder_create();

    String s = String_create("67");
    StringBuilder_appendString(sb, s);

    String expected = String_create("67");
    String actual = StringBuilder_toString(sb);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    StringBuilder_destroy(sb);
    String_destroy(s);
    String_destroy(expected);
    String_destroy(actual);
}

void test__StringBuilder_appendString__twoStrings(void) {
    StringBuilder sb = StringBuilder_create();

    String s1 = String_create("Hello ");
    String s2 = String_create("world!");

    StringBuilder_appendString(sb, s1);
    StringBuilder_appendString(sb, s2);

    String expected = String_create("Hello world!");
    String actual = StringBuilder_toString(sb);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    StringBuilder_destroy(sb);
    String_destroy(s1);
    String_destroy(s2);
    String_destroy(expected);
    String_destroy(actual);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__StringBuilder_appendStringLiteral__oneLiteral);
    RUN_TEST(test__StringBuilder_appendStringLiteral__twoLiterals);

    RUN_TEST(test__StringBuilder_appendString__oneString);
    RUN_TEST(test__StringBuilder_appendString__twoStrings);

    return UNITY_END();
}
