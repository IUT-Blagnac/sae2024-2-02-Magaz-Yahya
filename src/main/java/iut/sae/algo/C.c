#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/Basic.h> // Add this line

void RLE(const char *input, char *output) {
    int length = strlen(input);
    int count = 1;
    int position = 0;

    for (int i = 1; i <= length; i++) {
        if (i < length && input[i] == input[i - 1]) {
            count++;
        } else {
            while (count > 9) {
                output[position++] = '9';
                output[position++] = input[i - 1];
                count -= 9;
            }
            output[position++] = '0' + count;
            output[position++] = input[i - 1];
            count = 1;
        }
    }
    output[position] = '\0';
}

void unRLE(const char *input, char *output) {
    int position = 0;
    for (int i = 0; input[i] != '\0'; i += 2) {
        int count = input[i] - '0';
        char c = input[i + 1];
        memset(output + position, c, count);
        position += count;
    }
    output[position] = '\0';
}

void test_RLE() {
    char output[200];

    RLE("", output);
    CU_ASSERT_STRING_EQUAL(output, "");

    RLE("abc", output);
    CU_ASSERT_STRING_EQUAL(output, "1a1b1c");

    RLE("abbccc", output);
    CU_ASSERT_STRING_EQUAL(output, "1a2b3c");

    RLE("aaabaa", output);
    CU_ASSERT_STRING_EQUAL(output, "3a1b2a");

    RLE("aAa", output);
    CU_ASSERT_STRING_EQUAL(output, "1a1A1a");

    RLE("WWWWWWWWWWWWW", output);
    CU_ASSERT_STRING_EQUAL(output, "9W4W");
}

void test_RLE_additional() {
    char output[200];

    RLE("a", output);
    CU_ASSERT_STRING_EQUAL(output, "1a");

    RLE("A", output);
    CU_ASSERT_STRING_EQUAL(output, "1A");

    RLE("@#$", output);
    CU_ASSERT_STRING_EQUAL(output, "1@1#1$");

    RLE("aaaaaaaaaaaa", output);
    CU_ASSERT_STRING_EQUAL(output, "9a3a");
}

void test_unRLE() {
    char output[200];

    unRLE("", output);
    CU_ASSERT_STRING_EQUAL(output, "");

    unRLE("1a1b1c", output);
    CU_ASSERT_STRING_EQUAL(output, "abc");

    unRLE("1a2b3c", output);
    CU_ASSERT_STRING_EQUAL(output, "abbccc");

    unRLE("3a1b2a", output);
    CU_ASSERT_STRING_EQUAL(output, "aaabaa");

    unRLE("1a1A1a", output);
    CU_ASSERT_STRING_EQUAL(output, "aAa");

    unRLE("9W4W", output);
    CU_ASSERT_STRING_EQUAL(output, "WWWWWWWWWWWWW");
}

void test_unRLE_additional() {
    char output[200];

    unRLE("1@1#1$", output);
    CU_ASSERT_STRING_EQUAL(output, "@#$");

    unRLE("9a3a", output);
    CU_ASSERT_STRING_EQUAL(output, "aaaaaaaaaaaa");

    unRLE("2a2A2a", output);
    CU_ASSERT_STRING_EQUAL(output, "aaAAaa");
}

int main() {
    CU_initialize_registry();    
    CU_pSuite suite = CU_add_suite("RLE_test_suite", 0, 0); // Now it compiles
    CU_add_test(suite, "test_RLE", test_RLE);
    CU_add_test(suite, "test_RLE_additional", test_RLE_additional);
    CU_add_test(suite, "test_unRLE", test_unRLE);
    CU_add_test(suite, "test_unRLE_additional", test_unRLE_additional);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}