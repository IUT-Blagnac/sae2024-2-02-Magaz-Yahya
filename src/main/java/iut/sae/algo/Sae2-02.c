#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* RLE(const char* in) {
    if (in == NULL) return NULL;

    int len = strlen(in);
    if (len == 0) return strdup(""); // Handle empty input string

    int compteur = 1;
    char* rle = (char*)malloc(2 * len + 1); // Allocate memory for the worst case
    if (rle == NULL) return NULL; // Check malloc success

    int pos = 0;
    for (int i = 0; i < len; i++) {
        if (i + 1 < len && in[i] == in[i + 1] && compteur != 9) {
            compteur++;
        } else {
            pos += sprintf(rle + pos, "%d%c", compteur, in[i]);
            compteur = 1;
        }
        // Debugging output
        printf("Current char: %c, count: %d, pos: %d\n", in[i], compteur, pos);
    }
    rle[pos] = '\0'; // Ensure null termination
    rle = realloc(rle, pos + 1); // Resize to actual size used
    if (rle == NULL) return NULL; // Check realloc success

    return rle;
}

int main() {
    const char* input = "aaaabbbccdaaa";
    char* encoded = RLE(input);
    if (encoded != NULL) {
        printf("RLE: %s\n", encoded);
        free(encoded); 
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
