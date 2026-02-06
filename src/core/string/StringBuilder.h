#pragma once

#include <stddef.h>

#include "core/string/String.h"

typedef struct StringBuilder *StringBuilder;

StringBuilder StringBuilder_create();
void StringBuilder_destroy(StringBuilder sb);

size_t StringBuilder_getLength(StringBuilder sb);

void StringBuilder_appendStringLiteral(StringBuilder sb, const char *literal);
void StringBuilder_appendString(StringBuilder sb, String string);

String StringBuilder_toString(StringBuilder sb);
