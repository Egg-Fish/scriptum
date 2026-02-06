#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct String *String;

String String_create(const char *string);
void String_destroy(String s);
String String_copy(String s);

const char *String_getString(String s);
size_t String_getLength(String s);
char String_getCharAtIndex(String s, size_t index);

String String_toLowerCase(String s);
String String_toUpperCase(String s);

bool String_equals(String s1, String s2);
bool String_startsWith(String s1, String s2);
bool String_endsWith(String s1, String s2);

String String_concatenate(String s1, String s2);

void String_print(String s);
void String_println(String s);
