#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE 50

int stack[MAXSIZE];
int top = -1;

char Operator[6] = {'^', '/', '*', '+', '-', '\0'};


int isoperator(char c)
{
        char *p = Operator;

        while (*p != '\0') {
                if(*p == c)
                        return 1;
                p++;
        }

        return 0;
}


void push(int item)
{
        if (top >= MAXSIZE)
                return;
        top++;
        stack[top] = item;
}

int pop(void)
{
        int item;

        if (top < 0)
                return -1;
        item = stack[top];
        top--;
        return item;
}

char *get_digits(char *str)
{
        int i = 0;
        static char tmp[10];

        while (isdigit(str[i])) {
                tmp[i] = str[i];
                i++;
        }
        tmp[i] = '\0';

        return tmp;
}

int EvaluatePostfix(char *postfix)
{
        int i, flag;
        char ch;
        int result = 0;
        char *num;

        top = -1;
        flag = 0;
        for (i = 0; postfix[i] != '\0'; i++) {
                ch = postfix[i];

                if (isspace(ch)) continue;

                if(isdigit(ch)) {
                        char *str = &postfix[i];
                        int k = 0;
                        num = get_digits(str);
                        k = strlen(num);
                        i += k;
                        //printf("num: %s ; k: %d ; i: %d\n", num, k, i);
                        push(atoi(num));
                        continue;
                }

                if (isoperator(ch)) {
                        int op1, op2;

                        op1 = pop();
                        op2 = pop();
                        switch (ch) {
                                case '+':
                                        result = op2 + op1;
                                break;
                                case '-':
                                        result = op2 - op1;
                                break;
                                case '*':
                                        result = op2 * op1;
                                break;
                                case '/':
                                        result = op2 / op1;
                                break;
                                case '^':
                                        result = pow(op2, op1);
                                break;
                                default:
                                        return -1;
                                break;
                        }
                        push(result);
                }
                else {
                        return -1;
                }
        }
        result = pop();

        return result;
}

int main()
{
        char postfix[MAXSIZE];
        int ch;
        int i=0;
        int value = 0;
        int ret = -1;

        top = -1;
        memset(postfix, '\0', sizeof(postfix));
        memset(stack, 0, sizeof(stack));

        while ( (ch = getchar()) != '\n' && ch != EOF) {
                postfix[i++] = ch;
        }
        postfix[i] = '\0';
        value = EvaluatePostfix(postfix);
        printf("%d\n",value);

        return 0;
}
