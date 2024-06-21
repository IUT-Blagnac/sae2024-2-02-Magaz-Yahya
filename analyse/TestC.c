#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *RLE(const char *in) {
    if (in == NULL || in[0] == '\0') {
        printf("Tableau vide \n");
        exit(1);
    }

    int length = strlen(in);
    char *stringReturn = malloc((2 * length + 1) * sizeof(char));
    stringReturn[0] = '\0';  // Assurez-vous que la chaîne de sortie commence par une chaîne vide

    int pos = 0;
    char charSelect = in[0];
    int nbChar = 1;

    for (int i = 1; i <= length; i++) {
        if (i < length && in[i] == charSelect) {
            nbChar++;
        } else {
            pos += sprintf(stringReturn + pos, "%d%c", nbChar, charSelect);
            if (i < length) {
                charSelect = in[i];
                nbChar = 1;
            }
        }
    }

    return stringReturn;
}

char *unRLE(const char *in) {
    if (in == NULL || in[0] == '\0') {
        printf("Tableau vide \n");
        exit(1);
    }

    int length = strlen(in);
    char *stringReturn = malloc((length + 1) * sizeof(char));
    stringReturn[0] = '\0';  // Assurez-vous que la chaîne de sortie commence par une chaîne vide

    int pos = 0;

    for (int i = 0; i < length; i += 2) {
        int count = in[i] - '0';
        char charToRepeat = in[i + 1];

        for (int j = 0; j < count; j++) {
            stringReturn[pos++] = charToRepeat;
        }
    }

    stringReturn[pos] = '\0';

    return stringReturn;
}

int main() {
    {
        char input[] = "";
        char *encoded = RLE(input);
        printf("RLE(\"%s\") = \"%s\"\n", input, encoded);
    }

    {
        char input[] = "abc";
        char *encoded = RLE(input);
        printf("RLE(\"%s\") = \"%s\"\n", input, encoded);
    }

    {
        char input[] = "abbccc";
        char *encoded = RLE(input);
        printf("RLE(\"%s\") = \"%s\"\n", input, encoded);
    }

    {
        char input[] = "aaabaa";
        char *encoded = RLE(input);
        printf("RLE(\"%s\") = \"%s\"\n", input, encoded);
    }

    return 0;
}
