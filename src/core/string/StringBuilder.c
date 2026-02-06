#include "core/string/StringBuilder.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/string/String.h"

#define STRING_BUILDER_DEFAULT_CAPACITY 32

struct StringBuilder {
    size_t capacity;
    char *string;
};

StringBuilder StringBuilder_create() {
    StringBuilder sb;
    size_t capacity = STRING_BUILDER_DEFAULT_CAPACITY;

    sb = malloc(sizeof(struct StringBuilder));
    sb->capacity = capacity;
    sb->string = calloc(capacity, sizeof(char));

    return sb;
}

void StringBuilder_destroy(StringBuilder sb) {
    if (sb == NULL) {
        return;
    }

    free(sb->string);
    free(sb);

    return;
}

size_t StringBuilder_getLength(StringBuilder sb) { return strlen(sb->string); }

void StringBuilder_realloc(StringBuilder sb, size_t newCapacity) {
    if (newCapacity <= sb->capacity) {
        return;
    }

    sb->capacity = newCapacity;
    sb->string = realloc(sb->string, newCapacity);

    return;
}

void StringBuilder_appendStringLiteral(StringBuilder sb, const char *literal) {
    size_t stringLength = strlen(literal);
    size_t oldLength = StringBuilder_getLength(sb);
    size_t newLength = oldLength + stringLength;

    StringBuilder_realloc(sb, newLength + 1);

    strncpy(sb->string + oldLength, literal, stringLength);
    sb->string[newLength] = '\0';

    return;
}

void StringBuilder_appendString(StringBuilder sb, String string) {
    size_t stringLength = String_getLength(string);
    size_t oldLength = StringBuilder_getLength(sb);
    size_t newLength = oldLength + stringLength;

    StringBuilder_realloc(sb, newLength + 1);

    strncpy(sb->string + oldLength, String_getString(string), stringLength);
    sb->string[newLength] = '\0';

    return;
}

String StringBuilder_toString(StringBuilder sb) { return String_create(sb->string); }
