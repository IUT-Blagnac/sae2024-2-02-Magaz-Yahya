#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Complexité : 0(n)^2

// Fonction RLE
void RLE(char *s, char *r) {
  while (*s) {
    char current_char = *s;
    int n = 1;
    while (*(s + 1) && *s == *(s + 1) && n < 9) {
      n++;
      s++;
    }
    *r++ = '0' + n;
    *r++ = current_char;
    s++;
  }
  *r = '\0';
}

// Fonction RLE récursive
void RLE_recursive(char *s, char *r) {
  if (*s == '\0') {
    *r = '\0';
    return;
  }
  char current_char = *s;
  int n = 1;
  while (*(s + 1) && *s == *(s + 1) && n < 9) {
    n++;
    s++;
  }
  *r++ = '0' + n;
  *r++ = current_char;
  RLE_recursive(s + 1, r);
}

// Fonction unRLE
void unRLE(char *r, char *s) {
  while (*r) {
    int count = *r++ - '0';
    char current_char = *r++;
    memset(s, current_char, count);
    s += count;
  }
  *s = '\0';
}

// Fonction unRLE récursive
void unRLE_recursive(char *r, char *s) {
  if (*r == '\0') {
    *s = '\0';
    return;
  }
  int count = *r++ - '0';
  char current_char = *r++;
  memset(s, current_char, count);
  unRLE_recursive(r, s + count);
}