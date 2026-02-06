#pragma once

#include "core/string/String.h"

typedef enum {
    TOKEN_TYPE_INVALID,
    TOKEN_TYPE_INTEGER,
} TokenType;

String TokenType_toString(TokenType t);
void TokenType_print(TokenType t);
void TokenType_println(TokenType t);
