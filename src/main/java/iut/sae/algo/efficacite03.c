#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Prend une chaîne d'entrée et la compresse à l'aide de l'algorithme de codage Run-length.
 * 
 * @param input  la chaîne d'entrée
 * @param output le buffer à stocker
 */
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

/**
 * Prend une chaîne compressée d’encodage Run-length et la décompresse.
 * 
 * @param input  la chaîne d'entrée
 * @param outout le buffer à stocker
 */
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

/**
 * Il imprime à la fois les chaînes compressées et décompressées.
 * 
 * @return renvoie 0 en cas d'exécution réussie
 */
int main() {
    char input[100];
    char output[200];
    char decoded[100];

    printf("Enter the string: ");
    scanf("%99s", input);

    RLE(input, output);
    printf("Encoded: %s\n", output);

    unRLE(output, decoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}