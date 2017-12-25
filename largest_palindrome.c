#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	SIZE	100
#define max(a,b)	((a) > (b)) ? (a) : (b)

int K[SIZE][SIZE];

int PrintMatrix(int n, int A[][SIZE])
{
	int i,j;
	for (i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}

int palindrome(char *str, int start, int end)
{
	int i,j;
	int n=0;
	n = (end-start)+1;
	j=0;
	for (i=start; i<=(start+n/2); i++) {
		if (str[i] != str[end-j]) {
			return 0;
		}
		j++;
	}
	return 1;
}

int search_palindrome(char *str, int start, int end)
{
	int s = 0;
	int n=0;
	int i=0;
	
	n = (end-start)+1;

	if (n == 1)
		return 1;

	if (n == 2) {
		if (str[start] == str[end])
			return 2;
	}

	if (n == 3) {
		if (str[start] == str[end])
			return 3;
	}

	if (K[start][end] <= 0) {
		printf("start: %d, end: %d, n: %d\n", start,end,n);
		if (palindrome(str,start,end)) {
			printf("Full palindrome: \n");
			for (i=start; i<=end; i++) {
				printf("%c",str[i]);
			}
			printf("\n");
			return ((end-start)+1);
		}

		K[start][end] = max(search_palindrome(str,start+1,end), search_palindrome(str,start,end-1));
	}

	return K[start][end];
}

int main()
{
	int i,j;
	int n;
	char string[SIZE];
	char cells[SIZE][SIZE];
	int max1=0;
	int max2=0;
	int max=0;
	int len=0;

	freopen("palindrome_cells.txt","r",stdin);	
	//printf("Enter  a string: ");
	//scanf("%s", string);
	memset(K,0,sizeof(K));
	scanf("%d\n",&n);
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			scanf("%c",&cells[i][j]);
			string[j] = cells[i][j];
		}
		scanf("\n");
		string[j] = '\0';
		printf("string1: %s\n", string);
		max1 = search_palindrome(string,0,n-1);
		if (max1 > max)
			max = max1;
	}
	len = strlen(string);
	//printf("Is Palindrome: ");
	//if (palindrome(string,0,len-1))
	//	printf("Yes\n");
	//else
	//	printf("No\n");
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			string[j] = cells[j][i];
		}
		string[j] = '\0';
		printf("string2: %s\n", string);
		max2 = search_palindrome(string,0,n-1);
		if (max2 > max)
			max = max2;
	}
	//max = search_palindrome(string,0,len-1);
	printf("Max palindrome len: %d\n", max);
	//PrintMatrix(len,K);

	return 0;
}

