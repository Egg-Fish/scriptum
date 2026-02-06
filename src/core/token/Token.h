#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "core/string/String.h"
#include "core/token/TokenType.h"

typedef struct Token *Token;

Token Token_create(TokenType type, String lexeme);
void Token_destroy(Token t);
Token Token_copy(Token t);

TokenType Token_getType(Token t);
String Token_getLexeme(Token t);

String Token_toString(Token t);
void Token_print(Token t);
void Token_println(Token t);
