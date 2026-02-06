#include "core/string/String.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test__String_getString__emptyString(void) {
    String s = String_create("");

    const char *string = String_getString(s);
    TEST_ASSERT_EQUAL_STRING("", string);

    String_destroy(s);
}

void test__String_getString__nonemptyString(void) {
    String s = String_create("Hello world!");

    const char *string = String_getString(s);
    TEST_ASSERT_EQUAL_STRING("Hello world!", string);

    String_destroy(s);
}

void test__String_equals__emptyStrings(void) {
    String s1 = String_create("");
    String s2 = String_create("");

    TEST_ASSERT_TRUE(String_equals(s1, s2));
    TEST_ASSERT_TRUE(String_equals(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__leftEmptyString(void) {
    String s1 = String_create("");
    String s2 = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_equals(s1, s2));
    TEST_ASSERT_FALSE(String_equals(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__rightEmptyString(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("");

    TEST_ASSERT_FALSE(String_equals(s1, s2));
    TEST_ASSERT_FALSE(String_equals(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__equalStrings(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_equals(s1, s2));
    TEST_ASSERT_TRUE(String_equals(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__unequalStrings(void) {
    String s1 = String_create("Hello");
    String s2 = String_create("world!");

    TEST_ASSERT_FALSE(String_equals(s1, s2));
    TEST_ASSERT_FALSE(String_equals(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_equals__leadingWhitespace(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create(" Hello world!");

    TEST_ASSERT_FALSE(String_equals(s1, s2));
    TEST_ASSERT_FALSE(String_equals(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_startsWith__emptyStrings(void) {
    String s1 = String_create("");
    String s2 = String_create("");

    TEST_ASSERT_TRUE(String_startsWith(s1, s2));
    TEST_ASSERT_TRUE(String_startsWith(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_startsWith__leftEmptyString(void) {
    String s1 = String_create("");
    String s2 = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_startsWith(s1, s2));
    TEST_ASSERT_TRUE(String_startsWith(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_startsWith__rightEmptyString(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("");

    TEST_ASSERT_TRUE(String_startsWith(s1, s2));
    TEST_ASSERT_FALSE(String_startsWith(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_startsWith__equalStrings(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_startsWith(s1, s2));
    TEST_ASSERT_TRUE(String_startsWith(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_startsWith__rightPrefix(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("Hello");

    TEST_ASSERT_TRUE(String_startsWith(s1, s2));
    TEST_ASSERT_FALSE(String_startsWith(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_endsWith__emptyStrings(void) {
    String s1 = String_create("");
    String s2 = String_create("");

    TEST_ASSERT_TRUE(String_endsWith(s1, s2));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_endsWith__leftEmptyString(void) {
    String s1 = String_create("");
    String s2 = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_endsWith(s1, s2));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_endsWith__rightEmptyString(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("");

    TEST_ASSERT_TRUE(String_endsWith(s1, s2));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_endsWith__equalStrings(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_endsWith(s1, s2));
    TEST_ASSERT_TRUE(String_endsWith(s2, s1));

    String_destroy(s1);
    String_destroy(s2);
}

void test__String_concatenate__emptyStrings(void) {
    String s1 = String_create("");
    String s2 = String_create("");

    String s3 = String_concatenate(s1, s2);
    TEST_ASSERT_TRUE(String_equals(s3, s1));

    String_destroy(s1);
    String_destroy(s2);
    String_destroy(s3);
}

void test__String_concatenate__leftEmptyString(void) {
    String s1 = String_create("");
    String s2 = String_create("Hello world!");

    String s3 = String_concatenate(s1, s2);
    TEST_ASSERT_TRUE(String_equals(s3, s2));

    String_destroy(s1);
    String_destroy(s2);
    String_destroy(s3);
}

void test__String_concatenate__rightEmptyString(void) {
    String s1 = String_create("Hello world!");
    String s2 = String_create("");

    String s3 = String_concatenate(s1, s2);
    TEST_ASSERT_TRUE(String_equals(s3, s1));

    String_destroy(s1);
    String_destroy(s2);
    String_destroy(s3);
}

void test__String_concatenate__nonemptyStrings(void) {
    String s1 = String_create("Hello ");
    String s2 = String_create("world!");

    String s3 = String_concatenate(s1, s2);
    String expected = String_create("Hello world!");
    TEST_ASSERT_TRUE(String_equals(s3, expected));

    String_destroy(s1);
    String_destroy(s2);
    String_destroy(s3);
    String_destroy(expected);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__String_getString__emptyString);
    RUN_TEST(test__String_getString__nonemptyString);

    RUN_TEST(test__String_equals__emptyStrings);
    RUN_TEST(test__String_equals__leftEmptyString);
    RUN_TEST(test__String_equals__rightEmptyString);
    RUN_TEST(test__String_equals__equalStrings);
    RUN_TEST(test__String_equals__unequalStrings);
    RUN_TEST(test__String_equals__leadingWhitespace);

    RUN_TEST(test__String_startsWith__emptyStrings);
    RUN_TEST(test__String_startsWith__leftEmptyString);
    RUN_TEST(test__String_startsWith__rightEmptyString);
    RUN_TEST(test__String_startsWith__equalStrings);
    RUN_TEST(test__String_startsWith__rightPrefix);

    RUN_TEST(test__String_endsWith__emptyStrings);
    RUN_TEST(test__String_endsWith__leftEmptyString);
    RUN_TEST(test__String_endsWith__rightEmptyString);
    RUN_TEST(test__String_endsWith__equalStrings);

    RUN_TEST(test__String_concatenate__emptyStrings);
    RUN_TEST(test__String_concatenate__leftEmptyString);
    RUN_TEST(test__String_concatenate__rightEmptyString);
    RUN_TEST(test__String_concatenate__nonemptyStrings);

    return UNITY_END();
}
