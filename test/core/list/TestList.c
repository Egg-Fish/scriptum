#include "core/list/List.h"

#include "unity.h"

#include <stdint.h>

void setUp(void) {}

void tearDown(void) {}

void test__List_appendItem__32Items(void) {
    List l = List_create();

    for (size_t i = 0; i < 32; i++) {
        List_appendItem(l, (void *)i);
    }

    TEST_ASSERT_EQUAL_INT(32, List_getLength(l));

    List_destroy(l);
}

void test__List_getItemAtIndex__32Items(void) {
    List l = List_create();

    for (size_t i = 0; i < 32; i++) {
        List_appendItem(l, (void *)(i + 1));
    }

    for (size_t i = 0; i < 32; i++) {
        size_t expected = i + 1;
        size_t actual = (size_t)List_getItemAtIndex(l, i);

        TEST_ASSERT_EQUAL_INT(expected, actual);
    }

    List_destroy(l);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__List_appendItem__32Items);
    RUN_TEST(test__List_getItemAtIndex__32Items);

    return UNITY_END();
}
