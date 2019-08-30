#include <stdio.h>
#include <stdlib.h>


void print_element(int **dptr, int row, int col)
{
        int i,j;

        for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                        printf("%-2d   ", dptr[i][j]);
                }
                printf("\n");
        }
}

int contig_alloc()
{
        int **dptr = NULL, *ptr = NULL;
        int i, j;
        int row, col, len;

        row = 5; col = 10;

        len = sizeof(int *)*row + sizeof(int)*row*col;
        dptr = (int **)malloc(len);
        ptr = (int *)(dptr + row);

        for (i = 0; i < row; i++) {
                dptr[i] = (ptr + i*col);
        }
        for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                        dptr[i][j] = i + j;
                }
        }
        print_element(dptr, row, col);
}


int noncontig_alloc()
{
        int **dptr = NULL;
        int i, j;
        int row, col;

        row = 5;
        col = 10;
        dptr = (int **)malloc(sizeof(int *)*row);
        for (i = 0; i < row; i++) {
                dptr[i] = (int *)malloc(sizeof(int)*col);
                for (j = 0; j < col; j++) {
                        dptr[i][j] = i + j;
                }
        }
        print_element(dptr, row, col);

        return 0;
}

int main()
{
        //noncontig_alloc();
        contig_alloc();

        return 0;
}
