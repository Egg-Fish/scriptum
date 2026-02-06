#include "core/token/Token.h"

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test__Token_getLexeme__normal(void) {
    TokenType type = TOKEN_TYPE_INTEGER;
    String lexeme = String_create("67");
    Token t = Token_create(type, lexeme);

    String expected = String_create("67");
    String actual = Token_getLexeme(t);
    TEST_ASSERT_TRUE(String_equals(expected, actual));

    String_destroy(lexeme);
    Token_destroy(t);
    String_destroy(expected);
    String_destroy(actual);
}

void test__Token_toString__integerToken(void) {
    TokenType type = TOKEN_TYPE_INTEGER;
    String lexeme = String_create("67");
    Token t = Token_create(type, lexeme);

    String expected = String_create("(TokenType.Integer, \"67\")");
    String actual = Token_toString(t);

    // TODO make a better assertion macro for String types
    TEST_ASSERT_TRUE(String_equals(expected, actual));

    String_destroy(lexeme);
    Token_destroy(t);
    String_destroy(expected);
    String_destroy(actual);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__Token_getLexeme__normal);

    RUN_TEST(test__Token_toString__integerToken);

    return UNITY_END();
}
