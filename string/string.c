#include "string.h"

void str_copy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

void str_concat(char *dest, const char *src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

int str_compare(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int str_search(const char *haystack, const char *needle) {
    int i = 0, j;
    if (!*needle) return 0;

    while (haystack[i]) {
        j = 0;
        while (needle[j] && haystack[i + j] == needle[j]) {
            j++;
        }
        if (!needle[j]) return i;
        i++;
    }

    return -1;
}
