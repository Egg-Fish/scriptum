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
    String left = String_create("");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_equals(left, right));
    TEST_ASSERT_TRUE(String_equals(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_equals__leftIsEmptyString(void) {
    String left = String_create("");
    String right = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_equals(left, right));
    TEST_ASSERT_FALSE(String_equals(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_equals__rightIsEmptyString(void) {
    String left = String_create("Hello world!");
    String right = String_create("");

    TEST_ASSERT_FALSE(String_equals(left, right));
    TEST_ASSERT_FALSE(String_equals(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_equals__leftEqualsRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_equals(left, right));
    TEST_ASSERT_TRUE(String_equals(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_equals__unleftEqualsRight(void) {
    String left = String_create("Hello");
    String right = String_create("world!");

    TEST_ASSERT_FALSE(String_equals(left, right));
    TEST_ASSERT_FALSE(String_equals(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_equals__leadingWhitespace(void) {
    String left = String_create("Hello world!");
    String right = String_create(" Hello world!");

    TEST_ASSERT_FALSE(String_equals(left, right));
    TEST_ASSERT_FALSE(String_equals(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_startsWith__emptyStrings(void) {
    String left = String_create("");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_startsWith(left, right));
    TEST_ASSERT_TRUE(String_startsWith(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_startsWith__leftIsEmptyString(void) {
    String left = String_create("");
    String right = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_startsWith(left, right));
    TEST_ASSERT_TRUE(String_startsWith(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_startsWith__rightIsEmptyString(void) {
    String left = String_create("Hello world!");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_startsWith(left, right));
    TEST_ASSERT_FALSE(String_startsWith(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_startsWith__leftEqualsRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_startsWith(left, right));
    TEST_ASSERT_TRUE(String_startsWith(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_startsWith__leftStartsWithRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("Hello");

    TEST_ASSERT_TRUE(String_startsWith(left, right));
    TEST_ASSERT_FALSE(String_startsWith(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_endsWith__emptyStrings(void) {
    String left = String_create("");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_endsWith(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_endsWith__leftIsEmptyString(void) {
    String left = String_create("");
    String right = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_endsWith(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_endsWith__rightIsEmptyString(void) {
    String left = String_create("Hello world!");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_endsWith(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_endsWith__leftEqualsRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_endsWith(left, right));
    TEST_ASSERT_TRUE(String_endsWith(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_endsWith__leftEndsWithRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("world!");

    TEST_ASSERT_TRUE(String_endsWith(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_contains__emptyStrings(void) {
    String left = String_create("");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_contains(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_contains__leftIsEmptyString(void) {
    String left = String_create("");
    String right = String_create("Hello world!");

    TEST_ASSERT_FALSE(String_contains(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_contains__rightIsEmptyString(void) {
    String left = String_create("Hello world!");
    String right = String_create("");

    TEST_ASSERT_TRUE(String_contains(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_contains__leftEqualsRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("Hello world!");

    TEST_ASSERT_TRUE(String_contains(left, right));
    TEST_ASSERT_TRUE(String_contains(right, left));

    String_destroy(left);
    String_destroy(right);
}

void test__String_contains__leftContainsRight(void) {
    String left = String_create("Hello world!");
    String right = String_create("world");

    TEST_ASSERT_TRUE(String_contains(left, right));

    String_destroy(left);
    String_destroy(right);
}

void test__String_concatenate__emptyStrings(void) {
    String left = String_create("");
    String right = String_create("");

    String actual = String_concatenate(left, right);

    TEST_ASSERT_TRUE(String_equals(left, actual));
    TEST_ASSERT_TRUE(String_equals(right, actual));

    String_destroy(left);
    String_destroy(right);
    String_destroy(actual);
}

void test__String_concatenate__leftIsEmptyString(void) {
    String left = String_create("");
    String right = String_create("Hello world!");

    String expected = right;
    String actual = String_concatenate(left, right);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    String_destroy(left);
    String_destroy(right);
    String_destroy(actual);
}

void test__String_concatenate__rightIsEmptyString(void) {
    String left = String_create("Hello world!");
    String right = String_create("");

    String expected = left;
    String actual = String_concatenate(left, right);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    String_destroy(left);
    String_destroy(right);
    String_destroy(actual);
}

void test__String_concatenate__nonemptyStrings(void) {
    String left = String_create("Hello ");
    String right = String_create("world!");

    String expected = String_create("Hello world!");
    String actual = String_concatenate(left, right);

    TEST_ASSERT_TRUE(String_equals(expected, actual));

    String_destroy(left);
    String_destroy(right);
    String_destroy(expected);
    String_destroy(actual);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__String_getString__emptyString);
    RUN_TEST(test__String_getString__nonemptyString);

    RUN_TEST(test__String_equals__emptyStrings);
    RUN_TEST(test__String_equals__leftIsEmptyString);
    RUN_TEST(test__String_equals__rightIsEmptyString);
    RUN_TEST(test__String_equals__leftEqualsRight);
    RUN_TEST(test__String_equals__unleftEqualsRight);
    RUN_TEST(test__String_equals__leadingWhitespace);

    RUN_TEST(test__String_startsWith__emptyStrings);
    RUN_TEST(test__String_startsWith__leftIsEmptyString);
    RUN_TEST(test__String_startsWith__rightIsEmptyString);
    RUN_TEST(test__String_startsWith__leftEqualsRight);
    RUN_TEST(test__String_startsWith__leftStartsWithRight);

    RUN_TEST(test__String_endsWith__emptyStrings);
    RUN_TEST(test__String_endsWith__leftIsEmptyString);
    RUN_TEST(test__String_endsWith__rightIsEmptyString);
    RUN_TEST(test__String_endsWith__leftEqualsRight);
    RUN_TEST(test__String_endsWith__leftEndsWithRight);

    RUN_TEST(test__String_contains__emptyStrings);
    RUN_TEST(test__String_contains__leftIsEmptyString);
    RUN_TEST(test__String_contains__rightIsEmptyString);
    RUN_TEST(test__String_contains__leftEqualsRight);
    RUN_TEST(test__String_contains__leftContainsRight);

    RUN_TEST(test__String_concatenate__emptyStrings);
    RUN_TEST(test__String_concatenate__leftIsEmptyString);
    RUN_TEST(test__String_concatenate__rightIsEmptyString);
    RUN_TEST(test__String_concatenate__nonemptyStrings);

    return UNITY_END();
}
