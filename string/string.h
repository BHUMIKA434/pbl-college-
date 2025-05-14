#ifndef STRING_H
#define STRING_H

void str_copy(char *dest, const char *src);
void str_concat(char *dest, const char *src);
int str_compare(const char *str1, const char *str2);
int str_search(const char *haystack, const char *needle);

#endif
