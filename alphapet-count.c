#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void alpha_count(char *str, int count[])
{
        int i;

        for (i = 0; str[i] != '\0'; i++) {
                int a;
                if (isspace(str[i]))
                        continue;

                a = toascii(str[i]);
                count[a%128]++;
        }
}

int main()
{
        int i;
        char ch, sentence[4096];
        int count[128];

        printf("Enter a sentence:\n");
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strlen(sentence)-1] = '\0';

        printf("Read sentence as:\n");
        printf("%s\n", sentence);

        memset(count, 0, sizeof(count));
        alpha_count(sentence, count);
        //for (i = 0; i < 128; i++) {
        //      if (i >= toascii('a') && i <= toascii('z'))
        //              printf("%d : %d\n", i, count[i]);
        //}
        for (ch = 'a'; ch <= 'z'; ch++) {
                printf("%c : %d\n", ch, count[toascii(ch)]);
        }

        return 0;
}
