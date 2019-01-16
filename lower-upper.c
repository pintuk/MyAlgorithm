#include <stdio.h>


char *lower_case(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++) {
		//printf("BEFORE: %c : hex: 0x%x\n", str[i], str[i]);
		str[i] = str[i] | 0x20;
		//printf("AFTER: %c : hex: 0x%x\n", str[i], str[i]);
	}

	return str;
}

char *upper_case(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++) {
		str[i] = str[i] ^ 0x20;
	}

	return str;
}

int main()
{
	char str[20], *ptr;

	printf("Enter a upper case string:\n");
	scanf("%s", str);

	ptr = lower_case(str);
	printf("lower case = %s\n", ptr);
	ptr = upper_case(str);
	printf("upper case = %s\n", ptr);

	return 0;
}
