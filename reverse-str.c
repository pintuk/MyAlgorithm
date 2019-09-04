#include <stdio.h>
#include <string.h>

void swap(char *c1, char *c2)
{
        char c;

        c = *c1;
        *c1 = *c2;
        *c2 = c;
}

char *reverse(char *str)
{
        int i, len;
        char c;

        if (str == NULL)
                return NULL;

        len = strlen(str);
        for (i = 0; i < len/2; i++) {
                c = str[i];
                str[i] = str[len - 1 - i];
                str[len - 1 - i] = c;
                //swap(&str[i], &str[len - 1 - i]);
        }
        return str;
}

int main()
{
        char *ptr;
        char str[] = "sony";
        ptr = reverse(str);
        if (ptr != NULL)
                printf("%s\n", str);

        return 0;
}
