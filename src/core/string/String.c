#include "String.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char *string;
    size_t length;
};

String String_create(const char *string) {
    String s;
    size_t length = strlen(string);

    s = malloc(sizeof(struct String));
    s->length = length;
    s->string = malloc(length + 1);
    strncpy(s->string, string, length);
    s->string[length] = '\0';

    return s;
}

void String_destroy(String s) {
    if (s == NULL) {
        return;
    }

    free(s->string);
    free(s);

    return;
}

String String_copy(String s) {
    if (s == NULL) {
        return NULL;
    }

    const char *string = String_getString(s);
    String t = String_create(string);

    return t;
}

// TODO add null checks to getters

const char *String_getString(String s) { return s->string; }
size_t String_getLength(String s) { return s->length; }

// TODO add bounds checks

char String_getCharAtIndex(String s, size_t index) {
    const char *string = String_getString(s);

    return string[index];
}

void String_toLowerCase(String s) {
    char *c = (char *)String_getString(s);

    while (*c != '\0') {
        if (*c >= 'A' && *c <= 'Z') {
            *c += 32;
        }
        c++;
    }

    return;
}

void String_toUpperCase(String s) {
    char *c = (char *)String_getString(s);

    while (*c != '\0') {
        if (*c >= 'a' && *c <= 'z') {
            *c -= 32;
        }
        c++;
    }

    return;
}

bool String_equals(String s1, String s2) {
    size_t s1Length = String_getLength(s1);
    size_t s2Length = String_getLength(s2);

    if (s1Length != s2Length) {
        return false;
    }

    const char *s1String = String_getString(s1);
    const char *s2String = String_getString(s2);

    if (strncmp(s1String, s2String, s1Length) == 0) {
        return true;
    } else {
        return false;
    }
}

bool String_startsWith(String s1, String s2) {
    size_t s1Length = String_getLength(s1);
    size_t s2Length = String_getLength(s2);

    if (s1Length < s2Length) {
        return false;
    }

    const char *s1String = String_getString(s1);
    const char *s2String = String_getString(s2);

    if (strncmp(s1String, s2String, s2Length) == 0) {
        return true;
    } else {
        return false;
    }
}

bool String_endsWith(String s1, String s2) {
    size_t s1Length = String_getLength(s1);
    size_t s2Length = String_getLength(s2);

    if (s1Length < s2Length) {
        return false;
    }

    const char *s1String = String_getString(s1);
    const char *s2String = String_getString(s2);

    if (strncmp(s1String + (s1Length - s2Length), s2String, s2Length) == 0) {
        return true;
    } else {
        return false;
    }
}

bool String_contains(String s1, String s2) {
    size_t s1Length = String_getLength(s1);
    size_t s2Length = String_getLength(s2);

    if (s1Length < s2Length) {
        return false;
    }

    const char *s1String = String_getString(s1);
    const char *s2String = String_getString(s2);

    if (strstr(s1String, s2String) != NULL) {
        return true;
    } else {
        return false;
    }
}

String String_concatenate(String s1, String s2) {
    size_t s1Length = String_getLength(s1);
    size_t s2Length = String_getLength(s2);

    const char *s1String = String_getString(s1);
    const char *s2String = String_getString(s2);

    char *buf = calloc(s1Length + s2Length + 1, sizeof(char));
    strncpy(buf, s1String, s1Length);
    strncpy(buf + s1Length, s2String, s2Length);
    String s3 = String_create(buf);
    free(buf);

    return s3;
}

void String_print(String s) {
    if (s == NULL) {
        return;
    }

    const char *string = String_getString(s);

    printf("%s", string);

    return;
}

void String_println(String s) {
    String_print(s);
    printf("\n");

    return;
}
