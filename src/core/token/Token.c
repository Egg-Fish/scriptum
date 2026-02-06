#include "core/token/Token.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "core/string/String.h"
#include "core/string/StringBuilder.h"

struct Token {
    TokenType type;
    String lexeme;
};

Token Token_create(TokenType type, String lexeme) {
    Token t;

    t = malloc(sizeof(struct Token));
    t->type = type;
    t->lexeme = String_copy(lexeme);

    return t;
}

void Token_destroy(Token t) {
    if (t == NULL) {
        return;
    }

    String_destroy(Token_getLexeme(t));
    free(t);

    return;
}

Token Token_copy(Token t) {
    if (t == NULL) {
        return NULL;
    }

    TokenType type = Token_getType(t);
    String lexeme = Token_getLexeme(t);
    Token u = Token_create(type, lexeme);

    return u;
}

// TODO add null checks

TokenType Token_getType(Token t) { return t->type; }

String Token_getLexeme(Token t) { return t->lexeme; }

String Token_toString(Token t) {
    TokenType type = Token_getType(t);
    String typeString = TokenType_toString(type);
    String lexeme = Token_getLexeme(t);

    StringBuilder sb = StringBuilder_create();

    StringBuilder_appendStringLiteral(sb, "(");
    StringBuilder_appendString(sb, typeString);
    StringBuilder_appendStringLiteral(sb, ", \"");
    StringBuilder_appendString(sb, lexeme);
    StringBuilder_appendStringLiteral(sb, "\")");

    String s = StringBuilder_toString(sb);

    StringBuilder_destroy(sb);
    String_destroy(typeString);

    return s;
}

void Token_print(Token t) {
    String s;

    s = Token_toString(t);
    String_print(s);
    String_destroy(s);

    return;
}

void Token_println(Token t) {
    String s;

    s = Token_toString(t);
    String_println(s);
    String_destroy(s);

    return;
}
