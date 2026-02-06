#include "core/token/TokenType.h"

#include <stdio.h>

#include "core/string/String.h"

String TokenType_toString(TokenType t) {
    switch (t) {
    case TOKEN_TYPE_INTEGER:
        return String_create("TokenType.Integer");
    default:
        return String_create("TokenType.<INVALID>");
    }
}

void TokenType_print(TokenType t) {
    String s;

    s = TokenType_toString(t);
    String_print(s);
    String_destroy(s);

    return;
}

void TokenType_println(TokenType t) {
    String s;

    s = TokenType_toString(t);
    String_println(s);
    String_destroy(s);

    return;
}
