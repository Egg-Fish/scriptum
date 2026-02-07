#include <stdbool.h>
#include <stdio.h>

#include "core/list/List.h"
#include "core/string/String.h"
#include "core/token/Token.h"

int main(void) {
    String string = String_create("   Hello \n world! ");
    List lexemes = String_splitByWhitespace(string);

    for (size_t i = 0; i < List_getLength(lexemes); i++) {
        printf("lexeme %zu = ", i + 1);
        String lexeme = (String)List_getItemAtIndex(lexemes, i);
        String_println(lexeme);
    }
    
    return 0;
}
