#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static inline void swap(char *a, char *b)
{
        char t;
        t = *a;
        *a = *b;
        *b = t;
}

void reverse_str(char *start, char *end)
{
        char *ptr1, *ptr2;

        if (start == NULL || end == NULL)
                return;
        ptr1 = start;
        ptr2 = end;
        while (ptr1 < ptr2) {
                //printf("ptr1: %c, ptr2: %c\n", *ptr1, *ptr2);
                swap(ptr1, ptr2);
                ptr1++;
                ptr2--;
        }
}

int main()
{
        char string[] = "Let's take LeetCode contest";
        int i, len, count = 0;
        char *ptr = NULL, *begin = NULL, *end = NULL;

        printf("input: %s\n", string);
        len = strlen(string);
        //reverse_str(string, string + len - 1);
        begin = end = string;
        ptr = string;
#if 0
        while (ptr) {
                if (isspace(*ptr) || (*ptr == '\0')) {
                        count++;
                        printf("begin: %c, end: %c\n", *begin, *end);
                        printf("count: %d\n", count);
                        reverse_str(begin, end - 1);
                        printf("string so far: %s\n", string);
                        if (*ptr == '\0') break;
                        begin = end + 1;
                }
                end++;
                ptr++;
        }
#endif
        for (i = 0; i <= len; i++) {
                if (isspace(string[i]) || (i == len)) {
                        count++;
                        reverse_str(begin, &string[i-1]);
                        begin = &string[i+1];
                }
        }

        printf("%s\n", string);
        printf("count words: %d\n", count);
        reverse_str(string, string + len - 1);
        printf("reverse words: %s\n", string);

        return 0;
}
