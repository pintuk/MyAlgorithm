#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


#define MAXSIZE	50

int stack[MAXSIZE];
int top = -1;


void push(int item)
{
	if (top == MAXSIZE - 1) {
		printf("Error: stack overflow...\n");
		exit(0);
	}
	top++;
	stack[top] = item;
}

int pop(void)
{
	int item;
	if (top == -1) {
		printf("Error: stack is empty...\n");
		exit(0);
	}
	item = stack[top];
	top--;
	return item;
}

void Display(void)
{
	int i;
	for(i=top; i>=0; i--) {
		printf("%c\n",stack[i]);
	}
}

int Precedence(int op)
{
	int pre = 0;
	switch (op) 
	{
		case '+':
		case '-':
			pre = 1;
		break;
		
		case '*':
		case '/':
			pre = 2;
		break;

		case '^':
			pre = 3;
		break;

		default:
			pre = 0;
		break;
	}
	return pre;
}

int InfixtoPostfix(char *expr, char *postfix)
{
	int ch;
	int op;
	int i = 0; int j = 0;

	top = -1;
	memset(postfix, '\0', sizeof(postfix));
	while( expr[i] != '\0') {
 		ch = expr[i];
		if ( (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) {
			postfix[j++] = ch;
		}
		else if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
			//check precedence of operator
			if (Precedence(stack[top]) > Precedence(ch)) {
				op = pop();
				postfix[j++] = op;
				push(ch);
			}
			else {
				push(ch);
			}
		}
		else if (ch == ')') {
			while(stack[top] != '(') {
				op = pop();
				postfix[j++] = op;
			}
			pop(); //remove '(' from stack
		}
		else if (ch == '(') {
			push(ch);
		}
		else {
			printf("ERROR: Invalid Symbol...<%c>\n",ch);
			return -1;
		}
		i++;
	}

	return 0;
}

int EvaluatePostfix(char *postfix)
{
	int i=0;
	int ch;
	int result = 0;

	top = -1;
	while (postfix[i] != '\0') {
		ch = postfix[i];
		if (ch >= '0' && ch <= '9') {
			push((ch-'0'));
		}
		else if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
			int op1,op2;
			op1 = pop();
			op2 = pop();
			switch (ch)
			{
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
					printf("Invalid operator.....<%c>\n",ch);
					exit(-1);
				break;
			}
			push(result);
		}
		else {
			printf("ERROR: Invalid Symbol...<ch>\n",ch);
			exit (-1);
		}
		i++;
	}
	result = pop();
	return result;
}

int main()
{
	char infix[MAXSIZE];
	char postfix[MAXSIZE];
	int ch;
	int i=0;
	int value = 0;
	int ret = -1;

	top = -1;
	memset(infix, '\0', sizeof(infix));
	memset(postfix, '\0', sizeof(postfix));
	memset(stack, 0, sizeof(stack));
	
	printf("Enter the expression: \n");
	while ( (ch = getchar()) != '\n') {
		infix[i++] = ch;
	}
	printf("Infix: %s\n",infix);
	ret = InfixtoPostfix(infix, postfix);
	if (ret < 0) {
		return;
	}
	printf("postfix: ");
	for (i=0; postfix[i] != '\0'; i++) {
		printf("%c",postfix[i]);
	}
	printf("\n");
	memset(stack, 0, sizeof(stack));
	top = -1;
	printf("AFTER EVALUATE:\n");
	value = EvaluatePostfix(postfix);
	printf("VALUE : %d\n",value);
	printf("\n");
}


