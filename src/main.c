#include <stdio.h>
#include <stdbool.h>

#include "core/string/String.h"
#include "core/token/Token.h"

int main(void) {
    Token t = Token_create(TOKEN_TYPE_INTEGER, String_create("67"));

    Token_println(t);

    return 0;
}
